#include "Geometry/TranslateTG.h"
#include "library/mat.h"

TranslateTG::TranslateTG(vec3 trasl): traslation(trasl)
{
    //Find translate function in mat.h
    matTG = Translate(trasl);

}

TranslateTG::~TranslateTG()
{

}

