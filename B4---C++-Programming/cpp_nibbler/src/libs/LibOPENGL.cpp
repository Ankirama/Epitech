#include "LibOPENGL.hh"

static IGraphLib	*g_lib;

static void _keyboard(unsigned char key, int, int) {
  if (key == 27) {
    glutLeaveMainLoop();
  }
}

static void _specKeyboard(int key, int, int) {
  if (g_lib->getMove()) {
    switch (key) {
    case GLUT_KEY_LEFT:
      g_lib->changeVelocity(ID_LEFT);
      g_lib->setMove(false);
      break;
    case GLUT_KEY_RIGHT:
      g_lib->setMove(false);
      g_lib->changeVelocity(ID_RIGHT);
      break;
    }
  }
}

LibOPENGL::LibOPENGL(int width, int height, int speed, GameLogic *gameLogic) {
  int	i;

  i = 0;
  this->m_gameLogic = gameLogic;
  this->m_width = width;
  this->m_height = height;
  this->m_speed = 1 / speed;
  this->m_x_scale = width / gameLogic->getWidth();
  this->m_y_scale = height / gameLogic->getHeight();
  this->m_x_velocity = 0.0f;
  this->m_y_velocity = 0.0f;
  this->m_x_factor = 0.01f;
  this->m_y_factor = 0.0f;
  this->m_move = false;
  glutInit(&i, 0);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(width, height);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutCreateWindow("Nibbler openGL");
  glLoadIdentity();
  gluOrtho2D(0.0f, width, 0.0f, height);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glMatrixMode(GL_PROJECTION);
}

bool LibOPENGL::update() {
  glutKeyboardFunc(_keyboard);
  glutSpecialFunc(_specKeyboard);
}

static void	_draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  g_lib->drawPieces();
  glFlush();
}

static void	_drawIDLE() {
  glutPostRedisplay();
}

bool LibOPENGL::game() {
  this->update();
  glutIdleFunc(_drawIDLE);
  glutDisplayFunc(_draw);
  std::cout << "TEST" << std::endl;
  glutMainLoop();
}

void LibOPENGL::drawPiece(float x, float y, GLfloat *color) {
  float	x_min;
  float	y_min;
  float	x_max;
  float	y_max;

  x_min = x * this->m_x_scale;
  y_min = y * this->m_y_scale;
  x_max = x_min + this->m_x_scale;
  y_max = y_min + this->m_y_scale;
  glColor3fv(color);
  //  std::cout << "x_min : " << x_min << ", y_min : " << y_min << ", x_max : " << x_max << ", y_max : " << y_max << std::endl;
  glRectf(x_min, y_min, x_max, y_max);
}

void LibOPENGL::drawPieces() {
  std::vector<IPiece *>	snake;
  IPiece		*food;
  GLfloat		color[3];

  std::cout << "x_velo : " << this->m_x_velocity << ", x_factor : " << this->m_x_factor << std::endl;
  std::cout << "y_velo : " << this->m_y_velocity << ", y_factor : " << this->m_y_factor << std::endl;
  if ((this->m_x_velocity += this->m_x_factor) >= 1.0f || this->m_x_velocity <= -1.0f ||
      (this->m_y_velocity += this->m_y_factor) >= 1.0f || this->m_y_velocity <= -1.0f) {
    this->m_move = true;
    if (this->m_gameLogic->update((int)this->m_x_velocity, (int)this->m_y_velocity) == false)
      glutLeaveMainLoop();
    this->m_x_velocity = 0.0f;
    this->m_y_velocity = 0.0f;
  }
  snake = this->m_gameLogic->getSnake()->getPieces();
  food = this->m_gameLogic->getFood()->getPiece();
  for (size_t i = 0; i < snake.size(); ++i) {
    color[0] = 0.0f;
    color[1] = 0.0f;
    color[2] = 1.0f;
    this->drawPiece(snake[i]->getX() + this->m_x_velocity, snake[i]->getY() + this->m_y_velocity, color);
  }
  color[0] = 1.0f;
  color[1] = 0.0f;
  color[2] = 0.0f;
  this->drawPiece(food->getX(), food->getY(), color);

}

void LibOPENGL::changeVelocity(int power) {
  if (this->m_x_factor == 0.0f) {
    this->m_x_factor = this->m_y_factor == 0.1f ? power * -0.01f : power * 0.01f;
    this->m_y_factor = 0;
  }
  else {
    this->m_y_factor = this->m_x_factor == 0.1f ? 0.01f * power : -0.01f * power;
    this->m_x_factor = 0;
  }
}

void LibOPENGL::resize(int, int) {
  glutReshapeWindow(this->m_width, this->m_height);
}

extern "C"
{
  IGraphLib *create_lib(int width, int height, int speed, GameLogic* gameLogic) {
    g_lib = new LibOPENGL(width, height, speed, gameLogic);
    return (g_lib);
  }
}
