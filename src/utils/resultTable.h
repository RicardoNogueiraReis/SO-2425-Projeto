#include "../adts/PathList.h"
#include "../utils/timeMilis.h"

#pragma once

typedef struct resultTable
{
   int numeroTeste;
   const char nomeTeste[15];
   Millis tempoExecucao;
   int numeroProcessos;
   int numeroCidadaos;
   PathList solucao;
   int nIterations;
   Millis duracao;
}ResultTable;

typedef ResultTable* PtResultTable;

void resultTableCreate(PtResultTable resultTable, int nteste, const char* nomeTeste, Millis tempoExecucao, int nProcessos, int nCidadaos, PathList solucao, int nIterations, Millis duracao);

void resultTablePrint(PtResultTable resultTable);