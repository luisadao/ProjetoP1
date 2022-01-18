#include "funcoesTestes.h"

void apresentarDadosTeste(tipoTeste vetorTestes[], int quantTotalTestes, tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade)
{
    int posicaoTeste=0,  posicaoUtente=0, i=0, contaTestesPositivos=0;
    char designacaoTeste[MAXSTRING];

    if(quantTotalTestes == 0)
    {
        printf("\nERRO : nao existem testes registados");

    }
    else
    {
        lerString("\nIndique a designacao do teste que pretende visualisar os dados : ",designacaoTeste, MAXSTRING,SIM);

        posicaoTeste = procurarTeste(vetorTestes, quantTotalTestes, designacaoTeste);

        if(posicaoTeste != -1){

        posicaoUtente = procuraNumeroUtente(vetorMembrosCAcademica,quantMembrosComunidade,vetorTestes[posicaoTeste].numUtenteSaude);

        printf("\nNome : %s",vetorMembrosCAcademica[posicaoUtente].nome);
        printf("\nTipo Membro : ");
        switch(vetorMembrosCAcademica[posicaoUtente].tipoMembro)
        {
        case 1:
            printf("Estudante");
            break;
        case 2:
            printf("Docente");
            break;
        case 3:
            printf("Tecnico");
            break;
        }

        printf("\nTipo : ");
        switch(vetorTestes[posicaoTeste].tipoDeTeste)
        {
        case 1:
            printf("Antigenio");
            break;
        case 2:
            printf("PCR");
            break;
        }
        printf("\nData : ");
        escreverData(vetorTestes[posicaoTeste].dataTeste);

        if(vetorTestes[posicaoTeste].resultado != -1)
        {
            printf("\nResultado : ");
            switch(vetorTestes[posicaoTeste].resultado)
            {
            case 0:
                printf("Negativo");
                break;
            case 1:
                printf("Positivo");
                break;
            case 2:
                printf("Inconclusivo");
                break;

            }
            printf("\nHora da colheita : ");
            escreverHoras(vetorTestes[posicaoTeste].horaColheita);
            printf("\nDuracao (Em minutos) : %02d", vetorTestes[posicaoTeste].duracaoMinutos);

        }

        printf("\nQuantidade testes positivos : ");
        for(i=0; i<quantTotalTestes; i++)
        {

            if(vetorTestes[i].numUtenteSaude == vetorTestes[posicaoTeste].numUtenteSaude && vetorTestes[i].resultado == 1)
            {
                contaTestesPositivos++;
            }

        }

        printf("%d",contaTestesPositivos);
        }else{
            printf("\nERRO : Nao foi encontrado um teste com a designacao indicada.\n");

        }


        //procurar em todos os testes do utilizador quais os que estao positivos
    }

}

void listarTestes(tipoTeste vetorTestes[],int quantTestesAgendados, int quantTestesRealizados)
{
    int i, quantTotalTestes;

    printf("\n\n------------- LISTAR TESTES -------------\n");

    if(quantTestesAgendados == 0 && quantTestesRealizados == 0)
    {
        printf("\nERRO : nao existem testes registados");

    }
    else
    {
        quantTotalTestes = quantTestesAgendados + quantTestesRealizados;
        for(i=0; i < quantTotalTestes ; i++)
        {

            printf("\n\nDesignacao : %s",vetorTestes[i].designacaoTeste);
            printf("\nTipo : ");
            switch(vetorTestes[i].tipoDeTeste)
            {
            case 1:
                printf("Antigenio");
                break;
            case 2:
                printf("PCR");
                break;
            }
            printf("\nData : ");
            escreverData(vetorTestes[i].dataTeste);
            printf("\nNumero Utente : %d", vetorTestes[i].numUtenteSaude);

            if(vetorTestes[i].resultado != -1)
            {
                printf("\nResultado : ");
                switch(vetorTestes[i].resultado)
                {
                case 0:
                    printf("Negativo");
                    break;
                case 1:
                    printf("Positivo");
                    break;
                case 2:
                    printf("Inconclusivo");
                    break;

                }
                printf("\nHora da colheita : ");
                escreverHoras(vetorTestes[i].horaColheita);
                printf("\nDuracao (Em minutos) : %02d", vetorTestes[i].duracaoMinutos);

            }

        }
    }
}


