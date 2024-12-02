#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#include "fscs.h"
#include "../utils/data.h"
// #include "../adts/list/list.h"
#include "../adts/ChoiceList.h"
#include "../adts/Stack.h"

#define NORTE 0
#define ESTE 1
#define SUL 2
#define OESTE 3

int calculateMaxSolutions(const int numCidadaos, const int numSupermercados) {
    return (numCidadaos < numSupermercados) ? numCidadaos : numSupermercados;
}

int findSafeCitizen(int citizenID, PtMapaEsquina mapa, pt_FileTestData data, PtPathList pathList) {
    
    Cidadao citizen = data_getCidadao(data, citizenID-1);

    ChoiceList choiceList;
    listCreate(&choiceList);

    Stack pathsStack;
    stackCreate(&pathsStack);

    StackElem esquina;

    bool isSupermarket = false;

    mapaVisitEsquina(mapa, citizen.avenida, citizen.rua);

    do
    {
        esquina_init(&esquina, citizen.avenida, citizen.rua);
        stackPush(&pathsStack, esquina);

        listClear(&choiceList);

        bool isVisited;
        
        if (mapaIsEsquinaVisited(mapa, citizen.avenida-1, citizen.rua, &isVisited) == 0 && !isVisited)
            listAdd(&choiceList, 0, NORTE);
        if (mapaIsEsquinaVisited(mapa, citizen.avenida+1, citizen.rua, &isVisited) == 0 && !isVisited)
            listAdd(&choiceList, 0, SUL);
        if (mapaIsEsquinaVisited(mapa, citizen.avenida, citizen.rua-1, &isVisited) == 0 && !isVisited)
            listAdd(&choiceList, 0, OESTE);
        if (mapaIsEsquinaVisited(mapa, citizen.avenida-1, citizen.rua+1, &isVisited) == 0 && !isVisited)
            listAdd(&choiceList, 0, ESTE);
        if (listIsEmpty(&choiceList))
            return 0;

        int max;
        listSize(&choiceList, &max);

        ListElem direction;
        listGet(&choiceList, (rand() % max), &direction);

        switch (direction)
        {
            case NORTE:
                citizen.avenida--;
            break;
            case SUL:
                citizen.avenida++;
            break;
            case OESTE:
                citizen.rua--;
            break;
            case ESTE:
                citizen.rua++;
            break;
        }
        mapaVisitEsquina(mapa, citizen.avenida, citizen.rua);

        mapaIsEsquinaSuperMarket(mapa, citizen.avenida, citizen.rua, &isSupermarket);
    }
    while (!isSupermarket);
    esquina_init(&esquina, citizen.avenida, citizen.rua);
    stackPush(&pathsStack, esquina);
    plistAdd(pathList, citizenID, pathsStack);
    return 1;
}
