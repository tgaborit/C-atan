#ifndef PROBABILITE_H
#define PROBABILITE_H

#include "fenetre.h"
#include "get_plateau.h"
#include "plateau.h"

void Affiche2(SDL_Renderer* renderer, double posx, double posy);

void Affiche3(SDL_Renderer* renderer, double posx, double posy);

void Affiche4(SDL_Renderer* renderer, double posx, double posy);

void Affiche5(SDL_Renderer* renderer, double posx, double posy);

void Affiche6(SDL_Renderer* renderer, double posx, double posy);

void Affiche7(SDL_Renderer* renderer, double posx, double posy);

void Affiche8(SDL_Renderer* renderer, double posx, double posy);

void Affiche9(SDL_Renderer* renderer, double posx, double posy);

void Affiche10(SDL_Renderer* renderer, double posx, double posy);

void Affiche11(SDL_Renderer* renderer, double posx, double posy);

void Affiche12(SDL_Renderer* renderer, double posx, double posy);

void AfficheProbaNormal(SDL_Renderer* renderer);

void AfficheRandomProba(Partie* p, double x, double y, SDL_Renderer* renderer, double posimx, double posimy);

void AfficheRandomProbaPlateau(Partie *p, SDL_Renderer *renderer);

#endif
