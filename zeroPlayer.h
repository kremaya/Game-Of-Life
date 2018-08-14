/*
 * zeroPlayer.h
 *
 *  Created on: Dec 11, 2016
 *      Author: ise
 */

#ifndef ZEROPLAYER_H_
#define ZEROPLAYER_H_




Element CopyZeroCell(Element elem);

void FreeZeroCell(Element elem);

Element EvolveZeroCell(Element elem);

void PrintZeroCell(Element elem);

Array buildZeroArray(int n, char* arr);

#endif /* ZEROPLAYER_H_ */
