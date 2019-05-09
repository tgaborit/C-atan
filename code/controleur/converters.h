/**
* \file converters.h
* \brief En-tête de la conversion des boutons vers des données utilisables par le modèle.
* \author Titouan Gaborit
* \date 6 mai 2019
*
*
*
*/

#ifndef CONVERTERS_H
#define CONVERTERS_H

#include "controller_path.h"
#include "controller_crossing.h"
#include "controller_terrain.h"
#include "controller_resource.h"
#include "controller_player.h"
//#include "ressource.h"

typedef enum {
        BLE,
        BOIS,
        PIERRE,
        ARGILE,
        MOUTON
} TypeRessource;/* pour tester */

/**
* \struct PathCoordinates
* \brief Structure contenant les coordonnées dans le modèle d'un chemin.
*
* Les coordonnées d'un chemin comprennent une abscisse x, une ordonnée y et une position dans l'hexagone.
*/
typedef struct {
        double x;       /*!< Abscisse de l'hexagone où se trouve le chemin.*/
        double y;       /*!< Ordonnée de l'hexagone où se trouve le chemin.*/
        int position;   /*!< Position du chemin dans l'hexagone.*/
} PathCoordinates;

/**
* \struct CrossCoordinates
* \brief Structure contenant les coordonnées dans le modèle d'un croisement.
*
* Les coordonnées d'un croisement comprennent une abscisse x, une ordonnée y et une position dans l'hexagone.
*/
typedef struct {
        double x;       /*!< Abscisse de l'hexagone où se trouve le croisement.*/
        double y;       /*!< Ordonnée de l'hexagone où se trouve le croisement.*/
        int position;   /*!< Position du croisement dans l'hexagone.*/
} CrossCoordinates;

/**
* \struct TerrCoordinates
* \brief Structure contenant les coordonnées dans le modèle d'un terrain.
*
* Les coordonnées d'un terrain comprennent une abscisse x et une ordonnée y.
*/
typedef struct {
        double x;       /*!< Abscisse de l'hexagone correspondant au terrain.*/
        double y;       /*!< Ordonnée de l'hexagone correspondant au terrain.*/
} TerrCoordinates;

PathCoordinates pathButtonToPathCoordinates(PathButton path_clicked);
CrossCoordinates crossButtonToCrossCoordinates(CrossButton cross_clicked);
TerrCoordinates terrButtonToTerrCoordinates(TerrButton terr_clicked);
TypeRessource resourceButtonToTypeRessource(ResourceButton resource_clicked);
int playerButtonToInteger(PlayerButton player_clicked);

#endif //CONVERTERS_H