tipoTeste* agendarTeste(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, tipoTeste vetorTestes[],int *quantTestesAgendados, int quantTestesRealizados)
{

    int nrMembro, posicaoNUtente,i,quantTestesPCRDia=0, posTeste=0,quantTestesTotal=0,datasIguais=0;
    tipoTeste *vetorTestesBackup = vetorTestes;



    if(quantMembrosComunidade == 0)
    {
        printf("\n\nERRO : nao existem membros registados na comunidade\n\n");
    }
    else
    {
        printf("\n------------- AGENDAR TESTE -------------\n");

        nrMembro = lerInteiro("\nInsira o Nº de utente do Membro que pretende agendar um teste.",MIN_NUM_UTENTE,MAX_NUM_UTENTE);
        posicaoNUtente = procuraNumeroUtente(vetorMembrosCAcademica, quantMembrosComunidade, nrMembro);

        if(posicaoNUtente == -1)
        {
            printf("\n\nERRO : o utente indicado nao se encontra registado\n");
        }
        else
        {
            quantTestesTotal = *quantTestesAgendados + quantTestesRealizados;

            vetorTestes = realloc(vetorTestes, (quantTestesTotal+1)*sizeof(tipoTeste));

            if(vetorTestes == NULL)
            {
                printf("\nERRO : Nao foi possivel alocar o espaco de memoria.\n");
                vetorTestes = vetorTestesBackup;
            }
            else
            {

                lerString("\nIndique a designacao do Teste : ", vetorTestes[quantTestesTotal].designacaoTeste,MAXSTRING,SIM);

                posTeste = procurarTeste(vetorTestes,quantTestesTotal,vetorTestes[quantTestesTotal].designacaoTeste);

                if(posTeste != -1)
                {
                    printf("\nERRO : Ja existe um teste com a designacao indicada.");
                }
                else
                {
                    vetorTestes[quantTestesTotal].numUtenteSaude = nrMembro;

                    vetorTestes[quantTestesTotal].dataTeste = lerData("\nIndique a data em que pretende realizar o teste : ",MINANO,MAXANO);

                    vetorTestes[quantTestesTotal].tipoDeTeste = lerInteiro("\nIndique o tipo de teste que prentende agendar : (1 - Antigenio , 2 - PCR)",TESTEANTIGENIO,TESTEPCR);

                    if(vetorTestes[quantTestesTotal].tipoDeTeste == TESTEPCR)
                    {
                        // VERIFICAR SE O MAXIMO DE TESTES PCR FORAM ATINGIDOS
                        for(i=0; i<quantTestesTotal; i++)
                        {
                            datasIguais = comparaData(vetorTestes[i].dataTeste, vetorTestes[quantTestesTotal].dataTeste);

                            if(vetorTestes[i].tipoDeTeste == TESTEPCR && datasIguais == 1)
                            {
                                quantTestesPCRDia++;
                                if(quantTestesPCRDia==MAXTESTESPCRDIA)
                                {
                                    printf("\nERRO : Nao e possivel agendar um teste do tipo PCR para o dia ");
                                    escreverData(vetorTestes[quantTestesTotal].dataTeste);
                                    i=quantTestesTotal;
                                }
                            }

                        }
                        if(quantTestesPCRDia!=MAXTESTESPCRDIA)
                        {
                            vetorMembrosCAcademica[posicaoNUtente].quantTestesAgendados++;

                            vetorTestes[quantTestesTotal].resultado = -1;

                            printf("\nTotal de Testes agendados do Membro (%s) : %d\n", vetorMembrosCAcademica[posicaoNUtente].nome, vetorMembrosCAcademica[posicaoNUtente].quantTestesAgendados);

                            logTestes(vetorTestes[quantTestesTotal], vetorMembrosCAcademica[posicaoNUtente], "Teste Agendado");

                            (*quantTestesAgendados)++;
                        }
                    }
                    else
                    {
                        vetorMembrosCAcademica[posicaoNUtente].quantTestesAgendados++;

                        vetorTestes[quantTestesTotal].resultado = -1;

                        printf("\nTotal de Testes agendados do Membro (%s) : %d\n", vetorMembrosCAcademica[posicaoNUtente].nome, vetorMembrosCAcademica[posicaoNUtente].quantTestesAgendados);

                        logTestes(vetorTestes[quantTestesTotal], vetorMembrosCAcademica[posicaoNUtente], "Teste Agendado");

                        (*quantTestesAgendados)++;

                    }
                }
            }
        }
    }

    return vetorTestes;
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
        fprintf(ficheiro,"\nDesignacao Teste : %s", teste.designacaoTeste);
        fprintf(ficheiro,"\nNr. Membro : %d - %s", membro.numUtenteSaude, membro.nome);
        fprintf(ficheiro, "\nEstado de vacinacao : ");
        switch(membro.estadoVacina)
        {
        case 0:
            fprintf(ficheiro,"Nao Vacinado");
            break;
        case 1:
            fprintf(ficheiro,"Primeira Dose");
            break;
        case 2:
            fprintf(ficheiro,"Segunda Dose");
            break;
        case 3:
            fprintf(ficheiro,"Terceira Dose");
            break;
        }

        fprintf(ficheiro,"\nData do Teste: %02d-%02d-%d", teste.dataTeste.dia, teste.dataTeste.mes, teste.dataTeste.ano);
        if (teste.tipoDeTeste == TESTEPCR)
        {
            fprintf(ficheiro,"\nTipo de Teste: PCR\n");
        }
        else
        {
            fprintf(ficheiro,"\nTipo de Teste: Antigenio\n");
        }

        if(teste.resultado != -1)
        {
            fprintf(ficheiro,"\nResultado : ");
            switch(teste.resultado)
            {
            case 0:
                fprintf(ficheiro,"Negativo");
                break;
            case 1:
                fprintf(ficheiro,"Positivo");
                break;
            case 2:
                fprintf(ficheiro,"Inconclusivo");
                break;
            }

            fprintf(ficheiro,"\nHora da colheira : %02d:%02d", teste.horaColheita.hora, teste.horaColheita.minutos);
            fprintf(ficheiro,"\nTempo decorrido (Em minutos): %02d",teste.duracaoMinutos);

        }


        fclose(ficheiro);
    }

}


