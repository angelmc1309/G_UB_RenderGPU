#pragma once

#include <library/vec.h>
using namespace Common;

// Tipus de Lights
enum LightType {Puntual, Direccional, Spot};

// Classe que representa els atributs d'una Light
// TO DO: A la fase 1 has d'incloure els atributs necessaris per codificar una llum

class Light {
    public:
        Light(LightType l);

        vec4 getLightPosition();
        void setLightPosition(vec4 v);

        vec3 getIa() const;
        void setIa(const vec3 &value);

        vec3 getId();
        void setId(vec3 i);

        vec3 getIs() const;
        void setIs(const vec3 &value);

        vec3 getCoeficients() const;
        void setCoeficients(const vec3 &value);

        LightType getTipusLight() const;
        void setTipusLight(const LightType &value);

        vec3 getDirection() const;
        void setDirection(const vec3 &value);

        float getAngle() const;
        void setAngle(const float &value);

    private:
        vec4 lightPosition;
        vec3 ambiental;
        vec3 diffuse;
        vec3 specular;
        vec3 coeficients;
        LightType typo;
        vec3 direction;
        float angle;
};

