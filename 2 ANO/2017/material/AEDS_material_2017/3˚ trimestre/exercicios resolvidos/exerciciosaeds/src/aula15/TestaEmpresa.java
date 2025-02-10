/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula15;

/**
 *
 * @author Leandro
 */
public class TestaEmpresa {
    
    public static void main (String[] args) {
        
        // Novo funcionário f1
        Funcionario f1 = new Funcionario("Leandro");
        f1.mostra();
        
        // Atualizando as informações do funcionário
        f1.setRG("12345678");
        f1.setDepartamento("Informatica");
        f1.setSalario(937.00);
        Data dataEntradaF1 = new Data();
        dataEntradaF1.setData(20, 1, 2010);
        f1.setDataEntrada(dataEntradaF1);
        f1.mostra();
        
        // Novo funcionário f2
        Funcionario f2 = new Funcionario();
        f2.mostra();
        
        // Atualizando as informações do funcionário
        f2.setNome("Virginia");
        f2.setRG("01234567");
        f2.setDepartamento("Informatica");
        f2.setSalario(937.00);
        Data dataEntradaF2 = new Data();
        dataEntradaF2.setData(20, 8, 2014);
        f2.setDataEntrada(dataEntradaF2);
        f2.mostra();
        
        // Nova empresa
        Empresa emp1 = new Empresa();
        emp1.setNome("Coltec");
        emp1.setCNPJ("123456789/0001-23");
        emp1.adiciona(f1);
        emp1.adiciona(f2);
        
        emp1.mostraEmpregados();                        
    }
    
}
