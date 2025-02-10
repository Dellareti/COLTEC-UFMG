package Banco;

import java.util.GregorianCalendar;

public class Data {
    int dia,mes,ano;

    public Data(int dia, int mes, int ano) {
        GregorianCalendar date = new GregorianCalendar();
        date.setLenient(false);
        date.set(ano, mes, dia);
        try {
            date.getTime();
            this.dia = dia;
            this.mes = mes;
            this.ano = ano;
        } catch (Exception e){
            System.out.println("Data invalida!");
        }
    }
    
    
    public int getDia() {
        return dia;
    }

    public int getMes() {
        return mes;
    }

    public int getAno() {
        return ano;
    }


} 