//
// Created by tgaborit on 27/03/19.
//

#ifndef CATANE_CONTROLER_TURN_H
#define CATANE_CONTROLER_TURN_H

#define CARDW 115
#define CARDH 166

void controlerTurn(SDL_bool program_launched/*, partie * the_partie*/);
void quit(SDL_bool * program_launched);
void initWoodCard();
SDL_bool isInArea(SDL_MouseButtonEvent mouse_button, SDL_Rect area);

#endif //CATANE_CONTROLER_TURN_H
