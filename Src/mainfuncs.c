/*
 * mainfuncs.c
 *
 *  Created on: Sep 2, 2021
 *      Author: tamacake39
 */

#include "global.h"

//+++++++++++++++++++++++++++++++++++++++++++++++
//　searchA_run
// 一,二次探索走行（1区画走行）
// 引数：一,二時走行フラグ
// 戻り値：なし
//+++++++++++++++++++++++++++++++++++++++++++++++
void searchA_run(int fs) {
    drive_enable_motor();

    for (n_run = 0; n_run < 5; n_run++) {
        MF.FLAG.SCND = (n_run ? 1 : 0);
        {
            rotate_R90();
            drive_wait();
            set_position(0);
            drive_wait();
            rotate_L90();
            drive_wait();
            set_position(1);
            drive_wait();
        }

        goal_x = GOAL_X;
        goal_y = GOAL_Y;
        searchA(1);

        HAL_Delay(500);

        goal_x = goal_y = 0;
        searchA(0);
    }

    drive_disable_motor();

    return;
}

//+++++++++++++++++++++++++++++++++++++++++++++++
//　searchB_run
// 一,二次探索走行（連続走行）
// 引数：一,二時走行フラグ
// 戻り値：なし
//+++++++++++++++++++++++++++++++++++++++++++++++
void searchB_run(int fs) {
    drive_enable_motor();

    for (n_run = 0; n_run < 5; n_run++) {
        MF.FLAG.SCND = (n_run ? 1 : 0);
        {
            rotate_R90();
            drive_wait();
            set_position(0);
            drive_wait();
            rotate_L90();
            drive_wait();
            set_position(1);
            drive_wait();
        }

        goal_x = GOAL_X;
        goal_y = GOAL_Y;
        searchB(1);

        HAL_Delay(500);

        goal_x = goal_y = 0;
        searchB(0);
    }

    drive_disable_motor();

    return;
}

//+++++++++++++++++++++++++++++++++++++++++++++++
//　searchC_run
// 一,二次探索走行（スラローム連続走行）
// 引数：一,二時走行フラグ
// 戻り値：なし
//+++++++++++++++++++++++++++++++++++++++++++++++
void searchC_run(int fs) {
    drive_enable_motor();

    for (n_run = 0; n_run < 5; n_run++) {
        MF.FLAG.SCND = (n_run ? 1 : 0);
        {
            rotate_R90();
            drive_wait();
            set_position(0);
            drive_wait();
            rotate_L90();
            drive_wait();
            set_position(1);
            drive_wait();
        }

        goal_x = GOAL_X;
        goal_y = GOAL_Y;
        if (n_run) {
            searchC_ad(1);
        } else {
            searchC(1);
        }

        HAL_Delay(500);

        goal_x = goal_y = 0;
        if (n_run) {
            searchC_ad(0);
        } else {
            searchC(0);
        }
    }

    drive_disable_motor();

    return;
}

//+++++++++++++++++++++++++++++++++++++++++++++++
// searchC_run_second
// 二次探索走行単体（スラローム連続走行）
// 引数：なし
// 戻り値：なし
//+++++++++++++++++++++++++++++++++++++++++++++++
void searchC_run_second(void) {
    drive_enable_motor();

    rotate_R90();
    drive_wait();
    set_position(0);
    drive_wait();
    rotate_L90();
    drive_wait();
    set_position(1);
    drive_wait();

    goal_x = GOAL_X;
    goal_y = GOAL_Y;

    searchC_ad(1);

    HAL_Delay(500);

    goal_x = goal_y = 0;

    searchC_ad(0);

    drive_disable_motor();

    return;
}

//+++++++++++++++++++++++++++++++++++++++++++++++
//　sensor_check
// センサチェック
// 引数：なし
// 戻り値：なし
//+++++++++++++++++++++++++++++++++++++++++++++++
void sensor_check(void) {
    do {
        get_wall_info();
        led_write(wall_info & 0x11, wall_info & 0x88, wall_info & 0x44);
        printf(" ad_l : %4d, ad_fl : %4d, ad_fr : %4d, ad_r : %4d\n", ad_l,
               ad_fl, ad_fr, ad_r);
        printf("dif_l : %4d, dif_r : %4d\n", dif_l, dif_r);
        if (wall_info & 0x11) {
            printf("Left : [X], ");
        } else {
            printf("Left : [ ], ");
        }
        if (wall_info & 0x88) {
            printf("Front : [X], ");
        } else {
            printf("Front : [ ], ");
        }
        if (wall_info & 0x44) {
            printf("Right : [X]\n");
        } else {
            printf("Right : [ ]\n");
        }

        HAL_Delay(500);
    } while (!HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin) == GPIO_PIN_RESET);
    HAL_Delay(100);
}
