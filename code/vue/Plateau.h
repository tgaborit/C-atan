#ifndef PLATEAU_H
#define PLATEAU_H

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>




void SDL_ExitWithError(const char *message);

void AfficheFenetre();

void AfficheTuile(SDL_Renderer* renderer);

void AfficheJoueur(SDL_Renderer *renderer);

void AfficheCarteArgile(SDL_Renderer *renderer);

void AfficheCarteBle(SDL_Renderer *renderer);

void AfficheCarteBois(SDL_Renderer *renderer);

void AfficheCarteMouton(SDL_Renderer *renderer);

void AfficheCarteArgile(SDL_Renderer *renderer);	

//void AfficheCartesDev(SDL_Renderer *renderer);

/*void AfficheConstructions(SDL_Renderer *renderer);	//faire une texture

void AfficheProbas(SDL_Renderer *renderer);

void AfficheReussite(SDL_Renderer *renderer);	//fonction modele

void AfficheHelp(SDL_Renderer *renderer);

void AfficheDes(SDL_Renderer *renderer);

void AfficheSkip(SDL_Renderer *renderer);*/

#endif
