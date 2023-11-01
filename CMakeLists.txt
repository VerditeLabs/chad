cmake_minimum_required(VERSION 3.10)

project(chad C ASM)
enable_language(ASM)

add_executable(chad
        chad.c
        main.c
        thirdparty/tgc/tgc.c
        chad_templates.h)


target_include_directories(chad PUBLIC
        thirdparty/cosmo
        thirdparty/tgc)

target_compile_options(chad PUBLIC -g -Og -gdwarf-4 -static -fPIE -fPIC)
target_link_options(chad PUBLIC    -g -Og -gdwarf-4 -static -fPIE -fPIC)

target_link_directories(chad PUBLIC thirdparty/cosmo)