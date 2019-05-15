cmake_minimum_required(VERSION 3.10)

# On appelle le projet catane
project(catane)

# CMake n'a pas de module FindSDL2_ttf.cmake, on en ajoute donc un dans l'arborescence projet.
# Il faut donc ajouter son chemin dans les chemins des modules CMake.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# On génère les fichiers binaires dans un répertoire bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Liste des fichiers sources du modèle, de la vue et du contrôleur
file(GLOB_RECURSE CATANE_SOURCES
        ${CMAKE_SOURCE_DIR}/modele/*.c
        ${CMAKE_SOURCE_DIR}/vue/*.c
        ${CMAKE_SOURCE_DIR}/controleur/*.c
        )

# Liste des fichiers d'en-tête du modèle, de la vue et du contrôleur
file(GLOB_RECURSE CATANE_HEADERS
        ${CMAKE_SOURCE_DIR}/modele/*.h
        ${CMAKE_SOURCE_DIR}/vue/*.h
        ${CMAKE_SOURCE_DIR}/controleur/*.h
        )

# On ajoute les fichiers sources et les fichiers d'en-tête du modèle, de la vue, du contrôleur à l'exécutable catane.
# On ajoute aussi le fichier catane.c qui contient le main du programme.
add_executable(catane catane.c ${CATANE_SOURCES} ${CATANE_HEADERS})

# On ajoute les dossiers contenant les fichiers d'en-tête du modèle, de la vue, du contrôleur, à la liste des dossiers où chercher les fichiers d'en-tête
target_include_directories(catane PUBLIC ${CMAKE_SOURCE_DIR}/modele/headers ${CMAKE_SOURCE_DIR}/vue/headers ${CMAKE_SOURCE_DIR}/controleur/headers)

# On inclut la biliothèque math.h au projet
target_link_libraries(catane m)

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


# Liste des fichiers sources des tests
file(GLOB_RECURSE TESTS_SOURCES
        ${CMAKE_SOURCE_DIR}/tests/*.c
        )

# Liste des fichiers d'en-tête des tests
file(GLOB_RECURSE TESTS_HEADERS
        ${CMAKE_SOURCE_DIR}/tests/*.h
        )

# Liste des fichiers sources du modèle
file(GLOB_RECURSE MODELE_SOURCES
        ${CMAKE_SOURCE_DIR}/modele/*.c
        )

# Liste des fichiers d'en-tête du modèle
file(GLOB_RECURSE MODELE_HEADERS
        ${CMAKE_SOURCE_DIR}/modele/*.c
        )

# On ajoute les fichiers sources et les fichiers d'en-tête du modèle et des tests à l'exécutable catane_tests
add_executable(catane_tests ${MODELE_SOURCES} ${MODELE_HEADERS} ${TESTS_SOURCES} ${TESTS_HEADERS})

# On ajoute les dossiers contenant les fichiers d'en-tête du modèle, de la vue, du contrôleur, à la liste des dossiers où chercher les fichiers d'en-tête
target_include_directories(catane_tests PUBLIC ${CMAKE_SOURCE_DIR}/modele/headers ${CMAKE_SOURCE_DIR}/tests/modele/headers)

# Recherche de la bibliothèque externe cmocka
find_package(CMOCKA REQUIRED)

if (CMOCKA_FOUND)
    # Une fois la bibliothèque cmocka trouvée, elle est incluse au projet
    target_include_directories(catane_tests PUBLIC ${CMOCKA_INCLUDE_DIRS})
    target_link_libraries(catane_tests ${CMOCKA_LIBRARIES})
else()
    # Sinon, on affiche un message et on arrête le script
    message(FATAL_ERROR "libcmocka not found")
endif ()
