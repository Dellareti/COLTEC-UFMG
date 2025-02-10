package programa;
  
import java.util.Scanner;
  
class Funcionario {
    private String nome ;
    private String departamento ;
    private double salario;
    Data dataDeEntrada = new Data();
    private String rg;
    private int identificador;
    private static int totalfuncionarios=0;
      
    Funcionario(){
        System.out.println("\n\nCriando Funcionario!\n");
        Funcionario.totalfuncionarios = Funcionario.totalfuncionarios + 1;
    }  
    
    Funcionario(String nome){
        this.nome = nome;
        Funcionario.totalfuncionarios = Funcionario.totalfuncionarios + 1;
    }
    
    public void getmostra(){
        System.out.println("\nNome:\t" + this.nome);
        System.out.println("Identificador:\t" +this.identificador);
        System.out.println("Departamento:\t" + this.departamento);
        System.out.println("Salário:\t" + this.salario);
        System.out.print("Data:\t" + this.dataDeEntrada.dia);
        System.out.print("/"+ this.dataDeEntrada.mes);
        System.out.println("/"+ this.dataDeEntrada.ano);
        System.out.println("RG:\t" + this.rg);
        System.out.println("");
    }
      
    public void setpreencher(){
        System.out.println("Digite o nome:");
        this.nome = new Scanner(System.in).next();
        System.out.println("Digite o departamento:");
        this.departamento = new Scanner(System.in).next();
        System.out.println("Digite o salário:");
        this.salario = new Scanner(System.in).nextDouble();
        System.out.println("Digite o dia/mes/ano:");
        
        int verifica=0;
        Data dt;
        do{
            this.dataDeEntrada.dia = new Scanner(System.in).nextInt();
            this.dataDeEntrada.mes = new Scanner(System.in).nextInt();
            this.dataDeEntrada.ano = new Scanner(System.in).nextInt();

            dt = new Data(this.dataDeEntrada.dia,this.dataDeEntrada.mes,this.dataDeEntrada.ano);
        
        }while(dt.validade==0);
                        
        System.out.println("Digite o RG:");
        this.rg = new Scanner(System.in).next();
        this.identificador = this.getTotalFuncionarios();
    }
        
    public int getcomparar(Funcionario b){
        if(this.nome.equals(b.nome) && this.departamento.equals(b.nome) && this.salario == b.salario && this.dataDeEntrada.dia == b.dataDeEntrada.dia && this.dataDeEntrada.mes == b.dataDeEntrada.mes && this.dataDeEntrada.ano == b.dataDeEntrada.ano && this.rg.equals(b.rg))
            return 1;
        else
            return 0;
    }
    
    public static int getTotalFuncionarios(){
        return Funcionario.totalfuncionarios;
    }
}