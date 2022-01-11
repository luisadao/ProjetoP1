#include "funcoesTestes.h"

void apresentarDadosTeste(tipoTeste vetorTestes[], int quantTotalTestes, tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade)
{
    int posicaoTeste=0, codigoTeste=0, posicaoUtente=0, i=0, contaTestesPositivos=0;

    if(quantTotalTestes == 0)
    {
        printf("\nERRO : nao existem testes registados");

    }
    else
    {
        codigoTeste = lerInteiro("\nIndique o codigo do teste que pretende visualisar os dados : ", 1,quantTotalTestes);

        posicaoTeste = procurarTeste(vetorTestes, quantTotalTestes, codigoTeste);

        posicaoUtente = procuraNumeroSNS(vetorMembrosCAcademica,quantMembrosComunidade,vetorTestes[posicaoTeste].numUtenteSaude );

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


        //procurar em todos os testes do utilizador quais os que estao positivos



    }

}

void listarTestes(tipoTeste vetorTestes[],int quantTotalTestes)
{
    int i;

    printf("\n\n------------- LISTAR TESTES -------------\n");

    if(quantTotalTestes == 0)
    {
        printf("\nERRO : nao existem testes registados");

    }
    else
    {

        for(i=0; i < quantTotalTestes ; i++)
        {
            printf("\n\nCodigo : %d",vetorTestes[i].codigoTeste);
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

                    if(vetorTestes[i].tipoDeTeste == TESTEPCR && vetorTestes[i].dataTeste.dia == vetorTestes[*quantTestesAgendados].dataTeste.dia && vetorTestes[i].dataTeste.mes == vetorTestes[*quantTestesAgendados].dataTeste.mes && vetorTestes[i].dataTeste.ano == vetorTestes[*quantTestesAgendados].dataTeste.ano)
                    {
                        quantTestesPCRDia++;
                        if(quantTestesPCRDia==MAXTESTESPCRDIA)
                        {
                            printf("\nERRO : Nao e possivel agendar um teste do tipo PCR para o dia ");
                            escreverData(vetorTestes[*quantTestesAgendados].dataTeste);
                            i=*quantTestesAgendados;
                            vetorTestes[*quantTestesAgendados] = vetorTestes[*quantTestesAgendados+1];
                            return;  //perguntar á professora se podemos fazer este return aqui

                        }
                    }


                }

            }

            vetorMembrosCAcademica[posicaoNUtente].quantTestesAgendados++;

            vetorTestes[*quantTestesAgendados].resultado = -1;

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

            if(vetorTestes[posicaoTeste].resultado != -1)
            {
                printf("\nERRO : o resultado do teste indicado ja foi registado");
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

                logTestes(vetorTestes[posicaoTeste], vetorMembrosCAcademica[posicaoNUtente], "Teste Realizado");
            }


        }


    }


}


void alterarDataTeste(tipoTeste vetorTeste[], int quantTestesAgendados)
{

    int posicaoTeste, codigoTeste;

    if(quantTestesAgendados == 0)
    {
        printf("\nERRO : nao existem testes agendados");

    }
    else
    {

        codigoTeste = lerInteiro("\nIntroduza o codigo do teste que pretende alterar a data : ", 1, quantTestesAgendados);

        posicaoTeste = procurarTeste(vetorTeste, quantTestesAgendados, codigoTeste);

        if(posicaoTeste == -1)
        {
            printf("\nERRO : Nao foi encontrado teste com o codigo indicado.\n");

        }
        else if(vetorTeste[posicaoTeste].resultado != -1)
        {
            printf("\nERRO : Nao e possivel alterar a data de um teste que ja foi realizado.\n");
        }
        else
        {
           vetorTeste[posicaoTeste].dataTeste = lerData("\nIntroduza a nova data em que pretende realizar o teste : ",MINANO,MAXANO);
           printf("\nO teste foi agendado para o dia : ");
           escreverData(vetorTeste[posicaoTeste].dataTeste);
        }

    }

}







