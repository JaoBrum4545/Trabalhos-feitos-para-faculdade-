package trabalho.pkg2.pkg2;

public class Cliente {
    
    private String nome;    
    private int cpf;
    
    Cliente(String nome, int cpf)
    {
        this.cpf=cpf;
        this.nome=nome;
    }
    
    public int getCpf()
    {
        return this.cpf;
    }
    
    public String getNome()
    {
        return this.nome;
    }
    
    
    
}
