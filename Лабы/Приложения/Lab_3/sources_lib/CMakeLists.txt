add_library(lab_3_lib STATIC "")
target_include_directories(lab_3_lib PUBLIC "../includes")
target_sources(lab_3_lib PRIVATE "critical_section.cpp" "event.cpp" "mutex.cpp")