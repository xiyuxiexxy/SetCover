

int getbit(int n, int i)
{
	return ((n & (1<<i))!=0);
}


int setbit(int n , int j )
{
	return n| (1<<j);

}


int clearbit(int n, int j)
{
	int mask = ~(1<<j);
	return n&mask;

}

int set2Zero(int * buffer, int i)
{
	int bin = i/INTSIZE;
	int offset = i% INTSIZE;  	
 
	buffer[bin] = clearbit(buffer[bin], offset);
	
}


printNeighbor(int *buffer, int M)
{	

	int i =0;
	for (i=0; i<M;i++)
	{
	
		
		int bin = i/INTSIZE;
		int offset = i% INTSIZE;  	
 
		int b = getbit(buffer[bin], offset);

		if (b==1)
		{
			printf(" %d ", i);
	
		}
	}

	printf("\n");
	
}


int set2One(int * buffer, int i)
{
	int bin = i/INTSIZE;
	int offset = i% INTSIZE;  	
 
	buffer[bin] = setbit(buffer[bin], offset);
	
}


int isSubset(int* p, int* q, int size)
{

	int i =0;

	int zero =1;
	for (i=0;i<size;i++)
	{
		int AND = p[i]&q[i];

		if (AND != p[i])
			return 0;

		if (AND!=0)
		{
			zero =0;
		}
	}
	if (zero==1)
	{
		return 0;
	}
	return 1;
}


	
