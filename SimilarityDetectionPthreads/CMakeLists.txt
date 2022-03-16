#CMakeLists.txt for generating Makefile for project compilation

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(SimilarityDetection)

# The version number.
SET (SimilarityDetection_VERSION_MAJOR 1)
SET (SimilarityDetection_VERSION_MINOR 0)

FIND_PACKAGE(BISON)
FIND_PACKAGE(FLEX)

FIND_PACKAGE(Threads REQUIRED)


BISON_TARGET(Parser res/dpl.y ${CMAKE_CURRENT_BINARY_DIR}/../src/parser.cpp)
FLEX_TARGET(Lexer res/dpl.l ${CMAKE_CURRENT_BINARY_DIR}/../src/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

SET(SOURCES
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Lexer_OUTPUTS}

    src/bison_util.cpp
    src/tokentype.cpp
    src/tokenizer_c_interface.cpp
    src/string_tokens.cpp

    src/ParserMain.cpp
    src/Scope.cpp
    src/Parameters.cpp
    src/Table.cpp
    src/Token.cpp

    src/Program.cpp
    src/ProgramPair.cpp

    src/KarpRabin.cpp
    src/KRGST.cpp
    src/GST_mod.cpp

    src/main.cpp
    )

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}/../include)

ADD_DEFINITIONS(-Wall -O3 -std=c++11 -pthread)

ADD_EXECUTABLE(app ${SOURCES})

TARGET_LINK_LIBRARIES(app ${CMAKE_THREAD_LIBS_INIT})

