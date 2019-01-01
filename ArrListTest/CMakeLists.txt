file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${ArrListTest} ${srcs} ${hdrs})
target_link_libraries(${ArrListTest} ${ArrListLib} gtest)
