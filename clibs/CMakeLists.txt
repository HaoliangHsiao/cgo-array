project(demosdk)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false *.c)

set(SOURCES ${SOURCES})

include_directories(./)

add_library(${PROJECT_NAME} STATIC ${SOURCES})