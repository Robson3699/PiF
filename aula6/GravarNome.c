#include <stdio.h>
#include <string.h>

int main() {
    float pt[3];
    char nome[20];
    FILE *arquivo;

    arquivo = fopen("notas.txt", "w");
    for (int i = 0; i < 3; i++) {
        printf("Digite o Nome:");
        printf("\n");
        scanf("%19s", nome);
        printf("Digite a Nota:");
        printf("\n");
        for(int j=0;j<3;j++){
        scanf("%f", &pt[j]);
        }
        fprintf(arquivo, "%s %f %f %f\n", nome, pt[0],pt[1],pt[2]);
    }
   fclose(arquivo);

    
    arquivo = fopen("notas.txt", "r");
    while (fscanf(arquivo, "%19s %f %f %f", nome, &pt[0],&pt[1],&pt[2] ) == 4) {
        float med=(pt[0]+pt[1]+pt[2])/3;
        printf("%s %f %f %f media: %f\n", nome, pt[0], pt[1],pt[2] ,med);
    }
    fclose(arquivo);

    return 0;
}