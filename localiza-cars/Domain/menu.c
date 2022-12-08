#include <setjmp.h>

#define TRY                     \
    do                          \
    {                           \
        jmp_buf buf_state;      \
        if (!setjmp(buf_state)) \
        {
#define CATCH \
    }         \
    else      \
    {
#define ENDTRY \
    }          \
    }          \
    while (0)
#define THROW longjmp(buf_state, 1)

void menuCarros(void);
void menuUser(void);
void inicio(void);
void sair(void);

void menuUser()
{
    char opcao[] = "";
    printf("LOCALIZA CARS\n\n");
    printf("Seja bem vindo ao nosso programa!!!\n\n");
    printf("1. Cadastro de Cliente\n");
    printf("2. Login\n");
    printf("3. Excluir todos os usuarios\n");
    printf("4. Para procurar um usuario:\n");
    // printf("5. Esqueci minha senha\n");
    printf("9. Sair do Programa\n");
    scanf("%c", &opcao);
    system("clear||cls");

    int opcaoInt;
    TRY
    {
        opcaoInt = atoi(opcao);
    }
    CATCH
    {
        opcaoInt = 999;
    }
    ENDTRY;

    switch (opcaoInt)
    {
    case 1:
        cadastro();
        printf("\n----------------------\n");
        return;
    case 2:
        login();
        printf("\n----------------------\n");
        return;
    case 3:
        Excluir();
        printf("\n----------------------\n");
        return;
    case 4:
        mostrarUser();
        return;
    // case 5:
    // alterarUser();
    // return;
    case 9:
        sair();
        return;
    default:
        printf("\n----------------------\n");
        printf("*** Opcao invalida. ***");
        printf("\n----------------------\n\n");
        return menuUser();
    }
}

void menuCarros()
{
    char opcao[] = "";
    printf("\t\t\t\t\t\tBEM VINDO AO SISTEMA DOS CARROS E VENDEDORES\n");
    printf("\t\t\t\t\t\tESCOLHA UMA OPCAO E APERTE ENTER\n");
    printf("1. Fazer devolucao do carro.(Incluir)\n");
    printf("2. Trocar de carro (Alterar)\n");
    printf("3. Excluir\n");
    printf("4. Visualizar carros\n");
    printf("5. Voltar.\n");
    scanf("%c", &opcao);
    system("clear||cls");
    int opcaoInt;
    TRY
    {
        opcaoInt = atoi(opcao);
    }
    CATCH
    {
        opcaoInt = 999;
    }
    ENDTRY;
    switch (opcaoInt)
    {
    case 1:
        incluirCarros();
        return;
    case 2:
        alterarCarros();
        return;
    case 3:
        excluirCarros();
        return;
    case 4:
        consultarCarros();
        return;
    case 5:
        menuUser();
        return;
    default:
        printf("\n----------------------\n");
        printf("*** Opcao invalida. ***");
        printf("\n----------------------\n\n");
        return menuCarros();
    }
}
void sair()
{
    printf("\t\t\t\t\tObrigado por usar nosso sistema :)\n");
    printf("\n\n\n\nPara suporte:\n");
    printf("\t\t\t\t\t\tRafael de Oliveira\n\t\t\t\t\t\tRobert Novaes\n\t\t\t\t\t\tGabrielle Aoki\n\t\t\t\t\t\tLarissa Soares\n\t\t\t\t\t\tRayane Bispo\n\t\t\t\t\t\tMaria Eduarda\n");
    system("pause>nul");
}

void inicio()
{
    printf("***********************************************\n\n");
    printf("*******_____________SEJA_______________********\n\n");
    printf("*******__________BEM VINDO_____________********\n\n");
    printf("*******_______________A________________********\n\n");
    printf("*******________LOCALIZA CARS'S_________********\n\n");
    printf("***********************************************\n\n\n\n");

    printf("Obrigado por usar nosso programa!!!\n");
    printf("Somos a Localiza Cars\n");
    getch();
    system("cls");
    menuUser();
}