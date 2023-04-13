#pragma once


#include "Geometry/ColorMapStatic.h"
#include "DataService/RealDataReader.h"
#include "SceneFactory.h"
#include "Mapping.h"

class SceneFactoryData : public SceneFactory
{
public:
    SceneFactoryData(shared_ptr<ConfigMappingReader> mapping);
    virtual shared_ptr<Scene>  createScene(QString nomFitxer);
    virtual shared_ptr<Scene>  createScene();


private:
    vec3 normalPlaBase;
    double dPlaBase;
    double xMax, xMin, zMax, zMin;
    QString texturePath;
    //ObjectFactory::OBJECT_TYPES groundType;
};


