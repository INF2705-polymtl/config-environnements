# Aide à la configuration d'environnements pour INF2705

En INF2705, on doit se servir que plusieurs bibliothèques tierces pour travailler en OpenGL. Celles-ci sont plus ou moins bas niveau et servent à importer les fonctionnalités OpenGL et à gérer les fenêtres et événements. Il y a beaucoup de façon d'installer ces bibliothèques et ça dépend entièrement de la plateforme et de l'IDE sur lesquels on travaille.

Étant en C++, on ne peut pas faire `pip install ce-que-je-veux` partout. Ceci dit, travailler avec Vcpkg (gestionnaire de bibliothèques en C++) et CMake (comme des *makefile* fancy) permet d'approcher un peu ce comportement multiplateforme.

[Vcpkg.md](doc/Vcpkg.md) montre comment se servir de Vcpkg sur Windows, Linux et MacOS à l'aide de Visual Studio ou de VSCode et CMake.

Une fois Vcpkg et VSCode ou Visual Studio configurés sur votre machine, vous pouvez installer les bibliothèques nécessaires. Dépendemment de ce que vous faites, vous pourriez avoir besoin de SDL, SFML, GLUT, GLEW, GLFW et glbinding. On fait une série de `vcpkg install la-patante`.

Sur Windows, l'installation des bibliothèques avec Vcpkg semble se faire relativement sans trop d'embûches.

[Ubuntu.md](doc/Ubuntu.md) montre les étapes qui semblent être nécessaires pour installer toutes ces librairies à partir d'une installation assez vierge de Ubuntu 22.

Ce sont des directives qui semblent suffisantes. Dans tous les cas, les résultats peuvent varier, consultez un médecin si votre configuration d'environnement persiste plus que quatre heures 😅.

