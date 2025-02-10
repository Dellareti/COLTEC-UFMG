package projeto;

import java.util.Scanner;

public class Projeto {
    public static void main(String[] args) {  
       
        System.out.print("Quantos contatos terá na agenda:\t");
        int qtd = new Scanner(System.in).nextInt();
        Agenda a = new Agenda(qtd);
        
        System.out.println("Quantidade de amigos:" + a.qtd_amigos);

        a.addinformacoes();
    
        a.imprimeAniversarios();
        a.imprimeEmail();
    }
}