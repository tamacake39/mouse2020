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

	drive_enable_motor();     //ステッピングモータを励磁，drive.c で定義されている

	MF.FLAG.SCND = fs;         //二次走行フラグをセット，マウスフラグは global.h に定義あり
	goal_x = GOAL_X;
	goal_y = GOAL_Y;          //ゴール座標を設定，GOAL_X・GOAL_Y は global.h に定義あり

	rotate_R90();             //右に90度回転する，drive.c で定義されている
	drive_wait();             //機体が安定するまで待機，drive.h に定義あり
	set_position(0);          //尻当てをして機体の位置を中央へ，drive.c で定義されている
	drive_wait();             //機体が安定するまで待機
	rotate_L90();             //左に90度回転する，drive.c で定義されている
	drive_wait();             //機体が安定するまで待機
	set_position(1);          //尻当てをして機体の位置を中央へ
	drive_wait();             //機体が安定するまで待機

	searchA();                //現在位置（スタート地点）からゴール座標まで探索走行（1区画走行）
	HAL_Delay(500);

	goal_x = goal_y = 0;      //ゴール座標をスタート地点に設定する

	rotate_R90();             //右に90度回転する，drive.c で定義されている
	drive_wait();             //機体が安定するまで待機，drive.h に定義あり
	set_position(0);          //尻当てをして機体の位置を中央へ，drive.c で定義されている
	drive_wait();             //機体が安定するまで待機
	rotate_L90();             //左に90度回転する，drive.c で定義されている
	drive_wait();             //機体が安定するまで待機
	set_position(0);          //尻当てをして機体の位置を中央へ
	drive_wait();             //機体が安定するまで待機

	searchA();                //探索しながらスタート地点に戻る（1区画走行）

	goal_x = GOAL_X;
	goal_y = GOAL_Y;          //ゴール座標を設定

	drive_disable_motor();    //ステッピングモータの励磁を切る
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

	MF.FLAG.SCND = (fs ? 1 : 0);
	goal_x = GOAL_X;
	goal_y = GOAL_Y;

	rotate_R90();
	drive_wait();
	set_position(0);
	drive_wait();
	rotate_L90();
	drive_wait();
	set_position(1);
	drive_wait();

	searchB();
	HAL_Delay(500);

	goal_x = goal_y = 0;

	searchB();

	goal_x = GOAL_X;
	goal_y = GOAL_Y;

	drive_disable_motor();
}

//+++++++++++++++++++++++++++++++++++++++++++++++
//　searchC_run
// 一,二次探索走行（スラローム連続走行）
// 引数：一,二時走行フラグ
// 戻り値：なし
//+++++++++++++++++++++++++++++++++++++++++++++++
void searchC_run(int fs) {

	drive_enable_motor();

	MF.FLAG.SCND = fs;
	goal_x = GOAL_X;
	goal_y = GOAL_Y;

	rotate_R90();
	drive_wait();
	set_position(0);
	drive_wait();
	rotate_L90();
	drive_wait();
	set_position(1);
	drive_wait();

	searchC();
	HAL_Delay(500);

	goal_x = goal_y = 0;

	searchC();

	goal_x = GOAL_X;
	goal_y = GOAL_Y;

	drive_disable_motor();
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