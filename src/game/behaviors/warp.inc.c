// warp.inc.c

void bhv_warp_loop(void) {
    if (o->oTimer == 0) {
        u16 sp6 = (o->oBehParams >> 24) & 0xFF;

        if (sp6 == 0) {
            o->hitboxRadius = 50.0f;
        } else if (sp6 == 0xFF) {
            o->hitboxRadius = 10000.0f;
        } else {
            o->hitboxRadius = sp6 * 10.0f;
        }
        o->hitboxHeight = 50.0f;
    }

    o->oInteractStatus = 0;
}

// identical to the above function except for o->hitboxRadius
void bhv_fading_warp_loop() {
    if (o->oTimer == 0) {
        u16 sp6 = (o->oBehParams >> 24) & 0xFF;

        if (sp6 == 0) {
            o->hitboxRadius = 85.0f;
        } else if (sp6 == 0xFF) {
            o->hitboxRadius = 10000.0f;
        } else {
            o->hitboxRadius = sp6 * 10.0f;
        }
        o->hitboxHeight = 50.0f;
    }

    o->oInteractStatus = 0;
}
