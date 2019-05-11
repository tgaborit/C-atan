cmake_minimum_required(VERSION 3.10)


# On appelle le projet catane
project(catane)

set(SOURCES_MODELE
        modele/sources/get_partie.c
        modele/sources/get_plateau.c
        modele/sources/joueur.c
        modele/sources/partie.c
        modele/sources/plateau.c
        modele/sources/set_partie.c
        modele/sources/set_plateau.c
        )

set(HEADERS_MODELE
        modele/headers/get_partie.h
        modele/headers/get_plateau.h
        modele/headers/joueur.h
        modele/headers/partie.h
        modele/headers/plateau.h
        modele/headers/ressource.h
        modele/headers/set_partie.h
        modele/headers/set_plateau.h
        )

set(SOURCES_VUE
        vue/sources/affiche_joueur.c
        vue/sources/affiche_texte.c
        vue/sources/architecture.c
        vue/sources/carte.c
        vue/sources/developpement.c
        vue/sources/fenetre.c
        vue/sources/place_infra.c
        vue/sources/probabilite.c
        vue/sources/SDL_erreur.c
        vue/sources/tuile.c
        )

set(HEADERS_VUE
        vue/headers/affiche_joueur.h
        vue/headers/affiche_texte.h
        vue/headers/architecture.h
        vue/headers/carte.h
        vue/headers/developpement.h
        vue/headers/fenetre.h
        vue/headers/place_infra.h
        vue/headers/probabilite.h
        vue/headers/SDL_erreur.h
        vue/headers/tuile.h
        )

set(SOURCES_CONTROLEUR
        controleur/sources/controller.c
        controleur/sources/controller_crossing.c
        controleur/sources/controller_path.c
        controleur/sources/controller_player.c
        controleur/sources/controller_resource.c
        controleur/sources/controller_terrain.c
        controleur/sources/controller_turn.c
        controleur/sources/controller_turn_events.c
        controleur/sources/converters.c
        )

set(HEADERS_CONTROLEUR
        controleur/headers/controller.h
        controleur/headers/controller_crossing.h
        controleur/headers/controller_path.h
        controleur/headers/controller_player.h
        controleur/headers/controller_resource.h
        controleur/headers/controller_terrain.h
        controleur/headers/controller_turn.h
        controleur/headers/controller_turn_events.h
        controleur/headers/converters.h
        )

add_executable(catane catane.c
        ${SOURCES_MODELE} ${HEADERS_MODELE}
        ${SOURCES_VUE} ${HEADERS_VUE}
        ${SOURCES_CONTROLEUR} ${HEADERS_CONTROLEUR}
        )

target_include_directories(catane PUBLIC modele/headers vue/headers controleur/headers)

target_link_libraries(catane m)

# CMake n'a pas de module FindSDL2_ttf.cmake, on en ajoute donc un dans l'arborescence projet.
# Il faut donc ajouter son chemin dans les chemins des modules CMake.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Recherche des bibliothèques externes SDL2 et SDL2_ttf
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

if (SDL2_FOUND)
    # Une fois la bibliothèque SDL2 trouvée, elle est incluse au projet
    target_include_directories(catane PUBLIC ${SDL2_INCLUDE_DIRS})
    target_link_libraries(catane ${SDL2_LIBRARIES})
else()
    # Sinon, on affiche un message et on arrête le script
    message(FATAL_ERROR "libsdl2-dev not found")
endif ()

if (SDL2_TTF_FOUND)
    # Une fois la bibliothèque SDL2_ttf trouvée, elle est incluse au projet
    target_include_directories(catane PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
    target_link_libraries (catane ${SDL2_TTF_LIBRARIES})
else ()
    # Sinon, on affiche un message et on arrête le script
    message(FATAL_ERROR "libsdl2-ttf-dev not found")
endif ()