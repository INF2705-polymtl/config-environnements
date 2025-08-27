# Aide à la configuration d'environnements pour INF2705

En INF2705, on doit se servir de plusieurs bibliothèques tierces pour travailler en OpenGL. Celles-ci sont plus ou moins bas niveau et servent à importer les fonctionnalités OpenGL et à gérer les fenêtres et événements. Il y a beaucoup de façon d'installer ces bibliothèques et ça dépend entièrement de la plateforme et de l'IDE sur lesquels on travaille.

Pour les biens du cours d'infographie, vous devez installer Vcpkg et configurer votre IDE de choix. Les fichiers de projets (solution Visual Studio et projet CMake) sont généralement fournis pour les exemples en classe et les laboratoires. **Vous pouvez donc vous limiter aux étapes présentées dans les TL;DR (*Too Long; Didn't Read*) pour les différents OS à la fin du présent document.**

## Configuration d'un IDE et gestionnaire de bibliothèque

Étant en C++, on ne peut pas faire `pip install ce-que-je-veux` partout. Ceci dit, travailler avec Vcpkg (gestionnaire de bibliothèques en C++) et CMake (comme des *makefile* fancy) permet d'approcher un peu ce comportement multiplateforme.

[Vcpkg.md](doc/Vcpkg.md) montre comment se servir de Vcpkg sur Windows, Linux et MacOS à l'aide de Visual Studio ou de VSCode et CMake.

Une fois Vcpkg et VSCode ou Visual Studio configurés sur votre machine, vous pouvez installer les bibliothèques nécessaires. On fait une série de `vcpkg install la-patante`.

## Installation des bibliothèques avec Vcpkg

Sur Windows, l'installation des bibliothèques avec Vcpkg semble se faire relativement sans trop d'embûches.

[Ubuntu.md](doc/Ubuntu.md) montre les étapes qui semblent être nécessaires avant de faire les `vcpkg install` à partir d'une installation assez vierge de Ubuntu 24.

Voici la commande pour installer les bibliothèques utiles pour le cours :

`vcpkg install glm sfml glbinding tinyobjloader imgui imgui-sfml`

Ce sont pas mal toutes les bibliothèques utilisées dans le cours.

## Tester le tout

Dans [ProjetTest](ProjetTest/) se trouve un petit programme qui permet de tester si votre configuration de Vcpkg est bien faite avec les bibliothèques bien installées. Il y a un [CMakeLists.txt](ProjetTest/CMakeLists.txt) et une [solution Visual Studio](ProjetTest/ProjetTest.sln) qui sont faites pour importer ce qui a été installé plus tôt. On a un *main.cpp* qui permet de rouler une fonctions qui exécute un programme OpenGL très simple : créer une fenêtre qui affiche un *ramp-up* de rouge. Chacune des fonctions (compilée dans son propre .cpp) utilise une certaine combinaison de bibliothèques.

Vous pouvez commentez/décommentez les appels dans le `main` pour rouler chaque programme. Vous pouvez faire la même chose pour les `target_link_libraries` et les `find_package` dans le *CMakeLists.txt* pour tester l'importation de chaque bibliothèque.

## TL;DR pour Windows

1. Installer la dernière version de Visual Studio (Community est suffisant) avec les modules de C++.
1. Créer un dossier d'installation pour Vcpkg (disons `C:\Users\<votre compte>\vcpkg`) et aller dans ce dossier avec un terminal.
1. `git clone https://github.com/microsoft/vcpkg .`
1. `.\bootstrap-vcpkg.bat` (vous pouvez ajouter `-disableMetrics`)
1. `.\vcpkg integrate install`
1. `.\vcpkg install glm sfml glbinding tinyobjloader imgui imgui-sfml`
1. Ajouter une variable d'environnement `VCPKG_ROOT` contenant `C:\Users\<votre compte>\vcpkg`.
1. Ajouter `C:\Users\<votre compte>\vcpkg` au `PATH`.
1. Ouvrir [ProjetTest.sln](ProjetTest/ProjetTest.sln) avec Visual Studio et exécuter le programme.

Si vous voulez utiliser VSCode sur Windows, vous devez faire toutes les étapes ci-dessus incluant l'installation de Visual Studio, car ça installe le compilateur. Vous devez ensuite installer VSCode à partir du site de Microsoft, puis installer les extensions *C/C++* et *CMake Tools*. Vous pouvez ensuite ouvrir le dossier [ProjetTest](ProjetTest) avec VSCode et exécuter le programme.

## TL;DR pour Linux

1.  1. Pour Ubuntu : `sudo apt-get install build-essential cmake cmake-extras tar curl zip unzip git autoconf pkg-config libgl1-mesa-dev libgl-dev libglu1-mesa-dev libtool libudev-dev libx11-dev libxcursor-dev libxi-dev libxinerama-dev libxmu-dev libxrandr-dev libxxf86vm-dev mesa-common-dev xorg-dev python3 python3-jinja2`
    1. Pour CentOS : `sudo dnf install cmake git clang autoconf libtool systemd-devel libX11 libX11-devel libXcursor libXcursor-devel libXrandr libXrandr-devel mesa-libGL mesa-libGL-devel mesa-libGLU mesa-libGLU-devel libXi libXi-devel perl-open perl-FindBin python3-jinja2 libXinerama libXinerama-devel`
1. Installer VSCode (à traver le genre de *app store* d'Ubuntu ou [avec YUM ou DNF](https://code.visualstudio.com/docs/setup/linux#_rhel-fedora-and-centos-based-distributions) sur CentOS).
1. Installer les extensions *C/C++* et *CMake Tools* pour VSCode.
1. Créer un dossier d'installation pour Vcpkg (disons `~/vcpkg`) et aller dans ce dossier avec un terminal.
1. `git clone https://github.com/microsoft/vcpkg .`
1. `./bootstrap-vcpkg.sh` (vous pouvez ajouter `-disableMetrics`)
1. `./vcpkg integrate install`
1. `./vcpkg install glm sfml glbinding tinyobjloader imgui imgui-sfml`
1. Ajouter une variable d'environnement `VCPKG_ROOT` contenant `~/vcpkg` (ou préférablement le chemin complet vers ce dossier).
1. Ajouter `~/vcpkg` au `PATH`.
1. Redémarrer la machine? Ça semble nécessaire pour certains.
1. Ouvrir le dossier [ProjetTest](ProjetTest) avec VSCode et exécuter le programme.

## TL;DR pour MacOS

1. Faire une prière à la pomme toute puissante, créatrice du *iCloud* et de la terre.
1. Installer XCode.
1. Installer XQuartz.
1. Installer Homebrew.
1. `brew install pkg-config libxinerama libxcursor mesa-glu libxi`
1. Installer VSCode.
1. Installer les extensions *C/C++* et *CMake Tools* pour VSCode.
1. Créer un dossier d'installation pour Vcpkg (disons `~/vcpkg`) et aller dans ce dossier avec un terminal.
1. `git clone https://github.com/microsoft/vcpkg .`
1. `./bootstrap-vcpkg.sh` (vous pouvez ajouter `-disableMetrics`)
1. `./vcpkg integrate install`
1. `./vcpkg install glm sfml glbinding tinyobjloader imgui imgui-sfml`
1. Ajouter une variable d'environnement `VCPKG_ROOT` contenant `~/vcpkg` (ou préférablement le chemin complet vers ce dossier).
1. Ajouter `~/vcpkg` au `PATH`.
1. Ouvrir le dossier [ProjetTest](ProjetTest) avec VSCode et exécuter le programme.
