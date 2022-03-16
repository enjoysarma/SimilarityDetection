

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(SimilarityDetection)

FIND_PACKAGE(BISON)
FIND_PACKAGE(FLEX)

FIND_PACKAGE(CUDA QUIET REQUIRED)
LIST(APPEND CUDA_NVCC_FLAGS " -Xptxas -dlcm=ca -lineinfo --gpu-architecture=sm_52 -std=c++11; -O3; -DVERBOSE")
SET(CUDA_PROPAGATE_HOST_FLAGS OFF)

BISON_TARGET(Parser res/dpl.y ${CMAKE_CURRENT_BINARY_DIR}/../src/parser.cpp)
FLEX_TARGET(Lexer res/dpl.l ${CMAKE_CURRENT_BINARY_DIR}/../src/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

# Bring in the header files into the project
INCLUDE_DIRECTORIES(
    include

    kernels
    utility
    thrust
    )

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

    src/findMatchesKernel.cu
    src/GST_mod.cpp
    src/Refactor.cpp

    src/main.cpp
    )

ADD_DEFINITIONS(-g -Wall -O3 -std=c++11)

CUDA_ADD_EXECUTABLE(app ${SOURCES})

