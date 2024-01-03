import os
import re
import threading

vert_buffer_size = 56
taskID = 0
fileList = []

def convert_tris(image_path):
    file = open(image_path, mode = 'r')
    print("Processing " + image_path + ".")
    lines = file.readlines()
    file.close()
    triIndices = []
    vertCount = 0
    addrMerge = []
    vertAddr = ""
    lineNum = 0
    allGood = True
    linesToDestroy = []
    vBuff = -1
    prevVBuff = 0
    addrFound = False
    for line in lines:
        lineS = line.strip()
        if line.find("gsSPVertex") != -1:
            matches = re.findall(r'\d+', lineS)
            count = int(matches[len(matches) - 2])
            vertCount += count
            if (prevVBuff != 0):
                vBuff += prevVBuff
            prevVBuff = count
            matches2 = re.findall(r'\S+', lineS)
            if (addrFound == False):
                addrFound = True
                vertAddr = matches2[0][11:-1]
            else:
                addrMerge.append(matches2[0][11:-1])
                #print(addrMerge)
            if (lines[lineNum + 1].find("Triangle")) != -1:
                linesToDestroy.append(lineNum)
            #print(vBuff)
            #print("Prev: " + str(prevVBuff))
        elif (line.find("gsSP2Triangles")) != -1 or (line.find("gsSP1Triangle")) != -1:
            matches = re.findall(r'\d+', lineS)
            triIndices.append(int(matches[1]) + vBuff)
            triIndices.append(int(matches[2]) + vBuff)
            triIndices.append(int(matches[3]) + vBuff)
            if (int(matches[0]) == 2): # The first index is either 1 or 2, representing 1tri or 2tri
                triIndices.append(int(matches[6]) + vBuff)
                triIndices.append(int(matches[7]) + vBuff)
                triIndices.append(int(matches[8]) + vBuff)
            if (addrFound == True):
                linesToDestroy.append(lineNum)
            #print(matches)
        else:
            if (vertCount > 0):
                #print(triIndices)

                if (len(addrMerge)) != 0:
                    baseFound = False
                    vertLine = 0
                    addrsNuked = 0
                    vertLineSnap = False
                    for vLine in lines:
                        vLineS = vLine.strip()
                        #print(vLineS)
                        if (vLineS.find(vertAddr) != -1 and baseFound == False):
                            baseFound = True
                        if (baseFound == True and vLine.find("};") != -1):
                            vertLineSnap = True
                        if (vertLineSnap == True):
                            linesToDestroy.append(vertLine)   
                            if (vLineS.find(addrMerge[0]) != -1):
                                del addrMerge[:1]
                                vertLineSnap = False
                                if (len(addrMerge) == 0):
                                    break
                        vertLine += 1


                #print("Triangles: " + str(triIndices))
                #print("Total Vertices: " + str(vertCount))
                trisToDraw = 0
                trisLeft = 0
                vertsIn = 0
                useVerts = 0
                trisDrawn = 0
                totalTri = 0
                newLine = ""
                maxVert = 0
                minVert = 20000
                triLen = len(triIndices)
                i = 0
                if (len(triIndices) != 0):
                    while (True):
                        if (trisLeft == 0):
                            useVerts = min(vertCount - vertsIn, vert_buffer_size)
                            #print("Useverts " + str(useVerts))
                            #print("i " + str(i))
                            #print("Len " + str(len(triIndices)))
                            triOffset = 0
                            if (i < len(triIndices)) and triIndices[i] - vertsIn < useVerts and triIndices[i + 1] - vertsIn < useVerts and triIndices[i + 2] - vertsIn < useVerts:
                                offset2 = vertsIn - (maxVert + 1)
                                maxVert = max(max(max(triIndices[i + 0], triIndices[i + 1]), triIndices[i + 2]), maxVert) - vertsIn
                                minVert = min(min(triIndices[i + 0], triIndices[i + 1]), triIndices[i + 2], minVert)
                                i += 3
                                trisToDraw += 1
                            else:
                                #print("min: " + str(minVert))
                                if (minVert - vertsIn < 0):
                                    triOffset = minVert - vertsIn
                                    #print(triOffset)
                                    allGood = False
                                else:
                                    triOffset = 0
                                i -= 3
                                #print("Use vert: " + str(useVerts))
                                #print("Max vert: " + str(useVerts + 1))
                                newLine += "    gsSPVertex(" + str(vertAddr) + " + " + str(vertsIn) + ", " + str(maxVert + 1) + ", 0),\n"
                                vertsIn += (maxVert + 1)
                                trisLeft = trisToDraw
                                trisToDraw = 0
                                trisDrawn = 0
                                #print("To draw: " + str(trisLeft) + " triangles.")
                                #print("Loaded: " + str(maxVert + 1) + " vertices.")
                        else:
                            offset = vertsIn - (maxVert + 1)
                            #print(offset)
                            #print(triIndices[0])
                            #print(triIndices[1])
                            #print(triIndices[2])
                            if (trisLeft > 1):
                                newLine += "    gsSP2Triangles(" + str(triIndices[0] - offset) + ", " + str(triIndices[1] - offset) + ", " + str(triIndices[2] - offset) + ", 0x0, " + str(triIndices[3] - offset) + ", " + str(triIndices[4] - offset) + ", " + str(triIndices[5] - offset) + ", 0x0),\n"
                                del triIndices[:6]
                                trisLeft -= 2
                                trisDrawn += 6
                                totalTri += 6
                                minVert = 20000
                            else:
                                newLine += "    gsSP1Triangle(" + str(triIndices[0] - offset) + ", " + str(triIndices[1] - offset) + ", " + str(triIndices[2] - offset) + ", 0x0),\n"
                                del triIndices[:3]
                                trisLeft -= 1
                                trisDrawn += 3
                                totalTri += 3
                                minVert = 20000
                            i = 0
                            #print("Verts left: " + str(int(vertCount) - int(vertsIn)))
                            #print("Tris left: " + str(trisLeft))
                            #print("Total left: " + str(len(triIndices)))
                            if (totalTri >= triLen):
                                break
                    #print(newLine)
                    if (allGood == True):
                        while (len(linesToDestroy) > 0):
                            lines[linesToDestroy[0]] = ""
                            del linesToDestroy[:1]
                    lines.insert(lineNum, newLine)
            vertCount = 0
            vBuff = 0
            prevVBuff = 0
            triIndices.clear()
            addrMerge.clear()
            addrFound = False
        lineNum += 1
        if (allGood == True):
            newFile = open(image_path, mode = 'w')
            newFile.writelines(lines)
            newFile.close()

def job():
    folder_path = "./"
    folder_blacklist = ["./actors", "./levels", "./bin"]
    for root, dirs, files in os.walk(folder_path):
        if any(folder in root for folder in folder_blacklist):
            for filename in files:
                if (filename.endswith(".c")):
                    image_path = os.path.join(root, filename)
                    tempThread = threading.Thread(target=convert_tris, args=(image_path,))
                    tempThread.start()
                    #tempThread.join()

print("Running!")
job()