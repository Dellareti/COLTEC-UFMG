/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula14;

/**
 *
 * @author Leandro
 */
public class TestaEmpresa {
    
    public static void main (String[] args) {
        
        // Novo funcionário f1
        Funcionario f1 = new Funcionario();
        
        // Atualizando as informações do funcionário
        f1.nome = "Leandro";
        f1.RG = "12345678";
        f1.departamento = "Informatica";
        f1.salario = 937.00;
        f1.dataEntrada = new Data();
        f1.dataEntrada.dia = 20;
        f1.dataEntrada.mes = 1;
        f1.dataEntrada.ano = 2010;
        
        // Novo funcionário f2
        Funcionario f2 = new Funcionario();
        
        // Atualizando as informações do funcionário
        f2.nome = "Virginia";
        f2.RG = "01234567";
        f2.departamento = "Informatica";
        f2.salario = 937.00;
        f2.dataEntrada = new Data();
        f2.dataEntrada.dia = 20;
        f2.dataEntrada.mes = 8;
        f2.dataEntrada.ano = 2014;
        
        // Nova empresa
        Empresa emp1 = new Empresa();
        emp1.nome = "Coltec";
        emp1.CNPJ = "123456789/0001-23";
        emp1.adiciona(f1);
        emp1.adiciona(f2);
        
        emp1.mostraEmpregados();
                
        
    }
    
}
