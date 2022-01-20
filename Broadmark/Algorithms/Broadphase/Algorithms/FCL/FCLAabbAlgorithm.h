#ifndef BROADMARK_FCLAABBALGORITHM_H
#define BROADMARK_FCLAABBALGORITHM_H

#include "Broadphase/Algorithms/BaseAlgorithm.h"
#include "Broadphase/OverlapChaches/SimpleCache.h"
#include "fcl/fcl.h"

class FCLAabbAlgorithm : public BaseAlgorithm<Object, SimpleCache> {
private:
  fcl::BroadPhaseCollisionManagerf *manager;
  std::vector<fcl::CollisionObjectf *> objects;

public:
  ~FCLAabbAlgorithm() override = default;
  void Initialize(InflatedSettings settings,
                  const SceneFrame &frameData) override;
  void UpdateObjects(const SceneFrame &frameData) override;
  void SearchOverlaps() override;
  void UpdateStructures() override;
};

class CollisionObjectC : public fcl::CollisionObjectf {
public:
  CollisionObjectC(const std::shared_ptr<fcl::CollisionGeometryf> &cgeom,
                   const fcl::Transform3f &tf)
      : CollisionObject(cgeom, tf) {}

  fcl::AABBf &getMutableAABB() { return aabb; }
};

class CustomCollisionData : public fcl::DefaultCollisionData<float> {
public:
  FCLAabbAlgorithm *algorithm;

public:
  CustomCollisionData(FCLAabbAlgorithm *algorithm)
      : fcl::DefaultCollisionData<float>(), algorithm((algorithm)){

                                            };
};

#endif // BROADMARK_FCLAABBALGORITHM_H
