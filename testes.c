#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main(){

    int c;
    printf("\ndigite um numero para hexadecimal: ");
    scanf("%d", &c);
    printf("\n %x",c);

    printf("\ndigite um numero para decimal: ");
    scanf("%x", &c);
    printf("\n %d",c);
    
    char cc;

    printf("\ndigite uma letra para hexadecimal: ");
    scanf("%s", &cc);
    printf("\n %x",cc);
    
    
    printf("\ndigite caracteres para decimal: ");
    scanf("%s", &cc);
    printf("\n %d",cc);
    
    return 0;
}

