public class Lampada{
    private boolean ligada;

    public void setLigada(boolean ligada){
        this.ligada = ligada;
    }
    
    public boolean getLigada(){
        return this.ligada;
    }

    public void ligar(boolean ligada){
        this.ligada = true;
    }

    public void desligar(boolean ligada){
        this.ligada = false;
    }

    public void mostrarStatus(boolean ligada){
        if (this.ligada == true){
            System.out.println("A lampada está ligada");
        }else{
            System.out.println("A lâmpada está desligada");
        }
    }

    @Override
    public String toString()
    {
        return "Status da Lâmpada:  " + this.ligada;
    }
}