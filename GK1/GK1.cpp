#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>


#ifdef __APPLE__

#include <GLUT/glut.h>

#else

#include <GL/glut.h>

#endif


///////////////////////////////////////////////////////////
// Wywo³ywana w celu przerysowania sceny

void RenderScene(void) {
	int n = 5;
	float R = 25;
	GLfloat x, y;

	// Wyczyszczenie okna aktualnym kolorem czyszczcym   

	glClear(GL_COLOR_BUFFER_BIT);

	// Aktualny kolor rysujcy - czerwony  

	//           R     G     B  


	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_POLYGON);
	for (int k = 0; k < n; k++)
	{
		x = R * cos((M_PI / 2 + 2 * M_PI*k) / n);
		y = R * sin((M_PI / 2 + 2 * M_PI*k) / n);
		glVertex2f(x, y);
	}
	glEnd();

	// Wys³anie polece do wykonania     

	glFlush();
}

///////////////////////////////////////////////////////////

// Konfiguracja stanu renderowania  

void SetupRC(void) {

	// Ustalenie niebieskiego koloru czyszczcego     

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

}

///////////////////////////////////////////////////////////

// Wywo³ywana przez bibliotek GLUT w przypadku zmiany rozmiaru okna

void ChangeSize(int w, int h) {

	GLfloat aspectRatio;

	// Zabezpieczenie przed dzieleniem przez zero  

	if (h == 0)   h = 1;

	// Ustawienie wielkoœci widoku na równ¹ wielkoœci okna     

	glViewport(0, 0, w, h);

	// Ustalenie uk³adu wspó³rzêdnych  

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	// Wyznaczenie przestrzeni ograniczaj¹cej (lewy, prawy, dolny, górny, bliski, odleg³y)  

	aspectRatio = (GLfloat)w / (GLfloat)h;

	if (w <= h)    glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);

	else    glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);  glLoadIdentity();

}

///////////////////////////////////////////////////////////

// G³ówny punkt wejcia programu

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(800, 600);

	glutCreateWindow("GLRect");

	glutDisplayFunc(RenderScene);

	glutReshapeFunc(ChangeSize);

	SetupRC();

	glutMainLoop();

	return 0;

}

