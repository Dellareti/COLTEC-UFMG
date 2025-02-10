package programa;
import java.util.Scanner;
class Empresa {
    private String nome;
    private String cnpj;
    Funcionario[] empregados = new Funcionario[3];
    int funcionariosEmpresa=0;
  
    public void setcria_Empresa(){
        System.out.println("Digite o nome da Empresa:");
        this.nome = new Scanner(System.in).next();
        System.out.println("Digite o cnpj:");
        this.cnpj = new Scanner(System.in).next();
    }
      
    public void adiciona(){
        Funcionario f = new Funcionario();
         
        if(this.funcionariosEmpresa==this.empregados.length){//realocar
            Funcionario[] empregados2 = new Funcionario[this.funcionariosEmpresa*2];     
            System.arraycopy(empregados,0,empregados2,0,this.empregados.length);
            empregados = empregados2;
        }
         
        f.setpreencher();
        this.empregados[this.funcionariosEmpresa] = f;
        this.funcionariosEmpresa++;
    }
  
    public void getmostraEmpregados(){
        System.out.println("\n\nEmpresa:\t" + this.nome);
        System.out.println("CNPJ:\t" + this.cnpj);
        for(int i=0;i<this.funcionariosEmpresa;i++){
        //    System .out . println ("Funcionário na posição : " + i);
            this.empregados[i].getmostra();
        }
    }
}