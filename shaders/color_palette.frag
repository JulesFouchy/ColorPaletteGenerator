#version 430

varying vec2 vTexCoords;

uniform float aspect_ratio;

uniform vec3 min_val;
uniform vec3 max_val;
uniform vec3 frequency;
uniform vec3 phase;

void main()
{
    vec2 uv = vTexCoords - 0.5;
    uv.x *= aspect_ratio;

    float t      = atan(uv.y, uv.x) / 6.28;
    float r      = length(uv);
    float mask   = smoothstep(0.001, -0.001, abs(r - 0.3) - 0.1);
    vec3  col    = mix(min_val, max_val, cos(6.28 * (frequency * t + phase))*0.5+0.5);
    col          = clamp(col, 0., 1.);
    col          = mix(vec3(0.04), col, mask);
    col          = pow(col, vec3(0.4545));
    gl_FragColor = vec4(col, 1.);
}