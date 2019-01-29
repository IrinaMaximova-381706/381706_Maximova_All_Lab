file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${Polish} ${srcs} ${hdrs}) 
target_link_libraries(${Polish} ${PolishLib}) 


