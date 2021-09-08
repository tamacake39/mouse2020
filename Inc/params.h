/*
 * params.h
 *
 *  Created on: May 2, 2019
 *      Author: blue
 */

#ifndef INC_PARAMS_H_
#define INC_PARAMS_H_

/*============================================================
 各種定数（パラメータ）設定
 ============================================================*/
/*------------------------------------------------------------
 走行系
 ------------------------------------------------------------*/
//----走行パルス関連----
#define PULSE_SEC_HALF      222		//半区画走行用パルス。2倍すると1区画分に
#define PULSE_ROT_R90       157		//右90度回転用パルス数
#define PULSE_ROT_L90       157		//左90度回転用パルス数
#define PULSE_ROT_180       314		//180度回転用パルス数

#define PULSE_SLA_R90       234		//半区画右90度スラローム用パルス数
#define PULSE_SLA_L90       236		//半区画左90度スラローム用パルス数

#define PULSE_SETPOS_BACK   250		//後ろ壁に当てるために下がるパルス数
#define PULSE_SETPOS_SET    103		//後ろ壁から中央までのパルス数

//----テーブルカウンタ関連----
#define MAX_T_CNT PULSE_SEC_HALF	//テーブルカウンタの最大値
#define MIN_T_CNT 0					//テーブルカウンタの最小値
#define MAX_T_CNT_SLA PULSE_SLA_R90		//テーブルカウンタの最大値
#define MIN_T_CNT_SLA 0					//テーブルカウンタの最小値

//----パラメータインデックス関連----
#define DEF_SEARCH_PARAM 0
#define DEF_SLA_PARAM_IN 1
#define DEF_SLA_PARAM_OUT 2

//----タイマ関連----
#define DEFAULT_INTERVAL  3000		//デフォルトのインターバル

//----動作方向関連----
#define MT_FWD_L  GPIO_PIN_RESET    //CW/CCWで前に進む出力（左）
#define MT_BACK_L GPIO_PIN_SET  //CW/CCWで後ろに進む出力（左）
#define MT_FWD_R  GPIO_PIN_SET  //CW/CCWで前に進む出力（右）
#define MT_BACK_R GPIO_PIN_RESET    //CW/CCWで後ろに進む出力（右）

/*------------------------------------------------------------
 センサ系
 ------------------------------------------------------------*/
//----壁判断閾値（しきい値）----
#define WALL_BASE_FR  280    //前壁右センサ
#define WALL_BASE_FL  388    //前壁左センサ
#define WALL_BASE_R   213   //右壁センサ
#define WALL_BASE_L   859   //左壁センサ

//----制御閾値（しきい値）----
#define CTRL_BASE_L   100   //左制御閾値
#define CTRL_BASE_R   100   //右制御閾値
#define CTRL_MAX      350   //制御量上限値
#define CTRL_CONT     0.3F  //比例制御係数

//----赤外線（赤色）LED発光待機時間（単位はマイクロ秒）
#define IR_WAIT_US  15

/*------------------------------------------------------------
 探索系
 ------------------------------------------------------------*/
//----ゴール座標----
#define GOAL_X 1  //7
#define GOAL_Y 0  //7

#endif /* INC_PARAMS_H_ */
