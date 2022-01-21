package trabalho.pkg2.pkg2;
import java.util.ArrayList;

public class Banco {

    private ArrayList <Conta> contas_associadas = new ArrayList<>(); 
    private ArrayList <Cliente> clientes_associadas = new ArrayList<>();
    private ArrayList <Transferencia> transferencias_realizadas = new ArrayList<>();

    Banco()
    {
        
    }        
    
    public void cadastra_Cliente(String nome, int cpf)
    {
        Cliente novo_cliente = new Cliente(nome,cpf);
        this.clientes_associadas.add(novo_cliente);
    }
    
    public void cadastra_Conta(int ca, int ndc)
    {
        Conta nova_conta = new Conta(ca,ndc);
        this.contas_associadas.add(nova_conta);
    }
    
    public boolean eEcle(int cpf)//Verifica se o cliente existe
    {
        for(int i = 0; i < this.clientes_associadas.size(); i++)
        {
            if(this.clientes_associadas.get(i).getCpf()==cpf)
            {
                return true;
            }
        }
        
        return false;
    }
    
    public boolean eEcne(int ndc)//Verifica se a conta exite
    {
        for(int i = 0; i < this.contas_associadas.size(); i++)
        {
            if(this.contas_associadas.get(i).getNdc()==ndc)
            {
                return true;
            }
        }
        
        return false;
    }
    
