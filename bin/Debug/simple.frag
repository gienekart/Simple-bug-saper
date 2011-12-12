uniform sampler2D texture0;
uniform sampler2D texture1;
uniform float objectSelection = 0.0;
uniform float textureMix = 0.0;
varying vec2 tex_coords;
varying vec3 position;
varying vec3 normal;
void main(void){
   // It could be more than 1.0
   textureMix = clamp(textureMix, 0.0, 1.0);

   //Light direction  
   vec3 lightDirection = normalize(gl_LightSource[1].position.xyz - position); 

   //calculate ambient strenght:  
   vec4 ambient = gl_FrontLightProduct[0].ambient; 
 
  //calculate diffuse strenght:  
  vec4 diffuse = gl_FrontLightProduct[1].diffuse * max(dot(normal,lightDirection), 0.0); 

  //selection brightness
  vec4 selection = vec4(objectSelection, objectSelection, objectSelection, objectSelection);

  vec4 lightStrenght = clamp(ambient + diffuse + selection, 0.0, 1.0);

  vec4 secondMix = vec4(textureMix, textureMix, textureMix, 1);
  vec4 baseMix = vec4(1 - textureMix, 1 - textureMix, 1 - textureMix, 1);

  vec4 endColor = texture2D(texture0, tex_coords) * baseMix + texture2D(texture1, tex_coords) * secondMix;
  endColor = clamp(endColor, 0.0, 1.0);

  gl_FragColor = (endColor) * (lightStrenght);
}
