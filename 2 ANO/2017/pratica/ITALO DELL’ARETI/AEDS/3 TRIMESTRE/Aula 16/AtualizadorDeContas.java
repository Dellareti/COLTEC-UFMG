package aula16;

public  class  AtualizadorDeContas {
    private  double  saldoTotal = 0;
    private  double  selic;
    
    public  AtualizadorDeContas(double  selic) {
        this.selic = selic;
    }
    public void roda(Conta c){
        System.out.println(c.getSaldo());
        c.depositar(12);
        System.out.println(c.getSaldo());
        this.saldoTotal=c.getSaldo();
    }

    public double getSaldoTotal() {
        return saldoTotal;
    }
}
