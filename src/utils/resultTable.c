#include <stdlib.h>
#include "../adts/PathList.h"

#define MAX_TESTS 10

struct resultTable
{
   int numeroTeste [MAX_TESTS];
   char nomeTeste[15];
   int tempoExecucao;
   int numeroProcessos;
   int numeroCidadaos;
   PathList solucoes;
   int duracao;
};

