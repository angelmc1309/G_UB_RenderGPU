#include "GeometryBuilders/Builder.h"
#include "DataService/ConfigMappingReader.h"
#include "SceneFactoryVirtual.h"
#include "SceneFactoryData.h"

Builder::Builder(GLWidget *glWid)
{
    glWidget = glWid;
    scene = glWidget->getScene();
    dataAnim = new DataAnimation();
}

void Builder::newObjFromFile()
{
    QString fileName = QFileDialog::getOpenFileName();
    if (!fileName.isNull()) {
            //Podriem fer un nou dialeg per fer set de la textura
            auto obj = make_shared<Object>(33554432, fileName);
            scene->addObject(obj);
            scene->camera->actualitzaCamera(scene->capsaMinima);
            emit newObj(obj);
    }
}

void Builder::newVirtualScene() {
    // TO DO Fase 1: creació de la nova escena Virtual a partir d'un fitxer
    // de  a partir de les dades
    // del configMapping  i un fitxer .txt de tipus VIRTUALWORLD.
    // Nomes hi hauran fitxers de tipus BoundaryObject.
    // Usa el ConfigMappingReader i la teva SceneFactoryVirtual
    // per a construir l'escena tal i com feies a la practica 1
    QString configMapping = QFileDialog::getOpenFileName();
    if (!configMapping.isNull()) {
        shared_ptr<ConfigMappingReader> cmr = make_shared<ConfigMappingReader>(configMapping);
        QString fileName = QFileDialog::getOpenFileName();
        if (!fileName.isNull()) {
            shared_ptr<SceneFactoryVirtual> sceneFactory = make_shared<SceneFactoryVirtual>(cmr);
            auto s = sceneFactory->createScene(fileName);
            glWidget->setScene(s);
            this->scene = glWidget->getScene();
            auto l  = make_shared<Light>(Puntual);
            scene->addLight(l);
            emit newScene(scene);
        }
    }
}
//"/home/eric/Documents/newGPU/rendergpu-c02/resources/models/sphere1.obj"

void Builder::newDataScene()
{
    // TO DO Fase 1: Crear la nova escena a partir de les dades
    // del configMapping i el fitxer .txt que conté les dades
    // Utilitza el ConfigMappingReader i la teva SceneFactoryData per a llegir els fitxers
    // i crear l'escena corresponent.
    QString configMapping = QFileDialog::getOpenFileName();
    if (!configMapping.isNull()) {
        shared_ptr<ConfigMappingReader> cmr = make_shared<ConfigMappingReader>(configMapping);
        QString fileName = QFileDialog::getOpenFileName();
        if (!fileName.isNull()) {
            shared_ptr<SceneFactoryData> sceneFactory = make_shared<SceneFactoryData>(cmr);
            auto s = sceneFactory->createScene(fileName);
            glWidget->setScene(s);
            this->scene = glWidget->getScene();
            auto l  = make_shared<Light>(Puntual);
            scene->addLight(l);
            emit newScene(scene);
        }
    }
    // Opcionalment pots crear un dialeg per posar els valors del mapping
}

void Builder::saveAnimationScene()
{
    this->dataAnim->OneSphere(this->scene);
}

