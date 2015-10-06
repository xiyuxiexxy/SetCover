
removePoleLink(int p)
{


	
	bzero(pmap[p],sizeof(int)*msize);
	colsum[p]=0;
	
	int m =0;
	
	for (m =0;m<M;m++)
	{
		if (rowsum[m]==P+1)
			continue;

		if (matrix[m][p]==1)
		{
			rowsum[m]--;
			set2Zero(mmap[m],p);
	
		}

	}
		
}



removeSubSetPole()
{

//	printArray(colsum, P);

	int i =0 ;
	int j =0;

	int s=0;
	//printf("remove subset poles: \n");
	
	for (i =0;i<P-1;i++)
	{
		for (j =i+1;j<P;j++)
		{
			
			int t = isSubset(pmap[i], pmap[j], msize);
			if(t==1)
			{

			//	printf("pole %d is a subset of %d\n", i,j);

			//	printf("%d ", i);


				removePoleLink(i);

				
				s=1;
				//printNeighbor(pmap[i], M);

				
			}
	
		}

	}	

//	printf("\n");
	return s;
}

