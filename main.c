/*
 * main.c
 *
 *  Created on: Dec 11, 2016
 *      Author: ise
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "defs.h"
#include "zeroPlayer.h"
#include "twoPlayer.h"
#include "gameIO.h"


int main(int argc, char* argv[]){

	if(argc!=5)
	{
		printf("illegal input");
		return -1;
	}

	int gameType;
	int n;
	int generations;
	char* filename;
	char* arr;

	gameType=atoi(argv[1]);
	n=atoi(argv[2]);
	filename =argv[3];
	generations=atoi(argv[4]);

	arr = GetText(filename,n);
	if(arr== NULL)
		return -1;


	Array game;
	if(gameType==1)
		game = buildZeroArray(n, arr);
	else
		game = buildTwoArray(n,arr);
	free(arr);

	if(game== NULL)
		return -1;
	updateNeighbors(game,n);


	int i=0;
	if(gameType==1) //if its zero players game
	{
		for(i=0;i<generations; i++)
		{
			Array evolved = EvolveArray(game);
			destroyArray(game);
			if(evolved==NULL)
				return -1;
			game = evolved;
			updateNeighbors(game,n);
		}
		PrintGame(game,n);
	}
	else //if its two players game
	{
		int player =1;
		for(i=0;i<generations; i++)
		{
			Array evolved = EvolveArray(game);
			destroyArray(game);
			if(evolved==NULL)
				return -1;
			game = evolved;
			updateNeighbors(game,n);
			PrintGame(game, n);

			if(i!=generations-1) //if its not the last generation
			{
				if(WinCheck(game, n)==0)// if there game is not over
				{
					PlayerMove(game, player);
					updateNeighbors(game,n);
					if (player==1)
						player=2;
					else
						player=1;
				}
				else // if the game is over
					i=generations; //end the game

			}
		}
	}

	destroyArray(game);

	return 0;


}
