/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula15;

import aula14.*;

/**
 *
 * @author maiab
 */
public class Data {
    
    /// Atributos de data
    private int dia;
    private int mes;
    private int ano;
    
    /// Número de dias de cada mês
    private static final int NUMERO_DIAS_MES_ANO_NAO_BISSEXTO[] = {
      31, 28, 31, 30, 31, 30, 31, 31,30 , 31, 30, 31
    };
    private static final int NUMERO_DIAS_MES_ANO_BISSEXTO[] = {
      31, 29, 31, 30, 31, 30, 31, 31,30 , 31, 30, 31
    };
    
    /**
     * Método que obtem o dia na data.
     * @return Dia.
     */
    int getDia() {
        return this.dia;
    }
    
    /**
     * Método que obtem o mês na data.
     * @return Mês.
     */
    int getMes() {
        return this.mes;
    }
    
    /**
     * Método que obtem o ano na data.
     * @return Ano.
     */
    int getAno() {
        return this.ano;
    }
    
    /**
     * Método que define a data.
     * @param dia Dia na data.
     * @param mes Mês na data.
     * @param ano Ano na data.
     */
    boolean setData(int dia, int mes, int ano) {
        
        // Verifica se o mês está na faixa correta
        if (mes < 1 || mes > 12) return false;
        
        // Verifica se o ano é bissexto
        boolean anoMultiplo4   = ((ano % 4) == 0);
        boolean anoMultiplo100 = ((ano % 100) == 0);
        boolean anoMultiplo400 = ((ano % 400) == 0);
        boolean bissexto = (anoMultiplo400) || (anoMultiplo4 && !anoMultiplo100);
        
        // Verifica se o dia está correto
        int nDiasMes = (bissexto ? NUMERO_DIAS_MES_ANO_BISSEXTO[mes - 1] :
                                   NUMERO_DIAS_MES_ANO_NAO_BISSEXTO[mes - 1]);
        if (dia < 1 || dia > nDiasMes) return false;
        
        // Se chegou até esse ponto, então a data está correta.        
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
        return true;
    }
    
    /**
     * Método que obtem a string representando a data no formado dd/mm/yyyy.
     * @return String com a data.
     */
    String getDataFormatada() {
        return String.format("%02d/%02d/%04d", getDia(), getMes(), getAno());
    }
    
}
