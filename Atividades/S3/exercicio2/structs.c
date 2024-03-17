/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Ponto2D{
    float x;
    float y;
}Ponto2D;

//Calcula a distância entre dois pontos de duas structs Ponto2D
double distanciaPontos(Ponto2D *p1, Ponto2D *p2){
    double dx = (double) fabs(p1->x - p2->x);
    double dy = (double) fabs(p1->y - p2->y);
    
    return sqrt(dx * dx + dy * dy);
}

//Calcula o ponto médio de dois pontos 2D retornando um Ponto2D
Ponto2D pontoMedio(Ponto2D *p1, Ponto2D *p2){
    double dx = (double) (p1->x + p2->x)/2;
    double dy = (double) (p1->y + p2->y)/2;
    
    Ponto2D p3 = {dx, dy};
    
    return p3;
}

//Funçao anterior, mas retorna um ponteiro com uma area alocada dinamicamente para a resposta da funçao
Ponto2D *pontoMedioAlocado(Ponto2D *p1, Ponto2D *p2){
    double dx = (double) (p1->x + p2->x)/2;
    double dy = (double) (p1->y + p2->y)/2;
    
    Ponto2D *p3 = (Ponto2D *) malloc(sizeof(Ponto2D));
    p3->x = dx;
    p3->y = dy;
    
    
    return p3;
}


int main()
{
    Ponto2D p1 = {10, 5};
    Ponto2D p2 = {8, 4};
    double distancia = distanciaPontos(&p1, &p2);
    printf("Distância entre: p1(%.2f, %.2f), p2(%.2f, %.2f) = %.2f\n", p1.x, p1.y, p2.x, p2.y, distancia);


    Ponto2D p3 = pontoMedio(&p1, &p2);
    printf("\nPonto médio entre: p1(%.2f, %.2f), p2(%.2f, %.2f) = pontoMedio(%.2f, %.2f)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    
    
    Ponto2D *p4;
    p4 = pontoMedioAlocado(&p1, &p2);
    printf("\nPonto médio com alocação dinâmica entre: p1(%.2f, %.2f), p2(%.2f, %.2f) = pontoMedio(%.2f, %.2f)", p1.x, p1.y, p2.x, p2.y, p4->x, p4->y);
    free(p4);

    return 0;
}

