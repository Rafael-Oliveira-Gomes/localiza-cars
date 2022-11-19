#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <conio.h>
#include "./Domain/user.c"
#include "./Domain/menu.c"
#include "./Domain/carros.c"


int main()
{
    setlocale(LC_ALL, "");
    setlocale(LC_ALL, "Portuguese");
    system("pause");
    system("cls || clear");
    menuUser();
}

