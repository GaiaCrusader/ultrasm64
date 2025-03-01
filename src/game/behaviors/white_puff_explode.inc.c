// white_puff_explode.inc.c

void bhv_white_puff_exploding_loop(void) {
    if (o->oTimer == 0) {
        cur_obj_compute_vel_xz();
        o->oWhitePuffUnkF4 = o->header.gfx.scale[0];
        switch (o->oBehParams2ndByte) {
            case 2:
                o->oOpacity = 254;
                o->oWhitePuffUnkF8 = -21;
                o->oWhitePuffUnkFC = 0;
                break;
            case 3:
                o->oOpacity = 254;
                o->oWhitePuffUnkF8 = -13;
                o->oWhitePuffUnkFC = 1;
                break;
        }
    }

    cur_obj_move_using_vel_and_gravity();
    cur_obj_apply_drag_xz(o->oDragStrength);

    if (o->oVelY > 100.0f) {
        o->oVelY = 100.0f;
    }

    if (o->oTimer > 20) {
        obj_mark_for_deletion(o);
    }

    if (o->oOpacity) {
        f32 scale;
        o->oOpacity += o->oWhitePuffUnkF8;
        if (o->oOpacity < 2) {
            obj_mark_for_deletion(o);
        }
        if (o->oWhitePuffUnkFC) {
            scale = o->oWhitePuffUnkF4 * ((254 - o->oOpacity) / 254.0f);
        } else {
            scale = o->oWhitePuffUnkF4 * (o->oOpacity / 254.0f);
        }
        cur_obj_scale(scale);
    }
}
