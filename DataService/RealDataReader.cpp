#include "RealDataReader.h"
#include "Geometry/Plane.h"
#include "Geometry/TranslateTG.h"
#include "Geometry/ScaleTG.h"


RealDataReader::RealDataReader(shared_ptr<Scene> s)
{
    scene = s;
}

void RealDataReader::readFile(QString fileName, shared_ptr<Mapping> map) {
    QFile file(fileName);

    mapping = map;

    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Error opening the file" << std::endl;
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        fileLineRead(line);
    }

    file.close();
}

void RealDataReader::fileLineRead (QString lineReaded) {

    QStringList fields = lineReaded.split(",");
    if (QString::compare("data", fields[0], Qt::CaseInsensitive) == 0)
        dataFound(fields);
    else
        std::cerr << "Element unknown" << std::endl;
}



void RealDataReader::dataFound(QStringList fields) {
    //data x z valor1 valor2...
    int n = mapping->getNumProps();

    if (fields.size() != (3 + n)) {
        std::cerr << "Wrong data format" << std::endl;
        //return;
    }

    for (int i=0; i<n; i++) {

        //Object creation
        shared_ptr<Object> o;
        QString objectPath = mapping->getObjectPath(i);
        o = ObjectFactory::getInstance().createObject(objectPath, -1.0f);

        float mappedVal = mapping->mapeigValor(fields[3 + i].toDouble(), i);
        shared_ptr<ScaleTG> scal = make_shared<ScaleTG>(mappedVal);
        o->aplicaTG(scal);

        Capsa3D objectBox = o->calculCapsa3D();

        //Apply translation
        vec3 puntBase = vec3(fields[1].toDouble(), objectBox.h/2, fields[2].toDouble());
        vec3 mappedCoords = mapping->mapeigPunt(puntBase);
        shared_ptr<TranslateTG> transl = make_shared<TranslateTG>(mappedCoords);
        o->aplicaTG(transl);

        QString objectTexPath = mapping->getObjectTexPath(i);
        o->setTexture(make_shared<QOpenGLTexture>(QImage(objectTexPath).mirrored()));

        scene->objects.push_back(o);
        /*
        if (type == ObjectFactory::CYLINDER) {
           o = ObjectFactory::getInstance().createObject(mapping->mapeigPunt(puntBase),
                                                           0.1,
                                                           mapping->mapeigValor(fields[3 + i].toDouble(), i),
                                                           -1.0,
                                                           mapping->getObjectTypeProp(i));


        } else if (type == ObjectFactory::TRIANGLE) {
            vec3 mappedBase = mapping->mapeigPunt(puntBase);
            double mappedVal = mapping->mapeigValor(fields[3 + i].toDouble(), i);
            o = ObjectFactory::getInstance().createObject(mappedBase,
                                                            vec3 (mappedBase.x, mappedBase.y+1, mappedVal + mappedBase.z),
                                                            vec3 (mappedVal + mappedBase.x, mappedBase.y+1, mappedBase.z),
                                                          -1.0f,
                                                            mapping->getObjectTypeProp(i));

         // Construccio de l'objecte al Mon Virtual
            puntBase.y += mapping->mapeigValor(fields[3 + i].toDouble(), i);
            o = ObjectFactory::getInstance().createObject(mapping->mapeigPunt(puntBase),
                                                          mapping->mapeigValor(fields[3 + i].toDouble(), i),
                                                          fields[3 + i].toDouble());
        }


        // Construccio i assignacio del material
        o->setMaterial(mapping->mapeigMaterial(i, mapping->getColorMapProp(i), fields[3 + i].toDouble()));
    
        // Afegir objecte a l'escena
        */
    }
}


