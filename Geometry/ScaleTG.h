#ifndef SCALETG_H
#define SCALETG_H

#include "TG.h"

class ScaleTG : public TG
{
public:
    float scalation;
    ScaleTG(float scalation);
    ~ScaleTG();
};

#endif // SCALETG_H
