#include <ultra64.h>

#include "sm64.h"
#include "profiler.h"
#include "game_init.h"

#ifdef PUPPYPRINT_DEBUG

s16 gProfilerMode = 0;

// the thread 3 info is logged on the opposite profiler from what is used by
// the thread4 and 5 loggers. It's likely because the sound thread runs at a
// much faster rate and shouldn't be flipping the index for the "slower" game
// threads, which could leave the frame data in a possibly corrupt or incomplete
// state.
s16 gCurrentFrameIndex1 = 1;
s16 gCurrentFrameIndex2 = 0;
s16 gCurrentFrameIndex3 = 1;

struct ProfilerFrameData gProfilerFrameData[2];

// log the current osTime to the appropriate idx for current thread5 processes.
void profiler_log_thread5_time(enum ProfilerGameEvent eventID) {
    gProfilerFrameData[gCurrentFrameIndex1].gameTimes[eventID] = osGetCount();

    // event ID 4 is the last profiler event for after swapping
    // buffers: switch the Info after updating.
    if (eventID == THREAD5_END) {
        gCurrentFrameIndex1 ^= 1;
        gProfilerFrameData[gCurrentFrameIndex1].numSoundTimes = 0;
    }
}

void profiler_log_thread9_time(enum ProfilerGameEvent9 eventID) {
    gProfilerFrameData[gCurrentFrameIndex3].videoTimes[eventID] = osGetCount();

    // event ID 4 is the last profiler event for after swapping
    // buffers: switch the Info after updating.
    if (eventID == THREAD9_END) {
        gCurrentFrameIndex3 ^= 1;
    }
}

// log the audio system before and after osTimes in pairs to the soundTimes array.
void profiler_log_thread4_time(void) {
    struct ProfilerFrameData *profiler = &gProfilerFrameData[gCurrentFrameIndex1];

    if (profiler->numSoundTimes < ARRAY_COUNT(profiler->soundTimes)) {
        profiler->soundTimes[profiler->numSoundTimes++] = osGetCount();
    }
}

// log the times for gfxTimes: RSP completes, and RDP completes.
void profiler_log_gfx_time(enum ProfilerGfxEvent eventID) {
    if (eventID == TASKS_QUEUED) {
        gCurrentFrameIndex2 ^= 1;
        gProfilerFrameData[gCurrentFrameIndex2].numVblankTimes = 0;
    }

    gProfilerFrameData[gCurrentFrameIndex2].gfxTimes[eventID] = osGetCount();
}

// log the times between vblank started and ended.
void profiler_log_vblank_time(void) {
    struct ProfilerFrameData *profiler = &gProfilerFrameData[gCurrentFrameIndex2];

    if (profiler->numVblankTimes < ARRAY_COUNT(profiler->vblankTimes)) {
        profiler->vblankTimes[profiler->numVblankTimes++] = osGetCount();
    }
}

#endif