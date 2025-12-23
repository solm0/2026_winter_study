#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShader1Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
" FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

const char* fragmentShader2Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
" FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
"}\n\0";

 void processInput(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, true);
  }
}

int main()
{
  // glfw, glad
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGLStudy", NULL, NULL);
  if (window == NULL)
  {
      std::cout << "Failed to create GLFW window\n";
      glfwTerminate();
      return -1;
  }

  glfwMakeContextCurrent(window);

  gladLoadGL(glfwGetProcAddress);

  int fbWidth, fbHeight;
  glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
  glViewport(0, 0, fbWidth, fbHeight);



  // shader object
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  GLuint fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader1, 1, &fragmentShader1Source, NULL);
  glCompileShader(fragmentShader1);
  GLuint shaderProgram1 = glCreateProgram();
  glAttachShader(shaderProgram1, vertexShader);
  glAttachShader(shaderProgram1, fragmentShader1);
  glLinkProgram(shaderProgram1);

  GLuint fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader2, 1, &fragmentShader2Source, NULL);
  glCompileShader(fragmentShader2);
  GLuint shaderProgram2 = glCreateProgram();
  glAttachShader(shaderProgram2, vertexShader);
  glAttachShader(shaderProgram2, fragmentShader2);
  glLinkProgram(shaderProgram2);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader1);
  glDeleteShader(fragmentShader2);

  GLfloat vertices1[] = {
    0.0f,  0.5f, 0.0f,   // top right
    -0.3f, -0.9f, 0.0f,  // bottom left
    -0.3f,  0.5f, 0.0f   // top left 
  }; 
  GLfloat vertices2[] = {
    0.0f,  0.5f, 0.0f,   // top right
    -0.3f, -0.9f, 0.0f,  // bottom left
    0.0f, -0.9f, 0.0f,  // bottom right
  };
  GLfloat vertices3[] = {
    0.3f,  0.2f, 0.0f,   // top right
    -0.6f, -0.1f, 0.0f,  // bottom left
    -0.6f,  0.2f, 0.0f   // top left 
  }; 
  GLfloat vertices4[] = {
    0.3f,  0.2f, 0.0f,   // top right
    -0.6f, -0.1f, 0.0f,  // bottom left
    0.3f, -0.1f, 0.0f,  // bottom right
  };
  GLfloat vertices5[] = {
    0.5f,  0.8f, 0.0f,   // top right
    -0.3f, 0.5f, 0.0f,  // bottom left
    -0.3f,  0.8f, 0.0f   // top left 
  }; 
  GLfloat vertices6[] = {
    0.5f,  0.8f, 0.0f,   // top right
    -0.3f, 0.5f, 0.0f,  // bottom left
    0.5f, 0.5f, 0.0f,  // bottom right
  };

  GLuint VAOs[6], VBOs[6];

  glGenVertexArrays(6, VAOs);
  glGenBuffers(6, VBOs);
  
  glBindVertexArray(VAOs[0]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(VAOs[1]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(VAOs[2]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(VAOs[3]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices4), vertices4, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(VAOs[4]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[4]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices5), vertices5, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(VAOs[5]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[5]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices6), vertices6, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(0);

  // unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  while (!glfwWindowShouldClose(window))
  {
    // input
    processInput(window);

    // clear color buffer
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // shader, vertex array
    glUseProgram(shaderProgram1);
    glBindVertexArray(VAOs[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(shaderProgram2);
    glBindVertexArray(VAOs[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(shaderProgram1);
    glBindVertexArray(VAOs[2]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(shaderProgram2);
    glBindVertexArray(VAOs[3]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(shaderProgram1);
    glBindVertexArray(VAOs[4]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(shaderProgram2);
    glBindVertexArray(VAOs[5]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // glfw: swap buffer & listen events
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // delete opengl objects, program
  glDeleteVertexArrays(6, VAOs);
  glDeleteBuffers(6, VBOs);
  glDeleteProgram(shaderProgram1);
  glDeleteProgram(shaderProgram2);

  // delete glfw
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}