#include <stdio.h>

int main(){
	int n;
	int count = 0;
	
	printf("Insira um valor: ");
	scanf("%d", &n);
	
	for(int i = 0; i<=n; i++){
		for(int j = 0; j<=i; j++){
			count++;
			printf("%d ", count);
				
		}	
		printf("\n");
	}



return 0;
}
