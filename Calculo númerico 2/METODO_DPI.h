#ifndef METODO_DPI_H_INCLUDED
#define METODO_DPI_H_INCLUDED

//O código que realiza a transição de A para A^-1 não é de minha autoria, segue abaixo a referencia:
	//GEEKSFORGEEKS. // C++ program to find adjoint and inverse of a matrix. Versão  [S. l.]: Geeksforgeeks.org. Disponível em: https://www.geeksforgeeks.org/adjoint-inverse-matrix/. Acesso em: 13 Julho 2021.	
#include "INVERTE_A_MATRIZ.h"

///////////////////////////////////////////////////////////////////////////////////////////

float* MDPI_1(float** Matriz,float* Y,int n)
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

float* MDPI_2(float* Z,float* Y,int n)
{
	
	float* L_k0 = cria_vetor(n);
	
	for(int i=0;i<n;i++)
	{
		
		L_k0[i] = Z[i]/Y[i];
		
	}
	
	return L_k0;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

float MDPI_3(float* Z,int n)
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

float* MDPI_4(float Alpha,float* Z,int n)
{
	
	float* Y = cria_vetor(n);
	
	for(int i=0;i<n;i++)
	{
		
		Y[i] = (1/Alpha)*Z[i];
		
	}
	
	return Y;
	
}

///////////////////////////////////////////////////////////////////////////////////////////

float MDPI_5(float* L_k1,float* L_k0,int n,float Erro)
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

bool MDPI_6(float* L_k1,float* L_k0,int n,float Erro)
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

void MDPI(float** Matriz,int n,float Erro)
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
	
	//O código que realiza a transição de A para A^-1 não é de minha autoria, segue abaixo a referencia:
	//GEEKSFORGEEKS. // C++ program to find adjoint and inverse of a matrix. Versão  [S. l.]: Geeksforgeeks.org. Disponível em: https://www.geeksforgeeks.org/adjoint-inverse-matrix/. Acesso em: 13 Julho 2021.	
	Matriz = InverteMatriz(Matriz,n);
	
	
	
	Z = MDPI_1(Matriz,Y,n);
		
	//L_k1 = MDPI_2(Z,Y,n);
	
	////////////////////////
	
	int k=0;
	
	do{
	
	L_k0 = L_k1;
	
	Alpha = MDPI_3(Z,n);
	
	Y = MDPI_4(Alpha,Z,n);
	
	Z = MDPI_1(Matriz,Y,n);
	
	L_k1 = MDPI_2(Z,Y,n);
	
	Lambda = MDPI_5(L_k1,L_k0,n,Erro);
	
	k++;
	
	}while(MDPI_6(L_k1,L_k0,n,Erro));
	
	////////////////////////
	
	std::cout<<"Lambda_"<<k<<"^-1: "<<fabs(Lambda)<<"\nLambda_"<<k<<": "<<fabs(1/Lambda)<<std::endl;
	std::cout<<"\nAutovetor:"; imprime_vetor(Y,n); std::cout<<"^t";
	
}

#endif
