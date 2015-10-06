
coveredmeter(int p)
{
	
	int i =0;
	for(i=0;i<M;i++)
	{

		if (matrix[i][p]==1)
		{


			coveredM[i]++; 	      // all cover count for clean up
	
			if (coveredM[i]==1)   // first time to remove meter from other neigbors
			{
				covercount++;
				

				rowsum[i]= P+1;					// remove meter
				bzero(mmap[i],sizeof(int)*psize);		// remove

				int pp =0;					// remove link to meters neigbhor
				for (pp=0;pp<P;pp++)
				{
	

					if (matrix[i][pp]==0) 
						continue;
					if( pp==p)
						continue;
					if (colsum[pp]==0)
						continue;

					colsum[pp]--;

					set2Zero(pmap[pp],i);
			
				}
			}
	
		}
	}

}
selectPole(int p)
{

//	printf("select pole %d with cover %d\n", p,colsum[maxpole] );
	selectedP[p]=1;

	
	colsum[p]=0;					// remove
	bzero(pmap[p],sizeof(int)*msize);		// remove


	coveredmeter(p);


}


int findMax()
{
	int i=0;
	
	int maxscore =0;
	for(i=0;i<P;i++)
	{
		if (colsum[i]==0)
			continue;


		if (maxscore<colsum[i])
		{
			maxscore = colsum[i];
			maxpole=i;
		}
	}
	return maxpole;	
}



int findMaxScore(double* gscore)
{
	int i=0;
	
	double maxscore  =0;

	for(i=0;i<P;i++)
	{
		if (gscore[i]==0)
			continue;


		if (maxscore <gscore[i])
		{
			maxscore = gscore[i];
			maxpole=i;
		}
	}
	return maxpole;	
}


