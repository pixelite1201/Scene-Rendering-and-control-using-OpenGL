#include<cstdlib>
#include<iostream>
#include<GL/glut.h>
#include<fstream>
#include "imageloader.h"
#include <cmath>
#include "flythrough.cpp"
#include "variable.h"
#include "doll.cpp"
#include "box.cpp"
#include "table_chair.cpp"
#include "cupboard.cpp"
#include "lamp.cpp"
#include "room.cpp"
#include "display.cpp"
#include "texture.cpp"
#include "scene_render.cpp"
#include "keyboard.cpp"
#include "mouse_special_key.cpp"
#include "init.cpp"
using namespace std;

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH); 
	glutInitWindowPosition(100,100);
	glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
	glutCreateWindow("Animated Cube");

	sceneRender();
	init();
	glClearColor(0.0,0.0,0.0,0.0);
//glutKeyboardFunc(keyboard);
	
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutSpecialFunc(inputKey);
	glutReshapeFunc(resize);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(100, update, 0);
	glutMainLoop();
	return 0;
}
