#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// utilize:     ./ordenador --help
// para entender oque o sistema faz

int comparar_numeros(const void *a, const void *b) {
    double num1 = *(double*)a;
    double num2 = *(double*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

void exibir_ajuda() {
    printf("\nOrdenador de Numeros\n");
    printf("Uso: ./ordenador <num1> <num2> <num3> ...\n");
    printf("Exemplo: ./ordenador 5.2 3 10 1.7 8\n\n");
    printf("Este programa ordena os numeros fornecidos em ordem crescente.\n");
    printf("Voce pode fornecer numeros inteiros ou decimais.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Erro: Nenhum numero fornecido para ordenacao.\n");
        exibir_ajuda();
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        exibir_ajuda();
        return 0;
    }

    double *numeros = (double*)malloc((argc - 1) * sizeof(double));
    if (numeros == NULL) {
        printf("Erro: Falha ao alocar memoria.\n");
        return 1;
    }

    printf("\nProcessando %d numero(s) fornecido(s):\n", argc - 1);
    
    for (int i = 1; i < argc; i++) {
        char *endptr;
        numeros[i-1] = strtod(argv[i], &endptr);
        
        if (*endptr != '\0') {
            printf("Aviso: O argumento '%s' nao e um numero valido e sera ignorado.\n", argv[i]);
            numeros[i-1] = 0;
        } else {
            printf("   Numero %d: %g\n", i, numeros[i-1]);
        }
    }

    qsort(numeros, argc - 1, sizeof(double), comparar_numeros);

    printf("\nNumeros ordenados (crescente):\n");
    for (int i = 0; i < argc - 1; i++) {
        printf("%g ", numeros[i]);
    }
    printf("\n\n");

    free(numeros);

    printf("Ordenacao concluida com sucesso!\n");
    printf("Obrigado por usar o Ordenador de Numeros.\n\n");

    return 0;
}