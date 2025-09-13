#include <stdio.h>

int main() {
    // --- Etapa 1: Definição dos Dados das Cartas (Países) ---
    // Os dados são "hardcoded" (definidos no código) para este desafio.

    // --- Carta 1: Brasil ---
    char nome_pais1[] = "Brasil";
    int populacao1 = 215300000;
    float area1 = 8516000.0;
    float pib1 = 1.608; // Em trilhões de USD
    int pontos_turisticos1 = 1500;
    float densidade1;

    // --- Carta 2: Pais de Gales ---
    char nome_pais2[] = "Pais de Gales";
    int populacao2 = 45810000;
    float area2 = 2780000.0;
    float pib2 = 0.487; // Em trilhões de USD
    int pontos_turisticos2 = 800;
    float densidade2;

    // --- Etapa 2: Cálculos dos Atributos Derivados ---
    // A densidade é calculada para ambas as cartas antes da batalha.
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    // --- Etapa 3: Menu Interativo e Entrada do Usuário ---
    int escolha;

    printf("==========================================\n");
    printf("### SUPER TRUNFO - BATALHA DE PAISES ###\n");
    printf("==========================================\n\n");
    printf("Carta 1: %s\n", nome_pais1);
    printf("Carta 2: %s\n\n", nome_pais2);

    printf("Escolha o atributo para a batalha:\n");
    printf("[1] Populacao\n");
    printf("[2] Area (km2)\n");
    printf("[3] PIB (em trilhoes de USD)\n");
    printf("[4] Pontos Turisticos\n");
    printf("[5] Densidade Demografica (menor vence)\n\n");
    
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha);
    printf("\n------------------------------------------\n");

    // --- Etapa 4: Lógica de Comparação com SWITCH ---
    // O 'switch' direciona o programa para o bloco de código correto
    // com base na escolha do usuário.
    switch (escolha) {
        case 1: // Comparação por População
            printf("Atributo escolhido: Populacao\n\n");
            printf("%s: %d habitantes\n", nome_pais1, populacao1);
            printf("%s: %d habitantes\n\n", nome_pais2, populacao2);

            if (populacao1 > populacao2) {
                printf("Resultado: %s venceu!\n", nome_pais1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: %s venceu!\n", nome_pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break; // 'break' impede que o código continue para o próximo 'case'.

        case 2: // Comparação por Área
            printf("Atributo escolhido: Area\n\n");
            printf("%s: %.2f km2\n", nome_pais1, area1);
            printf("%s: %.2f km2\n\n", nome_pais2, area2);

            if (area1 > area2) {
                printf("Resultado: %s venceu!\n", nome_pais1);
            } else if (area2 > area1) {
                printf("Resultado: %s venceu!\n", nome_pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 3: // Comparação por PIB
            printf("Atributo escolhido: PIB\n\n");
            printf("%s: %.3f trilhoes USD\n", nome_pais1, pib1);
            printf("%s: %.3f trilhoes USD\n\n", nome_pais2, pib2);

            if (pib1 > pib2) {
                printf("Resultado: %s venceu!\n", nome_pais1);
            } else if (pib2 > pib1) {
                printf("Resultado: %s venceu!\n", nome_pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Comparação por Pontos Turísticos
            printf("Atributo escolhido: Pontos Turisticos\n\n");
            printf("%s: %d pontos\n", nome_pais1, pontos_turisticos1);
            printf("%s: %d pontos\n\n", nome_pais2, pontos_turisticos2);

            if (pontos_turisticos1 > pontos_turisticos2) {
                printf("Resultado: %s venceu!\n", nome_pais1);
            } else if (pontos_turisticos2 > pontos_turisticos1) {
                printf("Resultado: %s venceu!\n", nome_pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        
        case 5: // Comparação por Densidade Demográfica
            printf("Atributo escolhido: Densidade Demografica (MENOR vence!)\n\n");
            printf("%s: %.2f hab/km2\n", nome_pais1, densidade1);
            printf("%s: %.2f hab/km2\n\n", nome_pais2, densidade2);

            // ATENÇÃO: A lógica aqui é invertida! O MENOR valor vence.
            if (densidade1 < densidade2) {
                printf("Resultado: %s venceu!\n", nome_pais1);
            } else if (densidade2 < densidade1) {
                printf("Resultado: %s venceu!\n", nome_pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            // O 'default' é executado se o usuário digitar um número
            // que não corresponde a nenhum 'case'.
            printf("Opcao invalida! Por favor, escolha um numero entre 1 e 5.\n");
            break;
    }

    printf("------------------------------------------\n");
    return 0;
}