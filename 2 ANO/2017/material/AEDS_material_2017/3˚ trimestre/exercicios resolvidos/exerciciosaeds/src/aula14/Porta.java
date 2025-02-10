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
class Porta {
    
    /// Atributos de porta
    boolean portaAberta;
    
    /**
     * Método que abre a porta.
     */
    void abre() {
        this.portaAberta = true;
    }
    
    /**
     * Método que fecha a porta.
     */
    void fecha() {
        this.portaAberta = false;
    }
    
}
