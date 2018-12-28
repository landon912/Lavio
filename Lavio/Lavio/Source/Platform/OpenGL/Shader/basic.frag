#version 330 core

layout(location = 0) out vec4 color;

uniform vec2 light_pos;

in DATA
{
	vec4 pos;
	vec2 uv;
	float tid;
	vec4 color;
} fs_in;

uniform sampler2D textures[32];

void main()
{
	//float intensity = 1.0 / (length(fs_in.pos.xy - light_pos) * 0.5);

	vec4 texColor = fs_in.color;

	if(fs_in.tid > 0.0)
	{
		int intTID = int(fs_in.tid - 0.5); //floor int
		texColor = texture(textures[intTID], fs_in.uv) * fs_in.color;
	}

	color = texColor;
}