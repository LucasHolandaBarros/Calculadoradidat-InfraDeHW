/**
 * Criado dia 23 de Agosto de 2024
 * Autor: Lucas de Holanda de Barros Soares - 3° Período | Turma B
 * Questão 1 -> Data: 25/08/2024 | Horário: 10:06:53
 * Questão 2 -> Data: 25/08/2024 | Horário: 11:28:22
 * Questão 3 -> Data: 29/08/2024 | Horário: 21:16:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void parabase2(int numero);
void parabase8(int numero);
void parabase16(int numero);
void paracodeBCD(int numero);
void complementoa2(int numero);
void parafloat(float numero);
void paradouble(double numero);

int main(){
    int opcao1, opcao2, opcao3;

    printf("\nCalculadora Didatica de Conversao\n\n=================================\n\nOpcoes:\n\n(1) - De base 10 para:\n\n(2) - De base 10 para base 2 com sinal e 16 bits, (complemento a 2)\n\n(3) - Converter real em decimal para float ou double\n\nSua escolha: ");
    scanf("%d", &opcao2);

    if(opcao2 == 1){
        int valor;
        printf("\nCalculadora Didatica de Conversao\n\n=================================\n\nOpcoes:\n\n(1) - De base 10 para base 2\n\n(2) - De base 10 para base 8\n\n(3) - De base 10 para base 16\n\n(4) - De base 10 para codigo BCD\n\nSua escolha: ");
        scanf("%d", &opcao1);

        if(opcao1 == 1){
            printf("\nDigite um valor na base 10 para converter para base 2:\n");
            scanf("%d", &valor);
            printf("\nResultado de %d na base 2:\n", valor);
            parabase2(valor);
        }else if(opcao1 == 2){
            printf("\nDigite um valor na base 10 para converter para base 8:\n");
            scanf("%d", &valor);
            printf("\nResultado de %d na base 8:\n", valor);
            parabase8(valor);
        }else if(opcao1 == 3){
            printf("\nDigite um valor na base 10 para converter para base 16:\n");
            scanf("%d", &valor);
            printf("\nResultado de %d na base 16:\n", valor);
            parabase16(valor);
        }else if(opcao1 == 4){
            printf("\nDigite um valor na base 10 para converter para codigo BCD:\n");
            scanf("%d", &valor);
            printf("\nResultado de %d em codigo BCD:\n", valor);
            paracodeBCD(valor);
        }
    }else if(opcao2 == 2){
        int valor;
        printf("\nDigite o valor que voce deseja transformar para base 2 com sinal com 16 bits: ");
        scanf("%d", &valor);
        printf("\nResultado de %d em Complemento a 2:\n", valor);
        complementoa2(valor);
    }else if(opcao2 == 3){
        float valor1;
        double valor2;
        printf("\nCalculadora Didatica de Conversao\n\n=================================\n\nOpcoes:\n\n(1) - De Real em Decimal para Float\n\n(2) - De Real em Decimal para Double\n\nSua escolha: ");
        scanf("%d", &opcao3);
        if(opcao3 == 1){
            printf("\nDigite um valor real em decimal para transformar em float: ");
            scanf("%f", &valor1);
            parafloat(valor1);
        }else if(opcao3 == 2){
            printf("\nDigite um valor real em decimal para transformar em double: ");
            scanf("%lf", &valor2);
            paradouble(valor2);
        }
    }

    return 0;
}

void parabase2(int numero){
    int binario[32];
    int i = 0;
    while(numero > 0){
        binario[i] = numero%2;
        printf("\nDivisao de %d por 2", numero);
        printf("\nResto a ser adicionado: %d", binario[i]);
        numero = numero/2;
        i++;
    }
    printf("\n\nInvertendo: ");
    for(int j = i-1; j >= 0; j--){
        printf("%d", binario[j]);
    }
}

void parabase8(int numero){
    int octal[32];
    int j = 0;
    while(numero > 0){
        octal[j] = numero%8;
        printf("\nDivisao de %d por 8", numero);
        printf("\nResto a ser adicionado: %d", octal[j]);
        numero = numero/8;
        j++;
    }
    printf("\n\nInvertendo: ");
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
        printf("\nDivisao de %d por 16", numero);
        if(resto == 10){
            hexadecimal[k] = 'A';
            printf("\nResto a ser adicionado: 10 = %c", hexadecimal[k]);
        }else if(resto == 11){
            hexadecimal[k] = 'B';
            printf("\nResto a ser adicionado: 11 = %c", hexadecimal[k]);
        }else if(resto == 12){
            hexadecimal[k] = 'C';
            printf("\nResto a ser adicionado: 13 = %c", hexadecimal[k]);
        }else if(resto == 13){
            hexadecimal[k] = 'D';
            printf("\nResto a ser adicionado: 14 = %c", hexadecimal[k]);
        }else if(resto == 14){
            hexadecimal[k] = 'E';
            printf("\nResto a ser adicionado: 15 = %c", hexadecimal[k]);
        }else if(resto == 15){
            hexadecimal[k] = 'F';
            printf("\nResto a ser adicionado: 16 = %c", hexadecimal[k]);
        }else{
            hexadecimal[k] = resto + 48;
            printf("\nResto a ser adicionado: %c", hexadecimal[k]);
        }
        numero = numero/16;
        k++;
    }
    printf("\n\nInvertendo: ");
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
            printf("\n0 em binario = 0000");
            strcpy(temp, "0000");
        }else if(divisao == 1){
            printf("\n1 em binario = 0001");
            strcpy(temp, "0001");
        }else if(divisao == 2){
            printf("\n2 em binario = 0010");
            strcpy(temp, "0010");
        }else if(divisao == 3){
            printf("\n3 em binario = 0011");
            strcpy(temp, "0011");
        }else if(divisao == 4){
            printf("\n4 em binario = 0100");
            strcpy(temp, "0100");
        }else if(divisao == 5){
            printf("\n5 em binario = 0101");
            strcpy(temp, "0101");
        }else if(divisao == 6){
            printf("\n6 em binario = 0110");
            strcpy(temp, "0110");
        }else if(divisao == 7){
            printf("\n7 em binario = 0111");
            strcpy(temp, "0111");
        }else if(divisao == 8){
            printf("\n8 em binario = 1000");
            strcpy(temp, "1000");
        }else if(divisao == 9){
            printf("\n9 em binario = 1001");
            strcpy(temp, "1001");
        }
        temp2[p] = temp;
        numero = numero/10;
        p++;
    }
    printf("\n\nInvertendo e Juntando: ");
    p = p - 1;
    while(p >= 0){
        printf("%s ", temp2[p]);
        free(temp2[p]);
        p--;
    }
}

void complementoa2(int numero){
    char comp[16];
    int i = 0, guarda;
    int numabs = abs(numero);
    if(numero < 0){
        while(numabs > 0){
            comp[i] = numabs%2;
            printf("\nDivisao de %d por 2", numabs);
            printf("\nResto a ser adicionado: %d", comp[i]);
            numabs = numabs/2;
            i++;
        }while(i < 16){
            comp[i] = 0;
            i++;
        }
        printf("\n\nMontando em binario:\n");
        for(int h = i-1; h >= 0; h--){
            printf("%d", comp[h]);
        }
        for(int j = i-1; j >= 0; j--){
            if(comp[j] == 1){
                guarda = j;
            }
        }
        for(int k = i-1; k > guarda; k--){
            if(comp[k] == 1){
                comp[k] = 0;
            }else{
                comp[k] = 1;
            }
        }
        printf("\n\nInvertendo os numeros ate o ultimo um: ");
        for(int p = i-1; p >= 0; p--){
            printf("%d", comp[p]);
        }
    }else{
        while(numero > 0){
            comp[i] = numero%2;
            printf("\nDivisao de %d por 2", numero);
            printf("\nResto a ser adicionado: %d", comp[i]);
            numero = numero/2;
            i++;
        }while(i < 16){
            comp[i] = 0;
            i++;
        }
        printf("\n\nInvertendo: ");
        for(int j = i-1; j >= 0; j--){
            printf("%d", comp[j]);
        }
    }
}

void parafloat(float numero){
    char bitsinal;
    int bisa = 0;
    int binario1[32];
    int binario2[32];
    int binario3[32];
    int i = 0;
    int j = 0;
    int posicaoDoUltimoUm;
    int numdecint;
    if(numero < 0){
        bitsinal = 1;
        printf("\nJa que o numero eh negativo:\n");
        printf("Bit de sinal = 1\n");
    }else{
        bitsinal = 0;
        printf("\nJa que o numero eh positivo:\n");
        printf("Bit de sinal = 0\n");
    }
    printf("\nTransformando a parte inteira em binario:\n");
    numero = fabs(numero);
    int numinteiro = (int)numero;
    float numdeci = numero - numinteiro;
    while(numinteiro > 0){
        binario1[i] = numinteiro%2;
        printf("\nDivisao da parte inteira %d por 2", numinteiro);
        printf("\nResto a ser adicionado: %d", binario1[i]);
        numinteiro = numinteiro/2;
        i++;
    }
    printf("\n\nResultado:\n");
    for(int a = i-1; a >= 0; a--){
        printf("%d", binario1[a]);
    }
    printf("\n\nTransformando a parte decimal em binario:\n");
    while(numdeci != 0){
        printf("\nMultiplicacao da parte decimal %.4f por 2", numdeci);
        numdeci = numdeci*2;
        numdecint = (int)numdeci;
        binario2[j] = numdecint;
        printf("\nParte inteira a ser adicionada: %d", binario2[j]);
        numdeci = numdeci - numdecint;
        j++;
    }while(j < 23){
        binario2[j] = 0;
        j++;
    }
    printf("\n\nResultado:\n");
    for(int b = 0; b < j; b++){
        printf("%d", binario2[b]);
    }
    printf("\n\nNumero Binario:\n");
    for(int a = i-1; a >= 0; a--){
        printf("%d", binario1[a]);
    }
    printf(".");
    for(int b = 0; b < j; b++){
        printf("%d", binario2[b]);
    }
    printf("\n\n");
    printf("Numero em notacao cientifica:\n1.");
    for(int a = i-2; a >= 0; a--){
        printf("%d", binario1[a]);
    }
    for(int b = 0; b < j; b++){
        printf("%d", binario2[b]);
    }
    for(int t = 0; t < i; t++){
        if(binario1[t] == 1){
            posicaoDoUltimoUm = t;
        }
    }
    printf(" x 2^%d\n\n", (i-posicaoDoUltimoUm)+2);
    while(j < (23-posicaoDoUltimoUm)){
        binario2[j] = 0;
        j++;
    }

    int biased = 127 + posicaoDoUltimoUm;

    printf("Calculo do BIASED (Representacao Enviesada do Expoente):\n");
    printf("%d + %d = %d", (i-posicaoDoUltimoUm)+2, 127, biased);
    printf("\n\n");

    printf("Convertendo o BIASED em binario:\n");

    while(biased > 0){
        binario3[bisa] = biased%2;
        printf("\nDivisao da parte inteira %d por 2", biased);
        printf("\nResto a ser adicionado: %d", binario3[bisa]);
        biased = biased/2;
        bisa++;
    }

    printf("\n\nResultado do Expoente: ");
    for(int j = bisa-1; j >= 0; j--){
        printf("%d", binario3[j]);
    }
    printf("\n\n");

    printf("Juntando os resultados: [Bit de Sinal] [Expoente] [Fracao]\n\n");

    printf("Resultado: ");
    printf("%d", bitsinal);
    printf(" ");
    for(int j = bisa-1; j >= 0; j--){
        printf("%d", binario3[j]);
    }
    printf(" ");
    for(int j = posicaoDoUltimoUm-1; j >= 0; j--){
        printf("%d", binario1[j]);
    }
    for(int p = 0; p < j; p++){
        printf("%d", binario2[p]);
    }
    
}

void paradouble(double numero){
    char bitsinal;
    int bisa = 0;
    int binario1[64];
    int binario2[64];
    int binario3[64];
    int i = 0;
    int j = 0;
    int posicaoDoUltimoUm;
    int numdecint;
    if(numero < 0){
        printf("\nJa que o numero eh negativo:\n");
        printf("Bit de sinal = 1\n");
        bitsinal = 1;
    }else{
        printf("\nJa que o numero eh positivo:\n");
        printf("Bit de sinal = 0\n");
        bitsinal = 0;
    }
    printf("\nTransformando a parte inteira em binario:\n");
    numero = fabs(numero);
    int numinteiro = (int)numero;
    double numdeci = numero - numinteiro;
    while(numinteiro > 0){
        binario1[i] = numinteiro%2;
        printf("\nDivisao da parte inteira %d por 2", numinteiro);
        printf("\nResto a ser adicionado: %d", binario1[i]);
        numinteiro = numinteiro/2;
        i++;
    }
    printf("\n\nResultado:\n");
    for(int a = i-1; a >= 0; a--){
        printf("%d", binario1[a]);
    }
    printf("\n\nTransformando a parte decimal em binario:\n");
    while(numdeci != 0){
        printf("\nMultiplicacao da parte decimal %.4f por 2", numdeci);
        numdeci = numdeci*2;
        numdecint = (int)numdeci;
        binario2[j] = numdecint;
        printf("\nParte inteira a ser adicionada: %d", binario2[j]);
        numdeci = numdeci - numdecint;
        j++;
    }while(j < 52){
        binario2[j] = 0;
        j++;
    }
    printf("\n\nResultado:\n");
    for(int b = 0; b < j; b++){
        printf("%d", binario2[b]);
    }
    printf("\n\nNumero Binario:\n");
    for(int a = i-1; a >= 0; a--){
        printf("%d", binario1[a]);
    }
    printf(".");
    for(int b = 0; b < j; b++){
        printf("%d", binario2[b]);
    }
    printf("\n\n");
    printf("Numero em notacao cientifica:\n1.");
    for(int a = i-2; a >= 0; a--){
        printf("%d", binario1[a]);
    }
    for(int b = 0; b < j; b++){
        printf("%d", binario2[b]);
    }
    for(int t = 0; t < i; t++){
        if(binario1[t] == 1){
            posicaoDoUltimoUm = t;
        }
    }
    printf(" x 2^%d\n\n", posicaoDoUltimoUm);
    while(j < (52-posicaoDoUltimoUm)){
        binario2[j] = 0;
        j++;
    }

    int biased = 1023 + posicaoDoUltimoUm;

    printf("Calculo do BIASED (Representacao Enviesada do Expoente):\n");
    printf("%d + %d = %d", posicaoDoUltimoUm, 1023, biased);
    printf("\n\n");

    printf("Convertendo o BIASED em binario:\n");

    while(biased > 0){
        binario3[bisa] = biased%2;
        printf("\nDivisao da parte inteira %d por 2", biased);
        printf("\nResto a ser adicionado: %d", binario3[bisa]);
        biased = biased/2;
        bisa++;
    }
    printf("\n\nResultado do Expoente: ");
    for(int j = bisa-1; j >= 0; j--){
        printf("%d", binario3[j]);
    }
    printf("\n\n");

    printf("Juntando os resultados: [Bit de Sinal] [Expoente] [Fracao]\n\n");

    printf("Resultado: ");
    printf("%d", bitsinal);
    printf(" ");
    for(int j = bisa-1; j >= 0; j--){
        printf("%d", binario3[j]);
    }
    printf(" ");
    for(int j = posicaoDoUltimoUm-1; j >= 0; j--){
        printf("%d", binario1[j]);
    }
    for(int p = 0; p < j; p++){
        printf("%d", binario2[p]);
    }
    
}