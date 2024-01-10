# Étapes de configuration pour Ubuntu

Un fois que votre Vcpkg et votre VSCode sont bien configurés, vous devriez pouvoir faire un *hello world* en C++ et importer une bibliothèque simple comme TCLAP.

Pour certains, il semble y avoir un problème avec la version de CMake installé par *snap*. Si dans VSCode vous avez une erreur du genre *Bad CMake executable*, faites selon [quelqu'un sur *askubuntu*](https://askubuntu.com/questions/1353824/bad-cmake-executable-vscode) et réinstallez CMake :

```
snap remove cmake
sudo apt-get update
sudo apt-get install cmake
sudo apt-add-repository universe
sudo apt-get install cmake-extras
```

Pour importer les bibliothèques reliées à OpenGL, sur Ubuntu il faut d'abord installer d'autres modules et bibliothèques au niveau utilisateur avec des bons vieux `sudo apt-get install mon-affaire`. En fait, Vcpkg vous dit s'il y a des `apt-get install` à faire quand vous faites `vcpkg install`.

On a compilé la liste des modules *apt* qui semblent être requis :

`sudo apt-get install autoconf pkg-config libgl1-mesa-dev libgl-dev libglu1-mesa-dev libtool libudev-dev libx11-dev libxcursor-dev libxi-dev libxinerama-dev libxmu-dev libxrandr-dev libxxf86vm-dev mesa-common-dev xorg-dev python3 python3-distutils python3-jinja2`

Après ça, vous devriez pouvoir faire tous vos `vcpkg install` d'un coup sans trop de problèmes.
