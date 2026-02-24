#include <stdio.h>

/* Tema 4 - Xadrez (nivel mestre)
   Simula movimentos de pecas usando recursao e loops. */

void mover_torre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    mover_torre(casas - 1);
}

void mover_rainha(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");
    mover_rainha(casas - 1);
}

void mover_bispo_rec(int casas) {
    if (casas == 0) return;
    printf("Cima Direita\n");
    mover_bispo_rec(casas - 1);
}

/* Bispo com loops aninhados:
   externo = sobe, interno = vai para direita */
void mover_bispo_loops(int casas) {
    int v, h;

    for (v = 0; v < casas; v++) {
        for (h = 0; h < casas; h++) {
            if (h == 0) {
                printf("Cima Direita\n");
                break;
            }
        }
    }
}

/* Cavalo (L): 2 casas pra cima e 1 pra direita
   loops aninhados com controle de fluxo */
void mover_cavalo(int cima, int direita) {
    int total = cima + direita;
    int passo, tent;

    for (passo = 0; passo < total; passo++) {
        for (tent = 0; tent < 3; tent++) {

            if (passo < cima) {
                if (tent == 0) {
                    printf("Cima\n");
                    break;
                }
                continue;
            }

            if (tent == 0) {
                printf("Direita\n");
                break;
            }
        }
    }
}

int main() {
    int torreCasas = 5;
    int bispoCasas = 5;
    int rainhaCasas = 8;

    int cavaloCima = 2;
    int cavaloDireita = 1;

    printf("Torre:\n");
    mover_torre(torreCasas);

    printf("\nBispo (recursivo):\n");
    mover_bispo_rec(bispoCasas);

    printf("\nRainha:\n");
    mover_rainha(rainhaCasas);

    printf("\nCavalo:\n");
    mover_cavalo(cavaloCima, cavaloDireita);

    printf("\nBispo (loops aninhados):\n");
    mover_bispo_loops(bispoCasas);

    return 0;
}
