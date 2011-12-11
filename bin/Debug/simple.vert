uniform float objectScale = 1.0;
uniform float objectAngle = 0.0;
varying vec2 tex_coords;
varying vec3 position;
varying vec3 normal;
void main()
{
  //texture mapping
  tex_coords = gl_MultiTexCoord0.xy;


  //scale and rotate vertex inside model
  vec4 internalVertex = gl_Vertex;
  internalVertex.x = gl_Vertex.x * cos(objectAngle) - gl_Vertex.z * sin(objectAngle);
  internalVertex.z = gl_Vertex.x * sin(objectAngle) + gl_Vertex.z * cos(objectAngle);
  internalVertex *= vec4(objectScale, objectScale, objectScale, 1);

  // Transforming The Vertex
  gl_Position = gl_ModelViewProjectionMatrix * internalVertex; 

  //getting position
  position = gl_ModelViewMatrix * internalVertex;

  //rotate normal
  vec3 internalNormal = gl_Normal;
  // I would supose xz rather than xy and positive value of objectAngle?! But it works.
  internalNormal.x = gl_Normal.x * cos(-objectAngle) - gl_Normal.y * sin(-objectAngle);
  internalNormal.y = gl_Normal.x * sin(-objectAngle) + gl_Normal.y * cos(-objectAngle);
  

  //getting normal
  normal = normalize(gl_NormalMatrix * internalNormal).xyz;
  gl_Normal = internalNormal;
}
