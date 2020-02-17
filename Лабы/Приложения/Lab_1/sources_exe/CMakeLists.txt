
add_executable(lab_1 "")

target_link_libraries(lab_1 PRIVATE lab_1_lib)

target_sources(lab_1 PRIVATE "../sources_exe/lab_1.cpp")