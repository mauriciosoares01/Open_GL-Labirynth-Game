/**************************
 *
 * Labirynth Game
 * Author: Maurício Silva Soares
 *
 **************************
*/

#include <stdlib.h>
#include <gl/glut.h>

float pX = 49, pY = 19; //initial position X,Y
float sX = 1, sY = 1; 	//step value 
float pR=1, pG=0, pB=0; //initial player color
float lR=0, lG=0, lB=0; //initial labirynth color
float wR=1, wG=1, wB=1; //initial window color

//Configure the window and the viewport
void Init(void){
	glClearColor(wR,wG,wB,1.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,100.0,0.0,100.0);
}

//Draw the player and the walls
void Draw(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(pR,pG,pB);
	glBegin(GL_POLYGON);
		glVertex3f(pX, pY, 0);
		glVertex3f(pX+2.0, pY, 0);
		glVertex3f(pX+2, pY+2, 0);
		glVertex3f(pX, pY+2, 0);
	glEnd();
	
//	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(lR,lG,lB);
	glBegin(GL_POLYGON);
		glVertex3f(48, 19, 0);
		glVertex3f(47, 19, 0);
		glVertex3f(47, 39, 0);
		glVertex3f(48, 39, 0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(32, 39, 0);
		glVertex3f(72, 39, 0);
		glVertex3f(72, 40, 0);
		glVertex3f(32, 40, 0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(51, 19, 0);
		glVertex3f(52, 19, 0);
		glVertex3f(52, 36, 0);
		glVertex3f(51, 36, 0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(51, 36, 0);
		glVertex3f(75, 36, 0);
		glVertex3f(75, 35, 0);		
		glVertex3f(51, 35, 0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(76, 35, 0);
		glVertex3f(75, 35, 0);
		glVertex3f(75, 43, 0);		
		glVertex3f(76, 43, 0);
	glEnd();
	
	glFlush();
}

//Move the player when directional keys are pressed
void KeyboardManagement(int key, int x, int y){

	switch(key){
		case GLUT_KEY_RIGHT:
			pX += 0.3f;
			break;
		case GLUT_KEY_LEFT:
			pX -= 0.3f;
			break;
		case GLUT_KEY_DOWN:
			pY -= 0.3f;
			break;
		case GLUT_KEY_UP:
			pY += 0.3f;
			break;	
	}	
	
	glutPostRedisplay();	
}

//void CreateMenu(){
//	
//}
//
//void MouseManagement(int button, int state, int x, int y){
//	if(button == GLUT_RIGHT_BUTTON){
//		if(state == GLUT_DOWN)
//			CreateMenu();
//	}
//}

int main(void){
	
	//Game window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(650,650);
    glutInitWindowPosition(100,50);
	glutCreateWindow("Labirynth Game");
	Init();
	glutDisplayFunc(Draw);
	glutSpecialFunc(KeyboardManagement);
//	glutMouseFunc(MouseManagement);
	glutMainLoop();
}


