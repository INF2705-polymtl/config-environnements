cmake_minimum_required(VERSION 3.0.0)
# La raison pour laquelle on fait une variable d'environnement VCPKG_ROOT.
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# Le nom du projet.
project(INF2705_Exemple)

# On met les fichiers sources (incluant les entêtes)
set(ALL_FILES
    "main.cpp"
    "runSfmlExample.cpp"
    "runGlutExample.cpp"
    "runSdlExample.cpp"
)
add_executable(${PROJECT_NAME} ${ALL_FILES})

# Les flags de compilation.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fsigned-char -Wno-unknown-pragmas -Wno-enum-compare")

# Tous ce qui suit sont des package Vcpkg. Pour savoir quoi mettre, on fait "vcpkg install <le package>", puis on met ce qu'ils disent de mettre dans le CMakeLists.
# Vous pouvez commenter/décommenter les packages que vous utilisez ou pas.

# GLM: Pour les math comme en GLSL.
find_package(glm CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

# SFML: Pour la gestion de fenêtre et d'événements.
#       Tout en C++, assez clean et léger.
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

# glbinding: Pour l'importation des fonctions OpenGL et la résolution d'adresses.
#            Tout en C++ assez moderne, très clean avec des enum, des namespace et peu de macros.
find_package(glbinding CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glbinding::glbinding glbinding::glbinding-aux)

# GLUT: Pour les fenêtres, événements et importation de fonctions OpenGL.
#       En C, très vieux et pas maintenu, mais ça fonctionne alors tout le monde s'en sert encore.
find_package(GLUT REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GLUT::GLUT)

# GLFW: Pour les fenêtres, événements et importation de fonctions OpenGL.
#       En C, un peu plus propre et maintenu que GLUT.
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

# SDL: Pour la gestion de fenêtre et d'événements.
#      En C, un peu vieux mais encore maintenu et utilisé.
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

# GLEW: Pour l'importation des fonctions OpenGL et la résolution d'adresses.
#       En C, ressemble à GLUT, ça fonctionne bien mais c'est plein de macros.
find_package(GLEW REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)
