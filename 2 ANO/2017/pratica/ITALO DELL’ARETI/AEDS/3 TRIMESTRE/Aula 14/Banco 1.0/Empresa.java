package Banco;

public class Empresa {
    String nome;
    String cnpj;
    int qtd_funcionarios = 0;
    Funcionario[] empregados = new Funcionario[2];
    
    void add_funcionario(){
        if(this.qtd_funcionarios==empregados.length){
            Funcionario[] empregados2 = new Funcionario[qtd_funcionarios*2];     
            System.arraycopy(empregados,0,empregados2,0,this.empregados.length);
            empregados = empregados2;
        }
        
        this.empregados[qtd_funcionarios] = new Funcionario();
        this.qtd_funcionarios++;
    }
    void mostraEmpregados(){
        for(int i=0; i<qtd_funcionarios;i++){
            System.out.println("pos "+ i);
            System.out.println(this.empregados[i].nome);
            System.out.println(this.empregados[i].salario);
        }
    }
}