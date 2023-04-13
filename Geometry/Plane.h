#ifndef PLANE_H
#define PLANE_H

#include "Geometry/Object.h"

class Plane: public Object
{
public:
    Plane(vector<vec3> planeLimits);
    ~Plane();
private:
    //shared_ptr<Object> plane;
};

#endif // PLANE_H
