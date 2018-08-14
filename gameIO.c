/*
 * gameIO.c
 *
 *  Created on: Dec 13, 2016
 *      Author: ise
 */

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "zeroPlayer.h"
#include "twoPlayer.h"
#include "gameIO.h"


void PrintGame(Array game, int n){
	int i;
	for(i=0;i<n;i++){
		PrintArray(get(game,i));
		printf("\n");
	}
}



int WinCheck(Array game, int n){ //return 0 if the game is not over, 1 if the game is over
	int i;
	int j;
	int count1=0;
	int count2=0;
	for(i=0;i<n;i++)
	{
		for(j=0; j<n;j++)
		{
			Cell cell = (Cell)get(get(game,i),j);
			if(cell->cellState==P1)
				count1++;
			if(cell->cellState==P2)
				count2++;

		}
	}
	if(count1==0||count2==0)
		return 1;
	else
		return 0;
}



char* GetText(char* filename, int n){

	FILE *fp;
	char c;
	int count=0;


	fp=fopen(filename, "r");
	if(fp==NULL){
		printf("wrong file\n");
		return NULL;
	}
	char * arr2;
	int arr2Size = n*n;
	arr2=(char*)calloc(sizeof(char),arr2Size);

	while(!feof(fp))
	{
		c = fgetc(fp);
		if(c=='X'||c=='.'||c=='Y')
		{
			arr2[count]=c;
			count++;
		}
	}

	fclose(fp);
    return arr2;


}

void PlayerMove(Array game, int player)
{
	int killRow;
	int killCol;
	int aliveRow;
	int aliveCol;

	printf("please enter kill row: ");
	scanf("%d", &killRow);
	printf("please enter kill col: ");
	scanf("%d", &killCol);
	printf("please enter alive row: ");
	scanf("%d", &aliveRow);
	printf("please enter alive col: ");
	scanf("%d", &aliveCol);

	((Cell)get(get(game,killRow),killCol))->cellState = DEAD;
    if(player==1)
    	((Cell)get(get(game,aliveRow),aliveCol))->cellState = P1;
    else
    	((Cell)get(get(game,aliveRow),aliveCol))->cellState = P2;
}

void updateNeighbors(Array game, int n)
{
	int i=0;
	int j=0;

	for(i=0;i<n;i++)
	{
		for( j=0;j<n ; j++)
		{
			Cell cell = (Cell)get(get(game,i),j);
			if(i==0 )
			{
				cell->neighbors[0]=BLANK;
				cell->neighbors[1]=BLANK;
				cell->neighbors[2]=BLANK;
			}
			else
			{
				if(j==0)
					cell->neighbors[0]=BLANK;
				else
					cell->neighbors[0]= ((Cell)get(get(game,i-1),j-1))->cellState;
				cell->neighbors[1]= ((Cell)get(get(game,i-1),j))->cellState;

				if(j==n-1)
					cell->neighbors[2]=BLANK;
				else
					cell->neighbors[2]=((Cell)get(get(game,i-1),j+1))->cellState;
			}

			if(i==n-1)
			{
				cell->neighbors[5]=BLANK;
				cell->neighbors[6]=BLANK;
				cell->neighbors[7]=BLANK;
			}
			else
			{
				if(j==0)
					cell->neighbors[5]=BLANK;
				else
					cell->neighbors[5]=((Cell)get(get(game,i+1),j-1))->cellState;
				cell->neighbors[6]= ((Cell)get(get(game,i+1),j))->cellState;
				if(j==n-1)
					cell->neighbors[7]=BLANK;
				else
					cell->neighbors[7]=((Cell)get(get(game,i+1),j+1))->cellState;
			}

			if(j==0)
				cell->neighbors[3]=BLANK;
			else
				cell->neighbors[3]=((Cell)get(get(game,i),j-1))->cellState;

			if(j==n-1)
				cell->neighbors[4]=BLANK;
			else
				cell->neighbors[4]=((Cell)get(get(game,i),j+1))->cellState;


		}
	}
}


