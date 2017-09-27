#include <iostream>

#include "glad/include/glad/glad.h"
#include "glfw/include/GLFW/glfw3.h"


const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "out vec4 f_color;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, 0, 1.0);\n"
        "   if(aPos.z == 0){\n"
        "       f_color = vec4(0.7f, 0.7f, 0.7f, 1.0f);\n"
        "   }else if(aPos.z == 0.1){\n"
        "       f_color = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
        "   }else if(aPos.z == 0.2){\n"
        "       f_color = vec4(0.0f, 0.0f, 1.0f, 1.0f);\n"
        "   }else{\n"
        "       f_color = vec4(0.0f, 0.0f, 0.0f, 1.0f);\n"
        "   }\n"
        "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "in vec4 f_color;\n"
        "void main()\n"
        "{\n"
        "   FragColor = f_color;\n"
        "}\n\0";


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow*window);

void moveEyes(double xpos, double ypos, float pDouble[162]);

void resetFace();

int main(void) {

    //initialize flfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Name", NULL, NULL);
    if(window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //make window current context
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //compile vertex shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //check if vertex shader compilation is successful
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "Failed vertex shader\n" << infoLog << std::endl;
    }

    //compile fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //check if fragment shader compilation is successful
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "Failed fragment shader\n" << infoLog << std::endl;
    }

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Failed linking\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



    unsigned int VBO;
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    while(!glfwWindowShouldClose(window)){

        float vertices[] = {
                // body
                0.5f,  0.5f, 0.0f,  // top right
                0.5f, -0.5f, 0.0f,  // bottom right
                -0.5f,  0.5f, 0.0f,  // top left
                // second triangle
                0.5f, -0.5f, 0.0f,  // bottom right
                -0.5f, -0.5f, 0.0f,  // bottom left
                -0.5f,  0.5f, 0.0f,   // top left

                //ears
                0.6f,  0.25f, 0.0f,  // top right
                0.6f, -0.25f, 0.0f,  // bottom right
                -0.6f,  0.25f, 0.0f,  // top left
                //second triangle
                0.6f,  -0.25f, 0.0f,  // bottom right
                -0.6f, -0.25f, 0.0f,  // bottom left
                -0.6f,  0.25f, 0.0f,  // top left

                //eye 1
                0.3f,  0.2f, 0.1f,  // top right
                0.3f, -0.2f, 0.1f,  // bottom right
                0.1f,  0.2f, 0.1f,  // top left
                //second triangle
                0.3f,  -0.2f, 0.1f,  // bottom right
                0.1f, -0.2f, 0.1f,  // bottom left
                0.1f,  0.2f, 0.1f,  // top left

                //iris 1
                0.25f,  0.1f, 0.2f,  // top right
                0.25f, -0.1f, 0.2f,  // bottom right
                0.15f,  0.1f, 0.2f,  // top left
                //second triangle
                0.25f,  -0.1f, 0.2f,  // bottom right
                0.15f, -0.1f, 0.2f,  // bottom left
                0.15f,  0.1f, 0.2f,  // top left

                //pupil  1
                0.225f,  0.05f, 0.3f,  // top right
                0.225f, -0.05f, 0.3f,  // bottom right
                0.175f,  0.05f, 0.3f,  // top left
                //second triangle
                0.225f,  -0.05f, 0.3f,  // bottom right
                0.175f, -0.05f, 0.3f,  // bottom left
                0.175f,  0.05f, 0.3f,  // top left

                //eye 2
                -0.3f,  0.2f, 0.1f,  // top right
                -0.3f, -0.2f, 0.1f,  // bottom right
                -0.1f,  0.2f, 0.1f,  // top left
                //second triangle
                -0.3f,  -0.2f, 0.1f,  // bottom right
                -0.1f, -0.2f, 0.1f,  // bottom left
                -0.1f,  0.2f, 0.1f,  // top left

                //iris 2
                -0.25f,  0.1f, 0.2f,  // top right
                -0.25f, -0.1f, 0.2f,  // bottom right
                -0.15f,  0.1f, 0.2f,  // top left
                //second triangle
                -0.25f,  -0.1f, 0.2f,  // bottom right
                -0.15f, -0.1f, 0.2f,  // bottom left
                -0.15f,  0.1f, 0.2f,  // top left

                //pupil  2
                -0.225f,  0.05f, 0.3f,  // top right
                -0.225f, -0.05f, 0.3f,  // bottom right
                -0.175f,  0.05f, 0.3f,  // top left
                //second triangle
                -0.225f,  -0.05f, 0.3f,  // bottom right
                -0.175f, -0.05f, 0.3f,  // bottom left
                -0.175f,  0.05f, 0.3f,  // top left

                //hair
                0.6f,  0.7f, 0.3f,  // top right
                0.6f, 0.5f, 0.3f,  // bottom right
                -0.6f,  0.7f, 0.3f,  // top left
                //second triangle
                0.6f,  0.5f, 0.3f,  // bottom right
                -0.6f, 0.5f, 0.3f,  // bottom left
                -0.6f,  0.7f, 0.3f,  // top left
        };

        processInput(window);

        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        moveEyes(xpos, ypos, vertices);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / (sizeof(float) * 3));

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}

void moveEyes(double xpos, double ypos, float *vertices) {
    xpos = (xpos - 400) / 800;
    ypos = -(ypos - 300) / 600;

//    std::cout << xpos << std::endl;

    float percentMovement = 0.1;
    float eye1_correctionx = (xpos - 0.1) * percentMovement;
    float eye1_correctiony = (ypos - 0) * percentMovement;

    if(eye1_correctionx > 0.05){
        eye1_correctionx = 0.05;
    }else if(eye1_correctionx < -0.05){
        eye1_correctionx = -0.05;
    }

    if(eye1_correctiony > 0.1){
        eye1_correctiony = 0.1;
    }else if(eye1_correctiony < -0.1){
        eye1_correctiony = -0.1;
    }

//    std::cout << eye1_correctionx << std::endl;

    float eye2_correctionx = (xpos - (-0.1)) * percentMovement;
    float eye2_correctiony = (ypos - 0) * percentMovement;

    if(eye2_correctionx > 0.05){
        eye2_correctionx = 0.05;
    }else if(eye2_correctionx < -0.05){
        eye2_correctionx = -0.05;
    }

    if(eye2_correctiony > 0.1){
        eye2_correctiony = 0.1;
    }else if(eye2_correctiony < -0.1){
        eye2_correctiony = -0.1;
    }

    for(int i = 54; i < 90; i += 3) {
        vertices[i] += eye1_correctionx;
        vertices[i + 1] += eye1_correctiony;
    }

    for(int i = 108; i < 144; i += 3){
        vertices[i] += eye2_correctionx;
        vertices[i + 1] += eye2_correctiony;
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow*window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}
