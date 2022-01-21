package trabalho.pkg2.pkg2;

public class Transferencia {
    
    private int valor_transferencia;
    private int conta_origem;
    private int conta_destino;
    
    Transferencia(int co, int cd, int val)//Constructor
    {
        
        this.conta_origem = co;
        this.conta_destino = cd;
        this.valor_transferencia = val;
        
    }
    
    public int getV_t()
    {
        return this.valor_transferencia;
    }
    
    public int getC_o()
    {
        return this.conta_origem;
    }
    
    public int getC_d()
    {
        return this.conta_destino;
    }
}
