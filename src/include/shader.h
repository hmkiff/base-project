#ifndef SHADER_H
#define SHADER_H

#include "../../libraries/include/glad/include/glad/glad.h"
#include <string>

class Shader {
public:
    // Constructor takes paths to vertex and fragment shader source files
    Shader(const char* vertexPath, const char* fragmentPath);

    // Use the shader
    void use();

    GLuint getProgram();

private:
    GLuint programID;

    // Utility function to read shader code from a file
    std::string readFile(const char* filePath);

    // Utility function to compile a shader
    GLuint compileShader(const char* shaderCode, GLenum shaderType);

    // Utility function to link the compiled shaders into a program
    void linkProgram(GLuint vertexShader, GLuint fragmentShader);
};

#endif // SHADER_H
