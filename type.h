#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INTSIZE 32    // bit of int for bit map



int M;		// number Meters
int P;		// number of Poles

int** matrix;   // Adjacent list of m*p
	  	// remain unchanged 


int* selectedP;  // indicator for selected poles				// in selected graph	 // for cleanup
int* coveredM;   // number of selected poles covers for each selected M		// in selected graph     // for cleanup



  
int * colsum;  // number of meters cover by a pole 				 // in remaining graph
int * rowsum;  // number of poles cover a meter;    				 // in remaining graph	




int ** pmap;	// bitmap for remaining neigbor (meter) of each remaining pole   // in remaining graph	 // for preprocessing
int ** mmap;    // bitmap for remaining neigbor (pole) of each remaining meter   // in remaining graph   // for preprocessing
int msize ;    // ceil(M/INTSIZE)
int psize  ;   // ceil(P/INTSIZE)


int* thardcount;  // # t-hard to cover meters covered by each pole		// for gscore
double * gscore; // for each pole						// for gscore


