file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${MultiStackLib} STATIC ${srcs} ${hdrs})


