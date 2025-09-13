/*
 ============================================================================
 Jogo: Super Trunfo - Desafio Nível Novato (Comparação)
 Autor: Gemini
 Data: 12/09/2025
 Descrição: Este programa cadastra duas cartas de Super Trunfo, calcula
            seus atributos derivados (densidade e PIB per capita) e,
            ao final, compara as duas com base em um atributo
            pré-definido no código, declarando a carta vencedora.
 ============================================================================
*/

#include <stdio.h>

// --- CONTROLE DA COMPARAÇÃO ---
// Mude o valor desta constante para escolher qual atributo comparar.
// Opções: "Populacao", "Area", "PIB", "Pontos Turisticos", "Densidade", "PIB per Capita"
#define ATRIBUTO_A_COMPARAR "Populacao"


int main() {
    // --- Variáveis para a Carta 1 ---
    char estado_carta1[3]; // "SP" + '\0'
    char codigo_carta1[4];
    char nome_cidade_carta1[50];
    int populacao_carta1;
    float area_carta1;
    float pib_carta1;
    int pontos_turisticos_carta1;
    float densidade_pop_carta1;
    float pib_per_capita_carta1;

    // --- Variáveis para a Carta 2 ---
    char estado_carta2[3];
    char codigo_carta2[4];
    char nome_cidade_carta2[50];
    int populacao_carta2;
    float area_carta2;
    float pib_carta2;
    int pontos_turisticos_carta2;
    float densidade_pop_carta2;
    float pib_per_capita_carta2;

    // --- Etapa 1: Cadastro das Cartas ---
    printf("### Cadastro de Cartas Super Trunfo ###\n\n");

    // --- Leitura dos Dados da Carta 1 ---
    printf("--- Inserindo dados da Carta 1 ---\n");
    printf("Digite o Estado (sigla, ex: SP): ");
    scanf("%s", estado_carta1);
    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigo_carta1);
    printf("Digite o Nome da Cidade: ");
    scanf("%s", nome_cidade_carta1);
    printf("Digite a Populacao: ");
    scanf("%d", &populacao_carta1);
    printf("Digite a Area (em km2): ");
    scanf("%f", &area_carta1);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib_carta1);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos_carta1);
    printf("\n");

    // --- Leitura dos Dados da Carta 2 ---
    printf("--- Inserindo dados da Carta 2 ---\n");
    printf("Digite o Estado (sigla, ex: RJ): ");
    scanf("%s", estado_carta2);
    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%s", codigo_carta2);
    printf("Digite o Nome da Cidade: ");
    scanf("%s", nome_cidade_carta2);
    printf("Digite a Populacao: ");
    scanf("%d", &populacao_carta2);
    printf("Digite a Area (em km2): ");
    scanf("%f", &area_carta2);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib_carta2);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos_carta2);
    printf("\n");

    // --- Etapa 2: Cálculos dos Atributos Derivados ---
    densidade_pop_carta1 = (float)populacao_carta1 / area_carta1;
    pib_per_capita_carta1 = (pib_carta1 * 1000000000) / populacao_carta1;

    densidade_pop_carta2 = (float)populacao_carta2 / area_carta2;
    pib_per_capita_carta2 = (pib_carta2 * 1000000000) / populacao_carta2;


    // ==================================================
    // --- Etapa 3: Lógica de Comparação e Resultado ---
    // ==================================================
    printf("------------------------------------------\n");
    printf("### HORA DO DUELO! ###\n");
    printf("------------------------------------------\n\n");
    
    // Mostra qual atributo foi escolhido para a batalha
    printf("Comparacao de cartas (Atributo: %s):\n\n", ATRIBUTO_A_COMPARAR);

    // Mostra os dados das cartas para o atributo escolhido
    printf("Carta 1 - %s (%s): %d\n", nome_cidade_carta1, estado_carta1, populacao_carta1);
    printf("Carta 2 - %s (%s): %d\n", nome_cidade_carta2, estado_carta2, populacao_carta2);
    printf("\n");

    // Estrutura de decisão para determinar o vencedor
    // Neste exemplo, a comparação é feita com o atributo "População".
    // Para comparar outro atributo, mude a variável dentro do if-else
    // e ajuste os printf para mostrar o valor correto.
    if (populacao_carta1 > populacao_carta2) {
        // Se a população da carta 1 for maior, ela vence.
        printf("Resultado: Carta 1 (%s) venceu!\n", nome_cidade_carta1);
    } else if (populacao_carta2 > populacao_carta1) {
        // Caso contrário, se a população da carta 2 for maior, ela vence.
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_cidade_carta2);
    } else {
        // Se nenhuma for maior que a outra, é um empate.
        printf("Resultado: Empate!\n");
    }

    return 0;
}