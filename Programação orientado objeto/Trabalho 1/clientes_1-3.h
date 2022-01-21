#ifndef CLIENTES_1-3_H_INCLUDED
#define CLIENTES_1-3_H_INCLUDED


class Clientes 
{
	private:
		int cpf;
		std::string Nome;
		
	public:
		Clientes(int cf, std::string Nm)://Construtor para criar um cliente
		Nome(Nm)
		{
			cpf=cf;
		}
		
		//------------------------------------------------------
		
		std::string getNome()
		{
			return(Nome);
		}
		
		//------------------------------------------------------
		
		int getcpf()
		{
			return(cpf);
		}
		
		//------------------------------------------------------
		
		~Clientes()//Destrutor para apagar o cliente
		{
			std::cout<<"--------------------------------"<<std::endl;
			std::cout<<"Meu CPF era: "<<cpf<<std::endl;
			std::cout<<"--------------------------------\n\n"<<std::endl;
		}
		
};

#endif
