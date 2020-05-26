cmake_minimum_required(VERSION 3.16)
project(Code_for_the_Robot)

set(CMAKE_CXX_STANDARD 14)

include_directories(main)

add_executable(Code_for_the_Robot
        main/Button.h
        main/Buzzer.h
        main/DC_Motors.h
        main/Display.h
        main/Humidity_sensor.h
        main/LDR.cpp
        main/LDR.h
        main/LDRs.h
        main/LED.cpp
        main/LED.h
        main/LEDs.h
        main/main.ino
        main/Potentiometer.h
        main/Ultrasonic_sensor.h)
