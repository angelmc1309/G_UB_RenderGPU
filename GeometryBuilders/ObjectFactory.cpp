#include "ObjectFactory.h"
#include "Geometry/Plane.h"

shared_ptr<Object> ObjectFactory::createObject(QString &fileName, float data){
    shared_ptr<Object> o;
    o = make_shared<Object>(100000, fileName);
    return o;
}

shared_ptr<Object> ObjectFactory::createObject(vector<vec3>points, vector<double> properties, float data, QString fileName){
    shared_ptr<Object> o;
  
    o = make_shared<Object>(100000, fileName);

    return o;
}

shared_ptr<Object> ObjectFactory::createPlane(vector<vec3>points){
    shared_ptr<Object> o;

    o = make_shared<Plane>(points);

    return o;
}
