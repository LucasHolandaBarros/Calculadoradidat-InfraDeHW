#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parabase2(int numero);
void parabase8(int numero);
void parabase16(int numero);
void paracodeBCD(int numero);

int main(){
    int opcao1, opcao2;
    int valor;

    printf("\nCalculadora Didatica de Conversao\n\n=================================\n\nOpcoes:\n\n(1) - De base 10 para:\n\n(2) - De base 10 para base com sinal e 16 bits, (complemento a 2)\n\n(3) - Converter real em decimal para float e double\n\nSua escolha: ");
    scanf("%d", &opcao2);

    if(opcao2 == 1){
        printf("\nCalculadora Didatica de Conversao\n\n=================================\n\nOpcoes:\n\n(1) - De base 10 para base 2\n\n(2) - De base 10 para base 8\n\n(3) - De base 10 para base 16\n\n(4) - De base 10 para codigo BCD\n\nSua escolha: ");
        scanf("%d", &opcao1);

        if(opcao1 == 1){
            printf("\nDigite um valor na base 10 para converter para base 2:\n");
            scanf("%d", &valor);
            printf("Resultado de %d na base 2: ", valor);
            parabase2(valor);
        }else if(opcao1 == 2){
            printf("\nDigite um valor na base 10 para converter para base 8:\n");
            scanf("%d", &valor);
            printf("Resultado de %d na base 8: ", valor);
            parabase8(valor);
        }else if(opcao1 == 3){
            printf("\nDigite um valor na base 10 para converter para base 16:\n");
            scanf("%d", &valor);
            printf("Resultado de %d na base 16: ", valor);
            parabase16(valor);
        }else if(opcao1 == 4){
            printf("\nDigite um valor na base 10 para converter para codigo BCD:\n");
            scanf("%d", &valor);
            printf("Resultado de %d em codigo BCD: ", valor);
            paracodeBCD(valor);
        }
    }else if(opcao2 == 2){
        
    }

    return 0;
}

void parabase2(int numero){
    int binario[32];
    int i = 0;
    while(numero > 0){
        binario[i] = numero%2;
        numero = numero/2;
        i++;
    }
    for(int j = i-1; j >= 0; j--){
        printf("%d", binario[j]);
    }
}

void parabase8(int numero){
    int octal[32];
    int j = 0;
    while(numero > 0){
        octal[j] = numero%8;
        numero = numero/8;
        j++;
    }
    for(int k = j-1; k >= 0; k--){
        printf("%d", octal[k]);
    }
}

void parabase16(int numero){
    char hexadecimal[32];
    int resto;
    int k = 0;
    while(numero > 0){
        resto = numero%16;
        if(resto == 10){
            hexadecimal[k] = 'A';
        }else if(resto == 11){
            hexadecimal[k] = 'B';
        }else if(resto == 12){
            hexadecimal[k] = 'C';
        }else if(resto == 13){
            hexadecimal[k] = 'D';
        }else if(resto == 14){
            hexadecimal[k] = 'E';
        }else if(resto == 15){
            hexadecimal[k] = 'F';
        }else{
            hexadecimal[k] = resto + 48;
        }
        numero = numero/16;
        k++;
    }
    for(int l = k-1; l >= 0; l--){
        printf("%c", hexadecimal[l]);
    }

}

void paracodeBCD(int numero){
    char *temp2[10];
    int divisao;
    int p = 0;
    while(numero > 0){
        char *temp = (char *)malloc(5 * sizeof(char));
        divisao = numero%10;
        if(divisao == 0){
            strcpy(temp, "0000");
        }else if(divisao == 1){
            strcpy(temp, "0001");
        }else if(divisao == 2){
            strcpy(temp, "0010");
        }else if(divisao == 3){
            strcpy(temp, "0011");
        }else if(divisao == 4){
            strcpy(temp, "0100");
        }else if(divisao == 5){
            strcpy(temp, "0101");
        }else if(divisao == 6){
            strcpy(temp, "0110");
        }else if(divisao == 7){
            strcpy(temp, "0111");
        }else if(divisao == 8){
            strcpy(temp, "1000");
        }else if(divisao == 9){
            strcpy(temp, "1001");
        }
        temp2[p] = temp;
        numero = numero/10;
        p++;
    }
    p = p - 1;
    while(p >= 0){
        printf("%s ", temp2[p]);
        free(temp2[p]);
        p--;
    }
}