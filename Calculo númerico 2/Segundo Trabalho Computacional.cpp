#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <math.h>

#include "VETORES&MATRIZES.h"
#include "METODO_QR.h"
#include "METODO_DP.h"
#include "METODO_DPI.h"

//O código que realiza a transição de A para A^-1 não é de minha autoria, segue abaixo a referencia:
//GEEKSFORGEEKS. C++ program to find adjoint and inverse of a matrix. Versão  [S. l.]: Geeksforgeeks.org. Disponível em: https://www.geeksforgeeks.org/adjoint-inverse-matrix/. Acesso em: 13 Julho 2021.	

int main ()
{
	
	setlocale(LC_ALL, "Portuguese");
	
	int n;
	float** Matriz;
	float Erro;
	int Controle;
	
	std::cout<<"Insira a ordem da matriz: ";
	std::cin>>n;
	
	Matriz = cria_matriz(n);
	
	std::cout<<"\n\n";
	
	std::cout<<"Insira o erro: ";
	std::cin>>Erro;
	
	std::cout<<"\n\n";
	
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<n;j++)
		{
			std::cout<<"Insira o valor de ("<<i<<","<<j<<"): ";
			std::cin>>Matriz[i][j];
			std::cout<<"\n";
			
		}
		
	}
	
	std::cout<<"Método das potências ========= 1"<<std::endl;
	std::cout<<"Método das potências inversa = 2"<<std::endl;
	std::cout<<"Método QR ==================== 3"<<std::endl;
	
	std::cout<<"Qual opção você escolhe: ";
	std::cin>>Controle;
	
	std::cout<<"\n";
	
	switch(Controle)
	{
		case 1:
			
			std::cout<<"\n\nMDP_____________________________________________"<<std::endl;
			MDP(Matriz,n,Erro);
			
		
		case 2:
			
			std::cout<<"\n\nMDPI_____________________________________________"<<std::endl;
			MDPI(Matriz,n,Erro);
			
			
		case 3:
			
			std::cout<<"\n\nMQR_____________________________________________"<<std::endl;	
			MQR(Matriz,n,Erro);
			break;
			
			
		default: 
			std::cout<<"\n\nEssa Opção não existe"<<std::endl;
			break;
		
	}
	
std::cout<<"\n\nEncerrando programa . . . \n\n"<<std::endl;

return 4545;
	
}

