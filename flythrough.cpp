#include<cstdlib>
#include<iostream>
#include<GL/glut.h>
#include "imageloader.h"
#include <cmath>

using namespace std;
float width,height;
float count2=0;
float initial1=0;
int flag=0;
static float angle=0.0;
static float lx1=0.0f,ly1=0.0f,lz1=-1.0f,currentZ=0;
static float x=0.0f,y=0.0f,z=1.2f;
static float lx=0.0f,ly=0.0f,lz=-1.0f;
GLfloat ctrlpoints[1024][3];
float tim=0;
int imn=0;
int cp1=0;//keep index of ctrlpoints
int mode1=0;
int i1=0;
GLfloat ax[1024]={0},ay[1024]={0},az[1024]={1.2};
float Znear=0.5;
float Zfar = 200.0;
void moveMe() //since timer function is not working properly, i used this function to keep updating the values of lookat
{

	if(tim<1)//simply to provide delay in succesive increments of ax,ay,az, else we won't be able to see camera movements
	{
		tim=tim+0.5;
	}
	else if(tim>=1 && imn<i1-1)
	{                          //till the value of imn don't reach the last control point
		imn++;
		tim=0;
	}
	else
		mode1=0;
}
void curve()
{


	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, cp1, &ctrlpoints[0][0]);//used to draw bezier curve
	glEnable(GL_MAP1_VERTEX_3);
	GLint size;
	GLfloat feedBuffer[1024];
	glFeedbackBuffer (1024, GL_3D,feedBuffer);//used to read value of bezier curve vertex in feedBuffer
	glRenderMode (GL_FEEDBACK);//feedback mode don't draw on screen but store the value in feedbuffer
	glBegin (GL_POINTS);
	for (int i=0; i<=100; ++i)
	{
		GLfloat t = GLfloat(i)/100;
		glEvalCoord1f(t);
		// glPassThrough (1.0);
	}
	glEnd();

	size = glRenderMode (GL_RENDER);//again go to rendering mode
	GLint count = size;
	GLfloat token;
	i1=0;
	count2=abs(ctrlpoints[0][2]-ctrlpoints[cp1-1][2]);
	float temp=0;
		float temp2=0;
		float temp3=0.2*count2/100;
		float temp4=initial1*0.2;
	while (count) {
		temp4=temp4+temp3;
		token = feedBuffer[size-count]; count--;
		if (token == GL_POINT_TOKEN) 
			cerr<<"GL_POINT_TOKEN"<<endl;

		ax[i1]=(feedBuffer[size-count]-(width/2))/height;//store the corresponding curve points in array ax,ay,az
		count = count - 1;
		ay[i1]=(feedBuffer[size-count]-(height/2))/height;
		count = count - 1;
		temp=(2*(feedBuffer[size-count])-1);
		az[i1]=-(2*Zfar*Znear)/(Zfar+Znear-temp*(Zfar-Znear))+1.2;
		count = count - 1;
		temp2=-az[i1];
		ax[i1]=ax[i1]*(temp2+1-temp4);
		ay[i1]=ay[i1]*(temp2+1-temp4);	
		cerr<<ax[i1]<<endl;
		cerr<<ay[i1]<<endl;
		cerr<<az[i1]<<endl;
		i1++;

	}
	mode1=2;//change the mode to initialize the moveme function
}
