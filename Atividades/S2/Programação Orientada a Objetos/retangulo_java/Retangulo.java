public class Retangulo{
    private int altura;
    private int largura;

public void setAltura(int altura){
    this.altura = altura;
}

public int getAltura()
{
    return this.altura;
}

public void setLargura(int largura)
{
    this.largura = largura;
}

public int getLargura()
{
    return this.largura;
}

public void criaRetangulo(int altura, int largura){

    this.altura = altura;
    this.largura = largura;

}

public void criaRetangulo(int largura, double angulo){
    this.largura = largura;
    this.altura = (int) (Math.tan(angulo) * (double) this.largura);

}

public void criaRetangulo(double angulo, int diagonal){
    this.altura = (int) (Math.sin(angulo) * (double)diagonal); //precisaria usar this nesse método? mesmo altura e largura não sendo parâmetros?
    this.largura = (int) (Math.cos(angulo) * (double)diagonal);
}

public void criaRetangulo(double altura, double diagonal){
    this.altura = (int) altura;
    this.largura = (int) (Math.sqrt(Math.pow((int) diagonal, 2) - Math.pow(altura, 2)));
}
}