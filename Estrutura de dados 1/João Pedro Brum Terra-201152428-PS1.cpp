#include <iostream>  
#include <stack>

void hanoi(int n,std::stack<int>& origem,std::stack<int>& destino,std::stack<int>& auxiliar){
	if(n==1){ //Movimento da menor pe�a
		destino.push(origem.top());
		origem.pop();
		return;
	}
	
	hanoi(n-1,origem,auxiliar,destino);
	destino.push(origem.top());//Movimento das demais
	origem.pop();
	
	hanoi(n-1,auxiliar,destino,origem);
}

int main ()
{
	std::stack<int> A,B,C;
	
	int n;
	
	std::cin>>n;
	
    for(int i=n;i>=1;i--){//Armazena os valores na torre inicial
        A.push(i);
    }
	
	hanoi(n,A,C,B);//M�todo de resolu��o e transferencias!
	
	std::cout<<"\n";
	
	while(!C.empty())//Impress�o
	{
		std::cout<<C.top()<<" ";
		C.pop();
	}
	
	return (4545);
}
