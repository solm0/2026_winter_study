opengl을 필요로 하는 다른 헤더파일 이전에 glad를 include해야 한다.

# glfw window

`glfwInit` 창을 만들게 해주는 glfw를 initialize한다. 그다음 `glfwWindowHint`로 configure한다.

`glfwCreateWindow`한다. 가로세로 폭, 창 이름, NULL 2개. -> window object를 리턴한다. 이것은 window 관련 데이터를 가지고 있고, 대부분의 glfw 함수들에서 필요로 한다.

# glad init

glad가 opengl 함수들을 가져오기 때문에 glad를 initialize해야 한다. `glLoadGl`에 인자로 glfw가 os에 따라 맞는 함수위치를 준 `glfwGetProcAddress`를 넣으면 함수를 가져온다.

# viewport

`glViewport`로 opengl에게 창의 크기를 알려준다. 인자는 왼쪽아래 모퉁이의 위치, 가로세로 픽셀갯수.

# loop

delete하기 전에 loop를 열어서 창을 닫기 전에 계속 glfw에서 이벤트 받고 opengl에서 렌더하게 한다. 

`glfwWindowShouldClose`는 glfw가 닫힘명령을 받았는지를 가져온다. 그게 true면 while이 종료된다. 

`glfwPollEvents`는 키보드나 마우스 이벤트가 있는지 체크하고, 창 상태를 업데이트한다.

`glfwSwapBuffers`는 버퍼를 스왑한다.

# input

```
void processInput(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, true);
  }
}
```

`glfwGetKey`는 window와 키 코드를 받아서 그 키가 눌렸는지(`GLFW_PRESS`)를 리턴한다. 안 눌렸으면 `GLFW_RELEASE`를 리턴한다. 위 함수는 esc를 누르면 창을 닫는다. `processInput(window)`를 while안에 넣으면 된다.

while 루프 (=렌더 루프)는 프레임이다. ?

`glClear`가 clear할 수 있는 버퍼는 GL_COLOR_BUFFER_BUT, GL_DEPTH_BUFFER_BIT, GL_STENCIL_BUFFER_BIT이지만 현재 나는 color밖에 없으니까 그것만 지우면 된다.

`glClear`로 color buffer를 clear할 때마다 color buffer는 `glClearColor`에서 정한 색으로 채워진다.

= `glClearColor`는 state-setting function이고 `glClear`는 state-using function이다.


GL_COLOR_BUFFER_BIT 같은 것은 상수 state. opengl object는 생성/삭제할 수 있고, id(handle)이 있고, 상태를 가진다.