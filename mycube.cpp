#include<cstdlib>
#include<iostream>
#include<GL/glut.h>
#include<fstream>
#include "imageloader.h"
using namespace std;
float ratio;
GLfloat a=0;

void resize(int w,int h)
{
	if(h==0)
		h=1;
	ratio=1.0f*w/h;

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,ratio,2,200);


}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
			0,                            //0 for now
			GL_RGB,                       //Format OpenGL uses for image
			image->width, image->height,  //Width and height
			0,                            //The border of the image
			GL_RGB, //GL_RGB, because pixels are stored in RGB format
			GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
			//as unsigned numbers
			image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}
GLuint _textureId;
void sceneRender()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);

	glEnable(GL_NORMALIZE);
	Image* image = loadBMP("x.bmp");
	_textureId = loadTexture(image);
	delete image;
}
GLfloat		overtices[] =
{
	-1, -1, -1,   -1, -1,  1,   -1,  1,  1,   -1,  1, -1,
	1, -1, -1,    1, -1,  1,    1,  1,  1,    1,  1, -1,
	-1, -1, -1,   -1, -1,  1,    1, -1,  1,    1, -1, -1,
	-1, -1, -1,   -1,  1, -1,    1,  1, -1,    1, -1, -1,
	-1, -1,  1,   -1,  1,  1,    1,  1,  1,    1, -1,  1
};
GLfloat		ivertices[] =
{
-0.8, -1, -1,   -0.8, -1,  1,   -0.8,  1,  1,   -0.8,  1, -1,
	0.8, -1, -1,    0.8, -1,  1,    0.8,  1,  1,    0.8,  1, -1,
	-1, -1, -0.8,   -1,  1, -0.8,    1,  1, -0.8,    1, -1, -0.8,
	-1, -1,  0.8,   -1,  1,  0.8,    1,  1,  0.8,    1, -1,  0.8
	
};
GLfloat vertices[]=
{
-1,  1,  1,   -1,  1, -1,	 -0.8,  1, -1,	-0.8,  1,  1,  
 1,  1,  1,    1,  1, -1,	0.8,  1, -1,	0.8,  1,  1, 	
-1,  1, -1,    1,  1, -1, 	1,  1, -0.8,   -1, 1, -0.8,	
  -1,  1,  1,    1, 1,  1,	1,  1,  0.8,  -1, 1,  0.8	  
};
GLfloat topofbox[]=
{
-1,  1, -1,	-1,  1,  1,	 1,  1,  1,	1,  1, -1,	
-1,  1.2, -1,	-1,  1.2,  1,	 1,  1.2,  1,	1,  1.2, -1,		
-1,  1, -1,	-1,  1.2, -1,	  1,  1.2,  -1,	1,  1,  -1,	
-1,  1, -1,	-1,  1.2, -1,	-1,  1.2,  1,	-1,  1,  1,
1,  1,  1,	1,  1.2,  1,	 1,  1.2, -1,	1,  1, -1,
1,  1,  1,	1,  1.2,  1,	-1,  1.2,  1,	-1,  1,  1	

};
float textureCoordinates[] = { 0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,
	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,
	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,
	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,
	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,
	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,
	0.0f, 1.0f,
	
};
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



	gluLookAt(0, 0, 10.0, 0.0,0, -1.0, 0.0f, 1.0f, 0.0f);
	GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	GLfloat lightPos0[] = {0.0f,3.0f,0.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	//Bottom
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	

	glRotatef(40,1,0,0);
	glRotatef(0,0,1,0);
	glTexCoordPointer(2, GL_FLOAT, 0,textureCoordinates);
	glNormalPointer(GL_FLOAT,0,overtices);
	glVertexPointer(3, GL_FLOAT, 0, overtices);
	glDrawArrays(GL_QUADS, 0, 20);
	glTexCoordPointer(2, GL_FLOAT, 0,textureCoordinates);
	glNormalPointer(GL_FLOAT,0,ivertices);
	glVertexPointer(3, GL_FLOAT, 0, ivertices);
	glDrawArrays(GL_QUADS, 0, 16);
	glTexCoordPointer(2, GL_FLOAT, 0,textureCoordinates);
	glNormalPointer(GL_FLOAT,0,vertices);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 16);
	glPushMatrix();
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glTexCoordPointer(2, GL_FLOAT, 0,textureCoordinates);
	glNormalPointer(GL_FLOAT,0,topofbox);
	glVertexPointer(3, GL_FLOAT, 0, topofbox);
	glDrawArrays(GL_QUADS, 0, 24);
	glPopMatrix();

	glDisable( GL_TEXTURE_2D );


	

	glFlush();
	
	glutSwapBuffers();
	}
void keyboard( unsigned char key, int x, int y )
{
  
  switch(key)
    {
  case '1':
	if(a>180)
	a=0;
	a=a+1;
	break;
case '2':
	if(a==0)
	a=1;
	a=a-1;
	break;
    }
  glutPostRedisplay();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,640);
	glutCreateWindow("Animated Cube");
	sceneRender();
	glClearColor(0.0,0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}
