add_executable(${PROJECT_NAME} AppMain.cpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        algorithm_core
        )

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Broadmark_Release_x64")

add_subdirectory(Dependencies)
add_subdirectory(Broadphase)
add_subdirectory(Core)