int procurarTeste(tipoTeste vetorTestes[], int quantTestesAgendados, char designacaoTeste[])
{
    int i, posicaoTeste = -1, stringsIguais;

    for(i=0; i < quantTestesAgendados; i++)
    {
        stringsIguais = strcmp(vetorTestes[i].designacaoTeste,designacaoTeste);

        if(stringsIguais == 0) //strcmp() == 0 iguais se devolver 0 - PROJETO
        {
            posicaoTeste=i;
            i = quantTestesAgendados;
        }
    }

    return posicaoTeste;
}


void registarResultadoTeste(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, tipoTeste vetorTestes[],int *quantTestesAgendados, int *quantTestesRealizados)
{

    int posicaoNUtente, posicaoTeste,quantTestesTotal=0;
    char designacaoTeste[MAXSTRING];

    if(quantMembrosComunidade == 0)
    {
        printf("\n\nERRO : nao existem membros registados\n\n");

    }
    else if(*quantTestesAgendados == 0)
    {
        printf("\n\nERRO : nao existem testes agendados\n\n");
    }
    else
    {
        quantTestesTotal = *quantTestesAgendados+  *quantTestesRealizados;

        printf("\n\n----------- REGISTAR RESULTADO TESTE -----------\n\n ");

        lerString("\nIntroduza a designacao do teste que pretende registar o resultado : ",designacaoTeste, MAXSTRING,SIM);
        posicaoTeste = procurarTeste(vetorTestes, quantTestesTotal, designacaoTeste);
        printf("\nPOSICAO TESTE NO VETOR : %d \n", posicaoTeste);

        if(posicaoTeste == -1)
        {

            printf("\nERRO : Nao foi encontrado teste com a designacao indicada.\n");
        }
        else
        {
            if(vetorTestes[posicaoTeste].resultado != -1)
            {
                printf("\nERRO : o resultado do teste indicado ja foi registado");
            }
            else
            {

                posicaoNUtente = procuraNumeroUtente(vetorMembrosCAcademica, quantMembrosComunidade, vetorTestes[posicaoTeste].numUtenteSaude);

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

                (*quantTestesRealizados)++;
                (*quantTestesAgendados)--;

                logTestes(vetorTestes[posicaoTeste], vetorMembrosCAcademica[posicaoNUtente], "Teste Realizado");
            }
        }
    }
}


void alterarDataTeste(tipoTeste vetorTestes[], int quantTestesAgendados)
{

    int posicaoTeste;
    char designacaoTeste[MAXSTRING];

    if(quantTestesAgendados == 0)
    {
        printf("\nERRO : nao existem testes agendados");

    }
    else
    {
        lerString("\nIntroduza a designacao do teste que pretende registar o resultado : ",designacaoTeste, MAXSTRING,SIM);
        posicaoTeste = procurarTeste(vetorTestes, quantTestesAgendados, designacaoTeste);

        if(posicaoTeste == -1)
        {
            printf("\nERRO : Nao foi encontrado teste com o codigo indicado.\n");

        }
        else if(vetorTestes[posicaoTeste].resultado != -1)
        {
            printf("\nERRO : Nao e possivel alterar a data de um teste que ja foi realizado.\n");
        }
        else
        {
            vetorTestes[posicaoTeste].dataTeste = lerData("\nIntroduza a nova data em que pretende realizar o teste : ",MINANO,MAXANO);
            printf("\nO teste foi agendado para o dia : ");
            escreverData(vetorTestes[posicaoTeste].dataTeste);
        }

    }

}







