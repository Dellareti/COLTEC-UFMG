package programa;
 
import java.util.Scanner;
 
class Funcionario {
    String nome ;
    String departamento ;
    double salario;
    Data dataDeEntrada = new Data();
    String rg;
     
     
    void mostra(){
        System.out.println("\n\nFuncionário:\n");
        System.out.println("Nome:" + this.nome);
        System.out.println("Departamento:" + this.departamento);
        System.out.println("Salário:" + this.salario);
        System.out.print("Data:" + this.dataDeEntrada.dia);
        System.out.print("/"+ this.dataDeEntrada.mes);
        System.out.println("/"+ this.dataDeEntrada.ano);
        System.out.println("RG:" + this.rg);
    }
     
    void preencher(){
        System.out.println("Digite o nome:");
        this.nome = new Scanner(System.in).next();
        System.out.println("Digite o departamento:");
        this.departamento = new Scanner(System.in).next();
        System.out.println("Digite o salário:");
        this.salario = new Scanner(System.in).nextDouble();
        System.out.println("Digite o dia/mes/ano:");
        this.dataDeEntrada.dia = new Scanner(System.in).nextInt();
        this.dataDeEntrada.mes = new Scanner(System.in).nextInt();
        this.dataDeEntrada.ano = new Scanner(System.in).nextInt();
        System.out.println("Digite o RG:");
        this.rg = new Scanner(System.in).next();
 
    }
     
    int comparar(Funcionario b){
        if(this.nome.equals(b.nome) && this.departamento.equals(b.nome) && this.salario == b.salario && this.dataDeEntrada.dia == b.dataDeEntrada.dia && this.dataDeEntrada.mes == b.dataDeEntrada.mes && this.dataDeEntrada.ano == b.dataDeEntrada.ano && this.rg.equals(b.rg))
            return 1;
        else
            return 0;
    }
}