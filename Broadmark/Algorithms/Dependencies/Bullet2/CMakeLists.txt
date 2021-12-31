project(bullet2)

set(BULLET2_SRCS
        LinearMath/btAlignedAllocator.cpp
        LinearMath/btGeometryUtil.cpp
        LinearMath/btQuickprof.cpp
        LinearMath/btThreads.cpp
        LinearMath/btVector3.cpp
        btAxisSweep3.cpp
        btBroadphaseProxy.cpp
        btCollisionAlgorithm.cpp
        btDbvt.cpp
        btDbvtBroadphase.cpp
        btDispatcher.cpp
        btOverlappingPairCache.cpp
        )

set(BULLET2_HDRS
        LinearMath/btVector3.h
        LinearMath/btQuickprof.h
        btBroadphaseInterface.h
        LinearMath/btAlignedAllocator.h
        LinearMath/btTransform.h
        LinearMath/btQuaternion.h
        LinearMath/btAabbUtil2.h
        btAxisSweep3.h
        LinearMath/btGeometryUtil.h
        LinearMath/btThreads.h
        LinearMath/btMatrix3x3.h
        btBroadphaseProxy.h
        btDbvt.h
        LinearMath/btTransformUtil.h
        btCollisionAlgorithm.h
        btAxisSweep3Internal.h
        LinearMath/btMinMax.h
        LinearMath/btAlignedObjectArray.h
        LinearMath/btQuadWord.h
        LinearMath/btMatrixX.h
        LinearMath/btScalar.h
        btDbvtBroadphase.h
        btDispatcher.h
        btOverlappingPairCache.h
        btOverlappingPairCallback.h
        )

add_library(${PROJECT_NAME} ${BULLET2_SRCS} ${BULLET2_HDRS})