add_executable(lab_5_test "")
target_link_libraries(lab_5_test PRIVATE lab_5_lib)
target_sources(lab_5_test PRIVATE "../sources_exe/lab_5_test.cpp")