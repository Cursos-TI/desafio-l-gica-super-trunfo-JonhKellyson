#include <stdio.h>
#include <string.h> // Para strcpy
#include <stdlib.h> // Para exit()

int main() {
    // --- Dados das Cartas (Países) ---
    char nome_pais1[] = "Brasil", nome_pais2[] = "Japao";
    double populacao1 = 215300000, populacao2 = 125700000;
    double area1 = 8516000.0, area2 = 377975.0;
    double pib1 = 1.608, pib2 = 4.937; // Em trilhões de USD
    double pontos_turisticos1 = 1500, pontos_turisticos2 = 2500;
    double densidade1 = populacao1 / area1, densidade2 = populacao2 / area2;

    // --- Variáveis para a lógica do jogo ---
    int escolha1 = 0, escolha2 = 0;
    double valor1_carta1 = 0, valor2_carta1 = 0;
    double valor1_carta2 = 0, valor2_carta2 = 0;
    double soma_carta1 = 0, soma_carta2 = 0;
    char nome_attr1[30], nome_attr2[30];

    // --- Menu 1: Escolha do Primeiro Atributo ---
    printf("### SUPER TRUNFO - ESCOLHA O 1o ATRIBUTO ###\n");
    printf("[1] Populacao\n[2] Area\n[3] PIB\n[4] Pontos Turisticos\n[5] Densidade (menor vence)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha1);

    // Valida a primeira escolha e atribui os valores
    switch (escolha1) {
        case 1: strcpy(nome_attr1, "Populacao"); valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
        case 2: strcpy(nome_attr1, "Area"); valor1_carta1 = area1; valor1_carta2 = area2; break;
        case 3: strcpy(nome_attr1, "PIB"); valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: strcpy(nome_attr1, "Pontos Turisticos"); valor1_carta1 = pontos_turisticos1; valor1_carta2 = pontos_turisticos2; break;
        case 5: strcpy(nome_attr1, "Densidade"); valor1_carta1 = densidade1; valor1_carta2 = densidade2; break;
        default: printf("Erro: Escolha invalida.\n"); exit(1);
    }

    // --- Menu 2: Menu Dinâmico para o Segundo Atributo ---
    printf("\n### ESCOLHA O 2o ATRIBUTO (diferente do 1o) ###\n");
    if (escolha1 != 1) printf("[1] Populacao\n");
    if (escolha1 != 2) printf("[2] Area\n");
    if (escolha1 != 3) printf("[3] PIB\n");
    if (escolha1 != 4) printf("[4] Pontos Turisticos\n");
    if (escolha1 != 5) printf("[5] Densidade (menor vence)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha2);

    // Valida a segunda escolha (inválida se for igual à primeira ou fora do range)
    if (escolha2 == escolha1 || escolha2 < 1 || escolha2 > 5) {
        printf("Erro: Escolha invalida ou repetida.\n");
        exit(1);
    }
    switch (escolha2) {
        case 1: strcpy(nome_attr2, "Populacao"); valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
        case 2: strcpy(nome_attr2, "Area"); valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: strcpy(nome_attr2, "PIB"); valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: strcpy(nome_attr2, "Pontos Turisticos"); valor2_carta1 = pontos_turisticos1; valor2_carta2 = pontos_turisticos2; break;
        case 5: strcpy(nome_attr2, "Densidade"); valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
    }

    // --- Etapa Final: Comparação e Exibição dos Resultados ---
    soma_carta1 = valor1_carta1 + valor2_carta1;
    soma_carta2 = valor1_carta2 + valor2_carta2;

    printf("\n------------------ RESULTADO ------------------\n");
    printf("PAISES: %s vs %s\n\n", nome_pais1, nome_pais2);
    
    // Compara o Atributo 1 usando operador ternário para determinar o vencedor
    printf("--- Atributo 1: %s ---\n", nome_attr1);
    printf("%s: %.2f\n", nome_pais1, valor1_carta1);
    printf("%s: %.2f\n", nome_pais2, valor1_carta2);
    // Para densidade (escolha 5), a lógica é invertida (menor vence)
    printf("Vencedor: %s\n\n", (escolha1 == 5) ?
        ((valor1_carta1 < valor1_carta2) ? nome_pais1 : (valor1_carta2 < valor1_carta1) ? nome_pais2 : "Empate") :
        ((valor1_carta1 > valor1_carta2) ? nome_pais1 : (valor1_carta2 > valor1_carta1) ? nome_pais2 : "Empate"));

    // Compara o Atributo 2 usando operador ternário
    printf("--- Atributo 2: %s ---\n", nome_attr2);
    printf("%s: %.2f\n", nome_pais1, valor2_carta1);
    printf("%s: %.2f\n", nome_pais2, valor2_carta2);
    printf("Vencedor: %s\n\n", (escolha2 == 5) ?
        ((valor2_carta1 < valor2_carta2) ? nome_pais1 : (valor2_carta2 < valor2_carta1) ? nome_pais2 : "Empate") :
        ((valor2_carta1 > valor2_carta2) ? nome_pais1 : (valor2_carta2 > valor2_carta1) ? nome_pais2 : "Empate"));

    // Compara a SOMA FINAL e declara o grande vencedor
    printf("--- SOMA FINAL ---\n");
    printf("%s: %.2f\n", nome_pais1, soma_carta1);
    printf("%s: %.2f\n", nome_pais2, soma_carta2);
    printf("\n>>> VENCEDOR DA RODADA: ");
    if (soma_carta1 > soma_carta2) {
        printf("%s <<<\n", nome_pais1);
    } else if (soma_carta2 > soma_carta1) {
        printf("%s <<<\n", nome_pais2);
    } else {
        printf("EMPATE! <<<\n");
    }
    printf("---------------------------------------------\n");
    return 0;
}