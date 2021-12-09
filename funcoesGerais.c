#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesGerais.h"



void limpaBuffer(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}


int lerInteiro (char msg[] ,int limMin, int limMax)
{
    int num, controlo;

    do
    {

        printf("\n%s [%d, %d]: ",msg, limMin, limMax);
        controlo = scanf("%d", &num);
        limpaBuffer();
        if (num < limMin || num > limMax)
        {
            printf("\n\nERRO: valor fora do intervalo solicitado");
        }
        if(controlo != 1)
        {
            printf("\nERRO : formato errado.\n");
        }


    }
    while (num < limMin || num > limMax || controlo != 1);

    return num;
}



char lerCaracter(void){ //FUCAO QUE LE E DEVOLVE UM CARACTER EM MAISCULA

    char opcao;

    scanf(" %c", &opcao);
    opcao = toupper(opcao);

    return opcao;

};

//??? VERIFICAR UTILIDADE DA FUNCAO
int verificaExiste(int quantAVerificar){

    int quantFuncao=0;

    if(quantAVerificar != 0){
        quantFuncao = quantAVerificar;
    }else{
        printf("\nERRO - Nao existem dados\n");
        quantFuncao=0;
    }

    return quantFuncao;

}


void lerString(char msg[], char texto[], int tamanho, int obrigatorio)
{
    int tamEscrito;

    do
    {

        printf("\n%s", msg);

        fgets(texto, tamanho, stdin);

        tamEscrito = strlen(texto);

        if(tamEscrito == 1 && obrigatorio == SIM) //SIGNIFICA QUE O USR SO INSERIU O ENTER
        {
            printf("\nERRO:o campo e obrigatorio\n");
        }

    }
    while(tamEscrito == 1 && obrigatorio == SIM);


    if(texto[tamEscrito-1] != '\n' ) // se o \n esta na string é pq o texto coube todo logo nao limpamos o buffer
    {
        limpaBuffer();
    }
    else        // tirar o \n da string
    {
        texto[tamEscrito-1] = '\0';
    }

}



tipoData lerData(char msg[], int minAno, int maxAno)
{
    tipoData data;
    int controlo=0, maxDia, error=0;

    do
    {
        error=0;

        do
        {
            printf("\n%s", msg);
            controlo = scanf("%d-%d-%d", &data.dia, &data.mes, &data.ano);
            limpaBuffer();
            if(controlo != 3)
            {
                printf("\nERRO: Formato de data invalido");

            }
        }
        while(controlo != 3);

        if(data.ano < minAno || data.ano > maxAno)
        {
            printf("\nERRO : Ano invalido!\n");
            error=1;
        }
        else
        {
            switch(data.mes)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                maxDia=31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maxDia=30;
                break;
            case 2:
                if((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
                {
                    maxDia=29;
                }
                else
                {
                    maxDia=28;
                }
                break;
            default:
                printf("\nERRO : mes invalido!\n");
                error=1;

            }

            if(data.dia < 1 || data.dia > maxDia)
            {
                printf("\nERRO : dia invalido!\n");
                error=1;

            }
        }

    }
    while(error); // OU while(error==1)

    return data;

}



void escreverData(tipoData data)
{

    printf("%02d-%02d-%d", data.dia, data.mes, data.ano);

}
