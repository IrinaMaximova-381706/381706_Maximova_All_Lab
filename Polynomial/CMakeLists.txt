file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${Polynomial} ${srcs} ${hdrs}) 
target_link_libraries(${Polynomial} ${PolynomialLib}) 


