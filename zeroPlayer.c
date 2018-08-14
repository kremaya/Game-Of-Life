/*
 * zeroPlayer.c
 *
 *  Created on: Dec 11, 2016
 *      Author: ise
 */
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "zeroPlayer.h"


Element CopyZeroCell(Element elem){

	if(elem==NULL)
		return NULL;
	Cell cell=(Cell)elem;
	Cell res=(Cell)malloc(sizeof(struct t_cell));
	if(res==NULL)
			return NULL;
	res->cellState=cell->cellState;
	int i=0;
	for(i=0; i<8; i++)
		res->neighbors[i]=cell->neighbors[i];

	return res;
}

void FreeZeroCell(Element elem){
	Cell cell = (Cell)elem;
	free(cell);
}

Element EvolveZeroCell(Element elem){

	if(elem == NULL)
		return NULL;
	Cell cell = (Cell)elem;
	Cell res=CopyZeroCell(cell);
	if(res==NULL)
			return NULL;
	int i =0;
	int count=0;
	for(i=0; i<8; i++)
	{
		if(cell->neighbors[i] == P1 )
			count = count +1;
	}

	if(cell->cellState==DEAD)
	{
		if(count==3)
			{
				res->cellState=P1;
			}
	}
	else
	{
		if(count <=1||count >3)
		{
			res->cellState=DEAD;
		}
		else
		{
			res->cellState=P1;
		}

	}

	return res;
}

void PrintZeroCell(Element elem){
	Cell cell = (Cell)elem;
	if(cell==NULL)
		return;
	if(cell->cellState == DEAD ){
		printf(". ");
	}

	if(cell->cellState == P1 ){
			printf("X ");
		}
}

Array buildZeroArray(int n, char* arr){


	Array game = createArray(n,CopyArray,FreeArray,PrintArray,EvolveArray);
	if(game==NULL)
			return NULL;
	int i=0;
	int j=0;
	int inx=0;
	for(i=0;i<n;i++)
	{
		Array cellsArray = createArray(n,CopyZeroCell,FreeZeroCell,PrintZeroCell,EvolveZeroCell);
		if(cellsArray==NULL)
			return NULL;
		for( j=0;j<n ; j++)
		{
			Cell cell = (Element)malloc(sizeof(struct t_cell));
			if(cell==NULL)
						return NULL;
			if(arr[inx]=='X'){
				cell->cellState=P1;
			}
			else{
				cell->cellState=DEAD;
			}
			inx=inx+1;
			set(cellsArray,j,cell);
			FreeZeroCell(cell);
		}
		set(game,i,cellsArray);
		FreeArray(cellsArray);
	}

	return game;



}


