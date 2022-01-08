#include "funcoesTestes.h"


/*void agendarTeste(tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS], int quantMembrosComunidade, int *quantTestesAgendados)
{

    int posicaoNUtente=0, tempNUtente=0,quantTestesPCRDia=0, aux=0;


    if(quantMembrosComunidade == 0)
    {
        printf("\nERRO - Nao existem membros na comunidade!\n");
    }
    else
    {
        printf("\n------------- AGENDAR TESTE -------------\n");

        tempNUtente = lerInteiro("\nInsira o Nº de utente do Membro que pretende agendar um teste.",MIN_NUM_UTENTE,MAX_NUM_UTENTE);
        posicaoNUtente = procuraNumeroSNS(vetorMembrosCAcademica, quantMembrosComunidade, tempNUtente);

        if(posicaoNUtente != -1)

        {
            vetorMembrosCAcademica[posicaoNUtente].testesAgendados->tipoDeTeste = lerInteiro("\nIndique o tipo de teste que prentende agendar : (1 - Antigenio , 2 - PCR)", 1, 2);
            vetorMembrosCAcademica[posicaoNUtente].testesAgendados->dataTeste = lerData("\nIndique a data em que pretende realizar o teste :",MINANO,MAXANO);
            printf("\nANTES DO IF\n\n");

            if(vetorMembrosCAcademica[posicaoNUtente].testesAgendados->tipoDeTeste == 2)
            {
                printf("\nif(quantTestesAgendados != 0)\n");
                if(quantTestesAgendados != 0)
                {
                    for(int i; i<quantTestesAgendados; i++)
                    {
                        aux = comparaData(vetorMembrosCAcademica[posicaoNUtente].testesAgendados->dataTeste,vetorMembrosCAcademica[i].testesAgendados->dataTeste);

                        if(aux == 1)
                        {
                            quantTestesPCRDia++;
                        }

                    }
                }
                printf("if(quantTestesPCRDia>MAXTESTESDIA)");
                if(quantTestesPCRDia>MAXTESTESDIA)
                {
                    printf("\n\n\nERRO : Foi atigindo o maximo de testes PCR para o dia indicado.\n\n");

                }
                else
                {
                    vetorMembrosCAcademica[posicaoNUtente].quantTestesAgendados++;
                    (*quantTestesAgendados)++;

                }

            }


        }
        else
        {
            printf("\nERROR - Nao existe Membro registado com o numero de utente indicado.");
        }





    }


}
*/


void agendarTeste(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, tipoTeste vetorTestes[],int *quantTestesAgendados)
{

    int nrMembro, posicaoNUtente,i,quantTestesPCRDia=0;

    if(quantMembrosComunidade == 0)
    {
        printf("\n\nERRO : nao existem membros registados na comunidade\n\n");
    }
    else
    {
        printf("\n------------- AGENDAR TESTE -------------\n");

        nrMembro = lerInteiro("\nInsira o Nº de utente do Membro que pretende agendar um teste.",MIN_NUM_UTENTE,MAX_NUM_UTENTE);
        posicaoNUtente = procuraNumeroSNS(vetorMembrosCAcademica, quantMembrosComunidade, nrMembro);

        if(posicaoNUtente == -1)
        {
            printf("\n\nERRO : o utente indicado nao se encontra registado\n");
        }
        else
        {

            if(*quantTestesAgendados == 0) // ainda nao ha reservas
            {
                vetorTestes[*quantTestesAgendados].codigoTeste = 1;
            }
            else
            {
                vetorTestes[*quantTestesAgendados].codigoTeste = vetorTestes[*quantTestesAgendados-1].codigoTeste + 1;
            }

            printf("\nCodigo do Teste : %d\n",vetorTestes[*quantTestesAgendados].codigoTeste);

            vetorTestes[*quantTestesAgendados].numUtenteSaude = nrMembro;

            vetorTestes[*quantTestesAgendados].dataTeste = lerData("\nIndique a data em que pretende realizar o teste : ",MINANO,MAXANO);

            vetorTestes[*quantTestesAgendados].tipoDeTeste = lerInteiro("\nIndique o tipo de teste que prentende agendar : (1 - Antigenio , 2 - PCR)",TESTEANTIGENIO,TESTEPCR);

            if(vetorTestes[*quantTestesAgendados].tipoDeTeste == TESTEPCR)
            {
                // VERIFICAR SE O MAXIMO DE TESTES PCR FORAM ATINGIDOS
                for(i=0; i<*quantTestesAgendados; i++)
                {

                    if(vetorTestes[i].tipoDeTeste == TESTEPCR && vetorTestes[i].dataTeste == vetorTestes[*quantTestesAgendados].dataTeste)
                    {
                        quantTestesPCRDia++;
                        if(quantTestesPCRDia==MAXTESTESPCRDIA)
                        {
                            printf("\nERRO : Nao e possivel agendar um teste do tipo PCR para o dia ");
                            escreverData(vetorTestes[*quantTestesAgendados].dataTeste);
                            i=*quantTestesAgendados;

                        }
                    }


                }

            }



            vetorMembrosCAcademica[posicaoNUtente].quantTestesAgendados++;



            printf("\nTotal de Testes agendados do Membro (%s) : %d\n", vetorMembrosCAcademica[posicaoNUtente].nome, vetorMembrosCAcademica[posicaoNUtente].quantTestesAgendados);


            logTestes(vetorTestes[*quantTestesAgendados], vetorMembrosCAcademica[posicaoNUtente], "Teste Agendado");


            (*quantTestesAgendados)++;



        }

    }
}


