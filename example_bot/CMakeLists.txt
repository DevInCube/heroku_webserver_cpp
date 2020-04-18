cmake_minimum_required(VERSION 3.6)

project(mybot.out)

file(GLOB SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} heroku_webserver_cpp TgBot boost_system ssl crypto pthread)

# g++ -O2 -o mybot.out *.cpp --std=c++17 -lTgBot -lboost_system -lssl -lcrypto -lpthread