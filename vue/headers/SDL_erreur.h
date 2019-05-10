/**
 * \file SDL_erreur.h
 * \brief fichier de fonctions de gestion d'erreur
 * \author Emmanuel.D
 * \version 1.0
 * \date 02 mai 2019
 *
 * Déclare les fonctions utiles aux erreurs liées à l'utilisation de SDL2
 */

#ifndef SDL_ERREUR_H
#define SDL_ERREUR_H

#include <SDL.h>
#include <SDL_ttf.h>


/**
 * \fn void SDL_ExitWithError(const char *message)
 * \brief Fonction renvoyant un message d'erreur en SDL.
 *
 *
 * \param message, un pointeur vers le message d'erreur
 * \return aucun
 */

void SDL_ExitWithError(const char *message);

#endif // SDL_ERREUR_H
