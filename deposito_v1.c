//deposito_v1
//author:Andre Simao

#include <stdio.h>
#include <stdlib.h>

#define MAX_AREAS 3
#define MAX_CONTAINERS 3

//Estrutura Area
typedef struct {
    int num;
    int contagem;
} Area;

//Estrutura Container
typedef struct {
    int cod;
} Container;

//Estrutura N�
typedef struct no {
    Container p;
    struct no* proximo;
} No;

//Estrutura Pilha
typedef struct {
    No* topo;
    int tam;
} Pilha;

//Procedimento para criar pilha
void criar_pilha(Pilha* p) {
    p->topo = NULL;
    p->tam = 0;
}

//Fun��o para verificar se a pilha est� cheia
int pilha_cheia(Pilha* p) {
    return (p->tam >= MAX_CONTAINERS);
}

//Procedimento para empilhar (push)
void empilhar(Pilha* p, Container novoContainer) {
    if (pilha_cheia(p)) {
        printf("Capacidade maxima atingida. Nao e possivel empilhar mais containers nessa area.\n");
        return;
    }

    No* novo = malloc(sizeof(No));
    if (novo) {
        novo->p = novoContainer;
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
        printf("Container empilhado com sucesso.\n");
    } else {
        printf("Erro ao alocar memoria.\n");
    }
}

//Fun��o para verificar se a pilha est� vazia
int pilha_vazia(Pilha* p) {
    return (p->topo == NULL);
}

//Procedimento para desempilhar (pop)
void desempilhar(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia. Nao e possivel desempilhar.\n");
        return;
    }

    No* remover = p->topo;
    p->topo = remover->proximo;
    p->tam--;
    free(remover);
    printf("Container desempilhado com sucesso.\n");
}

//Procedimento para imprimir o conte�do do dep�sito
void imprimir_deposito(Pilha* pilhas) {
    printf("Conte�do do dep�sito:\n\n");
    printf("        |  Area 1  |  Area 2  |  Area 3  |\n");
    printf("----------------------------------------\n");

    for (int i = MAX_CONTAINERS - 1; i >= 0; i--) {
        printf("Linha %d |", i + 1);

        for (int j = 0; j < MAX_AREAS; j++) {
            Pilha* p = &pilhas[j];

            if (i < p->tam) {
                No* aux = p->topo;
                int linha = 1;

                while (linha < p->tam - i) {
                    aux = aux->proximo;
                    linha++;
                }

                printf("   %04d   |", aux->p.cod);
            } else {
                printf("          |");
            }
        }

        printf("\n");
        printf("----------------------------------------\n");
    }
}

int main() {
    Pilha pilhas[MAX_AREAS];
    Container novoContainer;
    int opcao;

    //Inicializa as pilhas
    for (int i = 0; i < MAX_AREAS; i++) {
        criar_pilha(&pilhas[i]);
    }

    do {
        printf("\n------------DEPOSITO------------\n");
        printf("0 - Sair\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                printf("Digite o codigo do container (max 4 digitos): ");
                scanf("%d", &novoContainer.cod);

                int area;
                printf("Digite o numero da area (1 a %d): ", MAX_AREAS);
                scanf("%d", &area);

                if (area >= 1 && area <= MAX_AREAS) {
                    empilhar(&pilhas[area - 1], novoContainer);
                } else {
                    printf("�rea inv�lida.\n");
                }
                break;
            case 2:
                printf("Digite o numero da area (1 a %d): ", MAX_AREAS);
                scanf("%d", &area);

                if (area >= 1 && area <= MAX_AREAS) {
                    desempilhar(&pilhas[area - 1]);
                } else {
                    printf("Area invalida.\n");
                }
                break;
            case 3:
                imprimir_deposito(pilhas);
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    //Desaloca a mem�ria das pilhas
    for (int i = 0; i < MAX_AREAS; i++) {
        No* atual = pilhas[i].topo;
        while (atual) {
            No* remover = atual;
            atual = atual->proximo;
            free(remover);
        }
    }

    return 0;
}