    public boolean eCntd(int cn,int val)//Verifica se a conta tem o saldo necessario 
    {
        for(int i = 0; i < this.contas_associadas.size(); i++)
        {
            if(this.contas_associadas.get(i).getNdc()==cn)
            {
                if(this.contas_associadas.get(i).getSaldo()>=val)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return false;
    }
    
    public void lista_Clientes()
    {
        int somatorio = 0;
        for(int i = 0; i < this.clientes_associadas.size(); i++)
        {   Operacoes op = new Operacoes();
            op.listar_Cliente(this.clientes_associadas.get(i));
            for(int j = 0; j < this.contas_associadas.size(); j++)
            {
                if(this.clientes_associadas.get(i).getCpf() == this.contas_associadas.get(j).getCa())
                {
                    somatorio = this.contas_associadas.get(j).getSaldo() + somatorio;
                }
            }
            System.out.println("Saldo total.....:R$"+somatorio+".\n");
            somatorio = 0;
        }
    }
    
    public void lista_Contas()
    {
        for(int i = 0; i < this.contas_associadas.size(); i++)
        {   Operacoes op = new Operacoes();
            op.listar_Conta(this.contas_associadas.get(i));
        }
    }
    
    public void saldo_Cliente(int cpf)
    {
        int somatorio = 0;
        for(int i = 0; i < this.clientes_associadas.size(); i++)
        {
            if(this.clientes_associadas.get(i).getCpf() == cpf)
            {
            for(int j = 0; j < this.contas_associadas.size(); j++)
            {
                if(this.clientes_associadas.get(i).getCpf() == this.contas_associadas.get(j).getCa())
                {
                    somatorio = this.contas_associadas.get(j).getSaldo() + somatorio;
                }
            }
            System.out.println("Saldo total do cliente "+this.clientes_associadas.get(i).getNome()+".....:R$"+somatorio+".\n");
            }
        }
    }
    
    public void saldo_Conta(int ndc)
    {
        for(int i = 0; i < this.contas_associadas.size(); i++)
        {
            if(this.contas_associadas.get(i).getNdc() == ndc)
            {
            System.out.println("Saldo total do cliente "+this.contas_associadas.get(i).getNdc()+" .....:"+this.contas_associadas.get(i).getSaldo()+".\n");    
            }
        }
    }
    
    public void realiza_transferencia(int co, int cd, int val)
    {
        Transferencia nova_entrada = new Transferencia(co,cd,val);
        this.transferencias_realizadas.add(nova_entrada);
        
        for(int i = 0; i < this.contas_associadas.size(); i++)
        {
            if(this.contas_associadas.get(i).getNdc() == co)
            {
            this.contas_associadas.get(i).setSaldo(this.contas_associadas.get(i).getSaldo()-val);
            }
        }
        
        for(int i = 0; i < this.contas_associadas.size(); i++)
        {
            if(this.contas_associadas.get(i).getNdc() == cd)
            {
            this.contas_associadas.get(i).setSaldo(this.contas_associadas.get(i).getSaldo()+val);
            }
        }
    }
    
    public void extrato_cliente(int cpf)
    {
        
       boolean ausencia = true;
        
       for(int i = 0; i < this.contas_associadas.size(); i++)
       {
           if(cpf == this.contas_associadas.get(i).getCa())
           {
               for(int j = 0; j < this.transferencias_realizadas.size(); j++)
               {
                   if(this.contas_associadas.get(i).getNdc() == this.transferencias_realizadas.get(j).getC_o())
                   {
                       for(int k = 0; k < this.contas_associadas.size(); k++)
                       {
                           if(this.contas_associadas.get(k).getNdc() == this.transferencias_realizadas.get(j).getC_d())
                           {
                               if(this.contas_associadas.get(i).getCa() == this.contas_associadas.get(k).getCa())
                               {
                                   System.out.println("Transferência interna no valor de R$"+this.transferencias_realizadas.get(j).getV_t()+" entre as contas "+this.contas_associadas.get(i).getNdc()+" e " + this.contas_associadas.get(k).getNdc() + " associadas ao cliente de CPF " + cpf+".\n");
                               }
                               else
                               {    
                               System.out.println("O cliente de CPF "+this.contas_associadas.get(i).getCa()+" transferiu R$"+this.transferencias_realizadas.get(j).getV_t()+" para a conta associada ao CPF "+this.contas_associadas.get(k).getCa()+".\n");
                               }
                               
                               ausencia = false;
                           }
                       }
                   }
                   if(this.contas_associadas.get(i).getNdc() == this.transferencias_realizadas.get(j).getC_d())
                   {
                       for(int k = 0; k < this.contas_associadas.size(); k++)
                       {
                           if(this.contas_associadas.get(k).getNdc() == this.transferencias_realizadas.get(j).getC_o())
                           {
                               ausencia = false;
                               
                               if(this.contas_associadas.get(i).getCa() != this.contas_associadas.get(k).getCa())
                               {
                                  System.out.println("O cliente de CPF "+this.contas_associadas.get(i).getCa()+" recebeu R$"+this.transferencias_realizadas.get(j).getV_t()+" da conta associada ao CPF "+this.contas_associadas.get(k).getCa()+".\n");
                               }
                           }
                       }
                   }
               }
           }
       } 
       
       if(ausencia == true)
       {
           System.out.println("O cliente de CPF "+cpf+" não realizou nenhuma transferencia até agora!\n");
       }
    }
    
    public void extrato_conta(int ndc)
    {
        
        boolean ausencia = true;
        
        for(int i = 0; i < this.contas_associadas.size(); i++)
        {
            if(this.contas_associadas.get(i).getNdc() == ndc)
            {
                for(int j = 0; j < this.transferencias_realizadas.size(); j++)
                {
                    if(this.transferencias_realizadas.get(j).getC_o() == ndc)
                    {
                        System.out.println("A conta de número " + ndc + " transferiu R$"+this.transferencias_realizadas.get(j).getV_t()
                        + " para a conta de número "+this.transferencias_realizadas.get(j).getC_d()+".\n");
                        ausencia = false;
                    }
                    if(this.transferencias_realizadas.get(j).getC_d() == ndc)
                    {
                        System.out.println("A conta de número " + ndc + " recebeu R$"+this.transferencias_realizadas.get(j).getV_t()
                        + " da conta de número "+this.transferencias_realizadas.get(j).getC_d()+".\n");
                        ausencia = false;
                    }
                }
            }
        }
        
        if(ausencia == true)
       {
           System.out.println("A conta de número "+ndc+" não realizou nenhuma transferencia até agora!\n");
       }
    }
    
    public void saldo_do_banco()
    {
        int somatorio = 0;
        
        for(int i = 0; i < this.contas_associadas.size(); i++)
        {
            somatorio = this.contas_associadas.get(i).getSaldo() + somatorio;
        }
        
        System.out.println("O banco guarda um total de R$"+somatorio+".\n");
    }
    
    
    
    
}
