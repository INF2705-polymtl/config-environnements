# Aide à la configuration d'environnements pour INF2705

En INF2705, on doit se servir de plusieurs bibliothèques tierces pour travailler en OpenGL. Celles-ci sont plus ou moins bas niveau et servent à importer les fonctionnalités OpenGL et à gérer les fenêtres et événements. Il y a beaucoup de façon d'installer ces bibliothèques et ça dépend entièrement de la plateforme et de l'IDE sur lesquels on travaille.

Pour les biens du cours d'infographie, vous devez installer Vcpkg et configurer votre IDE de choix. Les fichiers de projets (solution Visual Studio et projet CMake) sont généralement fournis pour les exemples en classe et les laboratoires. Vous pouvez donc vous limiter aux étapes présentées dans les TL;DR (*Too Long Didn't Read*) pour Windows et Ubuntu à la fin du présent document.

## Configuration d'un IDE et gestionnaire de bibliothèque

Étant en C++, on ne peut pas faire `pip install ce-que-je-veux` partout. Ceci dit, travailler avec Vcpkg (gestionnaire de bibliothèques en C++) et CMake (comme des *makefile* fancy) permet d'approcher un peu ce comportement multiplateforme.

[Vcpkg.md](doc/Vcpkg.md) montre comment se servir de Vcpkg sur Windows, Linux et MacOS à l'aide de Visual Studio ou de VSCode et CMake.

Une fois Vcpkg et VSCode ou Visual Studio configurés sur votre machine, vous pouvez installer les bibliothèques nécessaires. Dépendemment de ce que vous faites, vous pourriez avoir besoin de SDL, SFML, GLUT, GLEW, GLFW et glbinding. On fait une série de `vcpkg install la-patante`.

## Installation des bibliothèques avec Vcpkg

Sur Windows, l'installation des bibliothèques avec Vcpkg semble se faire relativement sans trop d'embûches.

[Ubuntu.md](doc/Ubuntu.md) montre les étapes qui semblent être nécessaires avant de faire les `vcpkg install` à partir d'une installation assez vierge de Ubuntu 24.

Voici la commande pour installer les bibliothèques utiles pour le cours :

`vcpkg install glm sfml glbinding sdl2 freeglut glew glfw3 tinyobjloader`

On ne va jamais se servir de toutes celles-ci en même temps dans le même projet, mais plutôt dans des combinaisons différentes. D'une part, les [exemples originaux de Benoît Ozell](https://gitlab.com/ozell/inf2705-exemples) utilise GLUT, SDL et GLEW. D'autre part, les [exemples de Charles Hosson](https://github.com/INF2705-polymtl/exemples-chosson) utilisent principalement SFML et glbinding. En laboratoire, ça varie.

Ce sont pas mal toutes les bibliothèques utilisées dans le cours.

## Tester le tout

Dans [ProjetTest](ProjetTest/) se trouve un petit programme qui permet de tester si votre configuration de Vcpkg est bien faite avec les bibliothèques bien installées. Il y a un [CMakeLists.txt](ProjetTest/CMakeLists.txt) et une [solution Visual Studio](ProjetTest/ProjetTest.sln) qui sont faites pour importer ce qui a été installé plus tôt. On a un *main.cpp* qui permet de rouler une fonctions qui exécute un programme OpenGL très simple : créer une fenêtre qui affiche un *ramp-up* de rouge. Chacune des fonctions (compilée dans son propre .cpp) utilise une certaine combinaison de bibliothèques.

Vous pouvez commentez/décommentez les appels dans le `main` pour rouler chaque programme. Vous pouvez faire la même chose pour les `target_link_libraries` et les `find_package` dans le *CMakeLists.txt* pour tester l'importation de chaque bibliothèque.

## TL;DR pour Windows

1. Installer la dernière version de Visual Studio (Community est suffisant) avec les modules de C++.
1. Créer un dossier d'installation pour Vcpkg (disons `C:\vcpkg`).
1. `git clone https://github.com/microsoft/vcpkg C:\vcpkg`
1. `C:\vcpkg\bootstrap-vcpkg.bat` (vous pouvez ajouter `-disableMetrics`)
1. Ajouter variable d'environnement `VCPKG_ROOT` contenant `C:\vcpkg`.
1. Ajouter `C:\vcpkg` au `PATH`.
1. `vcpkg integrate install`
1. `vcpkg install glm sfml glbinding sdl2 freeglut glew glfw3 tinyobjloader`
1. Ouvrir [ProjetTest.sln](ProjetTest/ProjetTest.sln) avec Visual Studio et exécuter le programme.
1. Réaliser que c'était probablement la première fois qu'on a utilisé un outil de Microsoft qui fonctionne bien. 🤯

## TL;DR pour Ubuntu

1. `sudo apt-get install build-essential cmake cmake-extras tar curl zip unzip git`
1. Installer VSCode (à traver le genre de *app store* d'Ubuntu).
1. Installer les extensions *C/C++* et *CMake Tools* pour VSCode.
1. Créer un dossier d'installation pour Vcpkg (disons `~/vcpkg`).
1. `git clone https://github.com/microsoft/vcpkg ~/vcpkg`
1. `~/vcpkg/bootstrap-vcpkg.sh` (vous pouvez ajouter `-disableMetrics`)
1. Ajouter variable d'environnement `VCPKG_ROOT` contenant `/vcpkg`.
1. Ajouter `~/vcpkg` au `PATH`.
1. `vcpkg integrate install`
1. `sudo apt-get install autoconf pkg-config libgl1-mesa-dev libgl-dev libglu1-mesa-dev libtool libudev-dev libx11-dev libxcursor-dev libxi-dev libxinerama-dev libxmu-dev libxrandr-dev libxxf86vm-dev mesa-common-dev xorg-dev python3 python3-jinja2`
1. `vcpkg install glm sfml glbinding sdl2 freeglut glew glfw3 tinyobjloader`
1. Redémarrer la machine.
1. Ouvrir le dossier [ProjetTest](ProjetTest) avec VSCode et exécuter le programme.
1. ???
1. profit

## Conclusion

Les résultats peuvent varier, consultez un médecin si votre configuration d'environnement persiste plus que quatre heures 😅.
