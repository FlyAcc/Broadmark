include_directories(
        ${PROJECT_SOURCE_DIR}/Algorithms
        ${PROJECT_SOURCE_DIR}/Algorithms/Dependencies/
        ${PROJECT_SOURCE_DIR}/Algorithms/Dependencies/Bullet3
)

set(ALGORITHM_CORE_SRCS
        Math/Random.cpp
        Math/Vec3.cpp
        Algorithm.cpp
        Assertions.cpp
        Results.cpp
        Settings.cpp
        )

set(ALGORITHM_CORE_HDRS
        Math/Random.h
        Math/SIMD.h
        Algorithms.h
        Clock.h
        Math/Vec3.h
        Assertions.h
        Parallel.h
        Math/Aabb.h
        Math/Axis.h
        Math/Plane.h
        Structures/Pool.h
        Structures/Stack.h
        Results.h
        Scene.h
        Settings.h
        )

add_library(algorithm_core ${ALGORITHM_CORE_SRCS} ${ALGORITHM_CORE_HDRS})

target_link_libraries(algorithm_core
        PRIVATE
        broadphase_algorithms
        Bullet3OpenCL_clew
        )