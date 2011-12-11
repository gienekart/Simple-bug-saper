uniform sampler2D texture0;
varying vec2 tex_coords;
varying vec3 position;
varying vec3 normal;
void main(void){
   //Light direction  
   vec3 lightDirection = normalize(gl_LightSource[1].position.xyz - position); 

   //calculate ambient strenght:  
   vec4 ambient = gl_FrontLightProduct[0].ambient; 
 
  //calculate diffuse strenght:  
  vec4 diffuse = gl_FrontLightProduct[1].diffuse * max(dot(normal,lightDirection), 0.0); 

  vec4 lightStrenght = clamp(ambient + diffuse, 0.0, 1.0);

  gl_FragColor = texture2D(texture0, tex_coords) * (lightStrenght);
}
