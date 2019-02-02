file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${PolynomialTest} ${srcs} ${hdrs})
target_link_libraries(${PolynomialTest} ${PolynomialLib} gtest)
