public class TestaLampada{
    public static void main(String[] args){
        Lampada l1 = new Lampada();
        l1.ligar(l1.getLigada());
        l1.mostrarStatus(l1.getLigada());
        System.out.println(l1);
    }
}