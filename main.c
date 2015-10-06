#include "include.h"

//#include "type.h"



// ./setcover #m #p infile

int main(int argc, char * argv[])
{

	char* infile=0;
	char str[64];

	int f ;
	int k;		
	int p ;

	if (argc<7)
	{
		
  		printf ("Enter Number of Meters: \n");
		scanf ("%d",&M);  
		
  		printf ("Enter Number of Poles: \n");
		scanf ("%d",&P);  

		
  		printf ("Enter Input File: \n");
  		scanf ("%s",str);  


		infile =str;

		
	
		printf ("Enter Number for Heuristic Funtions ( 0: Greedy; 1: Score1 ; 2:Score2 ;3: Score_G  \n");
		scanf ("%d",&f);  
	
		if(f==3)
		{
			printf ("Enter K number \n");
			scanf ("%d",&k);  
		}
		else
		{
			k=1;
		}
		
	  	printf ("Do you want Preprocessing? 0: No; 1: Yes\n");
		scanf ("%d",&p);  
	}
	else
	{	

		M = atoi(argv[1]);
		P = atoi(argv[2]);
		infile = argv[3];

		f = atoi(argv[4]);
		k = atoi(argv[5]);
		p = atoi(argv[6]);
		
	}

	

	

	

	initMatrix(M, P, &matrix, infile);	
	initCounters(M,P);	

	clock_t begin, end;
	
	begin = clock();

		if( f==0)
		{	
			greedyCover(p);
		}
		else
		{
			MGreedyCover(f,k,p);
		}
	
	end = clock();

	
	printf("clocks %d second %f\n", end - begin, (float)(end - begin) / CLOCKS_PER_SEC);
	
}
