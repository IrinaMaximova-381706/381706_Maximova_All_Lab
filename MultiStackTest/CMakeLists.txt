file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${MultiStackTest} ${srcs} ${hdrs})
target_link_libraries(${MultiStackTest} ${MultiStackLib} gtest)
