#ifndef VETORES&MATRIZES_H_INCLUDED
#define VETORES&MATRIZES_H_INCLUDED

float** cria_matriz(int n)
{
	
	float** novo = (float**)malloc(n*sizeof(float**));
	
	for(int i=0; i<n; i++)
	{
		
		novo[i] =  (float*)malloc(n*sizeof(float*));
		
	}
	
	return novo;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

float* cria_vetor(int n)
{
	
	float* novo = (float*)malloc(n*sizeof(float*));
	
	return novo; 
	
}

///////////////////////////////////////////////////////////////////////////////////////////

void imprime_matriz(float** mat, int n)
{
	
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<n;j++)
		{
			
			std::cout<<mat[i][j]<<" ";
			
		}
		
		std::cout<<std::endl;
		
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////

void imprime_vetor(float* vet, int n)
{
	
	std::cout<<"(";
	
	for(int i=0;i<n;i++)
	{
		
		std::cout<<vet[i];
		
		if(i<2)
		{
			std::cout<<", ";
		}
		
	}
	
	std::cout<<")";
	
}

#endif
