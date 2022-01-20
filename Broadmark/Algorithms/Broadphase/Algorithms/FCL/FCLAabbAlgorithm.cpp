#include "FCLAabbAlgorithm.h"

using namespace fcl;

bool simpleCallback(fcl::CollisionObjectf *obj1, fcl::CollisionObjectf *obj2,
                    void *data) {
  auto *collision_data = static_cast<CustomCollisionData *>(data);
  Object *objects = collision_data->algorithm->m_objects;
  collision_data->algorithm->m_cache.AddPair(
      &objects[(int)obj1->getUserData()], &objects[(int)obj2->getUserData()]);
  return collision_data->done;
}

void FCLAabbAlgorithm::Initialize(InflatedSettings settings,
                                  const SceneFrame &frameData) {
  BaseAlgorithm<Object, SimpleCache>::Initialize(settings, frameData);
  manager = new DynamicAABBTreeCollisionManager<float>();
  size_t count = m_settings.m_numberOfObjects;
  objects = std::vector<CollisionObjectf *>(count);
  for (int i = 0; i < m_settings.m_numberOfObjects; ++i) {
    const Aabb &aabb = frameData.m_aabbs[i];
    Vec3 size = aabb.Size();
    auto box = std::make_shared<Boxf>(Vector3f(size[0], size[1], size[2]));
    objects[i] = new CollisionObjectC(box, Transform3f::Identity());
    objects[i]->setUserData(reinterpret_cast<void *>(i));
  }
  manager->registerObjects(objects);
  manager->setup();
}

void FCLAabbAlgorithm::UpdateObjects(const SceneFrame &frameData) {
  BaseAlgorithm::UpdateObjects(frameData);

  for (int i = 0; i < m_settings.m_numberOfObjects; ++i) {
    const Aabb &aabb = frameData.m_aabbs[i];
    auto *objectC = (CollisionObjectC *)(objects[i]);
    objectC->getMutableAABB().min_ =
        Vector3f(aabb.m_min[0], aabb.m_min[1], aabb.m_min[2]);
    objectC->getMutableAABB().max_ =
        Vector3f(aabb.m_max[0], aabb.m_max[1], aabb.m_max[2]);
  }
}

void FCLAabbAlgorithm::SearchOverlaps() {
  DefaultCollisionData<float> *data = new CustomCollisionData(this);
  manager->collide(data, simpleCallback);
}

void FCLAabbAlgorithm::UpdateStructures() { manager->update(); }
