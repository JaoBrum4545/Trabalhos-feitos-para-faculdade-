#ifndef BANCO_1-3_H_INCLUDED
#define BANCO_1-3_H_INCLUDED

#include "clientes_1-3.h"
#include "contas_1-3.h"
#include "transferencias_1-3.h"


class Banco
{//O banco sera o local onde todos os metodos e dados serão armazenados para facilitar as suas manipulações
	private:
		std::vector <Clientes*> Lista_de_clientes;
		int numero_de_clientes; 
		
		std::vector <Contas*> Lista_de_contas;
		int numero_de_contas;
		
		std::vector <Transferencias*> Lista_de_transferencias;
		int numero_de_transferencias;
		
	public:
		
		CadastraCliente(int cf, std::string ne)//Aloca um novo cliente
		{
			numero_de_clientes = numero_de_clientes +1;
			
			Lista_de_clientes.push_back(new Clientes(cf,ne));
		}
		
		//------------------------------------------------------
		
		void imprimir_Lista_de_clientes()
		{
		for(int i(0); i<numero_de_clientes; i++)
		{
			std::cout<<"----------------------------------------------------------------------------"<<std::endl;
			std::cout<<"Nome..: "<<Lista_de_clientes[i]->getNome()<<std::endl;
			std::cout<<"cpf...: "<<Lista_de_clientes[i]->getcpf()<<std::endl;
			std::cout<<"----------------------------------------------------------------------------\n\n"<<std::endl;
		}
		}
		
		//------------------------------------------------------
		
		bool esse_cliente_existe(int cf)//Verifica a existencia do cliente
		{
			
		for(int i(0); i<numero_de_clientes; i++)
		{
			if(Lista_de_clientes[i]->getcpf()==cf)
			{
				//std::cout<<"Cpf encontrado!!!"<<std::endl;
				
				return (true);
			}
		}
			std::cout<<"\n\nCliente nao encontrado!!!"<<std::endl;
			return (false);
		}
		
		//------------------------------------------------------
		
		int busca_cliente(int cf)//Recebe o cpf do cliente e devolve a sua posição no vetor
		{
		for(int i(0); i<numero_de_clientes; i++)
		{
			if(Lista_de_clientes[i]->getcpf()==cf)
			{
				//std::cout<<"Conta encontrado!!!"<<std::endl;
				return (i);
			}
		}
		}
		
		//------------------------------------------------------
		
		CadastraConta(int ca, int cf)//Aloca uma nova conta
		{
			if(esse_cliente_existe(cf))
			{
				numero_de_contas = numero_de_contas + 1;
				
				Lista_de_contas.push_back(new Contas(ca,cf));
				
				Lista_de_contas[numero_de_contas-1]->setsaldo(1000);
			}
		}
		
		//------------------------------------------------------
		
		void imprimir_Lista_de_contas()
		{
		for(int i(0); i<numero_de_contas; i++)
		{
			std::cout<<"----------------------------------------------------------------------------"<<std::endl;
			std::cout<<"Codigo da conta..: "<<Lista_de_contas[i]->getcodigo_da_conta()<<std::endl;
			std::cout<<"Cpf associado....: "<<Lista_de_contas[i]->getcpf_associado()<<std::endl;
			std::cout<<"Saldo............: "<<Lista_de_contas[i]->getsaldo()<<std::endl;
			std::cout<<"----------------------------------------------------------------------------\n\n"<<std::endl;
		}
		}
		
		//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		bool essa_conta_existe(int ca)//Verifica se a conta existe
		{
		for(int i(0); i<numero_de_contas; i++)
		{
			if(Lista_de_contas[i]->getcodigo_da_conta()==ca)
			{
				//std::cout<<"Conta encontrado!!!"<<std::endl;
				return (true);
			}
		}
			std::cout<<"\n\nConta nao encontrado!!!"<<std::endl;
			return (false);
		}
		
		//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		int busca_conta(int ca)//Recebe o codigo da conta e devolve sua posição no vetor
		{
		for(int i(0); i<numero_de_contas; i++)
		{
			if(Lista_de_contas[i]->getcodigo_da_conta()==ca)
			{
				//std::cout<<"Conta encontrado!!!"<<std::endl;
				return (i);
			}
		}
		}
		
		//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		void Saldo_do_cliente(int cf)//Ele acha o saldo total do cliente em todas as suas contas
		{
	
		if(!esse_cliente_existe(cf))//Teste para ver se o cliente existe
		{
			return;
		}
				
		int saldo_total=0;
				
		for(int i(0); i<numero_de_contas; i++)
		{
			if(Lista_de_contas[i]->getcpf_associado()==cf)
			{
				saldo_total = saldo_total + Lista_de_contas[i]->getsaldo();//Acumulador de saldos
			}
		}
		std::cout<<"----------------------------------------------------------------------------"<<std::endl;
		std::cout<<"Nome do cliente..: "<<Lista_de_clientes[busca_cliente(cf)]->getNome()<<std::endl;
		std::cout<<"Cpf do cliente...: "<<cf<<std::endl;
		std::cout<<"Saldo............: "<<saldo_total<<std::endl;
		std::cout<<"----------------------------------------------------------------------------\n\n"<<std::endl;
		}
		
		//------------------------------------------------------
		
