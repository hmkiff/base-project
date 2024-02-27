#version 330 core

layout(location = 0) in vec3 aPos; // Input attribute: position
// Other input attributes (e.g., normals, texture coordinates) can be added here

uniform mat4 model;      // Model matrix
uniform mat4 view;       // View matrix
uniform mat4 projection; // Projection matrix

void main() {
    // Transform the vertex position to clip space
    // gl_Position = projection * view * model * vec4(aPos, 1.0);
    gl_Position = projection * vec4(aPos, 1.0);
}
