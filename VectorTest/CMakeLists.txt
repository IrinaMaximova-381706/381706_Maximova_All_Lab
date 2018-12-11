file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${VectorTest} ${srcs} ${hdrs})
target_link_libraries(${VectorTest} ${VectorLib} gtest)
