#include "swTriangle.h"

namespace sw {

bool Triangle::intersect(const Ray &r, Intersection &isect) const {
    // TODO: Implement ray-triangle intersection

    Vec3 e1 = vertices[1] - vertices[0];
    Vec3 e2 = vertices[2] - vertices[0];

    Vec3 plane_normal = e1 % e2;

    float m = -plane_normal * vertices[0];

    float t = (plane_normal * r.orig + m) / (-plane_normal * r.dir);

    if (t < r.minT || t > r.maxT) return false;

    Vec3 Q = r.orig + t * r.dir;

    //Vec3 V0toQ = Q - vertices[0];

    isect.hitT = t;
    isect.normal = plane_normal;
    isect.normal.normalize();
    isect.frontFacing = (-r.dir * isect.normal) > 0.0f;
    if (!isect.frontFacing) isect.normal = -isect.normal;
    isect.position = Q;
    isect.material = material;
    isect.ray = r;

    return true;
} 

} // namespace sw
