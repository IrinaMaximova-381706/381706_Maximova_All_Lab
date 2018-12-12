file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${MatrixTest} ${srcs} ${hdrs})
target_link_libraries(${MatrixTest} ${MatrixLib} gtest)
