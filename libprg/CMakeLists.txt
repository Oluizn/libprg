cmake_minimum_required(VERSION 3.21)

# Add header files here manually
set(HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/src/include/libprg/libprg.h"
        "${CMAKE_CURRENT_LIST_DIR}/src/include/libprg/projeto2.h"
        "${CMAKE_CURRENT_LIST_DIR}/src/include/libprg/aluno.h"
)
# Add source files here manually
set(SOURCES 
       "${CMAKE_CURRENT_LIST_DIR}/src/libprg/sum.c"
       "${CMAKE_CURRENT_LIST_DIR}/src/libprg/sub.c"
       "${CMAKE_CURRENT_LIST_DIR}/src/libprg/libprg.c"       
)

add_library(libprg
        src/libprg/lista_encadeada.c
        src/libprg/lista_contatos.c
        src/libprg/bubble_sort.c
        src/libprg/insertion_sort.c
        src/libprg/busca_linear.c
        src/libprg/busca_binario.c
        src/libprg/fila_estatica.c
        src/libprg/fila_dinamica.c
        src/libprg/pilha_estatica.c
        src/include/libprg/projeto2.h
        src/libprg/projeto2.c
        src/libprg/tabela_dispersao.c
        src/libprg/alunos.c
        src/include/libprg/aluno.h
        src/include/libprg/sort.h
        src/libprg/selection_sort.c
        src/libprg/imprimir.c
        src/libprg/merge_sort.c
        src/libprg/quick_sort.c
)
target_sources(libprg PUBLIC ${SOURCES})
target_include_directories(libprg PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/include)

target_compile_features(libprg PUBLIC c_std_17)

# https://cmake.org/cmake/help/latest/prop_tgt/AUTOGEN_TARGETS_FOLDER.html
source_group(
       TREE "${PROJECT_SOURCE_DIR}/libprg/src/include"
       PREFIX "Header Files"
       FILES ${HEADERS})

# https://cmake.org/cmake/help/latest/command/install.html
install(TARGETS libprg DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include)