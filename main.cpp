/**************************
 *
 * Labirynth Game
 * Author: Maurício Silva Soares
 *
 **************************
*/

#include <stdlib.h>
#include <gl/glut.h>
#include <iostream>

float pX = 49, pY = 19; //initial position X,Y
float step = 0.2; 	//step value 
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
	
	glColor3f(lR,lG,lB);
	//1
	glBegin(GL_POLYGON);
		glVertex3f(48, 19, 0);
		glVertex3f(47, 19, 0);
		glVertex3f(47, 39, 0);
		glVertex3f(48, 39, 0);
	glEnd();
	
	//2
	glBegin(GL_POLYGON);
		glVertex3f(47, 39, 0);
		glVertex3f(72, 39, 0);
		glVertex3f(72, 40, 0);
		glVertex3f(47, 40, 0);
	glEnd();
	
	//3
	glBegin(GL_POLYGON);
		glVertex3f(51, 19, 0);
		glVertex3f(52, 19, 0);
		glVertex3f(52, 36, 0);
		glVertex3f(51, 36, 0);
	glEnd();
	
	//4
	glBegin(GL_POLYGON);
		glVertex3f(51, 36, 0);
		glVertex3f(75, 36, 0);
		glVertex3f(75, 35, 0);		
		glVertex3f(51, 35, 0);
	glEnd();
	
	//5
	glBegin(GL_POLYGON);
		glVertex3f(76, 35, 0);
		glVertex3f(75, 35, 0);
		glVertex3f(75, 43, 0);		
		glVertex3f(76, 43, 0);
	glEnd();
	
	//6
	glBegin(GL_POLYGON);
		glVertex3f(76, 43, 0);
		glVertex3f(54, 43, 0);
		glVertex3f(54, 44, 0);		
		glVertex3f(76, 44, 0);
	glEnd();
	
	//7
	glBegin(GL_POLYGON);
		glVertex3f(50, 40, 0);
		glVertex3f(51, 40, 0);
		glVertex3f(51, 47, 0);		
		glVertex3f(50, 47, 0);
	glEnd();
	
	//8
	glBegin(GL_POLYGON);
		glVertex3f(50, 47, 0);
		glVertex3f(50, 48, 0);
		glVertex3f(57, 48, 0);		
		glVertex3f(57, 47, 0);
	glEnd();
	
	//9
	glBegin(GL_POLYGON);
		glVertex3f(60, 44, 0);
		glVertex3f(60, 54, 0);
		glVertex3f(61, 54, 0);		
		glVertex3f(61, 44, 0);
	glEnd();
	
	//10
	glBegin(GL_POLYGON);
		glVertex3f(57, 47, 0);
		glVertex3f(56, 47, 0);
		glVertex3f(56, 54, 0);		
		glVertex3f(57, 54, 0);
	glEnd();
	
	//player
	glColor3f(lR+0.3,lG,lB+0.1);
	glBegin(GL_POLYGON);
		glVertex3f(61, 54, 0);
		glVertex3f(56, 54, 0);
		glVertex3f(56, 58, 0);		
		glVertex3f(61, 58, 0);
	glEnd();
	
	glColor3f(pR,pG,pB);
	glBegin(GL_POLYGON);
		glVertex3f(pX, pY, 0);
		glVertex3f(pX+2.0, pY, 0);
		glVertex3f(pX+2, pY+2, 0);
		glVertex3f(pX, pY+2, 0);
	glEnd();
	
	glFlush();
}

bool Colision(int key){
		
	float pixel[4];
	
	switch(key){
		case GLUT_KEY_RIGHT:
			glReadPixels((pX+step+2),pY, 1, 1, GL_RGBA, GL_FLOAT, pixel);
			break;
		case GLUT_KEY_LEFT:
			glReadPixels((pX-step),pY, 1, 1, GL_RGBA, GL_FLOAT, pixel);
			break;
		case GLUT_KEY_DOWN:
			glReadPixels(pX,(pY-step), 1, 1, GL_RGBA, GL_FLOAT, pixel);
			break;
		case GLUT_KEY_UP:
			glReadPixels(pX,(pY+(step+2)), 1, 1, GL_RGBA, GL_FLOAT, pixel);
			break;	
	}
	
	printf("(%f,%f)\t",pX,pY);
	printf("lR: %f", lR);
	printf("pixel[0]: %f\t",pixel[0]);	
	printf("lG: %.2f", lG);
	printf("pixel[1]: %f\t",pixel[1]);
	printf("lB: %.2f", lB);
	printf("pixel[2]: %f\n",pixel[2]);
	
	if((pixel[0]==lR) && (pixel[1]==lG) && (pixel[2]==lB)){
		return false;
	}else{
		return true;
	}
		
}

//Move the player when directional keys are pressed
void KeyboardManagement(int key, int x, int y){

	if(Colision(key)){
		switch(key){
			case GLUT_KEY_RIGHT:
				pX += step;
				break;
			case GLUT_KEY_LEFT:
				pX -= step;
				break;
			case GLUT_KEY_DOWN:
				pY -= step;
				break;
			case GLUT_KEY_UP:
				pY += step;
				break;
			default:
				break;	
		}	
	}
	
	glutPostRedisplay();	
}

void LabColor(int choice){
	switch(choice){
		case 0:
			lR=1; lG=0; lB=0;
			break;
		case 1:
			lR=0; lG=1; lB=0;
			break;
		case 2:
			lR=0; lG=0; lB=1;
			break;
		case 3:
			lR=0; lG=0; lB=0;
			break;
	}
	
	glutPostRedisplay();
}

void PlayerColor(int choice){
	switch(choice){
		case 0:
			pR=1; pG=0; pB=0;
			break;
		case 1:
			pR=0; pG=1; pB=0;
			break;
		case 2:
			pR=0; pG=0; pB=1;
			break;
	}
	
	glutPostRedisplay();
}

void MainMenu(int choice){}

void NewMenu(){
	
	int menu, submenu1, submenu2;
	
	submenu1=glutCreateMenu(LabColor);
	glutAddMenuEntry("Red",0);
    glutAddMenuEntry("Green",1);
    glutAddMenuEntry("Blue",2);
    glutAddMenuEntry("Black",3);
    
    submenu2 = glutCreateMenu(PlayerColor);
    glutAddMenuEntry("Red",0);
    glutAddMenuEntry("Green",1);
    glutAddMenuEntry("Blue",2);
	
	menu=glutCreateMenu(MainMenu);
	glutAddSubMenu("Labirynth color",submenu1);
	glutAddSubMenu("Player color",submenu2);
	
	glutAttachMenu(GLUT_LEFT_BUTTON);
}

void MouseManagement(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		if(state == GLUT_DOWN)
			NewMenu();
	}
	
	glutPostRedisplay();
}

int main(void){
	
	//Game window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(650,650);
    glutInitWindowPosition(100,50);
	glutCreateWindow("Labirynth Game");
	Init();
	glutDisplayFunc(Draw);
	glutSpecialFunc(KeyboardManagement);
	glutMouseFunc(MouseManagement);
	glutMainLoop();
}


