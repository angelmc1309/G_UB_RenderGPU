#include "DataAnimation.h"


DataAnimation::DataAnimation()
{

}

void DataAnimation::OneSphere(shared_ptr<Scene> s){
    QString s1("://resources/models/JUPITER.obj");
    shared_ptr<Object> obj1 = make_shared<Object>(100000, s1);

    QString file = "://resources/textures/jupiter.png";
    shared_ptr<QOpenGLTexture> texture;
    shared_ptr<QOpenGLTexture> textureN;
    QStringList fileSpliter = file.split(".");
    QString textureNormals;
    textureNormals = fileSpliter[0];
    textureNormals.append("N.png");
    texture = make_shared<QOpenGLTexture>(QImage(file).mirrored());
    textureN = make_shared<QOpenGLTexture>(QImage(textureNormals).mirrored());
    // TO DO: A modificar en la fase 1 de la practica 2
    // Per ara es posa la textura al primer objecte de l'escena
    obj1->setTexture(texture);
    obj1->setTextureN(textureN);


    // ... Troç de codi just per a afegir animació a l'objecte
    shared_ptr<Animation> anim = make_shared<Animation>();
    anim->transf = make_shared<TranslateTG>(vec3(0.05,0.0,-0.01));
    obj1->addAnimation(anim);
    s->objects.push_back(obj1);
}
