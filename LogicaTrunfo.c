#include <stdio.h>
#include <string.h> 
#include <stdlib.h>


// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Desenvolvendo lógica
// Função para mostrar o menu principal

void iniciarJogoAutomatico() {
    // --- Variáveis para a CARTA 1 ---
    char estado[20];    
    char codigo[4];   
    char cidade[20];
    int populacao;   
    float area;
    float pib;
    int pontos;
    float capita;
    float densidade;
    float super_poder;

    // --- Variáveis para a CARTA 2 ---
    char estado2[20];
    char codigo2[4];
    char cidade2[20];
    int populacao2;
    float area2;
    float pib2;
    int pontos2;
    float capita2;
    float densidade2;
    float super_poder2;

    //CADASTRO DA CARTA 1
    printf("Dados da CARTA1 \nQual o nome do estado?\n");
    scanf("%s", estado); 
    printf("Qual o nome da cidade?\n");
    scanf("%s", cidade); 
    printf("Qual o código da carta? (Ex: SP1)\n");
    scanf("%s", codigo); 
    printf("População da cidade?\n");
    scanf("%d", &populacao);
    printf("Qual a área por km?\n");
    scanf("%f", &area);
    printf("Qual o PIB?\n");
    scanf("%f", &pib);
    printf("Qual o número de pontos turísticos?\n");
    scanf("%d", &pontos);

    // CADASTRO DA CARTA 2
    printf("\nDados da CARTA2 \nQual o nome do estado?\n");
    scanf("%s", estado2); 
    printf("Qual o nome da cidade?\n");
    scanf("%s", cidade2); 
    printf("Qual o código da carta? (Ex: SP1)\n");
    scanf("%s", codigo2); 
    printf("População da cidade?\n");
    scanf("%d", &populacao2);
    printf("Qual a área por km?\n");
    scanf("%f", &area2);
    printf("Qual o PIB?\n");
    scanf("%f", &pib2);
    printf("Qual o número de pontos turísticos?\n");
    scanf("%d", &pontos2);

    // --- CÁLCULOS DOS ATRIBUTOS ---
    // Carta 1
    densidade = (float)populacao / area;
    capita = pib / (float)populacao;
    super_poder = populacao + area + pib + pontos + capita + (1/densidade);

    // Carta 2
    densidade2 = (float)populacao2 / area2;
    capita2 = pib2 / (float)populacao2;
    super_poder2 = populacao2 + area2 + pib2 + pontos2 + capita2 + (1/densidade2);

    printf("========================================\n");
    printf("      JOGO SUPER TRUNFO - CIDADES\n");
    printf("========================================\n\n");
    
   // --- COMPARAÇÃO DAS CARTAS ---
    printf("População: %d\n", populacao > populacao2);
    printf("Área: %d\n", area > area2);
    printf("PIB: %d\n", pib > pib2);
    printf("Pontos Turísticos: %d\n", pontos > pontos2);
    printf("Densidade Populacional: %d\n", densidade < densidade2); // Regra invertida
    printf("PIB per Capita: %d\n", capita > capita2);
    printf("Super Poder: %d\n", super_poder > super_poder2);
 
    //Determinando e comparando carta vencedora
    if (pib > pib2) {
    printf("Resultado: Carta 1 com PIB (%.2f) venceu!\n", pib);
} else if (pib2 > pib) {
    printf("Resultado: Carta 2 com PIB (%.2f) venceu!\n", pib2);
} else {
    printf("Resultado: Houve um empate!\n");
}
}

void mostrarMenuPrincipal() {
    printf("\n--- Menu Principal ---\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
}

int main(){
    int opcao;

     do {
        mostrarMenuPrincipal();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Iniciando novo jogo...\n");
                iniciarJogoAutomatico();
                break;
            case 2:
                printf("\n--- REGRAS ---\n");
                printf("1. Duas cartas são sorteadas.\n");
                printf("2. O jogador escolhe um atributo da sua carta para comparar.\n");
                printf("3. Quem tiver o maior valor no atributo vence a rodada.\n");
                printf("4. EXCEÇÃO: Para 'Densidade Populacional', o MENOR valor vence.\n");
                break;
            case 3:
                printf("Obrigado por jogar! Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 3);

   return 0;
}