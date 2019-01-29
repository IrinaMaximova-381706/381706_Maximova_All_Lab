file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${StackList} ${srcs} ${hdrs}) 
target_link_libraries(${StackList} ${StackListLib}) 


