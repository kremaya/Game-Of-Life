/*
 * gameIO.h
 *
 *  Created on: Dec 13, 2016
 *      Author: ise
 */
#ifndef GAMEIO_H_
#define GAMEIO_H_


void PrintGame(Array game, int n);
int WinCheck(Array game, int n);
char* GetText(char* filename, int n);
void PlayerMove(Array game, int player);
void updateNeighbors(Array game, int n);


#endif /* GAMEIO_H_ */
