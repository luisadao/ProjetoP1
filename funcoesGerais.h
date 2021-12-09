#ifndef FUNCOESGERAIS_H_INCLUDED
#define FUNCOESGERAIS_H_INCLUDED

#define SIM 1
#define NAO 0

#define MINANO 1910
#define MAXANO 2004

#define MAXSTRING 50

typedef struct
{
    int dia, mes, ano;
} tipoData;

typedef struct{

    int hora, minutos;

}tipoHora;


char lerCaracter(void);
void limpaBuffer(void);
int lerInteiro (char msg[] ,int limMin, int limMax);
void lerString(char msg[], char texto[], int tamanho, int obrigatorio);
tipoData lerData(char msg[], int minAno, int maxAno);
void escreverData(tipoData data);


#endif // FUNCOESGERAIS_H_INCLUDED
