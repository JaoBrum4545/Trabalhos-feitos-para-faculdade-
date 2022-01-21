#ifndef CONTAS_1-3_H_INCLUDED
#define CONTAS_1-3_H_INCLUDED

class Contas
{
	private:
		int codigo_da_conta;
		int cpf_associado;
		int saldo;
		
	public :
		Contas(int ca, int cf)//Construtor para criar uma conta!
		{
			codigo_da_conta = ca;
			cpf_associado = cf;
		}
		
		//------------------------------------------------------		
		
		int getcodigo_da_conta()
		{
			return (codigo_da_conta);
		}
		
		//------------------------------------------------------

		int getcpf_associado()
		{
			return (cpf_associado);
		}
		
		//------------------------------------------------------
		
		int getsaldo()
		{
			return (saldo);
		}
		
		//------------------------------------------------------
		
		int setsaldo(int so)//Método para alterar o saldo
		{
			saldo = so;
		}
		
		~Contas()//Destrutor 
		{
			std::cout<<"--------------------------------"<<std::endl;
			std::cout<<"Meu Codigo era: "<<codigo_da_conta<<std::endl;
			std::cout<<"--------------------------------\n\n"<<std::endl;
		}
};

#endif
