#include "SceneFactoryVirtual.h"


SceneFactoryVirtual::SceneFactoryVirtual(shared_ptr<ConfigMappingReader> mr):SceneFactory()
{
    map = make_shared<Mapping>(mr);
}

shared_ptr<Scene> SceneFactoryVirtual::createScene(QString filename) {
    auto scene= make_shared<Scene>();
    shared_ptr<VirtualWorldReader> vwr = make_shared<VirtualWorldReader>(scene);
    vwr->readFile(filename, map);
    return scene;
}

shared_ptr<Scene> SceneFactoryVirtual::createScene() {
    auto scene = make_shared<Scene>();
    return scene;
}
