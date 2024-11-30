#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


#include "fscs.h"
#include "../utils/data.h"
// #include "../adts/list/list.h"
#include "../adts/List.h"
#include "../adts/Stack.h"

#define NORTE 0
#define ESTE 1
#define SUL 2
#define OESTE 3

int calculateMaxSolutions(const int numCidadaos, const int numSupermercados) {
    return (numCidadaos < numSupermercados) ? numCidadaos : numSupermercados;
}

int findSafeCitizen(int citizenID, PtMapaEsquina mapa, pt_FileTestData data) {
    srand(time(NULL)); //Para colocar no início do programa
    
    pt_Cidadao citizen = data_getCidadao(data, citizenID);

    List choiceList;
    listCreate(&choiceList);

    Stack pathsStack;
    stackCreate(&pathsStack);

    bool isSupermarket = false;

    mapaVisitEsquina(&mapa, citizen->avenida, citizen->rua);

    do
    {
        StackElem esquina;
        esquina_init(&esquina, citizen->avenida, citizen->rua);
        stackPush(&pathsStack, esquina);

        listClear(&choiceList);

        bool isVisited;
        
        if (mapaIsEsquinaVisited(mapa, citizen->avenida-1, citizen->rua, &isVisited) == 0 && !isVisited)
            listAdd(&choiceList, 0, NORTE);
        if (mapaIsEsquinaVisited(mapa, citizen->avenida+1, citizen->rua, &isVisited) == 0 && !isVisited)
            listAdd(&choiceList, 0, SUL);
        if (mapaIsEsquinaVisited(mapa, citizen->avenida, citizen->rua-1, &isVisited) == 0 && !isVisited)
            listAdd(&choiceList, 0, OESTE);
        if (mapaIsEsquinaVisited(mapa, citizen->avenida-1, citizen->rua+1, &isVisited) == 0 && !isVisited)
            listAdd(&choiceList, 0, ESTE);
        if(!listIsEmpty(&choiceList))
            return 0;

        int max;
        listSize(&choiceList, &max);

        ListElem direction;
        listGet(&choiceList, (rand() % max), &direction);

        //Implementar Semáforo Aqui
        switch (direction)
        {
            case NORTE:
                citizen->avenida--;
            break;
            case SUL:
                citizen->avenida++;
            break;
            case OESTE:
                citizen->rua--;
            break;
            case ESTE:
                citizen->rua++;
            break;
        }
        mapaVisitEsquina(&mapa, citizen->avenida, citizen->rua);
        //Verificar se a esquina atual é supermercado (VER MAPA_ESQUINA.H)
    }
    while (isSupermarket);
}


// int findSafeCitizen(int* numSolucoes, pt_Esquina **mapa, pt_FileTestData data) {

//     // Localização atual
//     int avenidaAtual = 0;
//     cidadao_getAvenida(data_getCidadao(data, 0), &avenidaAtual); // A (1 a M) NORTE-SUL

//     int ruaAtual = 0;
//     cidadao_getAvenida(data_getCidadao(data, 0), &ruaAtual); // B (1 a N) ESTE-OESTE.

//     avenidaAtual = 0;
//     ruaAtual = 0;

//     bool encontrouSolucao = false;
//     bool vizinhoFoiVisitado = true; // Também conta se for NULL


//     PtList caminhos = listCreate();

//     PtList caminhoProcura = listCreate();

//     pt_Esquina vizinho1 = NULL;
//     vizinho_init(vizinho1, avenidaAtual, ruaAtual, mapa, data, NORTE);

//     pt_Esquina vizinho2 = NULL;
//     vizinho_init(vizinho2, avenidaAtual, ruaAtual, mapa, data, ESTE);

//     pt_Esquina vizinho3 = NULL;
//     vizinho_init(vizinho3, avenidaAtual, ruaAtual, mapa, data, SUL);

//     pt_Esquina vizinho4 = NULL;
//     vizinho_init(vizinho4, avenidaAtual, ruaAtual, mapa, data, OESTE);

//     listAdd(caminhoProcura, NORTE, vizinho1);
//     listAdd(caminhoProcura, ESTE, vizinho1);
//     listAdd(caminhoProcura, SUL, vizinho1);
//     listAdd(caminhoProcura, OESTE, vizinho1);
    
    

//     // listPrint(caminhoProcura);

//     pt_Esquina to_remove = NULL;

//     for (size_t i = 0; i<10; i++)
//     {
//         listRemove(caminhos, i, &to_remove);
//         free(to_remove);
//     }

//     for (size_t i = 0; i < 10; i++)
//     {
//         listRemove(caminhoProcura, i, &to_remove);
//         free(to_remove);
//     }

//     listPrint(caminhos);
//     listPrint(caminhoProcura);
    

//     free(caminhos);
//     free(caminhoProcura);

//     /*
//     while(!encontrouSolucao) {
//         //pt_Esquina* vizinhos = vizinhos_init(avenidaAtual, ruaAtual, mapa, data);

//         print_esquina(vizinhos[ESTE]);
//         print_esquina(vizinhos[SUL]);
//         print_esquina(vizinhos[OESTE]);

//         vizinhoFoiVisitado = true;

//         while (vizinhoFoiVisitado) {
//             // escolher um vizinho aleatoriamente (de 0 a 4) correspondente aos defines no header
//             // se o visinho selecionado for nulo ou 
//         }
        
//         free(vizinhos);

//     }*/



//     //vizinhos[NORTE]->FoiVisitado;


//     return 0;
// }

void vizinho_init(pt_Esquina vizinho, const int avenidaAtual, const int ruaAtual, pt_Esquina **mapa, pt_FileTestData data, int direcao) {

    switch (direcao) {
        case NORTE:
            if(avenidaAtual + 1 > data_getTotalAvenidas(data) - 1) {
                break;
            }

            esquina_init(vizinho, avenidaAtual + 1, ruaAtual);
            break;

        case SUL:
            if(avenidaAtual - 1 < 0) {
                break;
            }

            esquina_init(vizinho, avenidaAtual - 1, ruaAtual);
            break;

        case ESTE:
            if(ruaAtual + 1 > data_getTotalRuas(data) - 1) {
                break;
            }

            esquina_init(vizinho, avenidaAtual, ruaAtual + 1);
            break;

        case OESTE:
            if(ruaAtual - 1 < 0) {
                break;
            }

            esquina_init(vizinho, avenidaAtual, ruaAtual - 1);
    }


}


/*

// Legacy code

pt_Esquina* vizinhos_init(const int avenida, const int rua, pt_Esquina **mapa, pt_FileTestData data) {
    pt_Esquina* vizinhos = malloc(4 * sizeof(pt_Esquina));

    for (size_t i = 0; i < 4; i++) {

        switch (i) {
            case NORTE:
                if(avenida + 1 > data->TotalAvenidas - 1) {
                    vizinhos[NORTE] = NULL;
                    continue;
                }

                vizinhos[NORTE] = mapa[avenida+1][rua];
                break;

            case SUL:
                if(avenida - 1 < 0) {
                    vizinhos[SUL] = NULL;
                    continue;
                }

                vizinhos[SUL] = mapa[avenida-1][rua];
                break;

            case ESTE:
                if(rua + 1 > data->TotalRuas - 1) {
                    vizinhos[ESTE] = NULL;
                    continue;
                }

                vizinhos[ESTE] = mapa[avenida][rua+1];
                break;

            case OESTE:
                if(rua - 1 < 0) {
                    vizinhos[OESTE] = NULL;
                    continue;
                }

                vizinhos[OESTE] = mapa[avenida][rua-1];
                break;

        }

    }

    return vizinhos;
}

 */