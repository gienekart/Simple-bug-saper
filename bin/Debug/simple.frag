uniform sampler2D texture0;
varying vec2 tex_coords;
void main(void){
   gl_FragColor = texture2D(texture0, tex_coords);
}
