#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <conio.h>


typedef struct Carro
{
    char carroInput[30];
    char manualAutomatico[30];
    int valor[30];
    char deletado[30];
} carros;

FILE *automoveis;


void incluirCarros(void);
void excluirCarros(void);
void consultarCarros(void);
void alterarCarros(void);

void incluirCarros()
{
    struct Carro carros;
    int retorno, continuar;
    automoveis = fopen("./BD/carros.txt", "ab");
    printf("Qual o nome do carro?\n");
    scanf("%s", &carros.carroInput);
    printf("Digite se o carro eh automatico ou manual: \n");
    scanf("%s", &carros.manualAutomatico);
    printf("Digite o valor do carro:\n");
    scanf("%d", &carros.valor);
    retorno = fwrite(&carros, sizeof(carros), 1, automoveis);
    if (retorno == 1)
    {
        fclose(automoveis);
        system("cls || clear");
        printf("Carro adicionado com sucesso\n");
        printf("1. Adicionar mais um carro:\n");
        printf("2. Voltar ao menu\n");
        scanf("%d", &continuar);
        switch (continuar)
        {
        case 1:
            incluirCarros();
            return;
        case 2:
            menuCarros();
            fclose(automoveis);
            return;
        default:
            printf("\n----------------------\n");
            break;
        }
    }
}

void excluirCarros()
{
    char apagar;
    system("color 4F");
    printf("\t\t\t\t\tAVISO\n");
    printf("TODOS OS REGISTROS SERAO APAGADOS!!\n");
    printf("E NAO SERA POSSIVEL RECUPERAR");
    printf("\n\n");
    printf("Deseja realmente apagar todos os usuarios? [S/N} \n");
    scanf("%s", &apagar);
    printf("\n ");
    while (apagar != 's' || apagar != 'S')
    {
        if (apagar == 's' || apagar == 'S')
        {
            automoveis = fopen("./BD/carros.txt", "w++");

            fclose(automoveis);
            printf("Feito exclusao como solicitado");
            system("color 0F");
            return menuCarros();
            system("clear||cls");
        }
        if (apagar == 'n' || apagar == 'N')
        {
            printf("Nenhum dado foi apagado!\n\n\n\n");
            system("color 0F");
            return menuCarros();
            system("clear||cls");
        }
    }
}

carros maxcar[100];
void consultarCarros()
{
int i = 0, retorno = 1, cont = 0;
    char nome[100], op;
    automoveis = fopen("./BD/carros.txt", "rb");
    if (automoveis == NULL)
    {
        printf(" Erro!\nO arquivo da lista não pode ser aberto! \n");
        getch();
        exit(1);
    }
    printf("Digite o nome que deseja procurar:\n");
    scanf("%s", &nome);
    retorno = fread(&maxcar[i], sizeof(carros), 1, automoveis); // vai ler o bloco de notas
    printf("\n");
    while (retorno == 1)
    {
        if (strcmp(nome, maxcar[i].carroInput) == 0) // vai comparar qual o q user escreveu com o retorno
        {
            printf("\n Nome....: %s", maxcar[i].carroInput);
            printf("\n Valor....: %d", maxcar[i].valor);
            printf("\n Manual / Automatico....: %s\n\n\n\n", maxcar[i].manualAutomatico);
            cont++;
        }
        i++;
        retorno = fread(&maxcar[i], sizeof(carros), 1, automoveis);
    }
    if (cont == 0)
    {
        printf("Nao ha carros com este nome!\n ");
    }
    getch();
    fclose(automoveis);
    printf("\n");
    printf("================");
    printf("\n");
    system("clear||cls");
    return menuCarros();
}

void alterarCarros()

{
    struct Carro carros;
    int i = 0, retorno = 1, cont = 0;
    char carro[30];
    automoveis = fopen("./BD/carros.txt", "r+b");
    printf("Digite o nome do carro para buscar:\n");
    scanf("%s", &carro);
    retorno = fread(&maxcar[i], sizeof(carros), 1, automoveis);
    printf("\n");
    while (retorno == 1)
    {
        if (strcmp(carro, maxcar[i].carroInput) == 0)
        {
            printf("%s\n", maxcar[i].carroInput);
            printf("%d\n", maxcar[i].valor);
            printf("%s\n", maxcar[i].manualAutomatico);
            cont = 1;
            fseek(automoveis, sizeof(struct Carro) * -1, SEEK_CUR);
            printf("\nDigite o nome do carro para alterar: \n");
            fflush(stdin);
            gets(carros.carroInput);
            printf("\nDigite o novo preco....: \n");
            scanf("%f", &carros.valor);
            fwrite(&carros, sizeof(carros), 1, automoveis);
            fseek(automoveis, sizeof(carros) * 0, SEEK_END);
            retorno = 2;
            printf("Dados alterados!!");
            menuCarros();
            system("cls || clear");
        }
    }
    i++;
    retorno = fread(&maxcar[i], sizeof(carros), 1, automoveis);
    if (cont == 0)
    {
        printf("Login ou senha incorreta!!\n ");
    }
    getch();
    fclose(automoveis);
    printf("\n");
    printf("================");
    printf("\n");
    system("clear||cls");
    return menuCarros();
}
