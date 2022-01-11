/*
 * mouse.cpp
 *
 *  Created on: Dec 21, 2021
 *      Author: tamacake39
 */

#include "global.h"

class Mouse {
public:
	int8_t x;
	int8_t y;
	int8_t dir;
	int8_t map[16][16];
	int8_t smap[16][16];

	Mouse(){
		x = y = dir = 0;
		rep(int8_t,i,0,16){
			rep(int8_t,i,0,16){
				map[i][j] = 0;
				smap[i][j] = 0;
			}
		}
	}

};
