/**
 * main.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGURA 24
#define ALTURA 20

char mapa[ALTURA][LARGURA + 1] = {
    "########################",
    "#@       #      #     #",
    "# ###### ###### # ### #",
    "# #    #      # #   # #",
    "# # ## ###### # ### # #",
    "# # #        #     #  #",
    "# # # ########### ####",
    "#   #       #        #",
    "##### ##### # ###### #",
    "#     #   # #      # #",
    "# #### # # ###### # ##",
    "#      # #        #  #",
    "###### ### ######### #",
    "#        #         # #",
    "# ######## ######  # #",
    "#        #      #    #",
    "# ###### ###### ######",
    "#      &       #     #",
    "#  ##########  #####S#",
    "########################"
};

int x1_pos = 1, y1_pos = 1;   // Jogador 1 (@)
int x2_pos = 7, y2_pos = 17;  // Jogador 2 (&)

int turno = 1;

int desafioLogico(char jogador) {
    int a = rand() % 2;
    int b = rand() % 2;
    int c = rand() % 2;
    int d = rand() % 2;
    int resultado, resposta;
    int tipo = rand() % 20;  // Agora temos 20 desafios diferentes!

    printf("\n[%c] DESAFIO LÓGICO:\n", jogador);

    switch (tipo) {
        case 0:
            printf("Quanto é %d && %d ? ", a, b);
            resultado = a && b;
            break;
        case 1:
            printf("Quanto é %d || %d ? ", a, b);
            resultado = a || b;
            break;
        case 2:
            printf("Quanto é !%d ? ", a);
            resultado = !a;
            break;
        case 3:
            printf("Quanto é (%d && %d) || %d ? ", a, b, c);
            resultado = (a && b) || c;
            break;
        case 4:
            printf("Quanto é (%d || %d) && !%d ? ", a, b, c);
            resultado = (a || b) && !c;
            break;
        case 5:
            printf("Quanto é !((%d || %d) && (!%d || %d)) ? ", a, b, c, d);
            resultado = !((a || b) && (!c || d));
            break;
        case 6:
            printf("Quanto é (%d && (%d || %d)) ? ", a, b, c);
            resultado = (a && (b || c));
            break;
        case 7:
            printf("Quanto é !(%d && %d) ? ", a, b);
            resultado = !(a && b);
            break;
        case 8:
            printf("Quanto é !(%d || %d) ? ", a, b);
            resultado = !(a || b);
            break;
        case 9:
            printf("Quanto é ((!%d || %d) && (%d && !%d)) ? ", a, b, c, d);
            resultado = ((!a || b) && (c && !d));
            break;
        case 10:
            printf("Quanto é !!%d ? ", a);
            resultado = !!a;
            break;
        case 11:
            printf("Quanto é (%d && !%d) || (!%d && %d) ? ", a, b, c, d);
            resultado = (a && !b) || (!c && d);
            break;
        case 12:
            printf("Quanto é (%d || !%d) && (%d || !%d) ? ", a, b, c, d);
            resultado = (a || !b) && (c || !d);
            break;
        case 13:
            printf("Quanto é !(%d || (%d && !%d)) ? ", a, b, c);
            resultado = !(a || (b && !c));
            break;
        case 14:
            printf("Se a=%d, b=%d: a é verdadeiro e b é falso? ", a, b);
            resultado = a && !b;
            break;
        case 15:
            printf("Se c=%d, d=%d: c ou d são verdadeiros? ", c, d);
            resultado = c || d;
            break;
        case 16:
            printf("Verdadeiro se (a=%d e b=%d) forem falsos. ", a, b);
            resultado = !a && !b;
            break;
        case 17:
            printf("Verdadeiro se apenas um entre a=%d e b=%d for verdadeiro. ", a, b);
            resultado = (a || b) && !(a && b);  // XOR
            break;
        case 18:
            printf("Quanto é (a && b) == (!c || d)? com a=%d b=%d c=%d d=%d: ", a, b, c, d);
            resultado = (a && b) == (!c || d);
            break;
        case 19:
            printf("Quanto é !(a && (!b || c))? com a=%d b=%d c=%d: ", a, b, c);
            resultado = !(a && (!b || c));
            break;
        default:
            resultado = 0;
    }

    scanf("%d", &resposta);
    while (getchar() != '\n'); // limpa o buffer
    return resposta == resultado;
}


void desenhaMapa() {
    system("clear"); // use "cls" no Windows
    for (int y = 0; y < ALTURA; y++) {
        for (int x = 0; x < LARGURA; x++) {
            if (y == y1_pos && x == x1_pos) printf("1");
            else if (y == y2_pos && x == x2_pos) printf("2");
            else printf("%c", mapa[y][x]);
        }
        printf("\n");
    }
}

int podeMover(int x, int y) {
    return mapa[y][x] == ' ' || mapa[y][x] == 'S';
}

int chegouNaSaida(int x, int y) {
    return mapa[y][x] == 'S';
}

char lerTecla() {
    char c = getchar();
    while (getchar() != '\n'); // limpa o buffer
    return c;
}

int main() {
    srand(time(NULL));
    char tecla;

    while (1) {
        desenhaMapa();
        printf("\nTurno do Jogador %d (%c)\n", turno, turno == 1 ? '@' : '&');
        printf("Controles: %s\n", turno == 1 ? "WASD" : "IJKL");
        printf("Digite a tecla de movimento: ");

        tecla = lerTecla();

        int novoX, novoY;

        if (turno == 1) {
            novoX = x1_pos;
            novoY = y1_pos;
            if (tecla == 'w') novoY--;
            else if (tecla == 's') novoY++;
            else if (tecla == 'a') novoX--;
            else if (tecla == 'd') novoX++;
            else continue;

            if (!desafioLogico('@')) {
                printf("Resposta errada! Turno perdido.\nPressione Enter para continuar...");
                getchar();
                turno = 2;
                continue;
            }

            if (podeMover(novoX, novoY)) {
                x1_pos = novoX;
                y1_pos = novoY;
                if (chegouNaSaida(x1_pos, y1_pos)) {
                    desenhaMapa();
                    printf("\n🏁 Jogador 1 venceu!\n");
                    break;
                }
            }
            turno = 2;
        } else {
            novoX = x2_pos;
            novoY = y2_pos;
            if (tecla == 'i') novoY--;
            else if (tecla == 'k') novoY++;
            else if (tecla == 'j') novoX--;
            else if (tecla == 'l') novoX++;
            else continue;

            if (!desafioLogico('&')) {
                printf("Resposta errada! Turno perdido.\nPressione Enter para continuar...");
                getchar();
                turno = 1;
                continue;
            }

            if (podeMover(novoX, novoY)) {
                x2_pos = novoX;
                y2_pos = novoY;
                if (chegouNaSaida(x2_pos, y2_pos)) {
                    desenhaMapa();
                    printf("\n🏁 Jogador 2 venceu!\n");
                    break;
                }
            }
            turno = 1;
        }
    }

    return 0;
}
