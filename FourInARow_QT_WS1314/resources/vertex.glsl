#version 150

in vec2 in_Position;

out vec2 uv;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;


void main(void)
{
        gl_Position = vec4(in_Position, 0, 1);
        uv = (in_Position+1.0)/2.0;
        uv.y = 1-uv.y;
}
