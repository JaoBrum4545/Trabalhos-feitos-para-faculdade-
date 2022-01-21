package trabalho.pkg2.pkg2;

public class Operacoes {
   
    public void listar_Cliente(Cliente cl)
    {
        System.out.println("Cpf.............:"+cl.getCpf()+". ");
        System.out.println("Nome............:"+cl.getNome()+". ");
    }
    
    public void listar_Conta(Conta cn)
    {
        System.out.println("Numero da conta.....:"+cn.getNdc()+". ");
        System.out.println("Cpf assosiado.......:"+cn.getCa()+". ");
        System.out.println("Saldo...............:R$"+cn.getSaldo()+".\n");
    }
}
