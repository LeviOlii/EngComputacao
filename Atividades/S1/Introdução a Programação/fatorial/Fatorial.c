#include <stdio.h>

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i = n - 1; i>=1; i--){
        n = n*i;
    }
    
    printf("\n%d", n);
    
    return 0;
}



