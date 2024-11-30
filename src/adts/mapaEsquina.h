#include <stdbool.h>

#define MAX_CITY_LENGTH 30
#define NUMBER_OF_SOLUCTIONS 30

#pragma once

typedef struct corner
{
    bool isVisited;
    bool isSuperMarket;
} Corner;

typedef struct mapaEsquina
{
    int maxAvenidas;
    int maxRuas;
    Corner mapa[MAX_CITY_LENGTH][MAX_CITY_LENGTH];
} MapaEsquina;

typedef MapaEsquina* PtMapaEsquina;

/**
 * @brief Creates a new empty map with up to 30x30 elements.
 * 
 * @param mapa The Map Pointer
 * @return int - Success (0) or Error (>0)
 */
int mapaCreate(PtMapaEsquina mapa, int avenidas, int ruas);

/**
 * @brief Gets the visited state of a corner from the map.
 * 
 * @param mapa The Map
 * @param avenida The Avenue
 * @param rua The Street
 * @param esquinaStatus The Status of Corner
 * @return int - Success (0) or Error (>0)
 */
int mapaIsEsquinaVisited(PtMapaEsquina mapa, int avenida, int rua, bool *esquinaStatus);

/**
 * @brief Sets a corner of the map as visited. 
 * 
 * @param mapa The Map
 * @param avenida The Avenue
 * @param rua The Street
 * @return int - Success (0) or Error (>0)
 */
int mapaVisitEsquina(PtMapaEsquina mapa, int avenida, int rua);

/**
 * @brief Gets the supermarket state of a corner from the map.
 * 
 * @param mapa The Map
 * @param avenida The Avenue
 * @param rua The Street
 * @param esquinaStatus The Status of Corner
 * @return int - Success (0) or Error (>0)
 */
int mapaIsEsquinaSuperMarket(PtMapaEsquina mapa, int avenida, int rua, bool *esquinaStatus);