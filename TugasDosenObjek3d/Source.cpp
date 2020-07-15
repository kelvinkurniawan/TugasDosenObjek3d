#include <gl/glut.h>

float xrotation = 0.0f;
float yrotation = 0.0f;

float scale = 1.0f;
float xmovement = 0.0f;
float ymovement = 0.0f;
float zmovement = 0.0f;

class myObject {
public:
	void draw() {
		// Base

		glBegin(GL_TRIANGLES);
		glColor3ub(252, 187, 109);
		glVertex3f(-0.2, -0.2, -0.2);
		glVertex3f(-0.2, 0.2, -0.2);
		glVertex3f(-0.2, 0.2, 0.2);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3ub(216, 115, 127);
		glVertex3f(0.8, -0.2, -0.2);
		glVertex3f(0.8, 0.2, -0.2);
		glVertex3f(0.8, 0.2, 0.2);
		glEnd();

		// Side

		glBegin(GL_QUADS);
		glColor3ub(104, 93, 121);
		glVertex3f(-0.2, 0.2, 0.2);
		glVertex3f(0.8, 0.2, 0.2);
		glVertex3f(0.8, -0.2, -0.2);
		glVertex3f(-0.2, -0.2, -0.2);
		glEnd();

		glBegin(GL_QUADS);
		glColor3ub(88, 40, 65);
		glVertex3f(-0.2, 0.2, 0.2);
		glVertex3f(0.8, 0.2, 0.2);
		glVertex3f(0.8, 0.2, -0.2);
		glVertex3f(-0.2, 0.2, -0.2);
		glEnd();

		glBegin(GL_QUADS);
		glColor3ub(71, 92, 122);
		glVertex3f(-0.2, 0.2, -0.2);
		glVertex3f(0.8, 0.2, -0.2);
		glVertex3f(0.8, -0.2, -0.2);
		glVertex3f(-0.2, -0.2, -0.2);
		glEnd();
	}

	void transform() {
		glRotatef(xrotation, 1.0f, 0.0f, 0.0f); // Rotating horizontal
		glRotatef(yrotation, 0.0f, 1.0f, 0.0f); // Rotating vertical
		glScalef(scale, scale, scale); // Scalling
		glTranslatef(xmovement, ymovement, zmovement); // Translate / Movement
	}
};

void init()
{
	glClearColor(0.93f, 0.93f, 0.93f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

}

void display()
{
	myObject obj;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	obj.transform();
	obj.draw();

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


void keyboard(unsigned char key, int x, int y)
{
	switch (key){
	case 'a':
		yrotation += 5.0f;
		break;
	case 'd':
		yrotation -= 5.0f;
		break;
	case 'w':
		xrotation += 5.0f;
		break;
	case 's':
		xrotation -= 5.0f;
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

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutCreateWindow("Limas Segitiga - Tugas Dosen");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutReshapeFunc(resize);

	init();

	glutMainLoop();

	return 0;
}