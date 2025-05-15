#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *slug;
    int tam;
} Slugs;

void Velo(Slugs slug) {
    int h = 0;
    for (int i = 0; i < slug.tam; i++) {
        if (slug.slug[i] > h) {
            h = slug.slug[i];
        }
    }

    if (h < 10) {
        printf("1\n");
    } else if (h < 20) {
        printf("2\n");
    } else {
        printf("3\n");
    }
}

int main() {
    Slugs slug;

    while (scanf("%d", &slug.tam) != EOF) {
        slug.slug = malloc(slug.tam * sizeof(int));
        for (int i = 0; i < slug.tam; i++) {
            scanf("%d", &slug.slug[i]);
        }

        Velo(slug);
        free(slug.slug); 
    }

    return 0;
}