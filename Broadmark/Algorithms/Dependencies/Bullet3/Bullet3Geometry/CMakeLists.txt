set(Bullet3Geometry_SRCS
        b3GeometryUtil.cpp
        )

set(Bullet3Geometry_HDRS
        b3AabbUtil.h
        b3GeometryUtil.h
        )

add_library(Bullet3Geometry ${Bullet3Geometry_SRCS} ${Bullet3Geometry_HDRS})