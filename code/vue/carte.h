#ifndef TUILE_H
#define TUILE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "fenetre.h"


void AfficheCarteArgile(SDL_Renderer *renderer);

void AfficheCarteBle(SDL_Renderer *renderer);

void AfficheCarteBois(SDL_Renderer *renderer);

void AfficheCarteMouton(SDL_Renderer *renderer);

void AfficheCarteRoche(SDL_Renderer *renderer);

#endif

