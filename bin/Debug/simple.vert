uniform float objectScale = 1.0;
uniform float objectAngle = 0.0;
varying vec2 tex_coords;
varying vec3 position;
varying vec3 normal;
void main()
{
  //texture mapping
  tex_coords = gl_MultiTexCoord0.xy;

  //getting normal
  normal = normalize(gl_NormalMatrix * gl_Normal).xyz;

  //scale and rotate vertex inside model
  vec4 internalVertex = gl_Vertex;
  internalVertex.x = gl_Vertex.x * cos(objectAngle) - gl_Vertex.z * sin(objectAngle);
  internalVertex.z = gl_Vertex.x * sin(objectAngle) + gl_Vertex.z * cos(objectAngle);
  internalVertex *= vec4(objectScale, objectScale, objectScale, 1);

  // Transforming The Vertex
  gl_Position = gl_ModelViewProjectionMatrix * internalVertex; 

  //getting position
  position = gl_ModelViewMatrix * internalVertex;
}
