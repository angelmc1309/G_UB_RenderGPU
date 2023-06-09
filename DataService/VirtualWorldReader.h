#pragma once

#include <QObject>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>

#include <vector>
#include <iostream>
#include <sstream>

#include "Geometry/Scene.h"
#include "GeometryBuilders/ObjectFactory.h"
#include "GeometryBuilders/Mapping.h"

class VirtualWorldReader {
public:
    explicit VirtualWorldReader();

    VirtualWorldReader(shared_ptr<Scene> s);

    void readFile (QString fileName, shared_ptr<Mapping> map);

private:
    virtual void fileLineRead (QString lineReaded);

    shared_ptr<Scene> scene;
    shared_ptr<Mapping> mapping;

    void brObjectFound(QStringList fields);

};

