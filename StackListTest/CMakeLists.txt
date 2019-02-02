file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${StackListTest} ${srcs} ${hdrs})
target_link_libraries(${StackListTest} ${StackListLib} gtest)
