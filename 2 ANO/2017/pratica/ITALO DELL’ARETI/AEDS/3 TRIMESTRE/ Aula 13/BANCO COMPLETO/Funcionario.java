package Banco;

import java.util.Scanner;

public class Funcionario {
    String nome;
    String  departamento;
    double salario;
    String rg;
    Data dataDeEntrada = new Data();
    void mostra(){
        System.out.println("Funcionario:");
        System.out.println(this.nome);
        System.out.println(this.departamento);
        System.out.println(this.salario);
        System.out.println(this.rg);
        System.out.println(this.dataDeEntrada.dia+" "+this.dataDeEntrada.mes+" "+this.dataDeEntrada.ano);
    }
    void preenche(){
        this.nome = new Scanner(System.in).next();
        this.departamento = new Scanner(System.in).next();
        this.salario = new Scanner(System.in).nextDouble();
        this.rg = new Scanner(System.in).next();
        this.dataDeEntrada.dia = new Scanner(System.in).nextInt();    
        this.dataDeEntrada.mes = new Scanner(System.in).nextInt();    
        this.dataDeEntrada.ano = new Scanner(System.in).nextInt();    
    }
    boolean comparar(Funcionario b){
        if(this.nome.equals(b.nome) && this.departamento.equals(b.departamento) && this.rg.equals(b.rg) && this.salario==b.salario && this.dataDeEntrada.dia==b.dataDeEntrada.dia && this.dataDeEntrada.mes==b.dataDeEntrada.mes && this.dataDeEntrada.ano==b.dataDeEntrada.ano)
            return true;
        else 
            return false;
    }
}