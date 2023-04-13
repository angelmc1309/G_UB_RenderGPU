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
            N = Normal;
            float LN = max(dot(L,N), 0.0f);
            difuseAndSpecular = vec4(lights[i].id, 1.0) * materials.kd * LN;    //Solo difusa

            /* SPECULAR */
            V = normalize(obs - Position);
            H = normalize((L + V)/ (sqrt((L.x + V.x)*(L.x + V.x)) +
                                    sqrt((L.y + V.y)*(L.y + V.y)) +
                                    sqrt((L.z + V.z)*(L.z + V.z))));

            float NH = max(dot(H, N), 0.0f);
            difuseAndSpecular += vec4(lights[i].is, 1.0) * materials.ks * pow(NH, materials.shine); // Difusa y especular

            /* ATENUACIO */
            //float d = distance(vec3(Position), vec3(lights[i].position));
            //float atenuacion = (1.0f / (lights[i].coeficients.x * pow(d, 2.0) + lights[i].coeficients.y * d + lights[i].coeficients.z));
            //difuseAndSpecular *= atenuacion;

            //AMBIENTAL COLOR(local)
            ambiental = vec4(lights[i].ia, 1.0) * materials.ka;
            colorOut = difuseAndSpecular + ambiental;

        } else if (lights[i].typeLight == 1) {  //Direccional
            /* DIFUSE */
            L = normalize(vec4(-lights[i].direction, 1.0));
            N = Normal;
            float LN = max(dot(L,N), 0.0f);
            difuseAndSpecular = vec4(lights[i].id, 1.0) * materials.kd * LN;    //Solo difusa

            /* SPECULAR */
            V = normalize(obs - Position);
            H = normalize((L + V)/ (sqrt((L.x + V.x)*(L.x + V.x)) +
                                    sqrt((L.y + V.y)*(L.y + V.y)) +
                                    sqrt((L.z + V.z)*(L.z + V.z))));

            float NH = max(dot(H, N), 0.0f);
            difuseAndSpecular += vec4(lights[i].is, 1.0) * materials.ks * pow(NH, materials.shine); // Difusa y especular

            //AMBIENTAL COLOR(local)
            ambiental = vec4(lights[i].ia, 1.0) * materials.ka;
            colorOut = difuseAndSpecular + ambiental;

        } else {
            /* DIFUSE */
            L = normalize(vec4(-lights[i].direction, 1.0));  // Ligh direction
            float cutOff = cos(radians(lights[i].angle));

            if (cutOff > 0.0f) {     // the light is a spotlight
                vec4 D = lights[i].position - Position;  // Spot direction
                float spotCosine = dot(D,-L);

                if (spotCosine >= cutOff) {
                    N = Normal;
                    float LN = max(dot(D,N), 0.0f);
                    difuseAndSpecular = vec4(lights[i].id, 1.0) * materials.kd * LN;    //Solo difusa

                    /* SPECULAR */
                    V = normalize(obs - Position);
                    H = normalize((L + V)/ (sqrt((L.x + V.x)*(L.x + V.x)) +
                                            sqrt((L.y + V.y)*(L.y + V.y)) +
                                            sqrt((L.z + V.z)*(L.z + V.z))));

                    float NH = max(dot(H, N), 0.0f);
                    difuseAndSpecular += vec4(lights[i].is, 1.0) * materials.ks * pow(NH, materials.shine); // Difusa y especular

                    //AMBIENTAL COLOR(local)
                    ambiental = vec4(lights[i].ia, 1.0) * materials.ka;
                    colorOut = difuseAndSpecular + ambiental;
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

