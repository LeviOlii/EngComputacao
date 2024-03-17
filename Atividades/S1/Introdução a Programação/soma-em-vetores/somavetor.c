#include <stdio.h>

int main(){
	int n;
	int soma = 0;

	printf("Quantas notas você deseja informar?: ");
	scanf("%d", &n);
	int notas[n];

	for(int i = 0; i<n; i++){
		printf("\nInsira o valor: ");
		scanf("%d", &notas[i]);
	}

	for(int i = 0; i<n; i++){
		soma = soma + notas[i];
	}

	printf("\nSoma = %d", soma);

return 0;
}
