cmake_minimum_required(VERSION 3.10)

project(chad C ASM)
enable_language(ASM)

add_executable(chad
        chad.c
        main.c
        chad_templates.h
        chad_templates.c
        thirdparty/tgc/tgc.c)


target_include_directories(chad PUBLIC
        thirdparty/cosmo
        thirdparty/tgc)

target_compile_options(chad PUBLIC -g -O0 -gdwarf-4 -fPIE -fPIC)
target_link_options(chad PUBLIC    -g -O0 -gdwarf-4 -fPIE -fPIC)

target_compile_options(chad PUBLIC -fsanitize=address -fno-omit-frame-pointer)
target_link_options(chad PUBLIC -fsanitize=address -fno-omit-frame-pointer)

target_link_directories(chad PUBLIC thirdparty/cosmo)