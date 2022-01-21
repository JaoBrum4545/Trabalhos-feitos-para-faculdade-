#ifndef METODO_DP_H_INCLUDED
#define METODO_DP_H_INCLUDED

///////////////////////////////////////////////////////////////////////////////////////////

float* MDP_1(float** Matriz,float* Y,int n)
{
	
	float* Z = cria_vetor(n);
	
	float somatorio;
	
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<n;j++)
		{
			
			somatorio = Matriz[i][j]*Y[j] + somatorio; 
			
		}
		
		Z[i] = somatorio;
		
		somatorio = 0;
		
	}
	
	return Z;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

float* MDP_2(float* Z,float* Y,int n)
{
	
	float* L_k0 = cria_vetor(n);
	
	for(int i=0;i<n;i++)
	{
		
		L_k0[i] = Z[i]/Y[i];
		
	}
	
	return L_k0;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

float MDP_3(float* Z,int n)
{
	
	float Alpha = 0;
	
	for(int i=0;i<n;i++)
	{
		
		if(Alpha<abs(Z[i]))
		{
			
			Alpha = abs(Z[i]);
			
		}
		
	}
	
	return Alpha;
	
}
///////////////////////////////////////////////////////////////////////////////////////////

float* MDP_4(float Alpha,float* Z,int n)
{
	
	float* Y = cria_vetor(n);
	
	for(int i=0;i<n;i++)
	{
		
		Y[i] = (1/Alpha)*Z[i];
		
	}
	
	return Y;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

float MDP_5(float* L_k1,float* L_k0,int n,float Erro)
{
	float Lambda;
	
	for(int i=0;i<n;i++)
	{
		
		if((fabs(L_k1[i]-L_k0[i])/fabs(L_k1[i]))<Erro)
		{
			
			Lambda = L_k1[i];
			
			return Lambda;
			
		}		

	}
	
	Lambda = 1000;
			
	return Lambda;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

bool MDP_6(float* L_k1,float* L_k0,int n,float Erro)
{
	
	for(int i=0;i<n;i++)
	{
		
		if((fabs(L_k1[i]-L_k0[i])/fabs(L_k1[i]))<Erro)
		{
			
			return false;
		
		}		

	}
			
	return true;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

void MDP(float** Matriz,int n,float Erro)
{
	
	setlocale(LC_ALL, "Portuguese");
	
	float vetor_exemplo[] = { 1, 1, 1};
	
	float* Y;
	float* Z;
	float* L_k0;
	float* L_k1;
	float Alpha;
	float Lambda;
	
	
	Y = cria_vetor(n);
	Z = cria_vetor(n);
	L_k0 = cria_vetor(n);
	L_k1 = cria_vetor(n);
	
	////////////////////////
	
	for(int i=0;i<n;i++)
	{

		Y[i] = vetor_exemplo[i];
		
	}
	
	////////////////////////
	
	Z = MDP_1(Matriz,Y,n);
		
	L_k1 = MDP_2(Z,Y,n);
	
	////////////////////////
	
	do{
	
	L_k0 = L_k1;
	
	Alpha = MDP_3(Z,n);
	
	Y = MDP_4(Alpha,Z,n);
	
	Z = MDP_1(Matriz,Y,n);
	
	L_k1 = MDP_2(Z,Y,n);
	
	Lambda = MDP_5(L_k1,L_k0,n,Erro);
	
	}while(MDP_6(L_k1,L_k0,n,Erro));
	
	////////////////////////
	
	std::cout<<"Lambda_1: "<<Lambda<<std::endl;
	std::cout<<"\nAutovetor:"; imprime_vetor(Y,n);std::cout<<"^t";;
	
}

#endif
