package programa;

import java.util.GregorianCalendar;

class Data{
    int dia;
    int mes;
    int ano;
    int validade=0;

    Data(Integer dia, Integer mes, Integer ano) {
        GregorianCalendar date = new GregorianCalendar();
        date.setLenient(false);
        date.set(ano, mes, dia);
        try {
            date.getTime();
            this.dia = dia;
            this.mes = mes;
            this.ano = ano;
            this.validade = 1;
        } catch (Exception e){
            System.out.println("Data inválida");
            System.out.println("Digite novamente:\n");
            this.validade = 0;
        }
    }

    Data(){}
}