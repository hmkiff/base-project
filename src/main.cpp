// main.cpp

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "include/square.h"
#include "include/shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


int windowWidth = 800;
int windowHeight = 600;

const char* fragment_shader_path = "../shaders/fragment_shader_example.glsl";
const char* vertex_shader_path = "../shaders/vertex_shader_example.glsl";

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Configure GLFW to use the core profile without deprecated functions
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "My first OpenGL Window!", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize Glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize Glad" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Set the viewport size and register framebuffer size callback
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // vertex array and vertex buffer setup
    // Set up a vertex array object (VAO) and vertex buffer object (VBO)
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind VAO and VBO
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Define vertices of a line
    float vertices[10];

    Square mySquare = Square(100, {400.0f,300.0f});
    mySquare.printVertices();

    mySquare.unloadVertices(vertices);
    // Copy vertices to the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    // Set up vertex attributes
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VAO and VBO
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Create example shader
    Shader myShader(vertex_shader_path, fragment_shader_path);
    myShader.use();

    // Projection creation
    glm::mat4 projection = glm::ortho(0.0f, (float) width, (float) height, 0.0f, -1.0f, 1.0f);
    GLuint shaderProgram = myShader.getProgram();

    // Pass the projection matrix to the shader
    //glUseProgram(shaderProgram);
    int projectionLocation = glGetUniformLocation(shaderProgram, "projection");
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));


    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        // Handle or log the error
        std::cerr << "OpenGL Error: " << error << std::endl;
    }

    POS Pos = mySquare.getPosition();
    VEL vel = {0.2f,0.2f};
    mySquare.setVelocity(vel);

    glLineWidth(5.0f);

    // Main rendering loop
    while (!glfwWindowShouldClose(window)) {
        // Rendering code goes here

        // Clear window buffer
        glClear(GL_COLOR_BUFFER_BIT);

        error = glGetError();
        if (error != GL_NO_ERROR) {
            // Handle or log the error
            std::cerr << "OpenGL Error: " << error << std::endl;
        }
        // Render line
        // Use the shader program if you have one
        // Load example shader
        myShader.use();
        
        // error = glGetError();
        // if (error != GL_NO_ERROR) {
        //     // Handle or log the error
        //     std::cerr << "OpenGL Error: " << error << std::endl;
        // }

        // Bind VAO
        glBindVertexArray(VAO);

        error = glGetError();
        if (error != GL_NO_ERROR) {
            // Handle or log the error
            std::cerr << "OpenGL Error: " << error << std::endl;
        }

        // Draw the line
        glDrawArrays(GL_LINE_STRIP, 0, 5);

        error = glGetError();
        if (error != GL_NO_ERROR) {
            // Handle or log the error
            std::cerr << "OpenGL Error: " << error << std::endl;
        }

        // Unbind VAO
        glBindVertexArray(0);

        error = glGetError();
        if (error != GL_NO_ERROR) {
            // Handle or log the error
            std::cerr << "OpenGL Error: " << error << std::endl;
        }

        // Swap front and back buffers
        glfwSwapBuffers(window);

        error = glGetError();
        if (error != GL_NO_ERROR) {
            // Handle or log the error
            std::cerr << "OpenGL Error: " << error << std::endl;
        }

        // Square Animation
        mySquare.edgeDetect( (float) width, (float) height);
        mySquare.updatePosition();
        // mySquare.printPosition();
        mySquare.unloadVertices(vertices);
        
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up and terminate GLFW
    glfwTerminate();
    return 0;
}
