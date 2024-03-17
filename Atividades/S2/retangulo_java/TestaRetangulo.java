import java.lang.Math;
public class TestaRetangulo{
    public static void main(String[] args){
        Retangulo r1 = new Retangulo();
        Retangulo r2 = new Retangulo();
        r2.setAltura(10);
        System.out.println(r2.getAltura());
        r2.criaRetangulo(2, 45.0);
        System.out.println(r2.getAltura());
        System.out.println(Math.tan(45.0) * 2);
        //pq tg de 45 retorna 1.6197751905438615?
        
    }
}

