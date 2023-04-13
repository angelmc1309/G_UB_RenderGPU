#pragma once


#include <QFile>
#include <QTextStream>
#include <iostream>
#include <sstream>
#include <QObject>
#include <QString>
#include <QStringList>
#include <vector>
#include "Geometry/Scene.h"
#include "GeometryBuilders/ObjectFactory.h"
#include "Geometry/ColorMapStatic.h"

/*
 * Format del fitxer de configuració del mapping:
 *
 * dataType  format del rendering: potser ONLINE, IMAGE o TEMPORAL
 * limitsMon, definits per xmin, xmax, ymin, ymax, zmin, zmax
 * lookFrom, posicio observador
 * lookAt posicio on es mira
 * vup vector de verticalitat
 * vfov vertical field of view (obertura en vertical de la camera donada en graus)
 * aspectRatio, relacio width/height
 * witdh, amplada del viewport en pixels
 * output, nom del fitxer d'output en cas de ser IMAGE o TEMPORAL
 *
 *
 * TODO FASE 2: ampliar amb la informacio de les llums
*/


class ConfigMappingReader {
public:


    explicit ConfigMappingReader();

    ConfigMappingReader(QString filename);

    void readFile (QString fileName);

protected:
    virtual void fileLineRead (QString lineReaded);

    void mappingTypeFound(QStringList fields);

    void limitsRealFound(QStringList list);

    void limitsVirtualFound(QStringList list);

    void baseFound(QStringList list);

    void propFound(QStringList list);

    void BrObjectFound(QStringList fields);

public:

    float               Rxmin, Rxmax, Rymin, Rymax, Rzmin, Rzmax;
    float               Vxmin, Vxmax, Vymin, Vymax, Vzmin, Vzmax;
    int                 numProp;
    //GROUND:

    vec3                normalPlaorCentre;
    double              dPlaorRadi;
    QString             texturePath;
    Scene::DATA_TYPES   dataType;

    // Fase 4: Caldrà tenir aqui la textura del pla

    vector<pair<double, double>> propLimits;
    vector<QString> propPaths;
    vector<QString> propTexPath;
    vector<ColorMapStatic::ColorMapType> propsColor;
};

