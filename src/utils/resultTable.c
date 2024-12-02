#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "resultTable.h"

void resultTableCreate(PtResultTable resultTable, int nteste, const char* nomeTeste, Millis tempoExecucao, int nProcessos, int nCidadaos, PathList solucao, int nIterations, Millis duracao) {
   if (resultTable == NULL)
      return;
   
   resultTable->numeroTeste = nteste;
   strcpy(resultTable->nomeTeste, nomeTeste);
   resultTable->tempoExecucao = tempoExecucao;
   resultTable->numeroProcessos = nProcessos;
   resultTable->numeroCidadaos = nCidadaos;
   resultTable->solucao = solucao;
   resultTable->nIterations = nIterations;
   resultTable->duracao = duracao;
}

void resultTablePrint(PtResultTable resultTable) {
   if (resultTable == NULL)
      return;
   
   printf("Número do Teste: %d\n", resultTable->numeroTeste);
   printf("Nome do Teste: %s\n", resultTable->nomeTeste);
   printf("Tempo Total de Execução: %lld ms\n", resultTable->tempoExecucao);
   printf("Número de Processos Utilizados: %d\n", resultTable->numeroProcessos);
   printf("Número de Cidadãos \"Safos\": %d\n", resultTable->numeroCidadaos);
   plistPrint(&resultTable->solucao);
   printf("Número de Iterações: %d\n", resultTable->nIterations);
   printf("Tempo até atingir a Solução: %lld ms\n", resultTable->duracao);
}