#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "menus.h"
#include "funcoesGerais.h"
#include "funcoesMembros.h"
#include "funcoesVacinacao.h"
#include "funcoesConfinamento.h"
#include "funcoesFicheiros.h"
#include "funcoesTestes.h"
#include "funcoesEstatisticas.h"


int main()
{
    char opcaoPrincipal, opcaoSecundaria;
    int quantMembrosComunidade = 0, quantTestesAgendados = 0, quantMembrosVacinados = 0, quantTestesRealizados = 0, quantTotalTestes=0;
    tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS];
    tipoTeste *vetorTestes=NULL;



    do
    {
        opcaoPrincipal = menuPrincipal(quantMembrosComunidade, quantTestesAgendados, quantMembrosVacinados, quantTestesRealizados);

        switch(opcaoPrincipal)
        {

        case 'M':   //MENU MEMBROS
            do
            {
                opcaoSecundaria = menuMembros();

                switch(opcaoSecundaria)
                {
                case 'A':
                    adicionarMembro(&quantMembrosComunidade, &quantMembrosVacinados,vetorMembrosCAcademica);
                    break;
                case 'L':
                    listarDadosComunidade(quantMembrosComunidade, vetorMembrosCAcademica,vetorTestes,quantTestesAgendados);
                    break;
                case 'S':

                    break;
                default:
                    printf("\nERRO - OPCAO INVALIDA\n");

                }

            }
            while(opcaoSecundaria != 'S');
            break;
        case 'V':   //MENU VACINACAO
            do
            {
                opcaoSecundaria = menuVacinacao();

                switch(opcaoSecundaria)
                {
                case 'R':
                    registarEstadoVacinacao(quantMembrosComunidade, vetorMembrosCAcademica);
                    break;
                case 'A':
                    atualizarEstadoVacinacao(quantMembrosComunidade, vetorMembrosCAcademica);
                    break;
                case 'S':

                    break;
                default:
                    printf("\nERRO - OPCAO INVALIDA\n");

                }

            }
            while(opcaoSecundaria != 'S');
            break;
        case 'C':   //MENU CONFINAMENTO
            do
            {
                opcaoSecundaria = menuConfinamento();
                switch(opcaoSecundaria)
                {
                case 'R':
                    registarEstadoConfinamento(quantMembrosComunidade, vetorMembrosCAcademica);
                    break;
                case 'A':
                    atualizarEstadoConfinamento( quantMembrosComunidade,  vetorMembrosCAcademica);
                    break;
                case 'L':
                    listarCasosConfinamento(quantMembrosComunidade, vetorMembrosCAcademica);
                    break;
                case 'S':

                    break;
                default:
                    printf("\nERRO - OPCAO INVALIDA\n");

                }
            }
            while(opcaoSecundaria != 'S');
            break;
        case 'T':
            do  //MENU TESTES
            {
                opcaoSecundaria = menuTestes();

                switch(opcaoSecundaria)
                {
                case 'L':
                    listarTestes(vetorTestes, quantTestesAgendados,quantTestesRealizados);
                    break;
                case 'A':
                    vetorTestes = agendarTeste(vetorMembrosCAcademica,  quantMembrosComunidade, vetorTestes, &quantTestesAgendados, quantTestesRealizados);
                    break;
                case 'C':
                    alterarDataTeste(vetorTestes,  quantTestesAgendados);
                    break;
                case 'R':
                    registarResultadoTeste(vetorMembrosCAcademica, quantMembrosComunidade, vetorTestes, &quantTestesAgendados, &quantTestesRealizados);
                    break;
                case 'M':
                    quantTotalTestes = quantTestesAgendados + quantTestesRealizados;
                    apresentarDadosTeste( vetorTestes,  quantTotalTestes,  vetorMembrosCAcademica,  quantMembrosComunidade);
                    break;
                case 'S':
                    break;
                default:
                    printf("\nERRO - OPCAO INVALIDA\n");
                }


            }
            while(opcaoSecundaria != 'S');
            break;


        case 'F':
            do
            {
                opcaoSecundaria = menuFicheiros();
                switch(opcaoSecundaria)
                {
                case 'G':
                    gravaFicheiroBinarioComunidade(vetorMembrosCAcademica, quantMembrosComunidade,quantMembrosVacinados);
                    gravarFicheiroTextoComunidade(vetorMembrosCAcademica, quantMembrosComunidade,quantMembrosVacinados);
                    gravaFicheiroBinarioTestes(vetorTestes,quantTestesAgendados,quantTestesRealizados);

                    break;
                case 'L':
                    lerFicheiroBinarioComunidade(vetorMembrosCAcademica, &quantMembrosComunidade,&quantMembrosVacinados);
                    vetorTestes = lerFicheiroBinarioTestes(vetorTestes, &quantTestesAgendados, &quantTestesRealizados);

                    break;
                case 'S':

                    break;
                default:
                    printf("\nERRO - OPCAO INVALIDA\n");

                }
            }
            while(opcaoSecundaria != 'S');


            break;
        case 'E':
            apresentarDadosEstatisticos(vetorMembrosCAcademica, quantMembrosComunidade,vetorTestes,quantTestesAgendados,quantTestesRealizados);
            break;

        case 'S':

            break;

        default:
            printf("\nERRO - OPCAO INVALIDA\n");
        }

    }
    while(opcaoPrincipal != 'S');

    free(vetorTestes);

    return 0;
}
