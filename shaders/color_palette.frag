#version 430

varying vec2 vTexCoords;

uniform float aspect_ratio;

uniform vec3 a;
uniform vec3 b;
uniform vec3 c;
uniform vec3 d;

void main()
{
    vec2 uv = vTexCoords - 0.5;
    uv.x *= aspect_ratio;

    float t      = atan(uv.y, uv.x) / 6.28;
    float r      = length(uv);
    float mask   = smoothstep(0.001, -0.001, abs(r - 0.3) - 0.1);
    vec3  col    = a + b * cos(6.28 * (c * t + d));
    col          = clamp(col, 0., 1.);
    col          = mix(vec3(0.04), col, mask);
    col          = pow(col, vec3(0.4545));
    gl_FragColor = vec4(col, 1.);
}