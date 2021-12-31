SET(Bullet3Geometry_SRCS
        b3GeometryUtil.cpp
        )

SET(Bullet3Geometry_HDRS
        b3AabbUtil.h
        b3GeometryUtil.h
        )

ADD_LIBRARY(Bullet3Geometry ${Bullet3Geometry_SRCS} ${Bullet3Geometry_HDRS})