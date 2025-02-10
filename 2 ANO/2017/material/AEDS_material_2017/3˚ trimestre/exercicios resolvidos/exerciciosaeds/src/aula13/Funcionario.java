/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula13;

/**
 *
 * @author maiab
 */
class Funcionario {
    
    String nome;
    String RG;
    String departamento;
    double salario;
    // String dataEntrada; // Versão 1 de data
    Data dataEntrada;
    
    /**
     * Método que imprime no dispositivo de saída padrão o valor de todos
     * os atributos do funcionário.
     */
    void mostra() {
        System.out.printf("Nome........: %s\n"   , this.nome);
        System.out.printf("RG..........: %s\n"   , this.RG);
        System.out.printf("Departamento: %s\n"   , this.departamento);
        System.out.printf("Salario.....: %3.2f\n", this.salario);
        // System.out.printf("Data Entrada: %s\n"   , this.dataEntrada); // Versão 1 de data
        String dataEntradaString = (this.dataEntrada == null ? "null" : this.dataEntrada.getData());
        System.out.printf("Data Entrada: %s\n"   , dataEntradaString); // Versão 2 de data
        System.out.println("-------------------------------------------------");
    }
    
    /**
     * Método de teste.
     * @param args Argumentos passados pela linha de comando.
     */
    public static void main(String[] args){
        
        // Novo funcionário f1
        Funcionario f1 = new Funcionario();
        f1.mostra();
        
        // Atualizando as informações do funcionário
        f1.nome = "Leandro";
        f1.RG = "12345678";
        f1.departamento = "Informatica";
        f1.salario = 937.00;
        // f1.dataEntrada =  "20/01/2010"; // Versão 1 de data
        f1.dataEntrada = new Data();
        f1.dataEntrada.dia = 20;
        f1.dataEntrada.mes = 1;
        f1.dataEntrada.ano = 2010;
        f1.mostra();
        
        // Novo funcionário f2
        Funcionario f2 = new Funcionario();
        f2.mostra();
        
        // Atualizando as informações do funcionário
        f2.nome = "Leandro";
        f2.RG = "12345678";
        f2.departamento = "Informatica";
        f2.salario = 937.00;
        // f2.dataEntrada = "20/01/2010"; // Versão 1 de data
        f2.dataEntrada = new Data();
        f2.dataEntrada.dia = 20;
        f2.dataEntrada.mes = 1;
        f2.dataEntrada.ano = 2010;
        f2.mostra();    
        
        // São iguais
        System.out.println("F1 == F2? " + (f1 == f2));
        
        // Nova referência para o funcionário f1
        Funcionario f1NR = f1;

        // São iguais
        System.out.println("F1 == F1NR? " + (f1 == f1NR));
    
    }
    
}
