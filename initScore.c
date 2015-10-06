
allocateCounters(int M, int P)
{
	colsum =  (int *)malloc(sizeof(int)*P);
	bzero(colsum,sizeof(int)*P );


	rowsum =  (int *)malloc(sizeof(int)*M);
	bzero(rowsum,sizeof(int)*M );



	selectedP= malloc(sizeof(int)*P);
	bzero(selectedP,sizeof(int)*P );

	coveredM = malloc(sizeof(int)*M);
	bzero(coveredM,sizeof(int)*M );




	msize = (M+INTSIZE-1)/INTSIZE ;
	psize = (P+INTSIZE-1)/INTSIZE ;


	pmap = (int **)malloc(sizeof(int*)*P);
	int i = 0;	
	for(i=0;i<P;i++)
	{
		pmap[i] =( int*)malloc(sizeof(int)*msize);
		bzero(pmap[i],sizeof(int)*msize );
	}



	mmap = (int **)malloc(sizeof(int*)*M);
	
	//printf("msize %d, psize %d\n",msize, psize);

	for(i=0;i<M;i++)
	{
		mmap[i] =( int*)malloc(sizeof(int)*psize);
		bzero(mmap[i],sizeof(int)*psize);
	}


	
	thardcount = (int*)malloc(sizeof(int)*P);
	bzero(thardcount,sizeof(int)*P );

	
	gscore  = (double*)malloc(sizeof(double)*P);; // for each pole
	//bzero(gscore,sizeof(double)*P );
	
}




initCounters(int M, int P)
{
	allocateCounters(M,P);

//	printf("m %d, p %d\n", m,p);
	int i=0;
	for(i=0;i<M;i++)  // # of pole
	{
		int j =0;
		int r = 0;
		for(j=0;j<P;j++)
		{
	
			if (matrix[i][j]==1)
			{
				
				rowsum[i]++;
				
				colsum[j]++;
	
				set2One( mmap[i], j);
				set2One( pmap[j], i);
			}
	
		}
	}
}
