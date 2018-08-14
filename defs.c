/*
 * defs.c
 *
 *  Created on: Dec 11, 2016
 *      Author: ise
 */
#include <stdlib.h>
#include "defs.h"

Array createArray(int _size, CopyFunction _copy, FreeFunction _free, PrintFunction _print, EvolveFunction _evolve){

	Array arr=(Array)malloc(sizeof(struct t_array));
	if(arr == NULL){
		return NULL;
	}
	arr->size = _size;

	arr->elements = (Element*)calloc(sizeof(Element),_size);
	if(arr->elements == NULL){
		return NULL;
	}
	arr->copyElement = _copy;
	arr->freeElement = _free;
	arr->printElement = _print;
	arr->evolveElement = _evolve;

	return arr;
}

void destroyArray(Array array)
{

	if(array==NULL)
		return;
	int i=0;
	for(i=0; i<array->size; i++)
	{
		if(array->elements[i]!=NULL)
			array->freeElement(array->elements[i]);
	}
	free(array->elements);
	free(array);
}


void set(Array array, int i, Element element){
	if(array==NULL)
		return;

	if(array->elements[i]!=NULL){
		array->freeElement(array->elements[i]);
	}

	Element toCopy = array->copyElement(element);
	if(toCopy==NULL)
			return;
	array->elements[i]=toCopy;



}


Element get(Array array, int i){
	if(array==NULL)
		return NULL;
	return array->elements[i];
}



Element CopyArray(Element elem){

	if(elem==NULL)
		return NULL;
	Array arr = (Array)elem;
	Array res;
	res=createArray(arr->size,arr->copyElement,arr->freeElement,arr->printElement,arr->evolveElement);
	if(res==NULL)
		return NULL;
	int i=0;
	for(i=0; i<arr->size; i++)
	{
		Element toCopy = arr->copyElement(arr->elements[i]);
		if(toCopy==NULL)
				return NULL;
		res->elements[i]=toCopy;
	}
	return res;

}

void FreeArray(Element elem){

	Array arr = (Array)elem;
	if(arr==NULL)
		return;
	int i=0;
	for(i=0;i<arr->size;i++){
		if(arr->elements[i]!=NULL)
				arr->freeElement(arr->elements[i]);

	}
	free(arr->elements);
	free(arr);
}

Element EvolveArray(Element elem){
	Array arr = (Array)elem;
	if(arr==NULL)
		return NULL;
	Array res;
	res=createArray(arr->size,arr->copyElement,arr->freeElement,arr->printElement,arr->evolveElement);
	if(res==NULL)
			return NULL;
	int i=0;
	for(i=0; i<arr->size; i++)
	{
		Element elem2=arr->evolveElement(arr->elements[i]);
		if(elem2==NULL)
			return NULL;
		set(res,i,elem2);
		res->freeElement(elem2);
	}
	return res;


}

void PrintArray(Element elem){
	Array arr = (Array)elem;
	if(arr==NULL)
			return;
	int i=0;
	for(i=0;i<arr->size;i++){
		arr->printElement(arr->elements[i]);
	}
}







