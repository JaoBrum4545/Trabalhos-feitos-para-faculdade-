#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "clientes_1-3.h"
#include "contas_1-3.h"
#include "transferencias_1-3.h"
#include "banco_1-3.h"

//1-0: Criação do código.
//1-1: Verificando como faz para utilizar o vetor
//1-2: Refazendo o código do zero e colocando os ponteiros dentro da classe banco
//1-3: Separação do cabeçalho!

///////////////////////////////////////////////////////////////////////////////

int main ()
{
	int controle_do_switch, controle_do_3, controle_do_4, aux_1, aux_2, aux_3_1, aux_3_2, aux_3_3, controle_do_while = 0;
	
	Banco* banco = new Banco();
	
	banco->CadastraCliente(4444,"Generico 1");
	banco->CadastraCliente(5555,"Generico 2");
	banco->CadastraCliente(6666,"Generico 3");
	banco->CadastraCliente(7777,"Generico 4");
	banco->CadastraCliente(8888,"Generico 5");
	
	banco->CadastraConta(4141,4444);
	banco->CadastraConta(5151,5555);
	banco->CadastraConta(5252,5555);
	banco->CadastraConta(6161,6666);
	banco->CadastraConta(6262,6666);
	banco->CadastraConta(6363,6666);
	banco->CadastraConta(7171,7777);
	banco->CadastraConta(7272,7777);
	banco->CadastraConta(8181,8888);
	banco->CadastraConta(8282,8888);
	
	do
	{
		std::cout<<"Escolha uma opcao !!!\n\n"<<std::endl;//Menu
		std::cout<<"----------------------------------------------------------------------------"<<std::endl;
		std::cout<<"1: Lista todas as clientes. "<<std::endl;
		std::cout<<"2: Lista todas as contas. "<<std::endl;
		std::cout<<"3: Mostra o saldo do cliente ou da conta. "<<std::endl;
		std::cout<<"4: Mostra o extrato do cliente ou da conta. "<<std::endl;
		std::cout<<"5: Realiza transferencia entre duas contas. "<<std::endl;
		std::cout<<"6: Mostra o saldo total do banco. "<<std::endl;
		std::cout<<"0: Deleta toda informacao e finaliza o programa. "<<std::endl;
		std::cout<<"----------------------------------------------------------------------------\n\n"<<std::endl;
		
		std::cout<<"Digite opcao desejada: "<<std::endl;
		std::cin>> controle_do_switch;
		
		switch(controle_do_switch)
		{
			case 1://Lista clientes
					system("cls");
					banco->imprimir_Lista_de_clientes();
					
					getch();
					system("cls");
					
					break;
					
			case 2://lista contas
					system("cls");
					banco->imprimir_Lista_de_contas();
					
					getch();
					system("cls");
					
					break;
			
			case 3://Saldo do cliente ou da conta
					std::cout<<"\nDeseja ver o saldo do Cliente(1) ou Conta(2) ? : "<<std::endl;
					std::cin>> controle_do_3;
			
					switch(controle_do_3)
					{

						
						case 1://Do Cliente
						
								std::cout<<"\n\nDigite o CPF do cliente: "<<std::endl;
								std::cin>> aux_1;
								
								system("cls");
								banco->Saldo_do_cliente(aux_1);
								
								getch();
								system("cls");
						
						break;
						
						case 2://Da conta
								
								std::cout<<"\n\nDigite o Codigo da conta: "<<std::endl;
								std::cin>> aux_1;
								
								system("cls");
								banco->Saldo_da_conta(aux_1);
								
								getch();
								system("cls");
						
						break;
						
						default://opcao invalida
								system("cls");
								std::cout<<"\n\nOpcao invalida tente novamente\n\n"<<std::endl;
								
								break;
						
					}
					
					break;
			
			case 4://Extrato do cliente ou da conta
					std::cout<<"\nDeseja ver o extrato do Cliente(1) ou Conta(2) ? : "<<std::endl;
					std::cin>> controle_do_4;		
			
					switch(controle_do_4)
					{
						case 1://Do Cliente
								std::cout<<"\n\nDigite o CPF do cliente: "<<std::endl;
								std::cin>> aux_2;
								
								system("cls");
								
								banco->Extrato_do_cliente(aux_2);
								
								getch();
								system("cls");					
								break;
						
						case 2://Da conta
								std::cout<<"\n\nDigite o codigo da conta: "<<std::endl;
								std::cin>> aux_2;
								
								system("cls");
								
								banco->Extrato_da_conta(aux_2);
								
								getch();
								system("cls");					
								break;
						
						default://opcao invalida
								system("cls");
								std::cout<<"\n\nOpcao invalida tente novamente\n\n"<<std::endl;
								
								break;
						
					}
					
					break;
					
			case 5://Realiza transferencia de uma conta para outra
					
					std::cout<<"\n\nDigite o Codigo da conta que ira transferir: "<<std::endl;
					std::cin>> aux_3_1;
					
					if(!banco->essa_conta_existe(aux_3_1))
					{
						getch();system("cls");break;	
					}
					
					std::cout<<"\n\nDigite o Codigo da conta que ira receber: "<<std::endl;
					std::cin>> aux_3_2;
					
					if(!banco->essa_conta_existe(aux_3_2))
					{
						getch();system("cls");break;	
					}
					
					std::cout<<"\n\nDigite o valor a ser transferido: "<<std::endl;
					std::cin>> aux_3_3;
					
					system("cls");
				
					banco->Realizar_transferencia(aux_3_1,aux_3_2,aux_3_3);
					
					getch();
					system("cls");
					
					break;
					
			case 6://Mostrando o total do banco
		
					system("cls");
					banco->total();
					
					getch();
					system("cls");
					
					break;
			
			case 0://Finaliza o programa
					controle_do_while = 1;
					
					banco->deletar_geral();
					
					delete banco;
					
					break;
					
			default: //Opcao invalida
					system("cls");
					std::cout<<"\n\nOpcao invalida tente novamente\n\n"<<std::endl;
					
					break;
		}
			
	}
	while(controle_do_while!=1);
	
	std::cout<<"\n\nAte a proxima"<<std::endl;
}
