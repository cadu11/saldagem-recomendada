#include <stdio.h>
#include <string.h>

#define NUM_SOLDAS 3  // Número de tipos de solda cadastrados

// Estrutura para armazenar informações sobre os tipos de soldagem
typedef struct {
    char nome[20];
    char material[20];
    float resistencia;
    float custo;
    char aplicacao[50];
} Solda;

// Função para recomendar o melhor tipo de solda com base no material e custo-benefício
void recomendar_solda(char *material) {
    Solda soldas[NUM_SOLDAS] = {
        {"MIG/MAG", "Aco", 80.0, 50.0, "Estruturas metalicas"},
        {"TIG", "Aluminio", 90.0, 70.0, "Componentes esteticos"},
        {"Eletrodo", "Ferro", 75.0, 30.0, "Soldagem em campo aberto"}
    };

    int i, melhor_indice = -1;
    float melhor_custo_beneficio = 0.0;

    printf("Opcoes de soldagem para %s:\n", material);
    for (i = 0; i < NUM_SOLDAS; i++) {
        if (strcmp(soldas[i].material, material) == 0) {
            float custo_beneficio = soldas[i].resistencia / soldas[i].custo;
            printf("%s - Aplicacao: %s, Resistencia: %.2f, Custo: %.2f\n", soldas[i].nome, soldas[i].aplicacao, soldas[i].resistencia, soldas[i].custo);
            
            if (custo_beneficio > melhor_custo_beneficio) {
                melhor_custo_beneficio = custo_beneficio;
                melhor_indice = i;
            }
        }
    }

    if (melhor_indice != -1) {
        printf("\nMelhor escolha: %s com aplicacao em %s.\n", soldas[melhor_indice].nome, soldas[melhor_indice].aplicacao);
    } else {
        printf("Nenhuma solda adequada encontrada para esse material.\n");
    }
}

int main() {
    char material[20];
    printf("Digite o material da peca (Aco, Aluminio, Ferro): ");
    scanf("%s", material);
    recomendar_solda(material);
    return 0;
}

