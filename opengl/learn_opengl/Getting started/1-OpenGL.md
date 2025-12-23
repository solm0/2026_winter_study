# opengl이 무엇인가?

opengl이 무엇인가? opengl은 그래픽을 컨트롤하는 api라고 받아들여진다.
api가 무엇인가? api는 서로 다른 소프트웨어 어플리케이션이 소통하게 하는 규칙, 프로토콜(규칙, 절차, 관습), 도구의 모음이다.

그러나 opengl 혼자서는 api라고 할 수 없다. opengl의 각 함수가 어떻게 작동해야 하고 어떤 결과를 내야 하는지 명시해 놓은 사양일 뿐이다. 이것을 구현하는 것은 개발자의 몫이다. 주로 그래픽 카드 생산자가 그 그래픽카드에 맞는 방식으로 opengl을 라이브러리로 구현한다.

opengl을 쓴다는 것은 옛날에는 immediate mode를 사용하는 것을 뜻했다. 쉬웠지만 조작이 자유롭지 않았다. 그래서 opengl은 immediate mode를 없애고 core-profile mode란 걸 만들어서 거기서 직접 개발하게 했다. 그래서 더 유동적이고 효과적이 되었지만, 그만큼 어려워졌다.

# opengl 버전

LearnOpenGL 사이트에서는 opengl 3.3버전을 쓴다. 그 이유는, 3.3 이후의 버전은 부가적인 좀더 효과적 방법을 제시할 뿐이지 핵심 개념과 기술은 똑같기 때문이다. 그리고 최신버전 opengl은 최신 그래픽카드만 지원한다.

```
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
```

이건 어떤 opengl 버전을 쓸건지 glfw에게 알려주는 코드라고 한다.

영상튜토리얼에서 3.3을 썼는데 그게 옛날 영상이라 그런줄 알고 4.6으로 적었었다. 그런데 이 글을 읽으니 3.3으로 해도 될 것 같아서 3.3으로 바꿨다. 그리고 나서 정말 버전이 3.3으로 바뀐건지 테스트해보고 싶어서 출력해 봤다

```
int major, minor;
glGetIntegerv(GL_MAJOR_VERSION, &major);
glGetIntegerv(GL_MINOR_VERSION, &minor);
std::cout << major << "." << minor << std::endl;
```

참고로 이 코드는 glfwMakeContextCurrent(), gladLoadGL()이후에 적어야 한다. 안그러면 segmentation fault 에러가 난다.

4.1이 찍혔다. 왜 그런가 했는데 MacOS가 4.1 이후로 opengl지원을 안해서 내 맥북의 그래픽카드는 opengl 4.1을 쓰는 듯하다. glfwWindowHint()는 그냥 내가 3.3버전의 서브셋만 쓴다고 선언하는 것이지 어떤 Opengl버전을 쓸지는 이미 정해져 있는 것 같다.라고 추측한다.

# opengl의 context

opengl은 자기가 어떻게 작동해야 하는지 정의하는 값들로 이루어진 그 자체로 거대한 state machine이다. opengl의 상태는 보통 opengl context라고 한다. 이 context를 건드려서 뭘 렌더할지 바꾼다.(state-change) 그리고 상태를 읽어서 또 뭘 할지 정하기도 한다.(state-using)

# opengl의 object

opengl은 C로 쓰였다. C가 다른 고레벨 언어랑 번역이 잘 안되기 때문에 몇개의 추상화된 도구들이 만들어졌다. 그중 하나가 object이다. opengl 상태의 subset을 나타내는 옵션들의 모음이 object이다. 예를 들어 화면을 그리는 설정을 담은 object가 있을 수 있다.

이부분이 뭔 소린지 이해가 안돼서 챗지피티한테 물어봤다.

1. opengl은 C, C++, Java, Python, Rust 를 전부 지원해야 한다. 그래서 포인터, 클래스, 객체지향 문법을 포기하고 정수ID+상태머신? 이라는 걸 사용해야 했다. 언어중립적인 최선의 선택이었다고 한다.

상태머신이 뭐지? 상태머신은 시스템이나 프로그램의 동작을 상태(State), 전이(Transition), 이벤트(Event)를 이용해 모델링하는 거라고한다. 예를들어 자판기는 '동전투입', '상품선택'이라는 상태와 '음료제공', '거스름돈 반환'이라는 전이가 있다. 아직도 모르겠지만 뭐 여튼 추상화, 모듈화를 한다는 거지?

2. opengl은 전 세계 수천가지 GPU, 드라이버, OS 위에서 같은 코드가 동작해야 한다. 이때 opengl이 GPU 레지스터, 메모리 주소, 하드웨어 명령 같은 걸 직접 다루게 했다면 GPU마다 다른 코드를 작성해야 했을 것이다. 그래서 opengl에게 하드웨어를 직접 다루게 하지 말고, 정의된 추상화된 개념만 만지도록 했다고 한다.

그 추상화 중 하나가 object이다. object는 GPU 자원(메모리, 상태, 프로그램)을 하드웨어와 무관하게 표현한 추상개념이다. 그래서 opengl object는 c++ 클래스도 아니고, 실제 GPU 구조도 아니고, opengl이 만든 '개념적인 손잡이' 이다. object는 상태 묶음이고, api만 노출되었을 뿐 내부 구현은 숨겨져 있다.

opengl object의 예시로는 VBO, VAO, Texture, Shader, Program, Framebuffer등이 있다. 오픈지엘코드 보면 다 이런 거 만지는 거던데... GPU를 다루는 꼭두각시 같은걸 조종하고 있었다고 생각하면 되나?

근데 그럼 추상화된 개념 -> 하드웨어는 어떻게 되는건데? 그걸 그래픽카드 생산자가 구현한다는 건가? 챗지피티한테 물어보니까 맞다고한다. 그래픽카드 제조사(Nvidia, amd, intel, apple)가 opengl specification을 보고 자기 gpu구조에 맞게 드라이버라는 걸 구현한다고 한다.

드라이버는 GPU를 조정하고 통역사 역할을 하는데, 나는 opengl을 사용해서 GPU를 조종하는 게 아니라 GPU를 조종하는 드라이버를 조종하고있는 것이다. 나는 glBindBuffer, glDrawArrays, glUseProgram같은 약속된 주문만 외우고, 이걸 어떻게 실행할지는 드라이버가 책임지는 것이다.

이제야 왜 opengl이 사양일 뿐이고 구현을 그래픽카드 생산자가 한다는 건지 조금?알 것 같다.
