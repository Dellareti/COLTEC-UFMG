package Banco;
public class Principal {
    public static void main(String[] args) {
    /*
        Conta minhaConta,conta2;
        minhaConta = new Conta () ;
        conta2 = new Conta () ;
        minhaConta.titular.nome = "Maria";
        minhaConta.saldo = 1000;
        conta2.titular.nome = "ABC";
        conta2.saldo = 15;
        
        System.out.println("Saldo atual: " + minhaConta .saldo ); 
        minhaConta.saca(300);
        System.out.println("Saldo atual: " + minhaConta .saldo ); 
        
        if(conta2.trans(minhaConta,10));
    
        System.out.println("Saldo atual: " + minhaConta .saldo ); 
        System.out.println("Saldo atual: " + conta2.saldo ); 
    */
        Funcionario newb = new Funcionario("nebs",10);
        Funcionario newbie = new Funcionario("noob",1);
        newbie.setNome("joao");
        System.out.println("Done");
        System.out.println(newb.comparar(newbie));
    }
}