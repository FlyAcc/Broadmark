include_directories(
        ${PROJECT_SOURCE_DIR}
)

SET(Bullet3Collision_SRCS
        BroadPhaseCollision/b3DynamicBvh.cpp
        BroadPhaseCollision/b3DynamicBvhBroadphase.cpp
        BroadPhaseCollision/b3OverlappingPairCache.cpp
        )

SET(Bullet3CollisionBroadPhase_HDRS
        BroadPhaseCollision/b3BroadphaseCallback.h
        BroadPhaseCollision/b3DynamicBvh.h
        BroadPhaseCollision/b3DynamicBvhBroadphase.h
        BroadPhaseCollision/b3OverlappingPair.h
        BroadPhaseCollision/b3OverlappingPairCache.h
        )

SET(Bullet3CollisionBroadPhaseShared_HDRS
        BroadPhaseCollision/shared/b3Aabb.h
        )

SET(Bullet3Collision_HDRS
        ${Bullet3CollisionBroadPhase_HDRS}
        ${Bullet3CollisionBroadPhaseShared_HDRS}
        )

ADD_LIBRARY(Bullet3Collision ${Bullet3Collision_SRCS} ${Bullet3Collision_HDRS})