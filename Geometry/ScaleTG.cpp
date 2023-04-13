#include "ScaleTG.h"

ScaleTG::ScaleTG(float scalation) : scalation(scalation)
{
    matTG = Scale(vec3 (scalation, scalation, scalation));
}

ScaleTG::~ScaleTG()
{

}
