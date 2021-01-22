uniform sampler2D ShadowMap;
varying vec4 ShadowCoord;
varying vec3 normal;
varying vec4 position;
void main()
{	
	vec3 norm = normalize(normal);

	vec3 lightv = normalize(gl_LightSource[0].position.xyz);
	vec3 viewv = -normalize(position.xyz);
	vec3 halfv = normalize(lightv + viewv);
	if (dot(halfv, norm) < 0)
		norm = -norm;

	vec4 diffuse = max(0.0, dot(lightv, norm)) * gl_Color * gl_LightSource[0].diffuse;

	vec4 ambient = gl_Color * gl_LightSource[0].ambient;

	vec4 specular = vec4(0.0, 0.0, 0.0, 1.0);

	if (dot(lightv, viewv) > 0.0) {
		specular = pow(max(0.0, dot(norm, halfv)), gl_FrontMaterial.shininess) * gl_FrontMaterial.specular * gl_LightSource[0].specular;
	}

	vec4 shadowCoordinateWdivide = ShadowCoord / ShadowCoord.w;
	
	shadowCoordinateWdivide.z -= 0.00005;

	float distanceFromLight = texture2D(ShadowMap, shadowCoordinateWdivide.st).z;

	float shadow = 1.0;
	if (ShadowCoord.w > 0.0)
		shadow = distanceFromLight < shadowCoordinateWdivide.z ? 0.5 : 1.0;

	vec3 color = clamp(vec3(ambient + shadow * diffuse + shadow * specular), 0.0, 1.0);

	gl_FragColor = vec4(color , 1.0);
 
}

