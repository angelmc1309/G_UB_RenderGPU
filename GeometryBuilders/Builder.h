#ifndef BUILDER_H
#define BUILDER_H

#include <QtWidgets>
#include <Renders/GLWidget.h>
#include <DataAnimation.h>

class Builder : public QObject {
        Q_OBJECT

    shared_ptr<Scene> scene;
    DataAnimation *dataAnim;
    GLWidget *glWidget;

public:
    Builder(GLWidget *glWid);

public slots:
    void newObjFromFile();
    void newVirtualScene();
    void newDataScene();
    void saveAnimationScene();

signals:
    void newObj(shared_ptr<Object> o);
    void newScene(shared_ptr<Scene> sc);
};

#endif // BUILDER_H
