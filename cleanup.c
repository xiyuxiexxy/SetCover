

removePole(int sp)
{
	selectedP[sp]=0;

	int cm =0;
	for(cm=0;cm<M;cm++)
	{
		
		if(matrix[cm][sp]==0)
		{	continue;}

		if(coveredM[cm]>1)
		{
			coveredM[cm]--;	
		}


	}

	printf("cleanup pole %d \n", sp);

}

cleanpoles()
{

	int sp =0;

	int result =0;

	for (sp=0;sp<P;sp++)
	{
		if (selectedP[sp]==0)
		{	continue;}

		int cm =0;
		int clean =1;

		
		for(cm=0;cm<M;cm++)
		{
			if(matrix[cm][sp]==0)
			{	continue;}

			if(coveredM[cm]==1)    // one of meter is only covered by this pole
			{
				clean=0;
				break;		
			}

		}		

		if (clean==1)
		{
			//printf("pole %d is fully covered by other\n", sp);
			removePole(sp);
			result =1;
		}


	}

	return result;		
	
}
