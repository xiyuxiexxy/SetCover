
int isFeasible()
{
	int m =0;
	for (m=0;m<M;m++)
	{
		if (coveredM[m]<1)
			return 0;
	}
	return 1;

}

int CountPoles()
{

	printf("selected poles\n");
	int p=0;
	int value = 0;
	for (p=0;p<P;p++)
	{
		if(selectedP[p]==1)
		{
			printf("%d ",p);
			value ++;
		}

	}	
	printf("\n");

	return value;
}

printArray(int *array, int n)
{

//	printf("printarray%d\n", n);
	int i =0;
	for (i=0;i<n;i++)
	{
		printf("%d ",array[i]);

		if(i%10==9)
		{
			printf("\n");
		}
	}
	printf("\n");
	

}

printScore(double * array, int n)
{

//	printf("printarray%d\n", n);
	int i =0;
	for (i=0;i<n;i++)
	{
		printf("%f ",array[i]);

		if(i%10==9)
		{
			printf("\n");
		}
	}
	printf("\n");
	

}


printMatrix(int m, int p, int ** matrix)
{
	int i=0;
	for(i=0;i<m;i++)
	{
		int j =0;
		for(j=0;j<p;j++)
		{
			printf("%d", matrix[i][j]);	
		}
		printf("\n");
	}
	
}

