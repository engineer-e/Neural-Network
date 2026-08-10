cmake_minimum_required(VERSION 3.22)

project(Neural_Network_Design_2e)

set(CMAKE_CXX_STANDARD 17)


add_executable(Neural_Network_Design_2e
    main.cpp menu.h single_input_neuron.h
)

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/output")

add_custom_command(TARGET Neural_Network_Design_2e POST_BUILD

    COMMAND ${CMAKE_COMMAND} -E make_directory
    "${OUTPUT_DIR}"

    COMMAND ${CMAKE_COMMAND} -E copy
    "$<TARGET_FILE:Neural_Network_Design_2e>"
    "${OUTPUT_DIR}"


    COMMENT "Output Generated"

)
