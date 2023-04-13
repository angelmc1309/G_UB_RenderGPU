#include "Geometry/Light.h"

/**
 * @brief Light::Light
 * @param t
 */
Light::Light(LightType t) {
    // TO DO: A canviar a la fase 1 de la practica 2
    this->lightPosition = vec4(1.0, 1.0, 2.0, 1.0);
    this->ambiental = vec3(0.2, 0.2, 0.2);
    this->diffuse = vec3(0.8, 0.8, 0.8);
    this->specular = vec3(1.0, 1.0, 1.0);
    this->coeficients = vec3(0.0, 0.2, 0.8);
    this->typo = t;
    this->direction = vec3(1.0, 0.0, 0.5);
    this->angle = 10.40;
}

/**
 * @brief Light::getDiffuseIntensity
 * @return
 */
vec3 Light::getId() {
    // TO DO: A canviar a la fase 1 de la practica 2
   return diffuse;
}

/**
 * @brief Light::setId
 * @param i
 */
void Light::setId(vec3 i) {
    // TO DO: A canviar a la fase 1 de la practica 2
    this->diffuse = i;
}

/**
 * @brief Light::getLightPosition
 */
vec4 Light::getLightPosition() {
    // TO DO: A canviar a la fase 1 de la practica 2
    return lightPosition;
}

/**
 * @brief Light::setLightPosition
 * @param v
 */
void Light::setLightPosition(vec4 v) {
    // TO DO: A canviar a la fase 1 de la practica 2
    this->lightPosition = v;
}


/**
 * @brief Light::getIa
 * @return
 */
vec3 Light::getIa() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
       return this->ambiental;
}

/**
 * @brief Light::setIa
 * @param value
 */
void Light::setIa(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->ambiental = value;
}

/**
 * @brief Light::getIs
 * @return
 */
vec3 Light::getIs() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
       return this->specular;
}

/**
 * @brief Light::setIs
 * @param value
 */
void Light::setIs(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->specular = value;
}

/**
 * @brief Light::getCoeficients
 * @return
 */
vec3 Light::getCoeficients() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
       return this->coeficients;
}

/**
 * @brief Light::setCoeficients
 * @param value
 */
void Light::setCoeficients(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->coeficients = value;
}


/**
 * @brief Light::getTipusLight
 *
 */
LightType Light::getTipusLight() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
    return typo;
}

/**
 * @brief Light::setTipusLight
 * @param value
 */
void Light::setTipusLight(const LightType &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->typo = value;
}

vec3 Light::getDirection() const{
    return this->direction;
}

void Light::setDirection(const vec3 &value){
    this->direction = value;
}

float Light::getAngle() const{
    return this->angle;
}

void Light::setAngle(const float &value){
    this->angle = value;
}

