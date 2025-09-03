#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// --- PROTÓTIPOS DAS FUNÇÕES ---
void mostrarMenuPrincipal();
void iniciarJogo();
void mostrarMenuAtributos(int atributoAExcluir);
char* obterNomeAtributo(int escolha); 


int main() {
    int opcao;
    do {
        mostrarMenuPrincipal();
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            iniciarJogo();
            break;
        case 2:
            printf("\n--- REGRAS DO DESAFIO MESTRE ---\n");
            printf("1. Cadastre os dados de duas cartas (cidades).\n");
            printf("2. O jogador escolhera dois atributos diferentes para a batalha.\n");
            printf("3. O sistema somara os valores dos dois atributos para cada carta.\n");
            printf("4. A carta com a MAIOR soma vence a rodada.\n");
            printf("5. EXCECAO: Para 'Densidade Populacional', o MENOR valor e melhor.\n");
            printf("6. Se as somas forem iguais, o resultado e um EMPATE!\n");
            break;
        case 3:
            printf("Obrigado por jogar! Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }

    } while (opcao != 3);

    return 0;
}

void mostrarMenuPrincipal() {
    printf("\n--- JOGO SUPER TRUNFO: DESAFIO MESTRE ---\n");
    printf("1. Iniciar Novo Jogo\n");
    printf("2. Ver Regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
}

// Função principal que contém toda a lógica do jogo
void iniciarJogo() {
    // --- Variáveis para a CARTA 1 
    char estado1[20], cidade1[20], codigo1[4];
    int populacao1, pontos1;
    float area1, pib1, capita1, densidade1;

    // --- Variáveis para a CARTA 2 
    char estado2[20], cidade2[20], codigo2[4];
    int populacao2, pontos2;
    float area2, pib2, capita2, densidade2;

    int escolha1, escolha2;
    float valorAttr1_carta1 = 0, valorAttr2_carta1 = 0;
    float valorAttr1_carta2 = 0, valorAttr2_carta2 = 0;
    float soma_carta1 = 0, soma_carta2 = 0;

    // --- CADASTRO DA CARTA 1 ---
    printf("--- DADOS DA CARTA 1 ---\n");
    printf("Nome do estado: ");     scanf("%s", estado1);
    printf("Nome da cidade: ");     scanf("%s", cidade1);
    printf("Codigo da carta (Ex: SP1): "); scanf("%s", codigo1);
    printf("Populacao da cidade: "); scanf("%d", &populacao1);
    printf("Area por km2: ");        scanf("%f", &area1);
    printf("PIB da cidade: ");       scanf("%f", &pib1);
    printf("Numero de pontos turisticos: "); scanf("%d", &pontos1);

    // --- CADASTRO DA CARTA 2 ---
    printf("\n--- DADOS DA CARTA 2 ---\n");
    printf("Nome do estado: ");     scanf("%s", estado2);
    printf("Nome da cidade: ");     scanf("%s", cidade2);
    printf("Codigo da carta (Ex: RJ1): "); scanf("%s", codigo2);
    printf("Populacao da cidade: "); scanf("%d", &populacao2);
    printf("Area por km2: ");        scanf("%f", &area2);
    printf("PIB da cidade: ");       scanf("%f", &pib2);
    printf("Numero de pontos turisticos: "); scanf("%d", &pontos2);

    // --- CALCULOS DOS ATRIBUTOS DERIVADOS ---
    densidade1 = (area1 > 0) ? (float)populacao1 / area1 : 0;
    capita1 = (populacao1 > 0) ? pib1 / (float)populacao1 : 0;
    densidade2 = (area2 > 0) ? (float)populacao2 / area2 : 0;
    capita2 = (populacao2 > 0) ? pib2 / (float)populacao2 : 0;

    printf("\n========================================\n");
    printf("      QUE COMECE A BATALHA!\n");
    printf("========================================\n\n");

    // --- ESCOLHA DO PRIMEIRO ATRIBUTO ---
    mostrarMenuAtributos(0);
    printf("Jogador, escolha o PRIMEIRO atributo para comparar: ");
    scanf("%d", &escolha1);

    // --- ESCOLHA DO SEGUNDO ATRIBUTO ---
    printf("\n");
    mostrarMenuAtributos(escolha1);
    printf("Agora, escolha o SEGUNDO atributo (diferente do primeiro): ");
    scanf("%d", &escolha2);

    // --- BUSCANDO VALORES PARA O ATRIBUTO 1 ---
    switch(escolha1) {
        case 1: valorAttr1_carta1 = (float)populacao1; valorAttr1_carta2 = (float)populacao2; break;
        case 2: valorAttr1_carta1 = area1; valorAttr1_carta2 = area2; break;
        case 3: valorAttr1_carta1 = pib1; valorAttr1_carta2 = pib2; break;
        case 4: valorAttr1_carta1 = (float)pontos1; valorAttr1_carta2 = (float)pontos2; break;
        case 5: valorAttr1_carta1 = (densidade1 > 0) ? (1.0/densidade1)*1000 : 0; valorAttr1_carta2 = (densidade2 > 0) ? (1.0/densidade2)*1000 : 0; break;
        case 6: valorAttr1_carta1 = capita1; valorAttr1_carta2 = capita2; break;
    }

    // --- BUSCANDO VALORES PARA O ATRIBUTO 2 ---
    switch(escolha2) {
        case 1: valorAttr2_carta1 = (float)populacao1; valorAttr2_carta2 = (float)populacao2; break;
        case 2: valorAttr2_carta1 = area1; valorAttr2_carta2 = area2; break;
        case 3: valorAttr2_carta1 = pib1; valorAttr2_carta2 = pib2; break;
        case 4: valorAttr2_carta1 = (float)pontos1; valorAttr2_carta2 = (float)pontos2; break;
        case 5: valorAttr2_carta1 = (densidade1 > 0) ? (1.0/densidade1)*1000 : 0; valorAttr2_carta2 = (densidade2 > 0) ? (1.0/densidade2)*1000 : 0; break;
        case 6: valorAttr2_carta1 = capita1; valorAttr2_carta2 = capita2; break;
    }

    // --- SOMA DOS ATRIBUTOS ---
    soma_carta1 = valorAttr1_carta1 + valorAttr2_carta1;
    soma_carta2 = valorAttr1_carta2 + valorAttr2_carta2;

    // --- EXIBICAO CLARA DO RESULTADO ---
    printf("\n========================================\n");
    printf("             RESULTADO FINAL\n");
    printf("========================================\n");
    printf("Cartas: %s vs %s\n", cidade1, cidade2);
    printf("Atributos Comparados: %s + %s\n\n", obterNomeAtributo(escolha1), obterNomeAtributo(escolha2));

    printf("--- %s (%s) ---\n", cidade1, codigo1);
    printf("%s: %.2f\n", obterNomeAtributo(escolha1), valorAttr1_carta1);
    printf("%s: %.2f\n", obterNomeAtributo(escolha2), valorAttr2_carta1);
    printf("SOMA TOTAL: %.2f\n\n", soma_carta1);

    printf("--- %s (%s) ---\n", cidade2, codigo2);
    printf("%s: %.2f\n", obterNomeAtributo(escolha1), valorAttr1_carta2);
    printf("%s: %.2f\n", obterNomeAtributo(escolha2), valorAttr2_carta2);
    printf("SOMA TOTAL: %.2f\n\n", soma_carta2);

    // --- DETERMINANDO O VENCEDOR ---
    printf("----------------------------------------\n");
    if (soma_carta1 > soma_carta2) {
        printf("VENCEDOR: CARTA 1 - %s!\n", cidade1);
    } else if (soma_carta2 > soma_carta1) {
        printf("VENCEDOR: CARTA 2 - %s!\n", cidade2);
    } else {
        printf("RESULTADO: HOUVE UM EMPATE!\n");
    }
    printf("----------------------------------------\n");
    printf("\nPressione Enter para voltar ao menu principal...");
    // Pausa para o usuário ler o resultado
    getchar(); // Limpa o buffer do 'enter' anterior
    getchar(); // Aguarda o próximo 'enter'
}

// Função que exibe o menu de atributos, pulando um específico
void mostrarMenuAtributos(int atributoAExcluir) {
    printf("--------- ATRIBUTOS ---------\n");
    if (atributoAExcluir != 1) printf("1. Populacao\n");
    if (atributoAExcluir != 2) printf("2. Area\n");
    if (atributoAExcluir != 3) printf("3. PIB\n");
    if (atributoAExcluir != 4) printf("4. Pontos Turisticos\n");
    if (atributoAExcluir != 5) printf("5. Densidade Populacional (menor e melhor)\n");
    if (atributoAExcluir != 6) printf("6. PIB per Capita\n");
    printf("-----------------------------\n");
}

// Função que retorna o nome de um atributo com base no número
char* obterNomeAtributo(int escolha) {
    switch (escolha) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}