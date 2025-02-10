package testebar;
public class Cliente {
    private String nome;
    private String endereco;
    private String cpf;
    private String email;
    Utils dados;

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

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        if(this.dados.validaCPF(cpf))
            this.cpf = cpf;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        if(this.dados.validaEmail(email))
            this.email = email;
    }
    
    public void cria(){
        this.nome="Lucas";
        this.endereco = "Street Milk";
        this.setCpf("14401001505");
        this.setEmail("lucaspaulom@hotmail.com");
    } 
}