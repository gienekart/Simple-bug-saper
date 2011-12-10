uniform float objectScale = 4.0;
uniform float objectAngle = 0.0;
void main()
{
  //scale and rotate vertex inside model
  vec4 internalVertex = gl_Vertex;
  internalVertex.x = gl_Vertex.x * cos(objectAngle) - gl_Vertex.y * sin(objectAngle);
  internalVertex.y = gl_Vertex.x * sin(objectAngle) + gl_Vertex.y * cos(objectAngle);
  internalVertex *= vec4(objectScale, objectScale, objectScale, 1);

  // Transforming The Vertex
  gl_Position = gl_ModelViewProjectionMatrix * internalVertex; 
}
