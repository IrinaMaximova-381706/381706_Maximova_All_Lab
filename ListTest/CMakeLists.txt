file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${ListTest} ${srcs} ${hdrs})
target_link_libraries(${ListTest} ${ListLib} gtest)
