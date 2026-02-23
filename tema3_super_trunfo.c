#include <stdio.h>

/*
   Tema 3 - Super Trunfo
   Nivel Mestre

   Programa que cadastra duas cartas,
   calcula atributos derivados e permite
   comparar dois atributos escolhidos pelo usuario.
*/

int main() {

    // Dados da carta 1
    char estado1;
    char codigo1[4];
    char cidade1[100];
    int populacao1;
    float area1;
    float pib1;
    int pontos1;

    // Dados da carta 2
    char estado2;
    char codigo2[4];
    char cidade2[100];
    int populacao2;
    float area2;
    float pib2;
    int pontos2;

    // Variaveis calculadas
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // Variaveis para menu
    int atributo1, atributo2;

    // Valores escolhidos
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;

    float soma1, soma2;

    printf("=== Cadastro das Cartas ===\n\n");

    // Cadastro carta 1
    printf("Carta 1\n");
    printf("Estado: ");
    scanf(" %c", &estado1);

    printf("Codigo: ");
    scanf(" %3s", codigo1);

    printf("Cidade: ");
    scanf(" %99[^\n]", cidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area: ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Pontos Turisticos: ");
    scanf("%d", &pontos1);

    printf("\n");

    // Cadastro carta 2
    printf("Carta 2\n");
    printf("Estado: ");
    scanf(" %c", &estado2);

    printf("Codigo: ");
    scanf(" %3s", codigo2);

    printf("Cidade: ");
    scanf(" %99[^\n]", cidade2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area: ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Pontos Turisticos: ");
    scanf("%d", &pontos2);

    // Calculos
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    printf("\n=== Escolha dois atributos para comparar ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade (menor vence)\n");
    printf("6 - PIB per capita\n");

    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);

    if (atributo1 == atributo2) {
        printf("\nNao pode escolher o mesmo atributo duas vezes.\n");
        return 0;
    }

    // Atributo 1
    switch (atributo1) {
        case 1:
            valor1_c1 = populacao1;
            valor1_c2 = populacao2;
            break;
        case 2:
            valor1_c1 = area1;
            valor1_c2 = area2;
            break;
        case 3:
            valor1_c1 = pib1;
            valor1_c2 = pib2;
            break;
        case 4:
            valor1_c1 = pontos1;
            valor1_c2 = pontos2;
            break;
        case 5:
            valor1_c1 = densidade1;
            valor1_c2 = densidade2;
            break;
        case 6:
            valor1_c1 = pibPerCapita1;
            valor1_c2 = pibPerCapita2;
            break;
        default:
            printf("Opcao invalida.\n");
            return 0;
    }

    // Atributo 2
    switch (atributo2) {
        case 1:
            valor2_c1 = populacao1;
            valor2_c2 = populacao2;
            break;
        case 2:
            valor2_c1 = area1;
            valor2_c2 = area2;
            break;
        case 3:
            valor2_c1 = pib1;
            valor2_c2 = pib2;
            break;
        case 4:
            valor2_c1 = pontos1;
            valor2_c2 = pontos2;
            break;
        case 5:
            valor2_c1 = densidade1;
            valor2_c2 = densidade2;
            break;
        case 6:
            valor2_c1 = pibPerCapita1;
            valor2_c2 = pibPerCapita2;
            break;
        default:
            printf("Opcao invalida.\n");
            return 0;
    }

    // Soma dos atributos
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("\n=== Resultado ===\n");
    printf("Carta 1 (%s): %.2f\n", cidade1, soma1);
    printf("Carta 2 (%s): %.2f\n", cidade2, soma2);

    if (soma1 == soma2) {
        printf("Empate!\n");
    } else {
        printf("%s venceu!\n", (soma1 > soma2) ? cidade1 : cidade2);
    }

    return 0;
}
