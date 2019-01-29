file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${PolishTest} ${srcs} ${hdrs})
target_link_libraries(${PolishTest} ${PolishLib} gtest)
