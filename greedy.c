int maxpole;


int covercount;

greedyCover(int p)
{
	
	

	//preprocessing();	
	
	int run =1;
	
	while(covercount<M)
	{

		

		maxpole = findMax();

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



	
