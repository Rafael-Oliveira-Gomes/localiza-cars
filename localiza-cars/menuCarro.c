void menu(); 
void menu()
{
    int opcao = 0;
    printf("\t\t\t\t\t\tBEM VINDO AO SISTEMA DOS CARROS E VENDEDORES\n");
    printf("\t\t\t\t\t\tESCOLHA UMA OPCAO E APERTE ENTER\n");
    printf("1. Incluir carro\n");
    printf("2. Alterar carro\n");
    printf("3. Deletar\n");
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