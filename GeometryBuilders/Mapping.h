#pragma once

#include <string.h>

#include "DataService/ConfigMappingReader.h"
#include "Geometry/ColorMap.h"
#include "Geometry/ColorMapStatic.h"
#include "Geometry/Material.h"
#include "GeometryBuilders/ObjectFactory.h"

#include <QString>

using namespace std;



class Mapping
{
public:

    Mapping();
    Mapping(const shared_ptr<ConfigMappingReader> configMapping);

    vec3  mapeigPunt(vec3 puntMonReal);
    float mapeigValor(float valorMonReal);
    float mapeigValor(float valorMonReal, int i);
    double getPlaneCenter() { return setup->dPlaorRadi; }

    shared_ptr<Material> mapeigMaterial(int i, ColorMapStatic::ColorMapType tCM, double valorReal);

    int getNumProps() { return setup->numProp; };

    QString getObjectPath(int i) {
        return setup->propPaths[i];
    }
    QString getObjectTexPath(int i) {
        return setup->propTexPath[i];
    }
    ColorMapStatic::ColorMapType getObjectMaterial(int i) {
        return setup->propsColor[i];
    }


    shared_ptr<ColorMap> getColorMap(ColorMapStatic::ColorMapType tCM);


private:
    shared_ptr<ConfigMappingReader> setup;
};

