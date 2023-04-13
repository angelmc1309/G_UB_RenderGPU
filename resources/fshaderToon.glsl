#version 330

in vec4 Normal;   // Normal rasterizada
in vec4 Position; // Posicion rasterizada
out vec4 colorOut;

uniform mat4 model_view;
uniform mat4 projection;

/***       PAS 2      ***/
struct MaterialComponents {
    vec4 ka;
    vec4 kd;
    vec4 ks;
    float shine;
};

uniform MaterialComponents materials; //It'll be uniform

/***       PAS 3      ***/
struct LightComponents{
    vec3 ia;
    vec3 id;
    vec3 is;
    vec3 coeficients;
    vec4 position;
    vec3 direction;
    float angle;
    int typeLight;
};

uniform LightComponents lights[5];
//uniform int lengthLuces;
uniform vec3 iAmbientGlobal;

/***       PAS 4      ***/
uniform vec4 obs;

void main()
{
    /* PHONG SHADING  */
    vec4 H, L, N, V;
    vec4 difuseAndSpecular, ambiental;

    // TODO Tienes que saber el num. de lights de antemano, por ahora hardcoded
    for (int i = 0; i < 1 ; i++) {

        if (lights[i].typeLight == 0) {  //Puntual

            /* DIFUSE */
            L = normalize(lights[i].position - Position);

            float intensity = dot(normalize(vec4(lights[i].direction, 1.0)), normalize(Normal));
            if (intensity > 0.75) {
                colorOut = materials.kd * (1- intensity);
            } else if (intensity > 0.5) {
                colorOut = materials.kd * (1- intensity);
            } else if (intensity > 0.25) {
                colorOut = materials.kd * (1- intensity);
            } else {
                colorOut = materials.kd * (1- intensity);
            }

        } else if (lights[i].typeLight == 1) {  //Direccional
            /* DIFUSE */
            L = normalize(lights[i].position - Position);

            float intensity = dot(normalize(vec4(lights[i].direction, 1.0)), normalize(Normal));
            if (intensity > 0.75) {
                colorOut = materials.kd * (1- intensity);
            } else if (intensity > 0.5) {
                colorOut = materials.kd * (1- intensity);
            } else if (intensity > 0.25) {
                colorOut = materials.kd * (1- intensity);
            } else {
                colorOut = materials.kd * (1- intensity);
            }

        } else {
            /* DIFUSE */
            L = normalize(vec4(-lights[i].direction, 1.0));  // Ligh direction
            float cutOff = cos(radians(lights[i].angle));

            if (cutOff > 0.0f) {     // the light is a spotlight
                vec4 D = lights[i].position - Position;  // Spot direction
                float spotCosine = dot(D,-L);

                if (spotCosine >= cutOff) {
                    /* DIFUSE */
                    L = normalize(lights[i].position - Position);

                    float intensity = dot(normalize(vec4(lights[i].direction, 1.0)), normalize(Normal));
                    if (intensity > 0.75) {
                        colorOut = materials.kd * (1- intensity);
                    } else if (intensity > 0.5) {
                        colorOut = materials.kd * (1- intensity);
                    } else if (intensity > 0.25) {
                        colorOut = materials.kd * (1- intensity);
                    } else {
                        colorOut = materials.kd * (1- intensity);
                    }

                }
                else { // The point is outside the cone of light from the spotlight.
                    colorOut = vec4(lights[i].ia, 1.0) * materials.ka;
                }
            }
        }
    }
    vec4 ambientGlobal = vec4(iAmbientGlobal,1.0);
    colorOut +=  ambientGlobal * materials.ka;
    //colorOut = difuseAndSpecular;
}

