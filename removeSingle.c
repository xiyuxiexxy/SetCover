
removeMeter(int m)
{

	
	
	int p =0;
	for(p=0;p<P;p++)
	{
		if (matrix[m][p]==0)
			continue;

		if (colsum[p]==0)
			continue;

	
		selectPole(p);
	}

}

int removeSingleton()
{

	int m =0;
	int s =0;

//	printf("remove single meters: \n");	
	
	for (m=0;m<M;m++)
	{
		
		if (rowsum[m]==1)
		{
			removeMeter(m);

	//		printf("%d ",m);
			s = 1;
		}
	}	

	//printf("\n");

	return s;
}










