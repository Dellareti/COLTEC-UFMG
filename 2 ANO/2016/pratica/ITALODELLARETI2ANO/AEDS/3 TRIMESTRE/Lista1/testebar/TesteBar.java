package testebar;

import java.util.Scanner;

public class TesteBar {
    public static void main(String[] args) {
        Restaurante A = new Restaurante();
        A.inicializa();
       
        int op;
        System.out.println("Restaurante LeVelmond");
        do{
            System.out.println("\n\nOpções:\n\n1 - Reservas.\n\n2 - Ir a uma mesa\n\n3 - Sair");
            op = new Scanner(System.in).nextInt();
            
            if(op==1){
                int i;
                System.out.print("\n\nQual mesa deseja:\t");
                i = new Scanner(System.in).nextInt();
                A.n_clientes++;
                A.mesas[i].reservar();
            }
            
            else if (op==2){
                int j;
                System.out.print("\n\nPossui reserva (0=Não 1=Sim):\t");
                j = new Scanner(System.in).nextInt();
            
                if(j==1){
                    int k;
                    System.out.println("\n\nQual mesa:\t");
                    k = new Scanner(System.in).nextInt();
                    if(A.mesas[k].verifica_reserva()==true){
                       //vai pra mesa 
                       A.mesas[k].clientes[0].cria();
                       A.mesas[k].clientes[1].cria();
                       int op1;
                       
                       do{
                           System.out.println("\n\nDigite a opção do casal:");
                           System.out.println("\n1 - PF\n\n2 - Refresco\n\n3 - Sair");
                           op1 = new Scanner(System.in).nextInt();
                           
                           switch (op1) {
                               case 1:
                                   A.mesas[k].conta.pf++;
                                   break;
                               case 2:
                                   A.mesas[k].conta.refri++;
                                   break;
                               case 3:
                                    A.mesas[k].conta.listarConsumo();
                                    double pagar;
                                    A.mesas[k].liberar();
                                    pagar = A.mesas[k].conta.calcular10porcento();
                                    pagar = A.mesas[k].conta.dividirConta();
                                    System.out.println("Valor cada cliente (+ 10% do atendimento):\t" + pagar);     
                                    A.n_clientes--;
                                    System.out.println("Volte sempre.");
                                    break;
                               default:
                                   break;
                           }
                       }while(op1==1||op1==2);                 
                    } 
                }
                
                else{
                    A.n_clientes++;
                    //vai pra uma mesa disponível
                    A.mesas[A.n_clientes].reservar();
                    A.mesas[A.n_clientes].clientes[0].cria();
                    A.mesas[A.n_clientes].clientes[1].cria();
                    int op2;
                    System.out.println("Mesa:" + A.n_clientes);
                    do{
                        System.out.println("\n\nDigite a opção do casal:");
                        System.out.println("\n1 - PF\n\n2 - Refresco\n\n3 - Sair");
                        op2 = new Scanner(System.in).nextInt();

                        switch (op2) {
                            case 1:
                                A.mesas[A.n_clientes].conta.pf++;
                                break;
                            case 2:
                                A.mesas[A.n_clientes].conta.refri++;
                                break;
                            case 3:
                                A.mesas[A.n_clientes].conta.listarConsumo();
                                double pagar;
                                pagar = A.mesas[A.n_clientes].conta.calcular10porcento();
                                pagar = A.mesas[A.n_clientes].conta.dividirConta();
                                System.out.println("Valor cada cliente (+ 10% do atendimento):\t" + pagar);
                                A.mesas[A.n_clientes].liberar();
                                A.n_clientes--;
                                System.out.println("Volte sempre.");                                
                                break;
                            default:
                                break;
                        }
                    }while(op2==1||op2==2);
                }                
            }            
        }while(op==1||op==2);      
    }   
}

//Pf = R$10
//Refri = R$5