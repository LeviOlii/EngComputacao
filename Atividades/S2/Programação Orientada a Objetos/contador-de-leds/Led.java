import java.util.Scanner;

public class Led{
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        String leds = sc.nextLine();
        int soma = 0;
        int num_leds = leds.length();
        int vetor[] = new int[leds.length()];
        for(int i = 0; i<leds.length(); i++)
        {
            vetor[i] = Character.getNumericValue(leds.charAt(i));
        }
        
        
        for(int i = 0; i<leds.length(); i++)
        {
            switch(vetor[i])
            {
                case 0:
                case 6:
                case 9:
                soma = soma + 6;
                break;
                
                case 1:
                soma = soma + 2;
                break; 
                
                case 2:
                case 3:
                case 5:
                soma = soma + 5;    
                break;
                
                case 4:
                soma = soma + 4;
                break;
                
                case 7:
                soma = soma + 3;
                break;
                
                case 8:
                soma = soma + 7;
                break;
                
                default:
                System.out.println("Tah errado!");
                soma = 0;
                i = 0;
                break;
            }

        }
        System.out.println("A contagem de leds eh: " + soma);
    }
}
