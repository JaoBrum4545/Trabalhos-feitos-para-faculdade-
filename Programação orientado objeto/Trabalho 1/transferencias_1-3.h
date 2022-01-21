#ifndef TRANSFERENCIAS_1-3_H_INCLUDED
#define TRANSFERENCIAS_1-3_H_INCLUDED

class Transferencias 
{
	private:
		int Conta_que_transferiu;
		int saldo_ctu;
		int conta_que_recebeu;
		int saldo_cru;
		int valor_trasacionado;
	public :
		
		Transferencias(int ctu, int cru, int st, int sr, int valor)//Construtor para criar um registro de transferencia
		{
			Conta_que_transferiu = ctu;
			
			saldo_ctu = st - valor;
			
			conta_que_recebeu = cru;
			
			saldo_cru = sr + valor;
						
			valor_trasacionado = valor;
			
		}
		
		//--------------------------------------------------------------
		
		int getConta_que_transferiu()
		{
			return (Conta_que_transferiu);
		}
		
		//--------------------------------------------------------------
		
		int getsaldo_ctu()
		{
			return (saldo_ctu);
		}
		
		//--------------------------------------------------------------
		
		int getconta_que_recebeu()
		{
			return (conta_que_recebeu);
		}
		
		//--------------------------------------------------------------
		
		int getsaldo_cru()
		{
			return (saldo_cru);
		}
		
		//--------------------------------------------------------------
		
		int getvalor_trasacionado()
		{
			return (valor_trasacionado);
		}
		
		//--------------------------------------------------------------
		
		~Transferencias()//Destrutor para os registros de transferencias
		{
		
		}
};

#endif
