add_library(lab_2_lib STATIC "")
target_include_directories(lab_2_lib PUBLIC "../includes")
target_sources(lab_2_lib PRIVATE "func.cpp")