#version 300 es
in vec4 vertexColor;
out vec4 FragColor;
in vec2 TexCoord;
// texture sampler
uniform sampler2D texture;
uniform sampler2D texture1;

void main()
{
	// FragColor = mix(texture(texture, TexCoord),texture(texture1, TexCoord),1.0f);
	FragColor = texture(texture, TexCoord);
}
