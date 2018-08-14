#ifndef DEFS_H_
#define DEFS_H_

/*
 * Basic definitions
 */
typedef void * Element;
typedef Element (*CopyFunction)(Element);
typedef void (*FreeFunction)(Element);
typedef void (*PrintFunction)(Element);
typedef Element (*EvolveFunction)(Element);

/*
 * Structs and enums
 */
typedef enum e_state{
	DEAD, P1, P2, BLANK
}State;

struct t_cell{
	State cellState;
	State neighbors[8];
};
typedef struct t_cell * Cell;

struct t_array{
	int size;
	Element* elements;
	CopyFunction copyElement;
	FreeFunction freeElement;
	PrintFunction printElement;
	EvolveFunction evolveElement;
};
typedef struct t_array * Array;


/*
 * Function Decleration
 */
Array createArray(int _size, CopyFunction _copy, FreeFunction _free, PrintFunction _print, EvolveFunction _evolve);
void destroyArray(Array array);
void set(Array array, int i, Element element);		//assigns array[i]=element;
Element get(Array array, int i);					//returns array[i]
Element CopyArray(Element elem);
void FreeArray(Element elem);
Element EvolveArray(Element elem);
void PrintArray(Element elem);



#endif /* DEFS_H_ */
