package Banco;

import java.util.Scanner;

public class Funcionario {
    private String nome;
    private String  departamento;
    private double salario;
    private String rg;
    private int id;
    private static int qtd;
    private Data dataDeEntrada;
    Funcionario(){
        qtd++;
        id=qtd;
    }
    Funcionario(String nome,String dep,double salario,String rg,int d,int m,int a){
        this.nome=nome;
        this.departamento=dep;
        this.salario=salario;
        this.rg=rg;
        this.dataDeEntrada = new Data(d,m,a);
        qtd++;
        id=qtd;
    }
    void mostra(){
        System.out.println("Funcionario:");
        System.out.println(this.nome);
        System.out.println(this.departamento);
        System.out.println(this.salario);
        System.out.println(this.rg);
        System.out.println(this.dataDeEntrada.dia+" "+this.dataDeEntrada.mes+" "+this.dataDeEntrada.ano);
    }

    public String getDepartamento() {
        return departamento;
    }

    public String getRg() {
        return rg;
    }

    public static int getQtd() {
        return qtd;
    }

    public Data getDataDeEntrada() {
        return dataDeEntrada;
    }
    boolean comparar(Funcionario b){
        if(this.nome.equals(b.nome) && this.departamento.equals(b.departamento) && this.rg.equals(b.rg) && this.salario==b.salario && this.dataDeEntrada.dia==b.dataDeEntrada.dia && this.dataDeEntrada.mes==b.dataDeEntrada.mes && this.dataDeEntrada.ano==b.dataDeEntrada.ano)
            return true;
        else 
            return false;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    public int getId(){
        return this.id;
    }
    
}