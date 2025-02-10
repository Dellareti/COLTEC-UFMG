/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula14;

/**
 *
 * @author maiab
 */
class Data {
    
    /// Atributos de data
    int dia;
    int mes;
    int ano;
    
    /**
     * Método que obtem a string representando a data no formado dd/mm/yyyy.
     * @return String com a data.
     */
    String getData() {
        return String.format("%02d/%02d/%04d", this.dia, this.mes, this.ano);
    }
    
}
