#include "funcoesConfinamento.h"


void registarEstadoConfinamento(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS])
{

    int numUtenteTemp, posicaoUtente,aux;

    if(quantMembrosComunidade == 0)
    {
        printf("\nERROR - Nao existem membros registados.");
    }
    else
    {
        numUtenteTemp= lerInteiro("Indique o nr. de utente de quem pretende registar o confinamento : ", MIN_NUM_UTENTE,MAX_NUM_UTENTE);
        posicaoUtente = procuraNumeroSNS(vetorMembrosCAcademica,quantMembrosComunidade,numUtenteTemp);

        if(posicaoUtente != -1)  // encontrou o utente
        {

            printf("\nIndique o tipo de confinamento em que se encontra o utente %s.", vetorMembrosCAcademica[posicaoUtente].nome);

            vetorMembrosCAcademica[posicaoUtente].estadoConfinamento = lerInteiro("(0 - Nao Confinado , 1 - Quarentena , 2 - Isolamento Profilatico)", 0, ISOLAMENTOPROFILATICO); // 0 serve como  escapatoria caso o utilizador entre sem querer na opcao ???

            if(vetorMembrosCAcademica[posicaoUtente].estadoConfinamento  == 1 || vetorMembrosCAcademica[posicaoUtente].estadoConfinamento  == 2 )
            {
                vetorMembrosCAcademica[posicaoUtente].dataConfinamento = lerData("\nIndique a data em que entrou em confinamento : ",MINANOCONFINAMENTO,MAXANOCONFINAMENTO);
            }

        }
        else
        {
            printf("\nERROR - Nao existe utente com o numero %d.", numUtenteTemp);
        }

    }
}



void atualizarEstadoConfinamento(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS])
{

    int numUtenteTemp, posicaoUtente,aux;

    if(quantMembrosComunidade == 0)
    {
        printf("\nERROR - Nao existem membros registados.");
    }
    else
    {
        numUtenteTemp= lerInteiro("Indique o nr. de utente de quem pretende atualizar o confinamento : ", MIN_NUM_UTENTE,MAX_NUM_UTENTE);
        posicaoUtente = procuraNumeroSNS(vetorMembrosCAcademica,quantMembrosComunidade,numUtenteTemp);

        if(posicaoUtente != -1)  // encontrou o utente
        {

            aux = vetorMembrosCAcademica[posicaoUtente].estadoConfinamento ;
            vetorMembrosCAcademica[posicaoUtente].estadoConfinamento = lerInteiro("Deseja terminar o seu estado de confinamento (0 - NAO ; 1 - SIM)", NAO, SIM);
            if(vetorMembrosCAcademica[posicaoUtente].estadoConfinamento == 1)
            {
                vetorMembrosCAcademica[posicaoUtente].ultimoConfinamento = vetorMembrosCAcademica[posicaoUtente].estadoConfinamento;
                vetorMembrosCAcademica[posicaoUtente].estadoConfinamento = 0;
                vetorMembrosCAcademica[posicaoUtente].duracaoConfinamentoDias = lerInteiro("Indique a duracao em dias do seu confinamento : ",MINDIASCONFINAMENTO,MAXDIASCONFINAMENTO); //Assumindo que o max tempo de confinamento é de 15 dias
            }

        }
        else
        {
            printf("\nERROR - Nao existe utente com o numero %d.", numUtenteTemp);
        }


    }

}



void listarCasosConfinamento(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS])
{

    int i;

    if(quantMembrosComunidade == 0)
    {

        printf("\nERROR - Nao existem membros registados.");

    }
    else
    {
        for(i=0; i<quantMembrosComunidade; i++)
        {
            if(vetorMembrosCAcademica[i].ultimoConfinamento != 0)
            {
                printf("\nNome : %s",vetorMembrosCAcademica[i].nome);
                printf("\nTipo de Confinamento : ");
                switch(vetorMembrosCAcademica[i].ultimoConfinamento)
                {
                case 1 :
                    printf("Quarentena");
                    break;
                case 2:
                    printf("Isolamento Profilatico");
                    break;

                }
                printf("\nData de Confinamento : ");
                escreverData(vetorMembrosCAcademica[i].dataConfinamento);
                printf("\nDias em Confinamento : %d", vetorMembrosCAcademica[i].duracaoConfinamentoDias);

            }


        }





    }
}
