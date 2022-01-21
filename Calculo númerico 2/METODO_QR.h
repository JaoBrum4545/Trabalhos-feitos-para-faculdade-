#ifndef METODO_QR_H_INCLUDED
#define METODO_QR_H_INCLUDED

///////////////////////////////////////////////////////////////////////////////////////////

float** Produtomatriz(float** matriz1,float** matriz2,int n)
{

	float somatorio=0;

float** matrizp = cria_matriz(n);	
	
for(int i = 0; i < n; i++)
	{

		for(int j = 0; j < n; j++)
		{
			
			for(int k = 0; k < n; k++)
			{
			
				somatorio = matriz1[i][k] * matriz2[k][j] + somatorio;	
				
			}
		
			matrizp[i][j] = somatorio;
		
			somatorio = 0;	
			
		}
		
	}
	
	return matrizp;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

float** MQR_1(float** Matriz,int n,int q,int p)
{
	
	float** novo = cria_matriz(n);
	
	for(int i = 0;i < n;i++)
	{
		
		for(int j = 0;j < n;j++)
		{
			
			if((i!=j)&&((i!=p)||(i!=q)))
			{
				
				novo[i][j] = 0;
				
			}
			
			if((i==q)&&(j==p))
			{
				
				novo[i][j] = -Matriz[q][p]/(sqrt(Matriz[q][p]*Matriz[q][p]+Matriz[p][p]*Matriz[p][p]));
				
			}
			
			if((i==p)&&(j==q))
			{
				
				novo[i][j] = Matriz[q][p]/(sqrt(Matriz[q][p]*Matriz[q][p]+Matriz[p][p]*Matriz[p][p]));
				
			}
			
			if(i==j)
			{
				
				if((i==q)||(i==p))
				{
				
					novo[i][j] = Matriz[p][p]/(sqrt(Matriz[q][p]*Matriz[q][p]+Matriz[p][p]*Matriz[p][p]));
				
				}
				else
				{
					
					novo[i][j] = 1;
					
				}
				
			}
			
		}
		
	}
	
	return novo;
	
}

bool MQR_3(float** A,int n,float Erro)
{
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if((fabs(A[i][j])<Erro)&&(i>j)&&(A[i][j]!=0))
			{
				
				return false;
			}
		}
	}
	
	return true;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

float** transpmatriz(float** U, int n)
{
	float** M = cria_matriz(n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			M[i][j] = U[i][j];
		}
	}
		
	int a = n-1;
	float aux;
	
	for(int i=0;i<n;i++)
	{
		
		aux = M[i][a];
		M[i][a] = M[a][i];
		M[a][i] = aux;
		
	}
	
	return M;
}

///////////////////////////////////////////////////////////////////////////////////////////

void MQR_4(float** A,int n)
{
	
	for(int i = 0; i < n ; i++)
	{
		
		std::cout<<"Lambda_"<<i+1<<": "<<A[i][i]<<std::endl;
		
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////

float** MQR_2_1(float** R,float** A,int n)
{
	float** U = cria_matriz(n);
	int controle =0;
	
	for(int i = 0; i < n; i++)
	{
		
		for(int j = 0; j < n; j++)
		{
			
			if((A[i][j]!=0)&&(j<i))
			{
				U = MQR_1(A,n,i,j);
				
				if(controle ==0)
				{
					R = Produtomatriz(U,A,n);
				}
				else
				{
					R = Produtomatriz(U,R,n);
				}
				
				controle++;
				
			}
			
		}
		
	}
	
	return R;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

float** MQR_2_2(float** Q,float** A,int n)
{
	float** U = cria_matriz(n);
	int controle =0;
	
	for(int i = 0; i < n; i++)
	{
		
		for(int j = 0; j < n; j++)
		{
			
			if((A[i][j]!=0)&&(j<i))
			{
				U = MQR_1(A,n,i,j);
				
				U = transpmatriz(U,n);
				
				if(controle ==0)
				{
					Q = U;
				}
				else
				{
					Q = Produtomatriz(U,Q,n);
				}
				
				controle++;
				
			}
			
		}
		
	}
	
	return Q;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

void MQR(float** Matriz,int n,float Erro)
{
	
	setlocale(LC_ALL, "Portuguese");
	
	int cont;
	float** R;
	float** Q;
	float** A;
	
	R = cria_matriz(n);
	Q = cria_matriz(n);
	A = cria_matriz(n);
	
	////////////////////////
	
	A = Matriz;
	
	////////////////////////
	
	do{
	
	R = MQR_2_1(R,A,n);
	
	Q = MQR_2_2(Q,A,n);
	
	A = Produtomatriz(R,Q,n);
	
	}while(MQR_3(A,n,Erro));
	
	////////////////////////
	
	MQR_4(A,n);
	
}

#endif
