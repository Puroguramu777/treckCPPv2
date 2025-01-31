cmake_minimum_required(VERSION 3.16)

project(TrekAgency VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)  # Active la gestion automatique des fichiers .ui
set(CMAKE_AUTOMOC ON)  # Active la gestion automatique des fichiers .moc
set(CMAKE_AUTORCC ON)  # Active la gestion automatique des fichiers .qrc

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trouver Qt6 et ses composants nécessaires
find_package(Qt6 REQUIRED COMPONENTS Core Sql Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    database_manager.cpp
    test_db.cpp
    test_db.h
)

# Assurez-vous que le dossier contenant database_manager.h est bien inclus
include_directories(${CMAKE_SOURCE_DIR})  # Si database_manager.h est dans le même répertoire que les autres fichiers sources

# Créer l'exécutable
qt_add_executable(TrekAgency
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    database_manager.h
)

# Lier les bibliothèques Qt6
target_link_libraries(TrekAgency PRIVATE Qt6::Core Qt6::Sql Qt6::Widgets)

# Comparaison de version Qt6 pour des options spécifiques
if(Qt6_VERSION VERSION_LESS "6.1.0")
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TrekAgency)
endif()

# Définir les propriétés du projet pour MacOS et Windows
set_target_properties(TrekAgency PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Ajouter les directives d'installation pour le projet
include(GNUInstallDirs)
install(TARGETS TrekAgency
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finaliser l'exécutable si Qt6 est utilisé
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TrekAgency)
endif()
