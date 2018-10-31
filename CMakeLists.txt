cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME AllL) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

#set(Lift_lib Lift_lib) #Переменная с именем библиотеки

set(Vector Vector)
set(Vectorlib Vectorlib)
set(VectorTest VectorTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

#file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
#file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib ${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_subdirectory(gtest)
add_subdirectory(Vector) 
add_subdirectory(VectorLib) 
add_subdirectory(VectorTest)

#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
#add_subdirectory(Lift_lib) #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${Lift_lib}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}