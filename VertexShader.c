// Used for shadow lookup
varying vec4 ShadowCoord;
varying vec3 normal;
varying vec4 position;

void main()
{
	normal = normalize(gl_NormalMatrix * gl_Normal);
	position = gl_ModelViewMatrix * gl_Vertex;

    ShadowCoord= gl_TextureMatrix[7] * gl_Vertex;
  
	gl_Position = ftransform();

	gl_ClipVertex = gl_ModelViewMatrix * gl_Vertex;

	gl_FrontColor = gl_Color;
}

