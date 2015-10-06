#include <stdio.h>      /* printf */
#include <math.h>       /* pow */

int minmeter;


int isThard(int t, int mp, int m)
{
	if (rowsum[m]< mp+t)	
		return 1;
	return 0;
}



CountThard( int t, int mp , int f)
{

	bzero(thardcount, sizeof(int)*P);
	int m =0;
	for (m =0;m <M;m++)
	{
		int b = isThard(t, mp, m);

		if (b==1)
		{
			int p =0;
			for (p =0; p<P;p++)
			{
				if (f==1)
				{
					if (thardcount[p]==1)
						continue;
				}	


				if (colsum[p]==0)  // selected
					continue;
					
				if (matrix[m][p]==0)
					continue;

				thardcount[p]++;

				
			}

		} 
	}

}


resetGscore()
{
	int p = 0;
	for (p=0;p<P;p++)
	{
		gscore[p] =(double) colsum[p];
	}

}




int findmin()
{

	int i=0;
	for(i=0;i<M;i++)
	{
		if (rowsum[i]==P+1)
			continue;			
	

		if (rowsum[minmeter]>rowsum[i])
		{
			minmeter=i;
		}
	}
	
	return minmeter;
}

ScoreG( int k, int f )
{
	minmeter = findmin();

	int mp = rowsum[minmeter];
 
	resetGscore();	// start with s(p, inf);

	
	int t =0;
	for (t= 1;t<k+1;t++)
	{

		CountThard(t, mp, f);

		int p=0;
		for (p=0;p<P;p++)
		{

			
			if (gscore[p]==0)
			{	continue;}
			
	
			if (thardcount[p]==0)
			{	
				gscore[p]=0;	
				continue;

			}

			if (f==1| f==2)
			{
				gscore[p] *= thardcount[p];
			}
			else
			{
				gscore[p] *= pow((double)thardcount[p],(double) 1/t);
			}
			
		}

	}	
		
}


