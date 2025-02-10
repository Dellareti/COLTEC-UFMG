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
    
}

/**
 * TERRÍVEL ISSO AQUI! Essa classe Empresa deveria estar em um arquivo
 * separado, mas estou seguindo o exercício.
 * @author maiab
 */
class Empresa {
    
    /// Atributos de empresa
    String nome;
    String CNPJ;
    Funcionario[] empregados;
    
    /// Controle do array de funcionarios
    int proxPosicaoLivre = 0;
    int incrementoArray = 10;
    
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
            
            System.out.printf("Func. Pos %02d: Nome: %-20s / Salario: R$ %9.2f\n", i, f.nome, f.salario);
        }
        
    }
    
}