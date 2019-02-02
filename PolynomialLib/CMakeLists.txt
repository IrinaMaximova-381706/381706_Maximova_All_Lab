file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${PolynomialLib} STATIC ${srcs} ${hdrs})


