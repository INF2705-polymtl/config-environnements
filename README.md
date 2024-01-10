# Aide à la configuration d'environnements pour INF2705

En INF2705, on doit se servir que plusieurs bibliothèques tierces pour travailler en OpenGL. Celles-ci sont plus ou moins bas niveau et servent à importer les fonctionnalités OpenGL et à gérer les fenêtres et événements. Il y a beaucoup de façon d'installer ces bibliothèques et ça dépend entièrement de la plateforme et de l'IDE sur lesquels on travaille.

## Configuration d'un IDE et gestionnaire de bibliothèque

Étant en C++, on ne peut pas faire `pip install ce-que-je-veux` partout. Ceci dit, travailler avec Vcpkg (gestionnaire de bibliothèques en C++) et CMake (comme des *makefile* fancy) permet d'approcher un peu ce comportement multiplateforme.

[Vcpkg.md](doc/Vcpkg.md) montre comment se servir de Vcpkg sur Windows, Linux et MacOS à l'aide de Visual Studio ou de VSCode et CMake.

Une fois Vcpkg et VSCode ou Visual Studio configurés sur votre machine, vous pouvez installer les bibliothèques nécessaires. Dépendemment de ce que vous faites, vous pourriez avoir besoin de SDL, SFML, GLUT, GLEW, GLFW et glbinding. On fait une série de `vcpkg install la-patante`.

## Installation des bibliothèques avec Vcpkg

Sur Windows, l'installation des bibliothèques avec Vcpkg semble se faire relativement sans trop d'embûches.

[Ubuntu.md](doc/Ubuntu.md) montre les étapes qui semblent être nécessaires avant de faire les `vcpkg install` à partir d'une installation assez vierge de Ubuntu 22.

Voici la commande pour installer les bibliothèques courantes d'OpenGL :

`vcpkg install glm sfml glbinding sdl2 freeglut glew glfw3`

On ne va jamais se servir de toutes celles-ci en même temps dans le même projet, mais plutôt dans des combinaisons différentes. D'une part, les [exemples originaux de Benoît Ozell](https://gitlab.com/ozell/inf2705-exemples) utilise GLUT, SDL et GLEW. D'autre part, les [exemples de Charles Hosson](https://github.com/orgs/INF2705-polymtl/repositories) utilisent principalement SFML et glbinding. En laboratoire, ça varie.

Ce ne sont pas toutes les bibliothèques utilisées dans le cours, il y en a aussi pour charger des images, du son, etc., mais c'est suffisant pour commencer à utiliser OpenGL.

## Tester le tout

Dans [ProjetVscodeOpenGL](ProjetVscodeOpenGL/) se trouve un petit programme qui permet de tester si votre VSCode avec CMake est bien configuré avec les bibliothèques bien installées. Il y a un [CMakeLists.txt](ProjetVscodeOpenGL/CMakeLists.txt) qui est fait pour importer ce qui a été installé plus tôt. On a un *main.cpp* qui permet de rouler une fonctions qui exécute un programme OpenGL très simple : créer une fenêtre qui affiche un *ramp-up* de rouge. Chacune des fonctions (compilée dans son propre .cpp) utilise une certaine combinaison de bibliothèques.

Vous pouvez commentez/décommentez les appels dans le `main` pour rouler chaque programme. Vous pouvez faire la même chose pour les `target_link_libraries` et les `find_package` dans le *CMakeLists.txt* pour tester l'importation de chaque bibliothèque.

## Conclusion

Ce sont des directives qui semblent suffisantes. Dans tous les cas, les résultats peuvent varier, consultez un médecin si votre configuration d'environnement persiste plus que quatre heures 😅.
