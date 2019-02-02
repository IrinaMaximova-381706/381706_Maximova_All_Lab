cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME All_Labs) 
project(${PROJECT_NAME}) 

set(ExceptionLib ExceptionLib)

set(Vector Vector)
set(VectorLib VectorLib)
set(VectorTest VectorTest)

set(Matrix Matrix)
set(MatrixLib MatrixLib)
set(MatrixTest MatrixTest)

set(Stack Stack)
set(StackLib StackLib)
set(StackTest StackTest)

set(Queue Queue)
set(QueueLib QueueLib)
set(QueueTest QueueTest)

set(ArrList ArrList)
set(ArrListLib ArrListLib)
set(ArrListTest ArrListTest)

set(List List)
set(ListLib ListLib)
set(ListTest ListTest)

set(MultiStack MultiStack)
set(MultiStackLib MultiStackLib)
set(MultiStackTest MultiStackTest)

set(Polynomial Polynomial)
set(PolynomialLib PolynomialLib)
set(PolynomialTest PolynomialTest)

set(StackList StackList)
set(StackListLib StackListLib)
set(StackListTest StackListTest)

set(Polish Polish)
set(PolishLib PolishLib)
set(PolishTest PolishTest)


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ExceptionLib)
add_subdirectory(ExceptionLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib)
add_subdirectory(Vector)
add_subdirectory(VectorLib)
add_subdirectory(VectorTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib)
add_subdirectory(Matrix)
add_subdirectory(MatrixLib)
add_subdirectory(MatrixTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(Queue)
add_subdirectory(QueueLib)
add_subdirectory(QueueTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ArrListLib)
add_subdirectory(ArrList)
add_subdirectory(ArrListLib)
add_subdirectory(ArrListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(List)
add_subdirectory(ListLib)
add_subdirectory(ListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MultiStackLib)
add_subdirectory(MultiStack)
add_subdirectory(MultiStackLib)
add_subdirectory(MultiStackTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolynomialLib)
add_subdirectory(Polynomial)
add_subdirectory(PolynomialLib)
add_subdirectory(PolynomialTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackListLib)
add_subdirectory(StackList)
add_subdirectory(StackListLib)
add_subdirectory(StackListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolishLib)
add_subdirectory(Polish)
add_subdirectory(PolishLib)
add_subdirectory(PolishTest)




