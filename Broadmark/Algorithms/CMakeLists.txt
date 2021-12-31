add_executable(${PROJECT_NAME} AppMain.cpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        algorithm_core
        )

add_subdirectory(Dependencies)
add_subdirectory(Broadphase)
add_subdirectory(Core)