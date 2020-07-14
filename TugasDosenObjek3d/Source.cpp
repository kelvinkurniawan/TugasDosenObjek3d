#include <gl/glut.h>

bool mouseDown = false;

float xrot = 0.0f;
float yrot = 0.0f;

float xdiff = 0.0f;
float ydiff = 0.0f;

float scale = 1.0f;
float xmovement = 0.0f;
float ymovement = 0.0f;
float zmovement = 0.0f;

class myObject {
public:
	void drawing() {
		// Base
		glBegin(GL_TRIANGLES);
		glColor3f(1, 1, 0);
		glVertex3f(-0.2, -0.2, -0.2);
		glVertex3f(-0.2, 0.2, -0.2);
		glVertex3f(-0.2, 0.2, 0.2);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(1, 1, 0);
		glVertex3f(0.8, -0.2, -0.2);
		glVertex3f(0.8, 0.2, -0.2);
		glVertex3f(0.8, 0.2, 0.2);
		glEnd();

		// Red quads

		glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex3f(-0.2, 0.2, 0.2);
		glVertex3f(0.8, 0.2, 0.2);
		glVertex3f(0.8, -0.2, -0.2);
		glVertex3f(-0.2, -0.2, -0.2);
		glEnd();

		// Green quads

		glBegin(GL_QUADS);
		glColor3f(0, 1, 0);
		glVertex3f(-0.2, 0.2, 0.2);
		glVertex3f(0.8, 0.2, 0.2);
		glVertex3f(0.8, 0.2, -0.2);
		glVertex3f(-0.2, 0.2, -0.2);
		glEnd();

		// Red quads

		glBegin(GL_QUADS);
		glColor3f(0, 0, 1);
		glVertex3f(-0.2, 0.2, -0.2);
		glVertex3f(0.8, 0.2, -0.2);
		glVertex3f(0.8, -0.2, -0.2);
		glVertex3f(-0.2, -0.2, -0.2);
		glEnd();
	}
};

void drawBox()
{

	// Base
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 0);
	glVertex3f(-0.2, -0.2, -0.2);
	glVertex3f(-0.2, 0.2, -0.2);
	glVertex3f(-0.2, 0.2, 0.2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 0);
	glVertex3f(0.8, -0.2, -0.2);
	glVertex3f(0.8, 0.2, -0.2);
	glVertex3f(0.8, 0.2, 0.2);
	glEnd();

	// Red quads

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(-0.2, 0.2, 0.2);
	glVertex3f(0.8, 0.2, 0.2);
	glVertex3f(0.8, -0.2, -0.2);
	glVertex3f(-0.2, -0.2, -0.2);
	glEnd();

	// Green quads

	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex3f(-0.2, 0.2, 0.2);
	glVertex3f(0.8, 0.2, 0.2);
	glVertex3f(0.8, 0.2, -0.2);
	glVertex3f(-0.2, 0.2, -0.2);
	glEnd();

	// Red quads

	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex3f(-0.2, 0.2, -0.2);
	glVertex3f(0.8, 0.2, -0.2);
	glVertex3f(0.8, -0.2, -0.2);
	glVertex3f(-0.2, -0.2, -0.2);
	glEnd();

}

bool init()
{
	glClearColor(0.93f, 0.93f, 0.93f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

	return true;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f); // Rotating horizontal
	glRotatef(yrot, 0.0f, 1.0f, 0.0f); // Rotating vertical
	glScalef(scale, scale, scale); // Scalling
	glTranslatef(xmovement, ymovement, zmovement); // Translate / Movement

	drawBox();

	glFlush();
	glutSwapBuffers();
}

void resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45.0f, 1.0f * w / h, 1.0f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key){
	case 'a':
		yrot += 5.0f;
		break;
	case 'd':
		yrot -= 5.0f;
		break;
	case 'w':
		xrot += 5.0f;
		break;
	case 's':
		xrot -= 5.0f;
		break;
	case '1':
		scale += 0.2f;
		break;
	case '2':
		scale -= 0.2f;
		break;
	case 27:
		exit(1); 
		break;
	}

	glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y)
{

	switch (key) {
	case 100:
		xmovement -= 0.025f;
		break;
	case 101:
		ymovement += 0.025f;
		break;
	case 102:
		xmovement += 0.025f;
		break;
	case 103:
		ymovement -= 0.025f;
		break;
	}

	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;

		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutCreateWindow("limas segitiga");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(resize);
	//glutIdleFunc(idle);

	if (!init())
		return 1;

	glutMainLoop();

	return 0;
}