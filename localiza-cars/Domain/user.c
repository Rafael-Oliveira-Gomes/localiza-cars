#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <conio.h>

typedef struct Localiza
{
    char nome[30];
    char senha[30];
    char email[30];
    char sobrenome[30];
} contatos;
FILE *arquivoLogin;
contatos max[100];
void login(void);
void Excluir(void);
void Listar(void);
void mostrarUser(void);
void cadastro(void);
void alterarUser(void);

void cadastro()
{
    printf("------------------------------------\n"
           "|  Sistema de cadastro de cliente  |\n"
           "------------------------------------\n");
    arquivoLogin = fopen("./BD/login.txt", "ab");
    struct Localiza valores;
    int cont, i = 0;
    int c = 0;
    int retorno;
    int adicionar;
    printf("Digite o seu primeiro nome: \n");
    scanf("%s", &valores.nome);
    printf("Digite o seu sobrenome:\n");
    scanf("%s", &valores.sobrenome);
    printf("Digite o seu e-mail:\n");
    scanf("%s", &valores.email);
    printf("Crie uma senha de 4 caracteres: \n");
    fflush(stdin);
    for (c = 0; c < 4; c++)
    {
        valores.senha[c] = getch();
        putchar('*');
    }
    valores.senha[c] = "";
    retorno = fwrite(&valores, sizeof(valores), 1, arquivoLogin);
    fclose(arquivoLogin);
    system("clear||cls");
    if (retorno == 1)
    {
        printf("\t\t\tCadastro realizado com sucesso!!\n\n\n");
        printf("Deseja adicionar mais um usuario?\n");
        printf("1. Sim, desejo adicionar mais um usuario.\n");
        printf("2. Nao, quero ver a lista de gerenciamento\n");
        scanf("%d", &adicionar);
        system("clear||cls");
    }
    else
    {
        printf("Houve um erro ao se cadastrar :(.\n");
        printf("Tente novamente por favor.");
        system("clear||cls");
        return cadastro;
    }

    switch (adicionar)
    {
    case 1:
        cadastro();
        return;
    case 2:
        menuUser();
        return;
    default:
        printf("\n----------------------\n");
        break;
    }
}

void login()
{
    int i = 0, retorno = 1, cont = 0;
    char nome[30];
    char senha1[30];
    int c = 0;
    arquivoLogin = fopen("./BD/login.txt", "rb");
    printf("Digite o seu login:\n");
    scanf("%s", &nome);
    printf("Digite a sua senha:\n");
    fflush(stdin);
    for (c = 0; c < 4; c++)
    {
        senha1[c] = getch();
        putchar('*');
    }
    senha1[c] = "";
    retorno = fread(&max[i], sizeof(contatos), 1, arquivoLogin);
    printf("\n");
    while (retorno == 1)
    {
        if (strcmp(nome, max[i].nome) == 0)
        {
            if (strcmp(senha1, max[i].senha) == 0)
            {
                fclose(arquivoLogin);
                menuCarros();
                return;
            }
        }
        i++;
        retorno = fread(&max[i], sizeof(contatos), 1, arquivoLogin);
    }
    if (cont == 0)
    {
        fclose(arquivoLogin);
        printf("Login ou senha incorreta!!\n ");
    }
    getch();
    printf("\n");
    printf("================");
    printf("\n");
    system("clear||cls");
    return menuUser();
}

void Excluir()
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
            arquivoLogin = fopen("./BD/login.txt", "w++");
            fclose(arquivoLogin);
            printf("Feito exclusao como solicitado");
            system("color FD");
            return menuUser();
            system("clear||cls");
        }
        if (apagar == 'n' || apagar == 'N')
        {
            printf("Nenhum dado foi apagado!\n\n\n\n");
            system("color FD");
            return menuUser();
            system("clear||cls");
        }
    }
}
void mostrarUser()
{
    int i = 0, retorno = 1, cont = 0;
    char nome[100];
    arquivoLogin = fopen("./BD/login.txt", "rb");
    if (arquivoLogin == NULL)
    {
        printf(" Erro!\nO arquivo da lista não pode ser aberto! \n");
        getch();
        exit(1);
    }
    printf("Digite o nome que deseja procurar:\n");
    scanf("%s", &nome);
    retorno = fread(&max[i], sizeof(contatos), 1, arquivoLogin); // vai ler o bloco de notas
    printf("\n");
    while (retorno == 1)
    {
        if (strcmp(nome, max[i].nome) == 0) // vai comparar qual o q user escreveu com o retorno
        {
            printf("\n Nome....: %s", max[i].nome);
            printf("\n Sobrenome....: %s", max[i].sobrenome);
            printf("\n E-mail....: %s\n\n\n\n", max[i].email);
            cont++;
        }
        i++;
        retorno = fread(&max[i], sizeof(contatos), 1, arquivoLogin);
    }
    if (cont == 0)
    {
        printf("Nao ha contatos com este nome!\n ");
    }
    getch();
    fclose(arquivoLogin);
    printf("\n");
    printf("================");
    printf("\n");
    system("clear||cls");
    return menuUser();
}
void alterarUser()

{
    struct Localiza contatos;
    int i = 0, retorno = 1, cont = 0;
    char nome[100];
    arquivoLogin = fopen("./BD/login.txt", "rb");
    if (arquivoLogin == NULL)
    {
        printf(" Erro!\nO arquivo da lista não pode ser aberto! \n");
        getch();
        exit(1);
    }
    printf("Digite o nome que deseja procurar:\n");
    scanf("%s", &nome);
    retorno = fread(&max[i], sizeof(contatos), 1, arquivoLogin); // vai ler o bloco de notas
    printf("\n");
    while (retorno == 1)
    {
        if (strcmp(nome, max[i].nome) == 0) // vai comparar qual o q user escreveu com o retorno
        {
            printf("\n Nome....: %s", max[i].nome);
            printf("\n Sobrenome....: %s", max[i].sobrenome);
            printf("\n E-mail....: %s\n\n\n\n", max[i].email);
            cont++;
            fseek(arquivoLogin, sizeof(struct Localiza) * -1, SEEK_CUR);
            printf("\nDigite a nova senha: \n");
            fflush(stdin);
            gets(contatos.senha);
            fwrite(&contatos, sizeof(contatos), 1, arquivoLogin);
            fseek(arquivoLogin, sizeof(contatos) * 0, SEEK_END);
            retorno = 2;
            printf("Dados alterados!!");
            fclose(arquivoLogin);
            menuUser();
            system("cls || clear");
        }
        i++;
        retorno = fread(&max[i], sizeof(contatos), 1, arquivoLogin);
    }
    if (cont == 0)
    {
        printf("Nao ha contatos com este nome!\n ");
    }
    getch();
    fclose(arquivoLogin);
    printf("\n");
    printf("================");
    printf("\n");
    system("clear||cls");
    return menuUser();
}
