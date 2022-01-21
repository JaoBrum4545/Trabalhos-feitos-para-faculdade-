package trabalho.pkg2.pkg2;

public class Conta {
    
    private int numero_da_conta; 
    private int saldo;
    private int cpf_associado;

    Conta(int ca,int ndc)
    {
        this.cpf_associado = ca;
        this.numero_da_conta = ndc;
        this.saldo = 1000;
    }
    
    public int getNdc()
    {
        return this.numero_da_conta;
    }
    
    public int getCa()
    {
        return this.cpf_associado;
    }
    
    public int getSaldo()
    {
        return this.saldo;
    }
    
    public void setSaldo(int n)
    {
        this.saldo = n;
    }
    
}
