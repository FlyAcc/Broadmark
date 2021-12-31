include_directories(
        "${PROJECT_SOURCE_DIR}/../../"
        ${PROJECT_SOURCE_DIR}
)

find_package(CUDAToolkit)

SET(Bullet3OpenCL_clew_SRCS
        ParallelPrimitives/b3RadixSort32CL.cpp
        ParallelPrimitives/b3PrefixScanFloat4CL.cpp
        ParallelPrimitives/b3PrefixScanCL.cpp
        ParallelPrimitives/b3LauncherCL.cpp
        ParallelPrimitives/b3FillCL.cpp
        ParallelPrimitives/b3BoundSearchCL.cpp
        Initialize/b3OpenCLUtils.cpp
        BroadphaseCollision/b3GpuSapBroadphase.cpp
        BroadphaseCollision/b3GpuParallelLinearBvhBroadphase.cpp
        BroadphaseCollision/b3GpuParallelLinearBvh.cpp
        BroadphaseCollision/b3GpuGridBroadphase.cpp
        )


SET(Bullet3OpenCL_clew_HDRS
        BroadphaseCollision/b3SapAabb.h
        BroadphaseCollision/b3GpuGridBroadphase.h
        BroadphaseCollision/b3GpuBroadphaseInterface.h
        Initialize/b3OpenCLInclude.h
        Initialize/b3OpenCLUtils.h
        BroadphaseCollision/b3GpuParallelLinearBvhBroadphase.h
        BroadphaseCollision/b3GpuSapBroadphase.h
        BroadphaseCollision/b3GpuParallelLinearBvh.h
        ParallelPrimitives/b3BoundSearchCL.h
        ParallelPrimitives/b3BufferInfoCL.h
        ParallelPrimitives/b3FillCL.h
        ParallelPrimitives/b3LauncherCL.h
        ParallelPrimitives/b3OpenCLArray.h
        ParallelPrimitives/b3PrefixScanCL.h
        ParallelPrimitives/b3PrefixScanFloat4CL.h
        ParallelPrimitives/b3RadixSort32CL.h
        )


ADD_LIBRARY(Bullet3OpenCL_clew ${Bullet3OpenCL_clew_SRCS} ${Bullet3OpenCL_clew_HDRS})

target_link_libraries(Bullet3OpenCL_clew PRIVATE CUDA::OpenCL Bullet3Common)