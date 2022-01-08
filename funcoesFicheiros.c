#include "funcoesFicheiros.h"

void gravaFicheiroBinario(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade)
{

    FILE  *ficheiro;
    int controlo;

    if(quantMembrosComunidade == 0)
    {
        printf("ERRO - nao existem dados a guardar\n");
    }
    else
    {

        ficheiro = fopen("dadosComunidade.bin", "wb");

        if (ficheiro == NULL)
        {

            printf("\nERRO : falha na abertura do ficheiro!\n");
        }
        else
        {
            controlo = fwrite(&quantMembrosComunidade, sizeof(int), 1, ficheiro);

            if(controlo != 1)
            {
                printf("\nERRO (1): Falha na escrita dos dados\n");
            }
            else
            {
                controlo = fwrite(vetorMembrosCAcademica, sizeof(tipoMembroCAcademica), quantMembrosComunidade, ficheiro);

                if(controlo != quantMembrosComunidade)
                {
                    printf("\nERRO (2): Falha na escrita dos dados\n");
                }
                else
                {
                    printf("\nGravacao dos dados efetuada com SUCESSO!\n");
                }
            }

            fclose(ficheiro);
        }

    }

}


void lerFicheiroBinario(tipoMembroCAcademica vetorMembrosCAcademica[], int *quantMembrosComunidade){

    FILE  *ficheiro;
    int controlo;

    ficheiro = fopen("dadosComunidade.bin", "rb");

    if (ficheiro == NULL)
    {
        printf("\nERRO : falha na abertura do ficheiro!\n");
    }
    else
    {
        //controlo = fread(&*quantMembrosComunidade
        controlo = fread(quantMembrosComunidade, sizeof(int), 1, ficheiro);

        if(controlo != 1)
        {
            printf("\nERRO (1): Falha na leitura dos dados\n");
        }
        else
        {
            controlo = fread(vetorMembrosCAcademica, sizeof(tipoMembroCAcademica), *quantMembrosComunidade, ficheiro);

            if(controlo != *quantMembrosComunidade)
            {
                printf("\nERRO (2): Falha na leitura dos dados\n");
                *quantMembrosComunidade = 0;
            }
            else
            {
                printf("\nLeitura dos dados efetuada com SUCESSO!\n");
            }
        }

        fclose(ficheiro);
    }

}


void gravarFicheiroTexto(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade)
{
    int i;

    FILE *ficheiro;

    ficheiro = fopen("dadosComunidade.txt", "w");

    if(ficheiro == NULL)
    {
        printf("\nErro - falha na abertura do ficheiro\n");
    }
    else
    {

        for (i=0; i < quantMembrosComunidade; i++)
        {
            fprintf(ficheiro,"\n\nMembro (%d)\n", i+1);
            fprintf(ficheiro,"Nr.Utente: %d - Nome: %s\n", vetorMembrosCAcademica[i].numUtenteSaude, vetorMembrosCAcademica[i].nome);
            if (vetorMembrosCAcademica[i].estadoVacina == 0)
            {
                fprintf(ficheiro,"Membro Nao Vacinado");
            }
            else
            {
                fprintf(ficheiro,"Estado Vacina : %d Dose\t\t", vetorMembrosCAcademica[i].estadoVacina);
                fprintf(ficheiro,"Data Avaliacao: %d - %d - %d", vetorMembrosCAcademica[i].dataUltimaVacina.dia,vetorMembrosCAcademica[i].dataUltimaVacina.mes,vetorMembrosCAcademica[i].dataUltimaVacina.ano);

            }
            fprintf(ficheiro,"\n_________________________________________________\n");
        }

        fclose(ficheiro);
    }
}


