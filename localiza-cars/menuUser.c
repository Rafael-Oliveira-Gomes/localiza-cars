void mostrarMenu(void);
void mostrarMenu()
{
    int opcao = 0;
    printf("LOCALIZA CARS\n\n");
    printf("Seja bem vindo ao nosso programa!!!\n\n");
    printf("1. Cadastro de Cliente\n");
    printf("2. Login\n");
    printf("3. Excluir todos os usuarios\n");
    printf("4. Para procurar um usuario:\n");
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
    default:
        printf("\n----------------------\n");
        break;
    }
}