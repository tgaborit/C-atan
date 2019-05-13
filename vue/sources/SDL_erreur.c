/**
 * \file SDL_erreur.c
 * \brief fichier de fonctions de gestion d'erreur
 * \author Emmanuel.D
 * \version 1.0
 * \date 02 mai 2019
 *
 * Implémente les fonctions utiles aux erreurs liées à l'utilisation de SDL2
 */

 #include "SDL_erreur.h"


/**
 * \fn void SDL_ExitWithError(const char *message)
 * \brief Fonction renvoyant un message d'erreur en SDL.
 *
 *
 * \param message, un pointeur vers le message d'erreur
 * \return aucun
 */

void SDL_ExitWithError(const char *message)
{
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
    exit(EXIT_FAILURE);
}
