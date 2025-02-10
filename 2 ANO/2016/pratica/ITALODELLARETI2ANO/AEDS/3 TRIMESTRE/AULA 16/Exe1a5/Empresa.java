package programa;
import java.util.Scanner;
class Empresa {
    String nome;
    String cnpj;
    Funcionario[] empregados = new Funcionario[3];
 
    void cria_Empresa(){
        System.out.println("Digite o nome da Empresa:");
        this.nome = new Scanner(System.in).next();
        System.out.println("Digite o cnpj:");
        this.cnpj = new Scanner(System.in).next();
     
        for(int i=0;i<3;i++){
            empregados[i] = new Funcionario();
        }
    }
     
    void adiciona(int qtd){
        Funcionario f = new Funcionario();
        
        if(qtd==this.empregados.length){//realocar
            Funcionario[] empregados2 = new Funcionario[qtd*2];     
            System.arraycopy(empregados,0,empregados2,0,this.empregados.length);
            empregados = empregados2;
        }
        
        f.preencher();
        this.empregados[qtd] = f;
    }
 
    void mostraEmpregados(int qtd){
        for(int i=0;i<qtd;i++){
            System .out . println ("Funcionário na posição : " + i);
            this.empregados[i].mostra();
        }
    }
}