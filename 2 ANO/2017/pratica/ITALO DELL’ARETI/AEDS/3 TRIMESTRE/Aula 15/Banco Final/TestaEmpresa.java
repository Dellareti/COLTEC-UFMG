/*        Comp.add_funcionario("A",10);
        Comp.add_funcionario("B",15);
        Comp.add_funcionario("C",20);
        Comp.add_funcionario("D",25);
        Comp.add_funcionario("E",30);
        Comp.add_funcionario("F",35);
        Comp.add_funcionario("G",40);
        Comp.mostraEmpregados();
  */

package Banco;

import java.util.Scanner;

public class TestaEmpresa {
    public static void main(String[] args) {
        Empresa Comp = new Empresa();
        int c;
        do{
            System.out.println("--------------\nDigite 1 para adicionar um funcionario\n"
                    + "Digite 2 para adicionar listar os funcionario\n"
                    + "Digite 0 para sair\n"
                    + "--------------");
            c = new Scanner(System.in).nextInt();
            if(c==1){
                Comp.add_funcionario(); 
            }
            else if(c==2){
                Comp.mostraEmpregados();
            }
        }while(c!=0);

    }
}
