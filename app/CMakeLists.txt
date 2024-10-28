set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
)

add_executable(Eudaimonia ${PROJECT_SOURCES})
target_link_libraries(Eudaimonia PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)