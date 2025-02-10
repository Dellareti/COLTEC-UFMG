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
class Casa {
    
    /// Atributos de casa
    String cor;
    int totalDePortas = 0;
    Porta[] portas;
    
    /// Controle do array de portas
    int incrementoArray = 10;
    
    
    /**
     * Pinta a casa na cor desejada.
     * @param cor Cor desejada.
     */
    void pinta(String cor) {
        this.cor = cor;
    }
    
    /**
     * Método que retorna quantas portas estão abertas.
     * @return Número de portas abertas.
     */
    int quantasPortasEstaoAbertas() {
        
        // Se não tem portas, então nenhuma está aberta
        if (this.portas == null) {
            return 0;
        }
        
        // Vou iterar em todas as portas, independente da quantidade
        // Eu poderia utilizar a quantidade, mas vou fazer um FOR
        // de outra forma
        int nPortasAbertas = 0;
        for(Porta p : this.portas) {
            if (p == null) continue;
            
            if (p.portaAberta) nPortasAbertas++;
        }
        
        // Retorna o número de portas abertas
        return nPortasAbertas;
    }
    
    /**
     * Método que retorna o número total de portas da casa.
     * @return Total de portas da casa.
     */
    int totalDePortas() {
        return this.totalDePortas;
    }
    
    /**
     * Método que adiciona uma porta na lista de portas da casa
     * @param porta Porta a ser adicionada.
     */
    void adicionaPorta(Porta porta) {
        
        // Verifica se já possui a lista de empregados
        if (this.portas == null) {
            this.portas = new Porta[incrementoArray];
        }
        
        // Verifica se o array já está completo
        if (totalDePortas >= this.portas.length) {
            
            // Crio um novo array que caiba tudo que tinha antes + incremento
            Porta[] novoArrayPortas = new Porta[this.portas.length + 
                                                incrementoArray];
            
            // Transfiro todas as referências para o novo array
            this.totalDePortas = 0;
            for(Porta p : this.portas) {
                novoArrayPortas[this.totalDePortas++] = p;
            }
            
            // Atualizo a referência do objeto
            this.portas = novoArrayPortas;
        }
        
        // Adiciono a porta na próxima posição livre
        this.portas[this.totalDePortas++] = porta;        
        
    }
    
    public static void main(String[] args) {
        
        // Criando a casa
        Casa c = new Casa();
        c.pinta("Branco");
        
        // Criando a porta 1 da casa e abrindo
        Porta p1 = new Porta();
        p1.abre();
        
        // Criando a porta 2 da casa e fechando
        Porta p2 = new Porta();
        p2.fecha();
        
        // Criando a porta 3 da casa e fechando
        Porta p3 = new Porta();
        p3.abre();
        
        // Adiciona as portas na casa.
        c.adicionaPorta(p1);
        c.adicionaPorta(p2);
        c.adicionaPorta(p3);
        
        // Situal atual da casa
        System.out.printf("Cor da casa: %-10s\nPortas abertas: %02d de %02d\n",c.cor,c.quantasPortasEstaoAbertas(),c.totalDePortas);
        
        // Brincando com as portas
        p1.fecha();

        // Situal atual da casa
        System.out.printf("Cor da casa: %-10s\nPortas abertas: %02d de %02d\n",c.cor,c.quantasPortasEstaoAbertas(),c.totalDePortas);

        // Brincando com as portas
        p3.fecha();

        // Situal atual da casa
        System.out.printf("Cor da casa: %-10s\nPortas abertas: %02d de %02d\n",c.cor,c.quantasPortasEstaoAbertas(),c.totalDePortas);
        
        // Brincando com as portas
        p2.abre();

        // Situal atual da casa
        System.out.printf("Cor da casa: %-10s\nPortas abertas: %02d de %02d\n",c.cor,c.quantasPortasEstaoAbertas(),c.totalDePortas);
        
    }
    
    
    
}
