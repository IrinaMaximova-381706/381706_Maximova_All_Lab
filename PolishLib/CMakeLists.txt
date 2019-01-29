file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${PolishLib} STATIC ${srcs} ${hdrs})


