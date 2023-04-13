#pragma once

#include <cmath>
#include <iostream>
#include <stdlib.h>

#include <list>
#include <vector>
#include <string>
#include <stdio.h>

#include <library/Common.h>
#include <QDebug>

#include <Geometry/Object.h>
#include <Geometry/Light.h>
#include <Renders/Camera.h>

using namespace std;
using namespace Common;

// Scene: contains all objects, lights to visualize the scene
// the viewer is placed in the z+ axis

typedef struct{
    GLuint ia;
    GLuint id;
    GLuint is;
    GLuint coeficients;
    GLuint position;
    GLuint typeLight;
    GLuint direction;
    GLuint angle;
}lightGPU;

class Scene {

public:

    typedef enum {
        VIRTUALWORLD,
        REALDATA,
        TEMPORALVW,
        TEMPORALDATA
    } DATA_TYPES;
    lightGPU lightsGPU[5]; //If you change num remember vertexShader
    GLuint lightAmbientGlobalToGPU;

    vector<shared_ptr<Object>> objects;
    vector<shared_ptr<Light>>  lights;

    vec3    lightAmbientGlobal;
    shared_ptr<Camera> camera;
    // Capsa contenedora de l'escena
    Capsa3D capsaMinima;

    Scene();
    ~Scene();

    void   addObject(shared_ptr<Object> obj);
    void   addLight(shared_ptr<Light> l);
    shared_ptr<Light> getLightActual();
    void   setLightActual(shared_ptr<Light> l);

    void setCamera(shared_ptr<Camera> c);

    void toGPU(shared_ptr<QGLShaderProgram> p);
    void toGPUTexture(shared_ptr<QGLShaderProgram> p);
    void draw();
    void drawTexture();


    void lightsToGPU(shared_ptr<QGLShaderProgram> program);
    void setAmbientToGPU(shared_ptr<QGLShaderProgram> program);

    void calculCapsaMinCont3DEscena();
    void update(int nframe);

};

