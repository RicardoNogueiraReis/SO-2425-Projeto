#pragma once

#include "esquina.h"

typedef struct mapaEsquina MapaEsquina;

typedef MapaEsquina* PtMapaEsquina;

/**
 * @brief Creates a new empty map with up to 800x800 elements.
 * 
 * @param mapa The Map Pointer
 * @return int - Success (0) or Error (>0)
 */
int mapaCreate(PtMapaEsquina mapa, int avenidas, int ruas);

/**
 * @brief Gets an element from the map.
 * 
 * @param mapa The Map
 * @param avenida The Avenue
 * @param rua The Street
 * @param esquina The Element
 * @return int - Success (0) or Error (>0)
 */
int mapaGetEsquina(PtMapaEsquina mapa, int avenida, int rua, pt_Esquina* esquina);