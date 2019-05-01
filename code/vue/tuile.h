#ifndef TUILE_H
#define TUILE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>


#include "fenetre.h"
#include "ressource.h"
#include "get_plateau.h"
#include "joueur.h"
#include "plateau.h"


void AfficheTuile(SDL_Renderer* renderer);

void AfficheTuileArgile(SDL_Renderer* renderer, double x, double y);

void AfficheTuileBle(SDL_Renderer* renderer, double x, double y);

void AfficheTuileBois(SDL_Renderer* renderer, double x, double y);

void AfficheTuileMouton(SDL_Renderer* renderer, double x, double y);

void AfficheTuileRoche(SDL_Renderer* renderer, double x, double y);

void AfficheRandomTuile(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy);

void AfficheTuilePlateau(Partie *p, SDL_Renderer *renderer);

#endif
