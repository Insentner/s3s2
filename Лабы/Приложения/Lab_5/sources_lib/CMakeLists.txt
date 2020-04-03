add_library(lab_5_lib STATIC "")
target_include_directories(lab_5_lib PUBLIC "../includes")
target_sources(lab_5_lib PRIVATE "hz.cpp")