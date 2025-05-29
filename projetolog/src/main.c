/**
 * main.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGURA 39
#define ALTURA 19

char mapa[ALTURA][LARGURA + 1]; // +1 para o terminador nulo

int x1_pos = 1, y1_pos = 1;   // Jogador 1 começa no canto superior esquerdo
int x2_pos = 1, y2_pos = 1; // Jogador 2 começa no canto inferior direito

int turno = 1;

// Verifica coordenadas válidas para o labirinto (dentro dos limites e não nas bordas)
int valido(int x, int y) {
    return x > 0 && x < LARGURA - 1 && y > 0 && y < ALTURA - 1;
}

// Função recursiva para cavar o labirinto
void cavar(int x, int y) {
    int dirs[4][2] = {{0,-2}, {2,0}, {0,2}, {-2,0}};
    // Embaralha as direções
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int dx = dirs[i][0], dy = dirs[i][1];
        dirs[i][0] = dirs[r][0]; dirs[i][1] = dirs[r][1];
        dirs[r][0] = dx; dirs[r][1] = dy;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (valido(nx, ny)) {
            if (mapa[ny][nx] == '#') {
                mapa[ny][nx] = ' ';
                mapa[y + dirs[i][1]/2][x + dirs[i][0]/2] = ' ';
                cavar(nx, ny);
            }
        }
    }
}

void gerarLabirinto() {
    // Preenche todo o mapa com paredes
    for (int y = 0; y < ALTURA; y++) {
        for (int x = 0; x < LARGURA; x++) {
            mapa[y][x] = '#';
        }
        mapa[y][LARGURA] = '\0'; // Terminador de string
    }

    // Define as bordas
    for (int x = 0; x < LARGURA; x++) {
        mapa[0][x] = '#';
        mapa[ALTURA-1][x] = '#';
    }
    for (int y = 0; y < ALTURA; y++) {
        mapa[y][0] = '#';
        mapa[y][LARGURA-1] = '#';
    }

    // Inicia a partir do jogador 1
    mapa[y1_pos][x1_pos] = ' ';
    cavar(x1_pos, y1_pos);

    // Coloca a saída no canto inferior direito (posição fixa)
    mapa[ALTURA-2][LARGURA-2] = 'S';

    // Garante que as posições iniciais dos jogadores sejam espaços
    mapa[y1_pos][x1_pos] = ' ';
    mapa[y2_pos][x2_pos] = ' ';
}

void desenhaMapa() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    for (int y = 0; y < ALTURA; y++) {
        for (int x = 0; x < LARGURA; x++) {
            if (y == y1_pos && x == x1_pos) 
                printf("1");
            else if (y == y2_pos && x == x2_pos) 
                printf("2");
            else 
                printf("%c", mapa[y][x]);
        }
        printf("\n");
    }
}

int podeMover(int x, int y) {
    return (mapa[y][x] == ' ' || mapa[y][x] == 'S');
}

int chegouNaSaida(int x, int y) {
    return mapa[y][x] == 'S';
}

char lerTecla() {
    char c = getchar();
    while (getchar() != '\n'); // Limpa o buffer
    return c;
}

int desafioLogico(char jogador) {
    int a = rand() % 2;
    int b = rand() % 2;
    int c = rand() % 2;
    int d = rand() % 2;
    int resultado;
    char resposta;
    int tipo = rand() % 41; // 0 a 40

    printf("\n[%c] DESAFIO LÓGICO:\n", jogador);

    switch (tipo) {
        case 0: printf("Quanto é %d && %d ? (V/F) ", a, b); resultado = a && b; break;
        case 1: printf("Quanto é %d || %d ? (V/F) ", a, b); resultado = a || b; break;
        case 2: printf("Quanto é !%d ? (V/F) ", a); resultado = !a; break;
        case 3: printf("Quanto é (%d && %d) || %d ? (V/F) ", a, b, c); resultado = (a && b) || c; break;
        case 4: printf("Quanto é (%d || %d) && !%d ? (V/F) ", a, b, c); resultado = (a || b) && !c; break;
        case 5: printf("Quanto é !((%d || %d) && (!%d || %d)) ? (V/F) ", a, b, c, d); resultado = !((a || b) && (!c || d)); break;
        case 6: printf("Quanto é (%d && (%d || %d)) ? (V/F) ", a, b, c); resultado = (a && (b || c)); break;
        case 7: printf("Quanto é !(%d && %d) ? (V/F) ", a, b); resultado = !(a && b); break;
        case 8: printf("Quanto é !(%d || %d) ? (V/F) ", a, b); resultado = !(a || b); break;
        case 9: printf("Quanto é ((!%d || %d) && (%d && !%d)) ? (V/F) ", a, b, c, d); resultado = ((!a || b) && (c && !d)); break;
        case 10: printf("Quanto é !!%d ? (V/F) ", a); resultado = !!a; break;
        case 11: printf("Quanto é (%d && !%d) || (!%d && %d) ? (V/F) ", a, b, c, d); resultado = (a && !b) || (!c && d); break;
        case 12: printf("Quanto é (%d || !%d) && (%d || !%d) ? (V/F) ", a, b, c, d); resultado = (a || !b) && (c || !d); break;
        case 13: printf("Quanto é !(%d || (%d && !%d)) ? (V/F) ", a, b, c); resultado = !(a || (b && !c)); break;
        case 14: printf("Se a=%d, b=%d: a é verdadeiro e b é falso? (V/F) ", a, b); resultado = a && !b; break;
        case 15: printf("Se c=%d, d=%d: c ou d são verdadeiros? (V/F) ", c, d); resultado = c || d; break;
        case 16: printf("Verdadeiro se (a=%d e b=%d) forem falsos. (V/F) ", a, b); resultado = !a && !b; break;
        case 17: printf("Verdadeiro se apenas um entre a=%d e b=%d for verdadeiro. (V/F) ", a, b); resultado = (a || b) && !(a && b); break;
        case 18: printf("Quanto é (a && b) == (!c || d)? com a=%d b=%d c=%d d=%d: (V/F) ", a, b, c, d); resultado = (a && b) == (!c || d); break;
        case 19: printf("Quanto é !(a && (!b || c))? com a=%d b=%d c=%d: (V/F) ", a, b, c); resultado = !(a && (!b || c)); break;
        case 20: printf("Se a=%d, b=%d: a ou b são falsos? (V/F) ", a, b); resultado = !a || !b; break;
        case 21: printf("Se c=%d: c é falso? (V/F) ", c); resultado = !c; break;
        case 22: printf("Quanto é (%d ^ %d) ? (XOR) (V/F) ", a, b); resultado = (a || b) && !(a && b); break;
        case 23: printf("Quanto é ((%d || %d) && (%d || %d)) ? (V/F) ", a, b, c, d); resultado = (a || b) && (c || d); break;
        case 24: printf("Quanto é (!%d && !%d) ? (V/F) ", a, b); resultado = !a && !b; break;

        // Casos sobre sofismo/silogismo:
        case 25:
            printf("Todo homem é mortal. Sócrates é homem. Logo, Sócrates é mortal. (V/F) ");
            resultado = 1; // silogismo válido
            break;
        case 26:
            printf("Todo peixe é animal. Todo cachorro é animal. Logo, todo cachorro é peixe. (V/F) ");
            resultado = 0; // falácia (sofisma)
            break;
        case 27:
            printf("Se chove, a rua fica molhada. A rua está molhada. Logo, choveu. (V/F) ");
            resultado = 0; // falácia (afirmação do consequente)
            break;
        case 28:
            printf("Nenhum pássaro é mamífero. Todo pardal é pássaro. Logo, nenhum pardal é mamífero. (V/F) ");
            resultado = 1; // silogismo válido
            break;
        case 29:
            printf("Todo A é B. Todo B é C. Logo, todo C é A. (V/F) ");
            resultado = 0; // falácia (inversão errada)
            break;
        case 30:
            printf("Se alguém é brasileiro, então é sul-americano. João é brasileiro. Logo, João é sul-americano. (V/F) ");
            resultado = 1; // silogismo válido
            break;
        case 31:
            printf("Todo estudante é dedicado. Maria é dedicada. Logo, Maria é estudante. (V/F) ");
            resultado = 0; // falácia (afirmação do consequente)
            break;
        case 32:
            printf("Se há fumaça, há fogo. Não há fogo. Logo, não há fumaça. (V/F) ");
            resultado = 1; // silogismo válido (negação do consequente)
            break;
        case 33:
            printf("Todos os gatos são felinos. Alguns felinos são domésticos. Logo, alguns gatos são domésticos. (V/F) ");
            resultado = 1; // válido
            break;
        case 34:
            printf("Todo rato é mamífero. Todo gato é mamífero. Logo, todo gato é rato. (V/F) ");
            resultado = 0; // falácia (não é verdade)
            break;
        case 35:
            printf("Se está frio, eu uso casaco. Eu estou usando casaco. Logo, está frio. (V/F) ");
            resultado = 0; // falácia (afirmação do consequente)
            break;
        case 36:
            printf("Nenhum peixe é mamífero. Todo tubarão é peixe. Logo, nenhum tubarão é mamífero. (V/F) ");
            resultado = 1; // válido
            break;
        case 37:
            printf("Se Pedro estudou, então passou na prova. Pedro não passou na prova. Logo, Pedro não estudou. (V/F) ");
            resultado = 1; // válido (negação do consequente)
            break;
        case 38:
            printf("Alguns animais são aves. Todos os pássaros são aves. Logo, todos os animais são pássaros. (V/F) ");
            resultado = 0; // falácia
            break;
        case 39:
            printf("Todo A é B. Todo B é C. Logo, todo A é C. (V/F) ");
            resultado = 1; // válido
            break;
        case 40:
            printf("Se está chovendo, o chão está molhado. O chão está molhado. Logo, está chovendo. (V/F) ");
            resultado = 0; // falácia (afirmação do consequente)
            break;
    }

    // Leitura da resposta V ou F (case insensitive)
    do {
        resposta = getchar();
        while (getchar() != '\n'); // limpa buffer
        resposta = (resposta == 'v' || resposta == 'V') ? 'V' : (resposta == 'f' || resposta == 'F') ? 'F' : 0;
        if (!resposta) printf("Por favor, responda V ou F: ");
    } while (!resposta);

    return (resposta == 'V' && resultado == 1) || (resposta == 'F' && resultado == 0);
}

int main() {
    srand(time(NULL));
    gerarLabirinto();
    char tecla;

    while (1) {
        desenhaMapa();
        printf("\nTurno do Jogador %d (%c)\n", turno, turno == 1 ? '1' : '2');
        printf("Controles: %s\n", turno == 1 ? "WASD" : "IJKL");
        printf("Digite a tecla de movimento: ");

        tecla = lerTecla();
        int novoX, novoY;

        if (turno == 1) {
            novoX = x1_pos; novoY = y1_pos;
            if (tecla == 'w') novoY--;
            else if (tecla == 's') novoY++;
            else if (tecla == 'a') novoX--;
            else if (tecla == 'd') novoX++;
            else continue;

            // Verifica se a nova posição é válida (dentro do mapa e não é parede)
            if (novoX < 0 || novoX >= LARGURA || novoY < 0 || novoY >= ALTURA) {
                continue;
            }

            if (!desafioLogico('1')) {
                printf("Resposta errada! Turno perdido. Pressione Enter...");
                getchar();
                turno = 2;
                continue;
            }

            if (podeMover(novoX, novoY)) {
                x1_pos = novoX; y1_pos = novoY;
                if (chegouNaSaida(x1_pos, y1_pos)) {
                    desenhaMapa();
                    printf("\n🏁 Jogador 1 venceu!\n");
                    break;
                }
            }
            turno = 2;
        } else {
            novoX = x2_pos; novoY = y2_pos;
            if (tecla == 'i') novoY--;
            else if (tecla == 'k') novoY++;
            else if (tecla == 'j') novoX--;
            else if (tecla == 'l') novoX++;
            else continue;

            // Verifica se a nova posição é válida (dentro do mapa e não é parede)
            if (novoX < 0 || novoX >= LARGURA || novoY < 0 || novoY >= ALTURA) {
                continue;
            }

            if (!desafioLogico('2')) {
                printf("Resposta errada! Turno perdido. Pressione Enter...");
                getchar();
                turno = 1;
                continue;
            }

            if (podeMover(novoX, novoY)) {
                x2_pos = novoX; y2_pos = novoY;
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