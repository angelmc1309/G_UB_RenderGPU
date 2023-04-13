#include "SceneFactoryData.h"

SceneFactoryData::SceneFactoryData(shared_ptr<ConfigMappingReader> mr):SceneFactory()
{
    map = make_shared<Mapping>(mr);

    //this->normalPlaBase = mr->normalPlaorCentre;
    //this->dPlaBase = mr->dPlaorRadi;
    this->xMax = mr->Vxmax;
    this->xMin = mr->Vxmin;
    this->zMax = mr->Vzmax;
    this->zMin = mr->Vzmin;
    this->texturePath = mr->texturePath;
}


shared_ptr<Scene> SceneFactoryData::createScene(QString filename) {

    auto scene = make_shared<Scene>();
    auto rdr = make_shared<RealDataReader>(scene);
    rdr->readFile(filename, map);

    vector<vec3> vec;
    vec.push_back(vec3(xMin,0,zMax));
    vec.push_back(vec3(xMax,0,zMax));
    vec.push_back(vec3(xMin,0,zMin));
    vec.push_back(vec3(xMax,0,zMin));

    shared_ptr<Object> o  = ObjectFactory::getInstance().createPlane(vec);
    o->setTexture(make_shared<QOpenGLTexture>(QImage(this->texturePath).mirrored()));
    scene->objects.push_back(o);

    return scene;
}

shared_ptr<Scene> SceneFactoryData::createScene() {
    auto scene = make_shared<Scene>();
    return scene;
}
