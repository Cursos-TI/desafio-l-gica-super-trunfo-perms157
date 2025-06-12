#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do super Trunfo
struct Carta {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

// função para calcular os atributos derivados: densidade populacional e PIB per capita
void calcularAtributos(struct Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// função para exibir os dados principais da carta
void exibirCarta(struct Carta carta) {
    printf("%s (%s):\n", carta.cidade, carta.estado);
    printf("  População: %d\n", carta.populacao);
    printf("  Área: %.2f km²\n", carta.area);
    printf("  PIB: R$ %.2f bilhões\n", carta.pib);
    printf("  Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("  PIB per capita: R$ %.2f\n", carta.pib_per_capita);
}

int main() {
    // cadastro das duas cartas
    struct Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 2300.50, 15};
    struct Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6710000, 1182.30, 900.25, 10};

    // calcula atributos derivados
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Exibe cartas cadastradas
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("\nCarta 2:\n");
    exibirCarta(carta2);

    // Escolha do atributo a ser comparado
    // Altere aqui o atributo a ser comparado: populacao, area, pib, densidade_populacional ou pib_per_capita
    printf("\nComparação de cartas (Atributo: População):\n\n");

    printf("Carta 1 - %s: %d\n", carta1.cidade, carta1.populacao);
    printf("Carta 2 - %s: %d\n", carta2.cidade, carta2.populacao);

    // Comparação com base no atributo escolhido
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}