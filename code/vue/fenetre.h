#ifndef FENETRE_H
#define FENETRE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "get_plateau.h"
#include "architecture.h"
#include "carte.h"
#include "developpement.h"
#include "probabilite.h"
#include "tuile.h"



void SDL_ExitWithError(const char *message);

SDL_Window* InitFenetre();

SDL_Renderer* updateFenetre(Partie* p, SDL_Window* window, SDL_Renderer* oldrenderer);

void destroyFenetre(SDL_Window* window, SDL_Renderer* renderer);

void AfficheFenetre();

void AfficheHelp(SDL_Renderer *renderer);

void AfficheDe(SDL_Renderer *renderer);

void AfficheSkip(SDL_Renderer *renderer);

void AfficheJetonVoleur(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy);

void AfficheVoleur(Partie* p, SDL_Renderer* renderer);

void AfficheJoueur(SDL_Renderer* renderer);

#endif
