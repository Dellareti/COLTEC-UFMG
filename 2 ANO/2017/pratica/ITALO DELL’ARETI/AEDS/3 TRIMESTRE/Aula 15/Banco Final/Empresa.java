package Banco;

import java.util.Scanner;

public class Empresa {
    private String nome;
    private String cnpj;
    private int qtd_funcionarios = 0;
    private Funcionario[] empregados;

    public Empresa() {
        this.empregados = new Funcionario[2];
    }
    
    void add_funcionario(){
        if(this.qtd_funcionarios==empregados.length){
            Funcionario[] empregados2 = new Funcionario[qtd_funcionarios*2];     
            System.arraycopy(empregados,0,empregados2,0,this.empregados.length);
            empregados = empregados2;
        }
        
        
        System.out.println("Nome:");
        String nome = new Scanner(System.in).next();
        System.out.println("Departamento:");
        String dep = new Scanner(System.in).next();
        System.out.println("Salario:");
        double sal = new Scanner(System.in).nextDouble();
        System.out.println("RG:");
        String rg = new Scanner(System.in).next();
        System.out.println("Data entrada:");
        int dia = new Scanner(System.in).nextInt();    
        int mes = new Scanner(System.in).nextInt();    
        int ano = new Scanner(System.in).nextInt();    
        
        this.empregados[qtd_funcionarios] = new Funcionario(nome,dep,sal,rg,dia,mes,ano);
        this.qtd_funcionarios++;
    }
    void mostraEmpregados(){
        for(int i=0; i<qtd_funcionarios;i++){
            System.out.println("------------------");
            System.out.println("Nome:"+this.empregados[i].getNome());
            System.out.println("Departamento:"+this.empregados[i].getDepartamento());
            System.out.println("Salario:"+this.empregados[i].getSalario());
            System.out.println("RG:"+this.empregados[i].getRg());
            System.out.println("DATA ENTRADA:"+this.empregados[i].getDataDeEntrada().getDia()+
                    "/"+this.empregados[i].getDataDeEntrada().getMes()+"/"+
                    this.empregados[i].getDataDeEntrada().getAno());
            System.out.println("ID:"+this.empregados[i].getId());
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getQtd_funcionarios() {
        return qtd_funcionarios;
    }
}