void logTestes(tipoTeste teste, tipoMembroCAcademica membro, char operacao[])
{

    FILE *ficheiro;


    ficheiro = fopen("logTestes.txt", "a");

    if (ficheiro == NULL)
    {
        printf("\nERRO: falha na abertura do ficheiro\n");
    }
    else
    {
        fprintf(ficheiro,"\nOperacao: %s",operacao);
        fprintf(ficheiro,"\nCodigo Teste : %d", teste.codigoTeste);
        fprintf(ficheiro,"\nNr. Membro : %d - %s", membro.numUtenteSaude, membro.nome);
        fprintf(ficheiro,"\nTotal Testes Agendados do Membro : %d",membro.quantTestesAgendados);
        fprintf(ficheiro,"\nTotal Testes Realizados do Membro : %d",membro.quantTestesRealizados);
        fprintf(ficheiro,"\nData da Reserva: %02d-%02d-%d", teste.dataTeste.dia, teste.dataTeste.mes, teste.dataTeste.ano);
        if (teste.tipoDeTeste == TESTEPCR)
        {
            fprintf(ficheiro,"\nTipo de Teste: PCR\n");
        }
        else
        {
            fprintf(ficheiro,"\nTipo de Teste: Antigenio\n");
        }


        fclose(ficheiro);
    }





}



int procurarTeste(tipoTeste vetorTestes[], int quantTestesAgendados, int codigo)
{

    int i, posicaoTeste = -1;

    for(i=0; i < quantTestesAgendados; i++)
    {
        if(codigo == vetorTestes[i].codigoTeste) //strcmp() == 0 iguais se devolver 0 - PROJETO
        {
            posicaoTeste=i;
            i = quantTestesAgendados;
        }
    }

    return posicaoTeste;
}


void registarResultadoTeste(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, tipoTeste vetorTestes[],int *quantTestesAgendados, int *quantTestesRealizados)
{

    int codigoTeste, posicaoNUtente, posicaoTeste, i;

    if(quantMembrosComunidade == 0)
    {
        printf("\n\nERRO : nao existem membros registados\n\n");

    }
    else if( *quantTestesAgendados == 0)
    {
        printf("\n\nERRO : nao existem testes agendados\n\n");
    }
    else
    {

        printf("\n\n----------- REGISTAR RESULTADO TESTE -----------\n\n ");

        codigoTeste = lerInteiro("\nIntroduza o codigo do teste que pretende registar o resultado : ", 1, vetorTestes[*quantTestesAgendados-1].codigoTeste);
        posicaoTeste = procurarTeste(vetorTestes, *quantTestesAgendados, codigoTeste);

        if(posicaoTeste == -1)
        {

            printf("\nERRO : Nao foi encontrado teste com o codigo indicado.\n");
        }
        else
        {

            posicaoNUtente = procuraNumeroSNS(vetorMembrosCAcademica, quantMembrosComunidade, vetorTestes[posicaoTeste].numUtenteSaude);

            vetorTestes[posicaoTeste].horaColheita = lerHora("\nIndique a hora em que foi colhida a amostra : ",0,MAXHORAS);
            vetorTestes[posicaoTeste].duracaoMinutos = lerInteiro("\nIndique o tempo de duracao em minutos",0,MAXMINUTOSTESTE);


            vetorTestes[posicaoTeste].resultado = lerInteiro("\nIndique o resultado do teste realizado : (0 - Negativo ; 1 - Positivo ; 2 - Inconclusivo)",NEGATIVO,INCONCLUSIVO );

            if(vetorTestes[posicaoTeste].resultado == 1)
            {
                vetorMembrosCAcademica[posicaoNUtente].estadoConfinamento = ISOLAMENTOPROFILATICO;
                vetorMembrosCAcademica[posicaoNUtente].dataConfinamento = vetorTestes[posicaoTeste].dataTeste;

            }
            else if(vetorTestes[posicaoTeste].resultado == 2)
            {
                vetorMembrosCAcademica[posicaoNUtente].estadoConfinamento = QUARENTENA;
                vetorMembrosCAcademica[posicaoNUtente].dataConfinamento = vetorTestes[posicaoTeste].dataTeste;

            }

            vetorMembrosCAcademica[posicaoNUtente].quantTestesRealizados++;
            vetorMembrosCAcademica[posicaoNUtente].quantTestesAgendados--;


        }


    }


}










