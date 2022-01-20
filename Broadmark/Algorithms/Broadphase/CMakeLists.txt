include_directories(
        ${PROJECT_SOURCE_DIR}/Algorithms
        ${PROJECT_SOURCE_DIR}/Algorithms/Dependencies/Bullet3
)

# fcl needs to put on the top, or it would show
# "Target "Broadmark" links to target "Eigen3::Eigen" but the target was not found"
find_package(fcl CONFIG REQUIRED)
find_package(CUDAToolkit)
find_package(CGAL CONFIG REQUIRED)

set(BROADPHASE_ALGORITHMS_SRCS
        Algorithms/BF/BF.cpp
        Algorithms/CGAL/CGAL.cpp
        Algorithms/DBVT/DBVT.cpp
        Algorithms/GPU/Bullet3GPUAlgorithms.cpp
        Algorithms/Grid/Grid.cpp
        Algorithms/iSAP/AxisSweep.cpp
        Algorithms/KD/KD.cpp
        Algorithms/KD/KD_Broadphase.cpp
        Algorithms/KD/KD_Operators.cpp
        Algorithms/KD/KD_Update.cpp
        Algorithms/KD/KD_Validation.cpp
        Algorithms/SAP/SAP.cpp
        Algorithms/Tracy/Tracy.cpp
        Algorithms/Tracy/Tracy_Parallel.cpp
        Algorithms/FCL/FCLAabbAlgorithm.cpp
        )

set(BROADPHASE_ALGORITHMS_HDRS
        BroadphaseInterface.h
        Object.h
        ObjectPair.h
        OverlapCache.h
        Algorithms/GPU/Bullet3GPUAlgorithms.h
        Algorithms/BF/BF_Base.h
        Algorithms/Grid/Grid_ND_SAP.h
        Algorithms/Grid/Grid.h
        Algorithms/SAP/SAP_Base.h
        OverlapChaches/HashedCache.h
        Algorithms/SAP/SAP_SIMD.h
        Algorithms/BF/BF.h
        Algorithms/SAP/SAP_SIMD_Parallel.h
        Algorithms/CGAL/CGAL.h
        Algorithms/BF/BF_SIMD_Parallel.h
        Algorithms/SoAAlgorithm.h
        Algorithms/BF/BF_SIMD.h
        OverlapChaches/NullCache.h
        Algorithms/Tracy/Tracy.h
        Algorithms/Grid/Grid_ND_SAP_Parallel.h
        Algorithms/Grid/Grid_ND.h
        Algorithms/Grid/Grid_ND_Parallel.h
        Algorithms/DBVT/DBVT.h
        Algorithms/KD/KD_Node.h
        Algorithms/Misc/None.h
        Algorithms/KD/KD_Object.h
        Algorithms/Misc/Inspectors.h
        Algorithms/SAP/SAP_Parallel.h
        Algorithms/BaseAlgorithm.h
        Algorithms/BF/BF_Parallel.h
        Algorithms/KD/KD.h
        Algorithms/SAP/SAP.h
        OverlapChaches/SimpleCache.h
        Algorithms/Tracy/Tracy_Parallel.h
        Algorithms/iSAP/AxisSweep.h
        Algorithms/Grid/Grid_Base.h
        Algorithms/FCL/FCLAabbAlgorithm.h
        )

add_library(broadphase_algorithms ${BROADPHASE_ALGORITHMS_HDRS} ${BROADPHASE_ALGORITHMS_SRCS})

target_link_libraries(broadphase_algorithms
        PUBLIC
        fcl
        CGAL::CGAL
        CUDA::OpenCL
        broadmark_dependencies
        bullet2
        Bullet3Collision
        )

