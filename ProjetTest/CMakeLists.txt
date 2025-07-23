cmake_minimum_required(VERSION 3.5.0)

# La raison pour laquelle on fait une variable d'environnement VCPKG_ROOT.
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# Le nom du projet.
project(ProjetTest)

# On met les fichiers sources (incluant les entêtes)
set(ALL_FILES
    "main.cpp"
    "runSfmlExample.cpp"
)
add_executable(${PROJECT_NAME} ${ALL_FILES})

# Les flags de compilation.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fsigned-char -Wno-unknown-pragmas -Wno-enum-compare -D WIN32_LEAN_AND_MEAN -D NOMINMAX -D _CRT_SECURE_NO_WARNINGS -D GLM_FORCE_SWIZZLE -D GLM_FORCE_INTRINSICS")

# Tous ce qui suit sont des package Vcpkg. Pour savoir quoi mettre, on fait "vcpkg install <le package>", puis on met ce qu'ils disent de mettre dans le CMakeLists.
# Vous pouvez commenter/décommenter les packages que vous utilisez ou pas.

# GLM: Pour les math comme en GLSL.
find_package(glm CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

# SFML: Pour la gestion de fenêtre et d'événements.
#       Tout en C++, assez clean et léger.
find_package(SFML COMPONENTS System Window Graphics CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::System SFML::Graphics SFML::Window)

# glbinding: Pour l'importation des fonctions OpenGL et la résolution d'adresses.
#            Tout en C++ assez moderne, très clean avec des enum, des namespace et peu de macros.
find_package(glbinding CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glbinding::glbinding glbinding::glbinding-aux)

# ImGui et ImGui-SFML: Pour l'ajout de GUI léger et facilement intégré.
find_package(imgui CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)
find_package(ImGui-SFML CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)
