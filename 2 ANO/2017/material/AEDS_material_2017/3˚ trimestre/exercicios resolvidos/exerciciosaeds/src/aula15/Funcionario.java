/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula15;

/**
 *
 * @author maiab
 */
public class Funcionario {
    
    /// Atributos de funcionário
    private String nome;
    private String RG;
    private String departamento;
    private double salario;
    private Data dataEntrada;
    private int ID;
    
    /// Atributos da classe funcionário
    private static int ultimoIDFuncionario = 0;
    
    /* ------------------------ Construtores ---------------------------------*/
    
    /**
     * Construtor de funcionário que não define o nome do funcionário.
     */
    public Funcionario() {
        this("");
    }
    
    /**
     * Construtor de funcionário que espera o nome do funcionário.
     * @param nome Nome do funcionário.
     */
    public Funcionario(String nome) {
        this.ID = ++ultimoIDFuncionario;
        this.nome = nome;
    }
    
    /* ------------------------- Gets e Sets ---------------------------------*/
    
    /**
     * Método que retorna o ID do funcionário.
     * @return ID do funcionário.
     */
    public int getID() {
        return this.ID;
    }

    /**
     * Método que obtem o nome do funcionario
     * @return Nome do funcionário.
     */
    public String getNome() {
        return nome;
    }

    /**
     * Método que define o nome do funcionário.
     * @param nome Nome do funcionário.
     */
    public void setNome(String nome) {
        this.nome = nome;
    }

    /**
     * Método que obtem o RG do funcionário.
     * @return RG do funcionário.
     */
    public String getRG() {
        return RG;
    }

    /**
     * Método que define o RG do funcionário.
     * @param RG RG do funcionário.
     */
    public void setRG(String RG) {
        this.RG = RG;
    }

    /**
     * Método que obtem o departamento ao qual o funcionário pertence.
     * @return Departamento do funcionário.
     */
    public String getDepartamento() {
        return departamento;
    }

    /**
     * Método que define o departamento do funcionário.
     * @param departamento Departamento do funcionário.
     */
    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    /**
     * Método que obtem o salário do funcionário.
     * @return Salário do funcionário.
     */
    public double getSalario() {
        return salario;
    }

    /**
     * Método que define o salário do funcionário.
     * @param salario Salário do funcionário.
     */
    public void setSalario(double salario) {
        this.salario = salario;
    }

    /**
     * Método que retorna a data de entrada do funcionário.
     * @return Data de entrada do funcionário.
     */
    public Data getDataEntrada() {
        if (this.dataEntrada == null) return null;
        Data dataClone = new Data();
        dataClone.setData(this.dataEntrada.getDia(),
                          this.dataEntrada.getMes(),
                          this.dataEntrada.getAno());
        return dataClone;
    }

    /**
     * Método que define a data de entrada do funcionário.
     * @param dataEntrada Data de entrada do funcionário.
     */
    public void setDataEntrada(Data dataEntrada) {
        this.dataEntrada = new Data();
        this.dataEntrada.setData(dataEntrada.getDia(),
                                 dataEntrada.getMes(),
                                 dataEntrada.getAno());
    }
    
    /* --------------------------- Métodos -----------------------------------*/
    
    /**
     * Método que imprime no dispositivo de saída padrão o valor de todos
     * os atributos do funcionário.
     */
    void mostra() {
        System.out.printf("ID..........: %d\n"   , getID());
        System.out.printf("Nome........: %s\n"   , getNome());
        System.out.printf("RG..........: %s\n"   , getRG());
        System.out.printf("Departamento: %s\n"   , getDepartamento());
        System.out.printf("Salario.....: %3.2f\n", getSalario());
        String dataEntradaString = (getDataEntrada() == null ? "null" : getDataEntrada().getDataFormatada());
        System.out.printf("Data Entrada: %s\n"   , dataEntradaString); // Versão 2 de data
        System.out.println("-------------------------------------------------");
    }
    
}