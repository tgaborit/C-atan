cmake_minimum_required(VERSION 3.10)

# On appelle le projet catane
project(catane)

# Liste des fichiers source du modèle
set(SOURCES_MODELE
        modele/sources/get_partie.c
        modele/sources/get_plateau.c
        modele/sources/joueur.c
        modele/sources/partie.c
        modele/sources/plateau.c
        modele/sources/set_partie.c
        modele/sources/set_plateau.c
        )

# Liste des fichiers d'en-tête du modèle
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

# Liste des fichiers source de la vue
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

# Liste des fichiers d'en-tête de la vue
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

# Liste des fichiers source du contrôleur
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

# Liste des fichiers d'en-tête du contrôleur
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

# On génère les fichiers binaires dans un répertoire bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# On ajoute les fichiers source et les fichiers d'en-tête du modèle, de la vue, du contrôleur à l'exécutable catane.
# On ajoute aussi le fichier catane.c qui contient le main du programme.
add_executable(catane catane.c
        ${SOURCES_MODELE} ${HEADERS_MODELE}
        ${SOURCES_VUE} ${HEADERS_VUE}
        ${SOURCES_CONTROLEUR} ${HEADERS_CONTROLEUR}
        )

# On ajoute les dossiers contenant les fichiers d'en-tête du modèle, de la vue, du contrôleur, à la liste des dossiers où chercher les fichiers d'en-tête
target_include_directories(catane PUBLIC ${CMAKE_SOURCE_DIR}/modele/headers ${CMAKE_SOURCE_DIR}/vue/headers ${CMAKE_SOURCE_DIR}/controleur/headers)

# On inclut la biliothèque math.h au projet
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