add_library(lab_1_lib STATIC "")
target_include_directories(lab_1_lib PUBLIC "../includes")
target_sources(lab_1_lib PRIVATE "names.cpp" "directories.cpp" "version.cpp" "metrics.cpp" "parameters.cpp")