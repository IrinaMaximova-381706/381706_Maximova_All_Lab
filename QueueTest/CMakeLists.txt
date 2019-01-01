file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${QueueTest} ${srcs} ${hdrs})
target_link_libraries(${QueueTest} ${QueueLib} gtest)