		void Saldo_da_conta(int ca)//Acha o saldo de uma conta
		{
			if(!essa_conta_existe(ca))//Verifica a existencia do conta
			{
				return;
			}
		std::cout<<"----------------------------------------------------------------------------"<<std::endl;
		std::cout<<"Codigo da conta..........: "<<ca<<std::endl;
		std::cout<<"Cpf associado da conta...: "<<Lista_de_contas[busca_conta(ca)]->getcpf_associado()<<std::endl;
		std::cout<<"Saldo....................: "<<Lista_de_contas[busca_conta(ca)]->getsaldo()<<std::endl;
		std::cout<<"----------------------------------------------------------------------------\n\n"<<std::endl;
		}	
			
		
		//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		void Extrato_do_cliente(int cf)// Esta função verifica todas as transações associados ao um cliente
		{	
			
		if(!esse_cliente_existe(cf))// Verifica a existencia do cliente
		{
			return;
		}
		
		int ca, a = 0;
		
		for(int i(0); i<numero_de_contas; i++)
		{
		if(Lista_de_contas[i]->getcpf_associado()==cf)
		{
		
		ca = Lista_de_contas[i]->getcodigo_da_conta();

		
		for(int j(0); j<numero_de_transferencias; j++)
		{
			if(Lista_de_transferencias[j]->getConta_que_transferiu()==ca)
			{
				std::cout<<"Transferiu..: R$"<<Lista_de_transferencias[i]->getvalor_trasacionado()<<std::endl;
				a++;//Feito para verificar se houve transações
			}
			
			if(Lista_de_transferencias[j]->getconta_que_recebeu()==ca)
			{
				std::cout<<"Recebeu.....: R$"<<Lista_de_transferencias[j]->getvalor_trasacionado()<<std::endl;
				a++;//Feito para verificar se houve transações
			}
			
			std::cout<<"----------------------------------------------------------------------------\n\n"<<std::endl;
		}	
		}
		}
			if(a==0)
				std::cout<<"Esse cliente nao teve movimentacao alguma!!!"<<std::endl;
		}
		
		//------------------------------------------------------------------------------------------------------------------------------------------------------
		
				void Extrato_da_conta(int ca)// Esta função verifica todas as transações associados ao uma conta
		{	
			
		if(!essa_conta_existe(ca))	
		{
			return;
		}
		
		int a = 0;
		
		for(int j(0); j<numero_de_transferencias; j++)
		{
			if(Lista_de_transferencias[j]->getConta_que_transferiu()==ca)
			{
				std::cout<<"Transferiu..: R$"<<Lista_de_transferencias[j]->getvalor_trasacionado()<<std::endl;
				a++;//Feito para verificar se houve transações
			}
			
			if(Lista_de_transferencias[j]->getconta_que_recebeu()==ca)
			{
				std::cout<<"Recebeu.....: R$"<<Lista_de_transferencias[j]->getvalor_trasacionado()<<std::endl;
				a++;//Feito para verificar se houve transações
			}
			
			std::cout<<"----------------------------------------------------------------------------\n\n"<<std::endl;	
		}
			if(a==0)
				std::cout<<"Essa conta nao teve movimentacao alguma!!!"<<std::endl;
		}
		
		//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		void Realizar_transferencia(int ctu, int cru, int valor)//Cadastra um novo registro de transação
		{
			if(!essa_conta_existe(ctu))
				return;
				
			if(!essa_conta_existe(cru))
				return;
			
		if(valor<=Lista_de_contas[busca_conta(ctu)]->getsaldo())//Verifica se há saldo na conta
		{
			numero_de_transferencias = numero_de_transferencias + 1;
			
			Lista_de_transferencias.push_back(new Transferencias(ctu,cru,Lista_de_contas[busca_conta(ctu)]->getsaldo(),Lista_de_contas[busca_conta(cru)]->getsaldo(),valor));
			
			Lista_de_contas[busca_conta(ctu)]->setsaldo(Lista_de_contas[busca_conta(ctu)]->getsaldo() - valor);
			
			Lista_de_contas[busca_conta(cru)]->setsaldo(Lista_de_contas[busca_conta(cru)]->getsaldo() + valor);
		
		std::cout<<"Transferencia concluida"<<std::endl;
		}else{
			std::cout<<"Saldo insuficiente para concluir a transferencia"<<std::endl;
		}
		}
		
		//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		void total()//Imprime o total que há no banco (É esperado 10000)
		{
		int soma_total = 0;	
			
		for(int i(0); i<numero_de_contas; i++)
		{
			soma_total = soma_total + Lista_de_contas[i]->getsaldo();//Acumulador
		}	
		
		std::cout<<"----------------------------------------------------------------------------"<<std::endl;
		std::cout<<"Esse banco tem guardado....: R$"<<soma_total<<std::endl;
		}
		
		//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		void deletar_geral()//Libera espaço de cada um dos vetores
		{
		for(int i(0); i<numero_de_clientes; i++)
		{
			delete Lista_de_clientes[i];
		}
		for(int i(0); i<numero_de_contas; i++)
		{
			delete Lista_de_contas[i];
		}
		for(int i(0); i<numero_de_transferencias; i++)
		{
			delete Lista_de_transferencias[i];
		}
		std::cout<<"\n\nTodos os ponteiros foram liberados"<<std::endl;
		std::cout<<"\n\nFinalizando o programa"<<std::endl;
		}
		
		~Banco()//Destrutor do banco
		{
		}

};

#endif
