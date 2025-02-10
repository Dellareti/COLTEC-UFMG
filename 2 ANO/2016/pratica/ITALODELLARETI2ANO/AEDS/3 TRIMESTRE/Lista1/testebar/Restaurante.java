package testebar;
public class Restaurante {
    private String nome;
    private String endereco;
    Mesa[] mesas = new Mesa[10];
    int n_clientes=0;
    
    public void inicializa(){
        for(int i=0;i<10;i++){
            this.mesas[i] = new Mesa();
            this.mesas[i].inicializa();
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
}