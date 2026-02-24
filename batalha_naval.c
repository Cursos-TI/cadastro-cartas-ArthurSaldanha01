#include <stdio.h>

/* Tema 5 - Batalha Naval (nivel mestre)
   Tabuleiro 10x10 com navios e habilidades especiais usando matrizes e loops. */

#define N 10
#define NAVIO 3
#define HABIL 5

#define H 5
#define HC 2

void init_tabuleiro(int t[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            t[i][j] = 0;
        }
    }
}

int pode_colocar(int t[N][N], int lin, int col) {
    if (lin < 0 || lin >= N || col < 0 || col >= N) return 0;
    if (t[lin][col] != 0) return 0;
    return 1;
}

int coloca_navio_horizontal(int t[N][N], int lin, int col_ini, int tam) {
    int k;
    for (k = 0; k < tam; k++) {
        if (!pode_colocar(t, lin, col_ini + k)) return 0;
    }
    for (k = 0; k < tam; k++) {
        t[lin][col_ini + k] = NAVIO;
    }
    return 1;
}

int coloca_navio_vertical(int t[N][N], int lin_ini, int col, int tam) {
    int k;
    for (k = 0; k < tam; k++) {
        if (!pode_colocar(t, lin_ini + k, col)) return 0;
    }
    for (k = 0; k < tam; k++) {
        t[lin_ini + k][col] = NAVIO;
    }
    return 1;
}

int coloca_navio_diag_desc(int t[N][N], int lin_ini, int col_ini, int tam) {
    int k;
    for (k = 0; k < tam; k++) {
        if (!pode_colocar(t, lin_ini + k, col_ini + k)) return 0;
    }
    for (k = 0; k < tam; k++) {
        t[lin_ini + k][col_ini + k] = NAVIO;
    }
    return 1;
}

int coloca_navio_diag_asc(int t[N][N], int lin_ini, int col_ini, int tam) {
    int k;
    for (k = 0; k < tam; k++) {
        if (!pode_colocar(t, lin_ini - k, col_ini + k)) return 0;
    }
    for (k = 0; k < tam; k++) {
        t[lin_ini - k][col_ini + k] = NAVIO;
    }
    return 1;
}

void imprime_tabuleiro(int t[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}

void cria_cruz(int m[H][H]) {
    int i, j;
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            if (i == HC || j == HC) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
}

void cria_octaedro(int m[H][H]) {
    int i, j;
    int dist;
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            dist = (i > HC ? i - HC : HC - i) + (j > HC ? j - HC : HC - j);
            if (dist <= 2) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
}

void cria_cone(int m[H][H]) {
    int i, j;
    int largura, inicio, fim;
    for (i = 0; i < H; i++) {
        largura = 1 + 2 * i;
        inicio = HC - i;
        fim = HC + i;
        for (j = 0; j < H; j++) {
            if (j >= inicio && j <= fim) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
}

void sobrepoe_habilidade(int t[N][N], int m[H][H], int origemLin, int origemCol) {
    int i, j;
    int linTab, colTab;
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            if (m[i][j] == 1) {
                linTab = origemLin + (i - HC);
                colTab = origemCol + (j - HC);

                if (linTab >= 0 && linTab < N && colTab >= 0 && colTab < N) {
                    if (t[linTab][colTab] != NAVIO) {
                        t[linTab][colTab] = HABIL;
                    }
                }
            }
        }
    }
}

int main() {
    int tab[N][N];
    int tamNavio = 3;

    int cruz[H][H];
    int cone[H][H];
    int octa[H][H];

    int ok;

    init_tabuleiro(tab);

    ok = coloca_navio_horizontal(tab, 1, 1, tamNavio);
    if (!ok) return 0;

    ok = coloca_navio_vertical(tab, 4, 7, tamNavio);
    if (!ok) return 0;

    ok = coloca_navio_diag_desc(tab, 6, 1, tamNavio);
    if (!ok) return 0;

    ok = coloca_navio_diag_asc(tab, 8, 5, tamNavio);
    if (!ok) return 0;

    cria_cone(cone);
    cria_cruz(cruz);
    cria_octaedro(octa);

    sobrepoe_habilidade(tab, cone, 2, 5);
    sobrepoe_habilidade(tab, cruz, 5, 5);
    sobrepoe_habilidade(tab, octa, 7, 7);

    printf("=== Tabuleiro (0 agua, 3 navio, 5 habilidade) ===\n");
    imprime_tabuleiro(tab);

    return 0;
}
