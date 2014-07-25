#version 150

in vec2 uv;
uniform sampler2D yTexture;
uniform sampler2D uTexture;
uniform sampler2D vTexture;

out vec4 out_Color;
vec4 color = vec4(1,0,0,1);

void main(void)
{
  float y = texture2D(yTexture, uv).x;
  float u = texture2D(uTexture, uv).x;
  float v = texture2D(vTexture, uv).x;

  // BT.709
  //float r = y + 1.28033*v;
  //float g = y - 0.21482*u - 0.38059*v;
  //float b = y + 2.12798*u;

  y = 1.1643*(y-0.0625);
	u = u-0.5;
	v = v-0.5;

	float r = y+1.5958*v;
	float g = y-0.39173*u-0.81290*v;
	float b = y+2.017*u;

  //BT.601
  //float r = y + 1.13983*v;
  //float g = y - 0.39465*u - 0.5806*v;
  //float b = y + 2.03211*u;

  out_Color = vec4(r,g,b, 1);

  //out_Color = vec4(texture2D(vTexture, uv).x, texture2D(vTexture, uv).x, texture2D(vTexture, uv).x, 1);
  //out_Color = vec4(uv.x, uv.y, 0, 1);
}
