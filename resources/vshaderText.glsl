#version 330
#if __VERSION__<130
#define IN attribute
#define OUT varying
#else
#define IN in
#define OUT out
#endif


layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vColor;
layout (location = 2) in vec2 vCoordTexture;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 color;
out vec2 v_texcoord;



void main()
{
  gl_Position = projection*model_view*vPosition;
  gl_Position = gl_Position/gl_Position.w;
  color = vColor;
  // Pas de les coordenades de textura al fragment shader
  // El valor del color i les coordenades de textura s'interpolaran automaticament
  // en els fragments interiors a les cares dels polígons
  v_texcoord = vCoordTexture;
}
