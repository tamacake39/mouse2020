/*
 * auxiliary.h
 *
 *  Created on: May 2, 2019
 *      Author: blue
 */

#ifndef INC_AUXILIARY_H_
#define INC_AUXILIARY_H_

#define min(A, B) ((A) > (B)) ? (B) : (A)
#define max(A, B) ((A) > (B)) ? (A) : (B)

void led_write(uint8_t led1, uint8_t led2, uint8_t led3);
int select_mode(int mode);

#endif /* INC_AUXILIARY_H_ */
