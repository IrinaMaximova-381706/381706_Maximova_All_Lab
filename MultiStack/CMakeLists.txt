file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${MultiStack} ${srcs} ${hdrs}) 
target_link_libraries(${MultiStack} ${MultiStackLib}) 


