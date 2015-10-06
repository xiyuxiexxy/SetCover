
removeMeterLink(int m)
{

	
	
	bzero(mmap[m],sizeof(int)*psize);
	rowsum[m]=P+1;
	

	int p =0;
	
	for (p =0;p<P;p++)
	{
		if (colsum[p]==0)
			continue;

		if (matrix[m][p]==1)
		{
			//colsum[p]--;
			set2Zero(pmap[p],m);
		

		//	printf("neigbors of pole %d \n", p);
		//	printNeighbor(pmap[p],M);

		//	printf("\n");
		}

	}
		
}

// P(A) <= P(B)
// remove B!!


removeSupSetMeter()
{
	int i =0 ;
	int j =0;
	
	int s=0;


//	printf("remove supset meters \n");


	for (i =0;i<M-1;i++)
	{
		for (j =i+1;j<M;j++)
		{
			
			int t = isSubset(mmap[i], mmap[j], psize);
			if(t==1)
			{

			//	printf("meter %d is a subset of %d\n", i,j);

			//	printNeighbor(mmap[i], P);
			//	printNeighbor(mmap[j], P);


			//	printf("%d ",j);

				removeMeterLink(j);
								
				s=1;
				//printNeighbor(pmap[i], M);

				
			}
	
		}
	}

	//printf("\n");	
	return s;

}


