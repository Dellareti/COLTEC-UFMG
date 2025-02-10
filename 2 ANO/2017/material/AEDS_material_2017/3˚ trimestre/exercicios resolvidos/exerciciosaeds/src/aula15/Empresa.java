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
public class Empresa {
    
    /// Atributos de empresa
    private String nome;
    private String CNPJ;
    private Funcionario[] empregados;
    
    /// Controle do array de funcionarios
    private int proxPosicaoLivre = 0;
    private final int incrementoArray = 10;
    
    /* ------------------------- Gets e Sets ---------------------------------*/

    /**
     * Método que obtem o nome da empresa.
     * @return Nome da empresa.
     */
    public String getNome() {
        return nome;
    }

    /**
     * Método que define o nome da empresa.
     * @param nome Nome da empresa.
     */
    public void setNome(String nome) {
        this.nome = nome;
    }

    /**
     * Método que obtem o CNPJ da empresa.
     * @return CNPJ da empresa.
     */
    public String getCNPJ() {
        return CNPJ;
    }

    /**
     * Método que define o CNPJ da empresa.
     * @param CNPJ CNPJ da empresa.
     */
    public void setCNPJ(String CNPJ) {
        this.CNPJ = CNPJ;
    }
    
    /* --------------------------- Métodos -----------------------------------*/
    
    /**
     * Método que adiciona um funcionário na lista de empregados da empresa.
     * @param funcionario 
     */
    void adiciona(Funcionario funcionario) {
        
        // Verifica se já possui a lista de empregados
        if (empregados == null) {
            this.empregados = new Funcionario[incrementoArray];
        }
        
        // Verifica se o array já está completo
        if (proxPosicaoLivre >= this.empregados.length) {
            
            // Crio um novo array que caiba tudo que tinha antes + incremento
            Funcionario[] novoArrayFuncionario = new Funcionario[this.empregados.length + 
                                                                 incrementoArray];
            
            // Transfiro todas as referências para o novo array
            this.proxPosicaoLivre = 0;
            for(Funcionario f : this.empregados) {
                novoArrayFuncionario[this.proxPosicaoLivre++] = f;
            }
            
            // Atualizo a referência do objeto
            this.empregados = novoArrayFuncionario;
        }
        
        // Adiciono o funcionário na próxima posição livre
        this.empregados[this.proxPosicaoLivre++] = funcionario;
        
    }
    
    /**
     * Método que imprime as informações dos funcionários da empresa.
     */
    void mostraEmpregados() {
        
        // Passa por todos os funcionários adicionados na lista de empregados
        // da empresa e mostra sua posição no array e seu salário
        for(int i=0; i < this.proxPosicaoLivre; i++) {
            Funcionario f = this.empregados[i];
            
            System.out.printf("Func. Pos %02d: Nome: %-20s / Salario: R$ %9.2f\n", i, f.getNome(), f.getSalario());
        }
        
    }
 }
