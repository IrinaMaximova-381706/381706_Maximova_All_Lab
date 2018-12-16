file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${StackTest} ${srcs} ${hdrs})
target_link_libraries(${StackTest} ${StackLib} gtest)
