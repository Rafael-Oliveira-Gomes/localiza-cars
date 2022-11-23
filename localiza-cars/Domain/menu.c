void menuCarros(void);
void menuUser(void);
void inicio(void);

void menuUser()
{
    int opcao = 0;
    printf("LOCALIZA CARS\n\n");
    printf("Seja bem vindo ao nosso programa!!!\n\n");
    printf("1. Cadastro de Cliente\n");
    printf("2. Login\n");
    printf("3. Excluir todos os usuarios\n");
    printf("4. Para procurar um usuario:\n");
    printf("5. Esqueci minha senha\n");
    printf("0. Sair do Programa\n");
    scanf("%d", &opcao);
    system("clear||cls");
    switch (opcao)
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
    case 5:
        alterarUser();
        return;
    default:
        printf("\n----------------------\n");
        break;
    }
}

void menuCarros()
{
    int opcao = 0;
    printf("\t\t\t\t\t\tBEM VINDO AO SISTEMA DOS CARROS E VENDEDORES\n");
    printf("\t\t\t\t\t\tESCOLHA UMA OPCAO E APERTE ENTER\n");
    printf("1. Fazer devolucao do carro.(Incluir)\n");
    printf("2. Trocar de carro (Alterar)\n");
    printf("3. Excluir\n");
    printf("4. Visualizar carros\n");
    scanf("%d", &opcao);
    system("clear||cls");
    switch (opcao)
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
    default:
        break;
    }
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