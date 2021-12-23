#include "funcoesTestes.h"


void agendarTeste(tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS], int quantMembrosComunidade, int *quantTestesAgendados)
{

    int posicaoNUtente, tempNUtente,quantTestesPCRDia;


    if(quantMembrosComunidade == 0)
    {
        printf("\nERRO - Nao existem membros na comunidade!\n");
    }
    else
    {

        tempNUtente = lerInteiro("\nInsira o Nº de utente do Membro que pretende agendar um teste.",MIN_NUM_UTENTE,MAX_NUM_UTENTE);
        posicaoNUtente = procuraNumeroSNS(vetorMembrosCAcademica, quantMembrosComunidade, tempNUtente);

        if(posicaoNUtente != -1)

        {
            vetorMembrosCAcademica[posicaoNUtente].testesAgendados->tipoDeTeste = lerInteiro("\nIndique o tipo de teste que prentende agendar : (1 - Antigenio , 2 - PCR)", 1, 2);
            vetorMembrosCAcademica[posicaoNUtente].testesAgendados->dataTeste = lerData("\nIndique a data em que pretende realizar o teste :",MINANO,MAXANO);
            if(vetorMembrosCAcademica[posicaoNUtente].testesAgendados->tipoDeTeste == 2)
            {
                for(int i; i<quantTestesAgendados; i++)
                {

                    if(comparaData(vetorMembrosCAcademica[posicaoNUtente].testesAgendados->dataTeste,vetorMembrosCAcademica[i].testesAgendados->dataTeste ));
                    quantTestesPCRDia++;

                }

                if(quantTestesPCRDia>15)
                {

                }
                else
                {

                }

            }


        }
        else
        {
            printf("\nERROR - Nao existe Membro registado com o numero de utente indicado.");
        }





    }


}
