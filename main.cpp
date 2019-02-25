/**************************
 *
 * Labirynth Game
 * Author: Maurício Silva Soares
 *
 **************************
*/

#include <stdlib.h>
#include <gl/glut.h>

float pX = 49.0, pY = 19.0;  //initial position X,Y
float sX = 1.0f, sY = 1.0; //step value 

void Init(void){
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,100.0,0.0,100.0);
}

void Draw(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex3f(49.0, 19.0, 0);
		glVertex3f(51.0, 19.0, 0);
		glVertex3f(51.0, 21.0, 0);
		glVertex3f(49.0, 21.0, 0);
	glEnd();
	
	glFlush();
}

void KeyboardManagement(unsigned char key, int x, int y){
//	switch(key){
//		case'GLUT_KEY_RIGHT':
//		case'GlUT_KEY_LEFT':
//		case'GLUT_KEY_DOWN':
//		case'GLUT_KEY_UP':	
//	}		
}

void Animation(int mValue){
	
}

int main(void){
	
	//Game window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(650,650);
    glutInitWindowPosition(100,50);
	glutCreateWindow("Labirynth Game");
	Init();
	glutDisplayFunc(Draw);
	glutTimerFunc(33,Animation,1);
	
	glutMainLoop();
}


