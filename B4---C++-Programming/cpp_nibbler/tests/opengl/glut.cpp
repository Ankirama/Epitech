#include <iostream>
#include <GL/freeglut.h>

float velocity = 0.0f;
bool quit = false;

void	draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear Color and depth buffers

  glColor3f(1.0f, 0.0f, 1.0f);
  glRectf(10 + velocity, 10, 30 + velocity, 30);

  glColor3f(1.0f, 0.0f, 1.0f);
  glRectf(30 + velocity, 10, 50 + velocity, 30);

  velocity += 0.1f;
  //create triangle
  //  glBegin(GL_TRIANGLES);

  //  glVertex3f(-0.5,-0.5,0.0);
  //  glVertex3f(0.5,0.0,0.0);
  //  glVertex3f(0.0,0.5,0.0);
  //  glEnd();

  glFlush();
}

void	resize(int, int) {
  glutReshapeWindow(800, 640);
}

void	keyboard(unsigned char key, int, int) {
  if (key == 27) {
    quit = true;
    glutLeaveMainLoop();
  }
}

void	speKeyboard(int key, int, int) {
  switch (key) {
  case GLUT_KEY_LEFT:
    std::cout << "KEY LEFT" << std::endl;
    break;
  case GLUT_KEY_RIGHT:
    std::cout << "KEY RIGHT" << std::endl;
    break;
  }
}

/*
** Our constructor
*/
void	init(int width, int height)
{
  int	i;

  i = 0;
  glutInit(&i, 0); //Init glut
  glutInitWindowPosition(100, 100); //Init window's position
  glutInitWindowSize(width, height); //Init window's size
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //set DisplayMode (RGB, DOUBLE buffers, depth buffer
  glutCreateWindow("Nibbler"); //create Window with functions init (return window identifier)
  glLoadIdentity(); //reset transformations like translation / rotation
  gluOrtho2D(0.0, width, 0.0, height);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glMatrixMode(GL_PROJECTION);
}

void	game() {
  //callbacks
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(speKeyboard);
  glutIdleFunc(draw);
  glutReshapeFunc(resize); //remove resize window
  glutDisplayFunc(draw); //rendering
  glutMainLoop();
}

int	main()
{
  init(800, 640);
  game();
  return (0);
}
