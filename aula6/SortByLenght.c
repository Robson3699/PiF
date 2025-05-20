#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char *frase;
} Name;

typedef struct {
    char *palavra;
} Palavra;

int tam;
Palavra *palavras = NULL;

int comp(Palavra *a, Palavra *b) {
    return strlen(b->palavra) - strlen(a->palavra);
}

void SortByLength() {
    Palavra aux;
    for (int i = 1; i < tam; ++i) {
        int j = i, k = j - 1;
        while (k > -1 && comp(&palavras[j], &palavras[k]) < 0) {
            aux = palavras[j];
            palavras[j] = palavras[k];
            palavras[k] = aux;
            --j, --k;
        }
    }
}

int main() {
    int N;
    char frase[MAX];

    scanf("%d\n", &N);
    Name *nomes = malloc(N * sizeof(Name));
    if (!nomes) {
        fprintf(stderr, "Erro de alocação\n");
        return 1;
    }

    for (int k = 0; k < N; ++k) {
        fgets(frase, MAX, stdin);
        frase[strcspn(frase, "\n")] = 0;  // Remove o '\n'

        nomes[k].frase = malloc(strlen(frase) + 1);
        if (!nomes[k].frase) {
            fprintf(stderr, "Erro de alocação para frase\n");
            return 1;
        }
        strcpy(nomes[k].frase, frase);

        // Reset da lista de palavras
        tam = 0;
        free(palavras);
        palavras = malloc(MAX * sizeof(Palavra));
        if (!palavras) {
            fprintf(stderr, "Erro de alocação para palavras\n");
            return 1;
        }

        // Separar palavras
        char *ptr = strtok(frase, " ");
        while (ptr != NULL) {
            palavras[tam].palavra = malloc(strlen(ptr) + 1);
            if (!palavras[tam].palavra) {
                fprintf(stderr, "Erro de alocação para palavra\n");
                return 1;
            }
            strcpy(palavras[tam].palavra, ptr);
            tam++;
            ptr = strtok(NULL, " ");
        }

        SortByLength();

        printf("%s", palavras[0].palavra);
        for (int i = 1; i < tam; ++i) {
            printf(" %s", palavras[i].palavra);
        }
        printf("\n");

        // Libera palavras após o uso
        for (int i = 0; i < tam; ++i) {
            free(palavras[i].palavra);
        }
    }

    // Libera memória final
    free(palavras);
    for (int i = 0; i < N; ++i) {
        free(nomes[i].frase);
    }
    free(nomes);

    return 0;
}