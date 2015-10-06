#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1024
#define TOKEN " \n"




int allocateMatrix(int m, int p, int*** Matrix)
{

	int **matrix = (int **) malloc(sizeof(int*)*m);
	bzero(matrix, sizeof(int*)*m);

	int i=0;

	for(i=0;i<m;i++)
	{
		matrix[i]= (int *)malloc(sizeof(int)*p);
		bzero(matrix[i], sizeof(int)*p);

	}

	*Matrix= matrix;	
}

char line[SIZE];

int edge2matrix(int ** matrix, char* infile)
{
	FILE* fin = fopen(infile, "r");


	
	while (fgets(line,SIZE,fin ))
	{
	//	fprintf(stderr, "getline\n");

		int m = atoi(strtok(line, TOKEN))-1;
		int p = atoi(strtok(NULL, TOKEN))-1;		

		

		matrix[m][p]=1;

		//fprintf(stderr, "meter %d, pole %d\n", m,p);

	}
	fclose(fin);
}


int initMatrix(int m, int p, int *** matrix, char* infile)
{
	allocateMatrix(m,p,matrix);
	
	edge2matrix(*matrix, infile);	
}
