package trabalho.pkg2.pkg2;

import java.util.Scanner;

public class Trabalho22 {

    public static void main(String[] args) {
        
        Banco banco = new Banco();
        boolean controle = true;
        int op;
        int cod;
        
        banco.cadastra_Cliente("Generico_1", 1111);
        banco.cadastra_Cliente("Generico_2", 2222);
        banco.cadastra_Cliente("Generico_3", 3333);
        banco.cadastra_Cliente("Generico_4", 4444);
        
        banco.cadastra_Conta(1111, 1001);
        banco.cadastra_Conta(2222, 2001);
        banco.cadastra_Conta(2222, 2002);
        banco.cadastra_Conta(4444, 4001);
        banco.cadastra_Conta(2222, 2003);
        banco.cadastra_Conta(3333, 3001);
        
        do
        {
            System.out.print("Menu do Banco:\n"
                             + "(1)Listar todos os clientes.\n"
                             + "(2)Listar todas as contas.\n"
                             + "(3)Saldo do cliente(ou da conta).\n"
                             + "(4)Extrato do cliente(ou da conta).\n"
                             + "(5)Realizar tranferência entre contas.\n"
                             + "(6)Exibir o saldo total do Banco.\n"+"(0)Para encerrar a execução"+"\n\n\nQual opção você escolhe (insira apenas inteiros): ");
            try
            {
            Scanner val = new Scanner(System.in);
            op = val.nextInt();
            switch(op)
            {
                case 1:
                        banco.lista_Clientes();
                        break;
                case 2:
                        banco.lista_Contas();
                        break;
                case 3:
                        do//Mini menu da opção 3;
                        {
                        try//Esse try é para capturar tentativas de colocar algum outro valor que não é inteiro;
                        {
                        System.out.print("\n(1)Para verificar o saldo do cliente."
                                +"\n(2)Para verificar o saldo da conta.\n"+
                                "(0)Para sair dessa opção."+"\n\n\nQual opção você escolhe (insira apenas inteiros): ");
                        
                        val = new Scanner(System.in);
                        op = val.nextInt();//Seleciona a opção
            
                        switch(op)
                        {
                            
                            case 1:
                                try//Esse try é para verificar se o usuário colocou inteiro ou se o cliente existe de fato;
                                {
                                System.out.print("\nDigite o CPF do cliente: ");
                                val = new Scanner(System.in);
                                cod = val.nextInt();
                                if(banco.eEcle(cod)==false)
                                {
                                    throw new Exception("\nEsse cliente não existe! Tente novamente.\n");
                                }
                                banco.saldo_Cliente(cod);
                                break;
                                }
                                catch(Exception e)
                                {
                                    if(e.getMessage() != null)
                                    {
                                        System.out.println(e.getMessage());
                                    }
                                    else
                                    {
                                        System.out.println("\nValor colocado difirente de inteiro! Tente novamente.\n");
                                    }
                                }
                                break;    
                                
                                
                            case 2:
                                try//Esse try é para verificar se o usuário colocou inteiro ou se a conta existe de fato;
                                {
                                System.out.print("\nDigite o número da conta: ");
                                val = new Scanner(System.in);
                                cod = val.nextInt();
                                if(banco.eEcne(cod)==false)
                                {
                                    throw new Exception("\nEssa conta não existe! Tente novamente.\n");
                                }
                                banco.saldo_Conta(cod);
                                break;
                                }
                                catch(Exception e)
                                {
                                  if(e.getMessage() != null)
                                    {
                                        System.out.println(e.getMessage());
                                    }
                                    else
                                    {
                                        System.out.println("\nValor colocado difirente de inteiro! Tente novamente.\n");
                                    }  
                                }
                                break;
                            case 0:
                                    controle = false;
                                    break;
                            default:
                                    System.out.println("\nOpção Incorreta! Tente novamente.\n");
                                    break;
                        }
                        }
                        catch(Exception e)
                        {
                            System.out.println("\nValor colocado difirente de inteiro! Tente novamente.\n");
                        }
                        }while(controle == true);
                        controle = true;
                        break;
                case 4:
                        do//Mini menu da opção 4;
                        {
                        try//Esse try é para capturar tentativas de colocar algum outro valor que não é inteiro;
                        {
                        System.out.print("\n(1)Para verificar o extrato do cliente."
                                +"\n(2)Para verificar o extrato da conta.\n"+
                                "(0)Para sair dessa opção."+"\n\n\nQual opção você escolhe (insira apenas inteiros): ");
                        
                        val = new Scanner(System.in);
                        op = val.nextInt();
                        
                        switch(op)
                        {
                            
                            case 1://Esse try é para verificar se o usuário colocou inteiro ou se o cliente existe de fato;
                                try
                                {
                                System.out.print("\nDigite o CPF do cliente: ");
                                val = new Scanner(System.in);
                                cod = val.nextInt();
                                if(banco.eEcle(cod)==false)
                                {
                                    throw new Exception("\nEsse cliente não existe! Tente novamente.\n");
                                }
                                banco.extrato_cliente(cod);
                                break;
                                }
                                catch(Exception e)
                                {
                                    if(e.getMessage() != null)
                                    {
                                        System.out.println(e.getMessage());
                                    }
                                    else
                                    {
                                        System.out.println("\nValor colocado difirente de inteiro! Tente novamente.\n");
                                    }
                                }
                                break;    
                                
                                
                            case 2:
                                try//Esse try é para verificar se o usuário colocou inteiro ou se a conta existe de fato;
                                {
                                System.out.print("\nDigite o número da conta: ");
                                val = new Scanner(System.in);
                                cod = val.nextInt();
                                if(banco.eEcne(cod)==false)
                                {
                                    throw new Exception("\nEssa conta não existe! Tente novamente.\n");
                                }
                                banco.extrato_conta(cod);
                                break;
                                }
                                catch(Exception e)
                                {
                                  if(e.getMessage() != null)
                                    {
                                        System.out.println(e.getMessage());
                                    }
                                    else
                                    {
                                        System.out.println("\nValor colocado difirente de inteiro! Tente novamente.\n");
                                    }  
                                }
                                break;
                            case 0:
                                    controle = false;
                                    break;
                            default:
                                    System.out.println("\nOpção Incorreta! Tente novamente.\n");
                                    break;
                        }
                        }
                        catch(Exception e)
                        {
                            System.out.println("\nValor colocado difirente de inteiro! Tente novamente.\n");
                        } 
                        }while(controle == true);
                        
                        controle = true;
                        break;
                case 5:
                        try//Esse try é para verificar se o usuário colocou inteiro, se as contas existem de fato e se o saldo é suficiente;
                        {
                        System.out.print("\nDigite a número da conta de origem :");
                                val = new Scanner(System.in);
                                int cod_1 = val.nextInt();
                        if(banco.eEcne(cod_1)==false)
                        {
                            throw new Exception("\nEssa conta não existe! Tente novamente.\n");
                        } 
                        System.out.print("\nDigite a número da conta de destino :");
                                val = new Scanner(System.in);
                                int cod_2 = val.nextInt();
                        if(banco.eEcne(cod_2)==false)
                        {
                            throw new Exception("\nEssa conta não existe! Tente novamente.\n");
                        }
                        System.out.print("\nDigite o valor a ser transferido :");
                                val = new Scanner(System.in);
                                cod = val.nextInt();
                        if(banco.eCntd(cod_1, cod)==false)
                        {
                            throw new Exception("\nSaldo insuficiente! Tente novamente.\n");
                        }
                        banco.realiza_transferencia(cod_1,cod_2, cod);
                        break;
                        }
                        catch(Exception e)
                        {
                         if(e.getMessage() != null)
                                    {
                                        System.out.println(e.getMessage());
                                    }
                                    else
                                    {
                                        System.out.println("\nValor colocado difirente de inteiro! Tente novamente.\n");
                                    } 
                        }
                        break;
                case 6: 
                        banco.saldo_do_banco();
                        break;
                case 0: 
                        System.out.println("\nEncerrando Programa\n");
                        controle = false;
                        break;
                default:
                        System.out.println("\nOpção Incorreta! Tente novamente.\n");
                        break;
                       
             
            }
            }
            catch(Exception e)
            {
                System.out.println("\nValor colocado difirente de inteiro! Tente novamente.\n");
            } 
        }
        while(controle == true);
    }
    
}
