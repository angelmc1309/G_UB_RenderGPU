#include "VirtualWorldReader.h"


VirtualWorldReader::VirtualWorldReader(shared_ptr<Scene> s)
{
    scene = s;
}

void VirtualWorldReader::readFile(QString fileName, shared_ptr<Mapping> map) {

    mapping = map;
    std::cout << fileName.toStdString()<<std::endl;

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
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

void VirtualWorldReader::fileLineRead (QString lineReaded) {

    QStringList fields = lineReaded.split(",");
    brObjectFound(fields);

}

void VirtualWorldReader::brObjectFound(QStringList fields) {

    shared_ptr<Object> o;

    vector<vec3> points;
    vector<double> properties;
    QString textPath = "";
    textPath = fields[1];
    o = ObjectFactory::getInstance().createObject(fields[0], -1.0f);

    o->setTexture(make_shared<QOpenGLTexture>(QImage(textPath).mirrored()));
    scene->objects.push_back(o);

    /*
    if(fields.length() == 5){
        auto mat = make_shared<Lambertian>(vec3(fields[2].toDouble(),fields[3].toDouble(),fields[4].toDouble()));
    }else{
        auto mat = make_shared<Lambertian>(vec3(fields[2].toDouble(),fields[3].toDouble(),fields[4].toDouble()),
                vec3(fields[5].toDouble(),fields[6].toDouble(),fields[7].toDouble()), vec3(fields[8].toDouble(),
                fields[9].toDouble(),fields[10].toDouble()),vec3(fields[11].toDouble(),fields[12].toDouble(),fields[13].toDouble()),
                fields[14].toDouble());

        o->setMaterial(mat);
    }*/

}


