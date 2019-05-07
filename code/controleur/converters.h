/**
* \file converters.h
* \brief
* \author Titouan Gaborit
* \date 6 mai 2019
*
*
*
*/

#ifndef CONVERTERS_H
#define CONVERTERS_H

#include "controller_crossing.h"
#include "controller_resource.h"
#include "controller_path.h"

typedef enum {
        BLE,
        BOIS,
        PIERRE,
        ARGILE,
        MOUTON
} TypeRessource;/* pour tester */

typedef struct {
        double x;
        double y;
        int position;
} PathCoordinates;

typedef struct {
        double x;
        double y;
        int position;
} CrossCoordinates;

PathCoordinates pathButtonToPathCoordinates(PathButton path_clicked);
CrossCoordinates crossButtonToCrossCoordinates(CrossButton cross_clicked);
TypeRessource resourceButtonToTypeRessource(ResourceButton resource_clicked);

#endif //CONVERTERS_H
