#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

// ------------------------------------
// Cube (one face is enough to see shading clearly)
float vertices[] = {
    // positions          // normals
    -0.5f,-0.5f, 0.0f,    0.0f,0.0f,1.0f,
     0.5f,-0.5f, 0.0f,    0.0f,0.0f,1.0f,
     0.5f, 0.5f, 0.0f,    0.0f,0.0f,1.0f,

     0.5f, 0.5f, 0.0f,    0.0f,0.0f,1.0f,
    -0.5f, 0.5f, 0.0f,    0.0f,0.0f,1.0f,
    -0.5f,-0.5f, 0.0f,    0.0f,0.0f,1.0f
};

// ------------------------------------
// Gouraud shaders (lighting per-vertex)

const char* gouraudVS = R"(#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vec3 lightPos = vec3(1.5, 1.5, 2.0);
    vec3 lightColor = vec3(1.0);
    vec3 objectColor = vec3(0.2, 0.6, 1.0);

    vec3 FragPos = vec3(model * vec4(aPos,1.0));
    vec3 Normal = normalize(mat3(transpose(inverse(model))) * aNormal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(Normal, lightDir), 0.0);

    Color = (diff + 0.15) * objectColor;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
)";

const char* gouraudFS = R"(#version 330 core
out vec4 FragColor;
in vec3 Color;
void main()
{
    FragColor = vec4(Color, 1.0);
}
)";

// ------------------------------------
// Phong shaders (lighting per-fragment)

const char* phongVS = R"(#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 FragPos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
)";

const char* phongFS = R"(#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

void main()
{
    vec3 lightPos = vec3(1.5, 1.5, 2.0);
    vec3 lightColor = vec3(1.0);
    vec3 objectColor = vec3(0.2, 0.6, 1.0);

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);

    vec3 viewDir = normalize(-FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);

    vec3 result = (diff + spec + 0.15) * objectColor;
    FragColor = vec4(result, 1.0);
}
)";

// ------------------------------------
GLuint compileShader(GLenum type, const char* src)
{
    GLuint s = glCreateShader(type);
    glShaderSource(s, 1, &src, nullptr);
    glCompileShader(s);
    return s;
}

GLuint createProgram(const char* vs, const char* fs)
{
    GLuint v = compileShader(GL_VERTEX_SHADER, vs);
    GLuint f = compileShader(GL_FRAGMENT_SHADER, fs);

    GLuint p = glCreateProgram();
    glAttachShader(p, v);
    glAttachShader(p, f);
    glLinkProgram(p);

    glDeleteShader(v);
    glDeleteShader(f);
    return p;
}

// ------------------------------------
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Phong vs Gouraud (1 / 2)", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGL();

    GLuint gouraudProgram = createProgram(gouraudVS, gouraudFS);
    GLuint phongProgram   = createProgram(phongVS, phongFS);
    GLuint currentProgram = gouraudProgram;

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.08f, 0.08f, 0.12f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
            currentProgram = gouraudProgram;
        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
            currentProgram = phongProgram;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(currentProgram);

        float t = glfwGetTime();
        glm::mat4 model = glm::rotate(glm::mat4(1.0f), t, glm::vec3(0.4f, 1.0f, 0.0f));
        glm::mat4 view  = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2.0f));
        glm::mat4 proj  = glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f, 100.0f);

        glUniformMatrix4fv(glGetUniformLocation(currentProgram,"model"),1,GL_FALSE,glm::value_ptr(model));
        glUniformMatrix4fv(glGetUniformLocation(currentProgram,"view"),1,GL_FALSE,glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(currentProgram,"projection"),1,GL_FALSE,glm::value_ptr(proj));

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
