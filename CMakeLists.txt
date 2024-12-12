cmake_minimum_required(VERSION 3.16)
project(QtNetworkAndDatabase)

# Установите стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Найдите Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Network Sql)

# Укажите исходные файлы
set(SOURCES
    main.cpp
)

# Создайте исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})

# Подключите Qt6 модули
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Network
    Qt6::Sql
)
