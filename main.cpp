/**************************
 *
 * Maze Game
 * Author: Maurício Silva Soares
 * Using OpenGL
 * Goal:
 *	Move trough the maze until the end, without touch the walls
 * Controls:
 *	Directional keys for movement
 *	Left mouse buttom for color change
 *
 **************************
*/

#include <stdlib.h>
#include <gl/glut.h>
#include <iostream>

float pX = 48.5, pY = 19; //initial position X,Y
float step = 0.2; 	//step value 
float pR=1, pG=0, pB=0; //initial player color
float lR=0, lG=0, lB=0; //initial Maze color
float wR=1, wG=1, wB=1; //initial window color
int state=0; // 0 = on game, 1 = victory, 2 = game over


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

void Victory(void){
	state=1;
}

// a test to identifie collision by the color of the maze
bool ColisionByColor(int key){
		
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

// Collision based on a mockup available in github page
bool Collision(float x, float y, int rect,int key){
	// the collision is divided by 7 sectors (rect)
	switch(rect){
		case 1:
			if((48>x||x>49)||(19>y||y>37)){	// area 1 collision
				if(key==GLUT_KEY_RIGHT && (y>36 && y<37)){	// exception for area change
					return false;
				}else{
				printf("1");
				return true;
				}
			}else{	// if does not collide
				return false;
			}
			break;
		case 2:
			if((x>73)||(36>y||y>37)){ // area 2 collision
				if(key==GLUT_KEY_UP && (x>72 && y<73)){	// exception for area change
					return false;
				}else{
				printf("2");
				return true;
				}
			}else{	// if does not collide
				return false;
			}
			break;
		case 3:
			if((72>x||x>73)||(y>41)){	// area 3 collision
				if(key==GLUT_KEY_LEFT && (y>40 && y<41)){	// exception for area change
					return false;
				}else{
				printf("3");
				return true;
				}
			}else{	// if does not collide
				return false;
			}
			break;
		case 4:
			if((51>x)||(40>y||y>41)){	// area 4 collision
				if(key==GLUT_KEY_UP && (x>51 && y<52)){	// exception for area change
					return false;
				}else{
				printf("4");
				return true;
				}
			}else{	// if does not collide
				return false;
			}
			break;
		case 5:
			if((51>x||x>52)||(y>45)){	// area 5 collision
				if(key==GLUT_KEY_RIGHT && (y>44 && y<45)){	// exception for area change
					return false;
				}else{
				printf("5");
				return true;
				}
			}else{
				return false;
			}
			break;
		case 6:
			if((x>58)||(44>y)){	// area 6 collision
				if(key==GLUT_KEY_UP && (x>57 && y<58)){	// exception for area change
					return false;
				}else{
				printf("6");
				return true;
				}
			}else{	// if does not collide
				return false;
			}
			break;
		case 7:
			if((57>x||x>58)||(45>y)){	// area 7 collision
				printf("7");
				return true;
			}else{	// if does not collide
				return false;
			}
			break;
		default:
			return false;
	}
}

// verify wich area is the player in the maze (Veirify rectangle)
int VerifyRect(float x, float y){
	
	if((48<=x&&x<=49)&&(19<=y&&y<=37)){		//1
		printf("ret 1");
		return 1;
	}else if((49<=x&&x<=73)&&(36<=y&&y<=37)){	//2
		printf("ret 2");
		return 2;
	}else if((72<=x&&x<=73)&&(37<=y&&y<=41)){	//3
		printf("ret 3");
		return 3;
	}else if((51<=x&&x<=72)&&(40<=y&&y<=41)){	//4
		printf("ret 4");
		return 4;
	}else if((51<=x&&x<=52)&&(41<=y&&y<=45)){	//5
		printf("ret 5");
		return 5;
	}else if((52<=x&&x<=58)&&(44<=y&&y<=45)){	//6
		printf("ret 6");
		return 6;
	}else if((57<=x&&x<=58)&&(45<=y&&y<=54)){	//7
		printf("ret 7");
		return 7;
	}else if((57<=x&&x<=60)&&(54<=y&&y<=57)){
		return 0;
	}
}

//Move the player when directional keys are pressed
void KeyboardManagement(int key, int mouseX, int mouseY){
	
	float x=pX,y=pY;
	int rect = VerifyRect(x,y);
	
	if(state!=1){
		// add or subtract the step for wich directional key pressed
		switch(key){
			case GLUT_KEY_RIGHT:
				x += step;
				break;
			case GLUT_KEY_LEFT:
				x -= step;
				printf("%f",x);
				break;
			case GLUT_KEY_DOWN:
				y -= step;
				break;
			case GLUT_KEY_UP:
				y += step;
				break;
			default:
				break;	
		}
	}
	
	// verify the collision, if TRUE, reset the position
	if(Collision(x,y,rect,key)){
		state = 0;
		pX = 48.5;
		pY = 19;
		glutPostRedisplay();
	}else{	// else, the moviment is allowed
		pX = x;
		pY = y;
		glutPostRedisplay();
	}	
}

// change the maze color
void MazeColor(int choice){
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

//change the player color
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

// just to initialize the menu
void MainMenu(int choice){}

// create the menu and submenus for color change
void NewMenu(){
	
	int menu, submenu1, submenu2;
	
	submenu1=glutCreateMenu(MazeColor);
	glutAddMenuEntry("Red",0);
    glutAddMenuEntry("Green",1);
    glutAddMenuEntry("Blue",2);
    glutAddMenuEntry("Black",3);
    
    submenu2 = glutCreateMenu(PlayerColor);
    glutAddMenuEntry("Red",0);
    glutAddMenuEntry("Green",1);
    glutAddMenuEntry("Blue",2);
	
	menu=glutCreateMenu(MainMenu);
	glutAddSubMenu("Maze color",submenu1);
	glutAddSubMenu("Player color",submenu2);
	
	glutAttachMenu(GLUT_LEFT_BUTTON);
}

// calls a menu when left button is clicked
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


