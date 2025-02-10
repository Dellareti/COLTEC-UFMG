public class Ex1 {
    public static void main(String[] args) {
        Casa house = new Casa();
        house.pinta("vermelho");
        house.add(new Porta());
        house.add(new Porta());
        house.add(new Porta());
        System.out.println(house.total());
        System.out.println(house.portasAbertas());
    }
}
