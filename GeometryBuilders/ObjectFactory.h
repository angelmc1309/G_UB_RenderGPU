#pragma once

#include "Geometry/Object.h"

class ObjectFactory
{
    ObjectFactory(){};

public:

    static ObjectFactory& getInstance() {
        static ObjectFactory instance;
        return instance;
    }

    shared_ptr<Object> createObject(QString &fileName, float data);
    shared_ptr<Object> createObject(vector<vec3>points, vector<double> properties, float data, QString fileName);
    shared_ptr<Object> createPlane(vector<vec3>points);

};

