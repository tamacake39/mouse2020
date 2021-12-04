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
#define PULSE_SEC_HALF 222 //半区画走行用パルス。2倍すると1区画分に
#define PULSE_ROT_R90 154  //右90度回転用パルス数
#define PULSE_ROT_L90 154  //左90度回転用パルス数
#define PULSE_ROT_180 308  // 180度回転用パルス数

#define PULSE_SLA_R90 236 //半区画右90度スラローム用パルス数・加減速のために半分の値
#define PULSE_SLA_L90 236 //半区画左90度スラローム用パルス数・加減速のために半分の値
#define PULSE_SLA_PRE 24 //半区画左90度スラローム用パルス数

#define PULSE_SETPOS_BACK 250 //後ろ壁に当てるために下がるパルス数
#define PULSE_SETPOS_SET 103  //後ろ壁から中央までのパルス数

//----テーブルカウンタ関連----
#define MAX_T_CNT 2047              //テーブルカウンタの最大値
#define MIN_T_CNT 0                 //テーブルカウンタの最小値
#define MAX_T_CNT_SLA PULSE_SEC_HALF             //スラロームカウンタの初期値

//----タイマ関連----
#define DEFAULT_INTERVAL 2500 //デフォルトのインターバル

//----動作方向関連----
#define MT_FWD_L GPIO_PIN_RESET  // CW/CCWで前に進む出力（左）
#define MT_BACK_L GPIO_PIN_SET   // CW/CCWで後ろに進む出力（左）
#define MT_FWD_R GPIO_PIN_SET    // CW/CCWで前に進む出力（右）
#define MT_BACK_R GPIO_PIN_RESET // CW/CCWで後ろに進む出力（右）

/*------------------------------------------------------------
 センサ系
 ------------------------------------------------------------*/
//----壁判断閾値（しきい値）----
#define WALL_BASE_FR 280 //前壁右センサ
#define WALL_BASE_FL 388 //前壁左センサ
#define WALL_BASE_R 150  //右壁センサ
#define WALL_BASE_L 600  //左壁センサ

//----制御閾値（しきい値）----
#define CTRL_BASE_L 120 //左制御閾値
#define CTRL_BASE_R 30  //右制御閾値
#define CTRL_MAX 500  //制御量上限値
#define CTRL_CONT 0.7f //比例制御係数

//----赤外線（赤色）LED発光待機時間（単位はマイクロ秒）
#define IR_WAIT_US 15

/*------------------------------------------------------------
 探索系
 ------------------------------------------------------------*/
//----ゴール座標----
#define GOAL_X 13 // 7
#define GOAL_Y 12 // 7

#endif /* INC_PARAMS_H_ */
