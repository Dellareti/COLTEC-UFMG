package programa;
import java.util.Scanner;
public class Programa {
    public static void main(String[] args) {
 
        Empresa dados = new Empresa();
        dados.cria_Empresa();
                 
        int op;
        int qtd=0;
         
        do{
            System.out.println("Digite a opção:");
            System.out.println("1 - Adicionar funcinário\n2 - Mostrar Funcionários\n3 - Sair");
            op = new Scanner(System.in).nextInt();
            if(op==1){//Adicionar
                //ler dados
                dados.adiciona(qtd);
                qtd++;
            }
            else if(op==2){//Mostrar
                dados.mostraEmpregados(qtd);
            }
        }while(op==1||op==2);
    }   
}