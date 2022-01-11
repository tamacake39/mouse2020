/*
 * global.h
 *
 *  Created on: May 1, 2019
 *      Author: blue
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#define rep(type, i, x, y) for(type i = x; i < y; i++)


#include "main.h"
#include "params.h"

/*------------------------------------------------------------
 共用・構造体の定義
 ------------------------------------------------------------*/
/**********
 共用・構造体とは，共用体と構造体を組み合わせたもので，
 内部の一括操作も，メンバ単位での操作も可能なものである。
 例えば，以下のmouse_flags共用・構造体のMFでは，
 MF.FLAGS = 0;と全体を一括変更できるほか，
 MF.FLAG.DECL = 1;とメンバを指定して単体で変更することも出来る。
 **********/

//----フラグ共用・構造体----
typedef union {  //共用体の宣言
    uint16_t FLAGS;
    struct ms_flags {  //構造体の宣言
        uint16_t
            RSV0 : 1;  //予備ビット(B0) (:1は1ビット分の意味，ビットフィールド)
        uint16_t SCND : 1;   //二次走行フラグ(B1)
        uint16_t RSV2 : 1;   //予備ビット(B2)
        uint16_t CTRL : 1;   //制御フラグ(B3)
        uint16_t ACCL : 1;   //加速フラグ(B4)
        uint16_t DECL : 1;   //減速フラグ(B5)
        uint16_t DEF : 1;    //デフォルトインターバルフラグ(B6)
        uint16_t SLA : 1;    //スラロームフラグ(B7)
        uint16_t SLAD : 1;   //スラローム方向フラグ(B8)，ROTATE_Rが1
        uint16_t STRC : 1;   //壁判定厳格モード(B9)
        uint16_t RSV10 : 1;  //予備ビット(B10)
        uint16_t RSV11 : 1;  //予備ビット(B11)
        uint16_t RSV12 : 1;  //予備ビット(B12)
        uint16_t RSV13 : 1;  //予備ビット(B13)
        uint16_t RSV14 : 1;  //予備ビット(B14)
        uint16_t RSV15 : 1;  //予備ビット(B15)
    } FLAG;
} mouse_flags;

#ifdef MAIN_C_  // main.cからこのファイルが呼ばれている場合
/*グローバル変数の定義*/
volatile mouse_flags MF;  //マウスステータスをまとめた共用・構造体
#else  // main.c以外からこのファイルが呼ばれている場合
/*グローバル変数の宣言*/
extern volatile mouse_flags MF;
#endif

#include <stdio.h>

#include "auxiliary.h"
#include "drive.h"
#include "eeprom.h"
#include "interrupt.h"
#include "mainfunc.h"
#include "search.h"
#include "sensor.h"

#endif /* INC_GLOBAL_H_ */
