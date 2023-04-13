#pragma once

#include <QObject>
#include <vector>
#include <memory>

#include <library/Common.h>
using namespace Common;

#include <QGLShaderProgram>
#include <QOpenGLTexture>

#include <QFile>
#include <QRegularExpression>
#include <QDebug>
#include <QString>
#include <QStringList>

#include <Geometry/TG.h>
#include <Geometry/Animation.h>
#include <Geometry/Cara.h>

//typedef vec3  point3;
typedef vec4 point4;

using namespace std;

// TO DO: A canviar a la fase 1 de la practica 2
// Classe que representa els materials d'un objecte
class Material {


public:
    Material();

    void toGPU(shared_ptr<QGLShaderProgram> program);
private:
    vec4 ambiental;
    vec4 diffuse;
    vec4 specular;
    GLfloat shiness;

    struct {
        GLuint ka;
        GLuint kd;
        GLuint ks;
        GLuint shine;
    }MaterialGPU;
};

