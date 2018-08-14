/*
 * twoPlayer.c
 *
 *  Created on: Dec 12, 2016
 *      Author: ise
 */

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "twoPlayer.h"



Element CopyTwoCell(Element elem){

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

void FreeTwoCell(Element elem){
	Cell cell = (Cell)elem;
	free(cell);
}

Element EvolveTwoCell(Element elem){
	if(elem == NULL)
		return NULL;
	Cell cell = (Cell)elem;
	Cell res=CopyTwoCell(cell);
	if(res==NULL)
		return NULL;
	int i =0;
	int count1=0;
	int count2=0;
	for(i=0; i<8; i++)
	{
		if(cell->neighbors[i]== P1 )
			count1 = count1 +1;
		if(cell->neighbors[i]== P2 )
			count2 = count2 +1;
	}

	if(cell->cellState==DEAD)
	{
		if((count1+count2)==3)
		{
			if(count1>count2)
				res->cellState=P1;
			else
				res->cellState=P2;
		}
		else
			res->cellState=DEAD;
	}
	else
	{
		if((count1+count2)<=1||(count1+count2)>3)
		{
			res->cellState=DEAD;
		}
		else
		{
			if(count2==2||count2==3)
				res->cellState=P2;

			else
			{
				if(count1==2||count1==3)
					res->cellState=P1;
				else
					res->cellState=cell->cellState;
			}
		}

	}

	return res;
}

void PrintTwoCell(Element elem){
	Cell cell = (Cell)elem;
	if(cell==NULL)
			return;

	if(cell->cellState == DEAD ){
		printf(". ");
	}

	if(cell->cellState == P1 ){
		printf("X ");
	}
	if(cell->cellState == P2 ){
		printf("Y ");
	}
}


Array buildTwoArray(int n, char* arr){

	Array game = createArray(n,CopyArray,FreeArray,PrintArray,EvolveArray);
	if(game==NULL)
		return NULL;
	int i=0;
	int j=0;
	int inx=0;
	for(i=0;i<n;i++)
	{
		Array cellsArray = createArray(n,CopyTwoCell,FreeTwoCell,PrintTwoCell,EvolveTwoCell);
		if(cellsArray==NULL)
				return NULL;
		for( j=0;j<n ; j++)
		{
			Cell cell = (Element)malloc(sizeof(struct t_cell));
			if(cell==NULL)
					return NULL;
			if(arr[inx]=='X')
			{
				cell->cellState=P1;
			}
			else
			{
				if(arr[inx]=='Y')
				{
					cell->cellState=P2;
				}
				else
				{
					cell->cellState=DEAD;
				}
			}
			inx=inx+1;
			set(cellsArray,j,cell);
			FreeTwoCell(cell);
		}
		set(game,i,cellsArray);
		FreeArray(cellsArray);
	}

	return game;


}





