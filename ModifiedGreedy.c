int maxpole;


MGreedyCover( int f, int k, int p)
{

	
	
	int run =1;


	while(covercount<M)
	{

		//preprocessing();			

		ScoreG( k, f );
	
		
		maxpole = findMaxScore(gscore);

		

		selectPole(maxpole);
		if (run==1)
		{
			if (p==1)
			{
		
				if (covercount> M/2)
				{
					preprocessing();
					run =0;
				}
			}
		}
	
	}

	
	int c = cleanpoles();

	int value = CountPoles();

	printf("value %d, feasible? %d, cleanedup any poles? %d \n", value, isFeasible(), c);

}
