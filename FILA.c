#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// ESTRUTURA USADADA FILA
struct aviao
{
    char nome[60];
    int tempo;
    int numeroAviao;
} Aviao;

typedef struct no
{
    struct aviao Aviao;
    struct no *proximo;
} No;

void adicionarAviao(No **fila, struct aviao aviao, bool emergencia, int *tam)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->Aviao = aviao;
    novoNo->proximo = NULL;

    if (*fila == NULL)
    {
        *fila = novoNo;
    }
    else
    {
        if (emergencia)
        {
            novoNo->proximo = *fila;
            *fila = novoNo;
        }
        else
        {
            No *aux = *fila;
            while (aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            aux->proximo = novoNo;
        }
    }

    printf("Aviao adicionado na fila de espera\n");
    (*tam)++;
}
void listaravioes(No *fila)
{
    if (fila == NULL)
    {
        printf("Nenhum aviao na fila de espera\n");
    }
    else
    {
        printf("Avioes na fila de espera:\n");
        while (fila != NULL)
        {
            printf("Nome: %s Numero do Aviao: %d\n", fila->Aviao.nome, fila->Aviao.numeroAviao);
            fila = fila->proximo;
        }
    }
}
void autorizar(No **fila, int *tam)
{
    if (*fila == NULL)
    {
        printf("Nenhum aviao aguardando na fila de espera\n");
        return;
    }

    if (*fila != NULL)
    {
        No *aux = *fila;
        *fila = (*fila)->proximo;
        free(aux);
        printf("Decolagem autorizada para o primeiro aviao da fila\n");
        (*tam)--;
    }
    else
    {
        printf("A decolagem nao foi autorizada\n");
    }
}
void primeiroaviao(No *fila)
{
    if (fila == NULL)
    {
        printf("Nenhum aviao na fila de espera\n");
    }
    else
    {
        printf("Avioes na fila de espera:\n");
        printf("Nome: %s Numero do Aviao: %d, com voo de duracao de %d horas\n", fila->Aviao.nome, fila->Aviao.numeroAviao, fila->Aviao.tempo);
    }
}
int main()
{
    int li_opcao;
    struct aviao aviao;
    No *fila = NULL;
    int tam = 0;
    bool autorizado = false;

    do
    {
        printf("ESTRUTURA USADA - FILA");
        printf("\nControle de Avioes\n");
        printf("1 - Listar quantidade de avioes aguardando\n");
        printf("2 - Autorizar decolagem do primeiro aviao da fila\n");
        printf("3 - Adicionar aviao na fila de espera\n");
        printf("4 - Listar avioes na fila de espera\n");
        printf("5 - Adicionar voo de emergencia\n");
        printf("6 - Listar caracteristicas do primeiro aviao\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &li_opcao);
        getchar();

        switch(li_opcao)
        {
        case 1:
            printf("Quantidade de avioes aguardando: %d",tam);
            break;
        case 2:
            autorizar(&fila,&tam);
            break;
        case 3:
            printf("Digite o nome do aviao: ");
            fgets(aviao.nome,60,stdin);
            printf("Digite o numero do aviao: ");
            scanf("%d", &aviao.numeroAviao);
            getchar();
            printf("Digite o tempo de voo: ");
            scanf("%d", &aviao.tempo);
            adicionarAviao(&fila, aviao, false, &tam);
            break;
        case 4:
            listaravioes(fila);
            break;
        case 5:
            printf("Digite o nome do aviao de emergencia: ");
            fgets(aviao.nome, 60, stdin);
            printf("Digite o numero do aviao de emergencia: ");
            scanf("%d", &aviao.numeroAviao);
            printf("Digite o tempo de voo: ");
            scanf("%d",&aviao.tempo);
            adicionarAviao(&fila, aviao,true,&tam);
            break;
        case 6:
            primeiroaviao(fila);
            break;
        default:
            printf("Opcao digitada invalida.");
            break;

        }
    }
    while(li_opcao !=0);


    return 0;
}
