package Estatisticas;

public class Main {
    
    public static void main(String[] args) {
// Cria casa
         Casa minhaCasa = new Casa(2);
      
// Cria porta 
         Porta novaPorta = new Porta("aberta");

// Adiciona valor boleano diretamente ao atributo class Porta
         novaPorta.aberta = true;
      
// Utiliza de um metódo class Porta (somente para demonstração)
         novaPorta.estaAberta();

         // Valores originais atributos class Casa
         minhaCasa.cor = "Amarelo";
      
// Modificando os valores metódos class Casa
         minhaCasa.pinta("Branco");
         minhaCasa.adicionaPorta(novaPorta);	
         minhaCasa.quantasPortasEstaoAbertas();
         minhaCasa.totalDePortas();
      }
   }
