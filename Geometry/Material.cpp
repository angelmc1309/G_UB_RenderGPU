#include "Geometry/Material.h"


Material::Material() {
    // This values are done in order to test that material goes to GPU
    // Goma
    /*
    this->ambiental = vec4(0.05, 0.0, 0.0, 1.0);
    this->diffuse = vec4(0.5, 0.4, 0.4, 1.0);
    this->specular = vec4(0.7, 0.04, 0.04, 1.0);
    this->shiness = 0.078125;
    */

    // Plastico
/*
    this->ambiental = vec4(0.0, 0.1, 0.06, 1.0);
    this->diffuse = vec4(0.0, 0.51, 0.51, 1.0);
    this->specular = vec4(0.51, 0.51, 0.51, 1.0);
    this->shiness = 0.25;*/

    this->ambiental = vec4(0.2, 0.2, 0.2, 1.0);
    this->diffuse = vec4(0.8, 0.5, 0.5, 1.0);
    this->specular = vec4(0.5, 0.5, 0.5, 1.0);
    this->shiness = 20.0;
}

/**
 * Passa el material de CPU a GPU
 * @brief Material::toGPU
 * @param program
 */
void Material::toGPU(shared_ptr<QGLShaderProgram> program){
    MaterialGPU.ka = program->uniformLocation("materials.ka");
    MaterialGPU.kd = program->uniformLocation("materials.kd");
    MaterialGPU.ks = program->uniformLocation("materials.ks");
    MaterialGPU.shine = program->uniformLocation("materials.shine");

    glUniform4fv(MaterialGPU.ka, 1, ambiental);
    glUniform4fv(MaterialGPU.kd, 1, diffuse);
    glUniform4fv(MaterialGPU.ks, 1, specular);
    glUniform1f(MaterialGPU.shine, shiness);

    qDebug() << "Material Sended to GPU" ;
}

