#include<cstdlib>
#include<iostream>
#include<GL/glut.h>
#include "imageloader.h"
using namespace std;
float ratio;
enum modes{head,neck,uLegR,uArmR,uArmL, uLegL,lLegR,lArmR,lArmL, lLegL,feetR, feetL,handR,handL,torso ,scene,initial,box,human}mode;
GLfloat light_position[]={0.0, 3.0, 3.0, 1.0};
GLfloat light_diffuse[]={0.7, 0.7, 0.7, 1.0};
GLfloat light_specular[]={0.7 ,0.7, 0.7, 0.0};
GLint head_id=0,neck_id=0,torso_id=0,left_upper_leg_id=0,right_upper_leg_id=0,left_lower_leg_id=0,right_lower_leg_id=0,
      left_feet_id=0,right_feet_id=0,left_upper_arm_id=0,right_upper_arm_id=0,left_lower_arm_id=0,right_lower_arm_id=0,
      left_hand_id=0,right_hand_id=0,hip_id=0,box_id=0;
////////////////////////////////box//////////////////////////////
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
GLfloat mvertices[]=
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
//////////////////////box////////////////////////////////
/////////////////////cap///////////////////////////////////
GLfloat vertices[]=
{
	0.0,3.0,0.0,	-1.0,1.2,1.0,	1.0,1.2,1.0,	1.0,1.2,-1.0,	-1.0,1.2,-1.0,	-1.0,1.2,1.0
};
GLfloat texture[]=
{
	0.5,0.5,	0.2,0.0	,	0.4,0.0,	0.6,0.0,	0.8,0.0
};
////////////////////////////cap/////////////////////////
GLfloat a=0;
GLfloat scene_x=0, scene_y=0, scene_z=5.0f;
GLfloat scene_r_x=0,scene_r_y=0,scene_r_z=0;
GLfloat human_r_x=0,human_r_y=0,human_r_z=0;
GLfloat head_r_x=0,head_r_y=0,head_r_z=0;
GLfloat box_r_x=0,box_r_y=0,box_r_z=0;
GLfloat neck_r_x=0,neck_r_y=0,neck_r_z=0;
GLfloat uArmL_r_x=0,uArmL_r_y=0,uArmL_r_z=80;
GLfloat uArmR_r_x=0,uArmR_r_y=0,uArmR_r_z=-80;
GLfloat lArmR_r_x=0,lArmR_r_y=0,lArmR_r_z=0;
GLfloat lArmL_r_x=0,lArmL_r_y=0,lArmL_r_z=0;

GLfloat uLegL_r_x=0,uLegL_r_y=0,uLegL_r_z=0;
GLfloat uLegR_r_x=0,uLegR_r_y=0,uLegR_r_z=0;
GLfloat lLegR_r_x=0,lLegR_r_y=0,lLegR_r_z=0;
GLfloat lLegL_r_x=0,lLegL_r_y=0,lLegL_r_z=0;

GLfloat torso_r_x=0,torso_r_y=0,torso_r_z=0;
GLfloat feetR_r_x = 0,feetR_r_y = 0,feetR_r_z = 0;
GLfloat feetL_r_x = 0,feetL_r_y = 0,feetL_r_z = 0;

GLfloat handR_r_x = 0,handR_r_y = 0,handR_r_z = 0;
GLfloat handL_r_x = 0,handL_r_y = 0,handL_r_z = 0;

GLuint _textureId1;
GLuint _textureId;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;
GLUquadricObj *quadratic;

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
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
			0,                            //0 for now
			GL_RGB,                       //Format OpenGL uses for image
			image->width, image->height,  //Width and height
			0,                            //The border of the image
			GL_RGB,   //GL_RGB, because pixels are stored in RGB format
			GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
			//as unsigned numbers
			image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void sceneRender()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glMaterialf(GL_FRONT, GL_SHININESS, 100.0f);
	glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular);	
	glEnable(GL_NORMALIZE);
	Image* image = loadBMP("x.bmp");
	_textureId1 = loadTexture(image);

	Image* image1 = loadBMP("e.bmp");
	_textureId = loadTexture(image1);
	Image* image2 = loadBMP("m.bmp");
	_textureId2 = loadTexture(image2);
	Image* image3 = loadBMP("l.bmp");
	_textureId3 = loadTexture(image3);
	Image* image4 = loadBMP("p.bmp");
	_textureId4 = loadTexture(image4);
	Image* image5 = loadBMP("y.bmp");
	_textureId5 = loadTexture(image5);
	Image* image6 = loadBMP("shirt.bmp");
	_textureId6 = loadTexture(image6);
	delete image;
	delete image1;
	delete image2;
	delete image3;
	delete image4;
	delete image5;
	delete image6;
}
void struct_box()
{
	glNewList(box_id,GL_COMPILE); 
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0,textureCoordinates);
	glNormalPointer(GL_FLOAT,0,topofbox);
	glVertexPointer(3, GL_FLOAT, 0, topofbox);
	glDrawArrays(GL_QUADS, 0, 24);
	glPopMatrix();
	glEndList();
}

void struct_hip()
{
	glNewList(hip_id,GL_COMPILE); 
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();
	glRotatef(90,0,1,0);  //to align texture properly
	gluSphere( quadratic, 1.0, 100, 100);
	glPopMatrix();
	glEndList();
}
void struct_torso()
{
	glNewList(torso_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId6);
	glPushMatrix(); //cylinder of torso
	glRotatef(-90,1.0,0.0,0.0); 
	gluCylinder(quadratic,1.0f,1.0f,3.0f,50,50);
	glPopMatrix(); //cylinder of torso
	glDisable(GL_TEXTURE_2D);
	glPushMatrix(); //upper sphere
	glTranslatef(0.0f,3.0f,0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glRotatef(90,0,1,0);  //to align texture properly
	gluSphere( quadratic, 1.0, 100, 100);
	glPopMatrix(); //upper sphere of torso
	glEndList();
}
void struct_left_upper_arm()
{
	glNewList(left_upper_arm_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();			
	glRotatef(90.0,1.0,0.0,0.0); 
	gluCylinder(quadratic,0.4f,0.3f,2.0f,50,50);
	gluSphere( quadratic, 0.4, 100, 100);
	glPopMatrix();
	glEndList();
}
void struct_left_lower_arm()
{
	glNewList(left_lower_arm_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();				
	glRotatef(90.0,1.0,0.0,0.0); 
	gluCylinder(quadratic,0.3f,0.2f,2.0f,50,50);
	glPopMatrix();
	gluSphere( quadratic, 0.3, 100, 100);
	glEndList();
}
void struct_left_hand()
{
	glNewList(left_hand_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();//left hand geometry
	glRotatef(90,1,0,0);
	gluCylinder(quadratic,0.2f,0.3f,0.4f,50,50);
	glTranslatef(0,0,0.4);
	gluCylinder(quadratic,0.3f,0.2f,0.4f,50,50);
	glTranslatef(0,0,0.4);
	gluSphere( quadratic, 0.2, 100, 100);
	glPopMatrix();//left hand*/
	glEndList();
}
void struct_right_upper_arm()
{
	glNewList(right_upper_arm_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();			
	glRotatef(90.0,1.0,0.0,0.0); 
	gluCylinder(quadratic,0.4f,0.3f,2.0f,50,50);
	gluSphere( quadratic, 0.4, 100, 100);
	glPopMatrix();
	glEndList();
}
void struct_right_lower_arm()
{
	glNewList(right_lower_arm_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();				
	glRotatef(90.0,1.0,0.0,0.0); 
	gluCylinder(quadratic,0.3f,0.2f,2.0f,50,50);
	glPopMatrix();
	gluSphere( quadratic, 0.3, 100, 100);
	glEndList();
}
void struct_right_hand()
{
	glNewList(right_hand_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();//right hand
	glRotatef(90,1,0,0);
	gluCylinder(quadratic,0.2f,0.3f,0.4f,50,50);
	glTranslatef(0,0,0.4);
	gluCylinder(quadratic,0.3f,0.2f,0.4f,50,50);
	glTranslatef(0,0,0.4);
	gluSphere( quadratic, 0.2, 100, 100);
	glPopMatrix();//right hand*/
	glEndList();
}
void struct_neck()
{
	glNewList(neck_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();
	glRotatef(90,1.0,0.0,0.0);
	gluCylinder(quadratic,0.3f,0.3f,1.0f,50,50);
	gluSphere( quadratic, 0.3, 100, 100);
	glPopMatrix();
	glPushMatrix(); //lower sphere of neck
	glTranslatef(0,-0.9,0);
	gluSphere( quadratic, 0.3, 100, 100);
	glPopMatrix();
	gluSphere( quadratic, 0.3, 100, 100);//upper sphere of neck
	glEndList();
}
void struct_head()
{
	glNewList(head_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	gluSphere( quadratic, 1.0, 100, 100);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId5);
	glBegin( GL_QUADS);//right eye
	glNormal3f(0,0.6,1);
	glTexCoord2f( 0, 0 );glVertex3f(0.35,0.5 ,1.0);
	glTexCoord2f( 0, 1 ); glVertex3f(0.15, 0.5,1.0);
	glTexCoord2f( 1, 1 ); glVertex3f(0.15, 0.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(0.35, 0.0,1.0);
	glEnd();
	glBegin( GL_QUADS);//left eye
	glNormal3f(0,0.6,1);
	glTexCoord2f( 0, 0 );glVertex3f(-0.35,0.5 ,1.0);
	glTexCoord2f( 0, 1 ); glVertex3f(-0.15, 0.5,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(-0.15, 0.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(-0.35, 0.0,1.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glPushMatrix();//nose
	glTranslatef(0.0,-0.3,1.0);
	gluSphere(quadratic,0.2,100,100);
	glPopMatrix();
	glPushMatrix();//ear begin
	glTranslatef(-1.2,0.0,0.0);
	glPushMatrix();
	glRotatef(90,0,1,0);//to change the orientation of cylinder
	gluCylinder(quadratic,0.2f,0.2f,2.35f,50,50);
	glPopMatrix();
	gluSphere(quadratic,0.2,100,100);
	glTranslatef(2.35,0.0,0.0);
	gluSphere(quadratic,0.2,100,100);
	glPopMatrix();//ear finish
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glNormalPointer(GL_FLOAT,0,vertices);
	glTexCoordPointer(2, GL_FLOAT, 0,texture);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glPushMatrix();
	glTranslatef(0,2.5,0);
	gluSphere(quadratic,0.2,100,100);//sphere of cap
	glPopMatrix();
	glPushMatrix();//cap
	glTranslatef(0,-0.7,0);
	glRotatef(90,0,1,0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
	glPopMatrix();//cap
	glEndList();
}
void struct_left_upper_leg()
{
	glNewList(left_upper_leg_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();			
	glRotatef(90.0,1.0,0.0,0.0); 
	gluCylinder(quadratic,0.4f,0.3f,3.0f,50,50);
	glPopMatrix();
	glEndList();
}
void struct_left_lower_leg()
{
	glNewList(left_lower_leg_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();				
	glRotatef(90.0,1.0,0.0,0.0); 
	gluCylinder(quadratic,0.3f,0.2f,3.0f,50,50);
	glPopMatrix();
	gluSphere( quadratic, 0.3, 100, 100);
	glEndList();
}
void struct_left_feet()
{
	glNewList(left_feet_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();
	glRotatef(30,1,0,0);
	gluCylinder(quadratic,0.2f,0.3f,0.5f,50,50);
	glTranslatef(0,0,0.5);
	gluCylinder(quadratic,0.3f,0.2f,0.5f,50,50);
	glTranslatef(0,0,0.5);
	gluSphere( quadratic, 0.2, 100, 100);
	glPopMatrix();
	glEndList();
}
void struct_right_upper_leg()
{
	glNewList(right_upper_leg_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();			
	glRotatef(90.0,1.0,0.0,0.0); 
	gluCylinder(quadratic,0.4f,0.3f,3.0f,50,50);
	glPopMatrix();
	glEndList();
}
void struct_right_lower_leg()
{
	glNewList(right_lower_leg_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();				
	glRotatef(90.0,1.0,0.0,0.0); 
	gluCylinder(quadratic,0.3f,0.2f,3.0f,50,50);
	glPopMatrix();
	gluSphere( quadratic, 0.3, 100, 100);
	glEndList();
}
void struct_right_feet()
{
	glNewList(right_feet_id,GL_COMPILE);
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();
	glRotatef(30,1,0,0);
	gluCylinder(quadratic,0.2f,0.3f,0.5f,50,50);
	glTranslatef(0,0,0.5);
	gluCylinder(quadratic,0.3f,0.2f,0.5f,50,50);
	glTranslatef(0,0,0.5);
	gluSphere( quadratic, 0.2, 100, 100);
	glPopMatrix();//right feet
	glEndList();
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
	gluLookAt(scene_x,scene_y,scene_z,0,0,-1,0,1,0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//////////////////////////////////////////////////scene
	glPushMatrix();
	glScalef(0.2,0.2,0.2);
	glRotatef(scene_r_x,1.0,0.0,0.0); 
	glRotatef(scene_r_y,0.0,1.0,0.0);
	glRotatef(scene_r_z,0.0,0.0,1.0);
	/////////////////////////////////////////////////box
	glPushMatrix();
	glScalef(2,2,2);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId1);
	glTranslatef(-3,0,0);
	glRotatef(box_r_x,1.0,0.0,0.0); 
	glRotatef(box_r_y,0.0,1.0,0.0);
	glRotatef(box_r_z,0.0,0.0,1.0);
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
	glVertexPointer(3, GL_FLOAT, 0, mvertices);
	glDrawArrays(GL_QUADS, 0, 16);
	glPushMatrix();

	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glCallList(box_id);
	glDisable( GL_TEXTURE_2D );
	glPopMatrix();
	/////////////////////////////////////////////////human
	glPushMatrix();
	glTranslatef(3,0,0);
	glRotatef(human_r_x,1.0,0.0,0.0); 
	glRotatef(human_r_y,0.0,1.0,0.0);
	glRotatef(human_r_z,0.0,0.0,1.0);
	/////////////////////lower sphere of torso//hip
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glPushMatrix(); 
	glCallList(hip_id);
	glDisable(GL_TEXTURE_2D);
	////////////////////////hip, torso(Cylinder and upper sphere)
	glPushMatrix(); 
	glRotatef(torso_r_x,1.0,0.0,0.0);	//to animate
	glRotatef(torso_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(torso_r_z,0.0,0.0,1.0);	//to animate
	glCallList(torso_id);
	//////////////////////////////////////////hip,torso,left upper arm
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glPushMatrix(); 
	glTranslatef(-1.0f,3.0f,0.0f);			
	glRotatef(uArmL_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(uArmL_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(uArmL_r_z,0.0,0.0,1.0);	//to animate
	glRotatef(-90.0,0.0,0.0,1.0);
	glCallList(left_upper_arm_id);
	///////////////////////////////hip,torso,upper,lower arm
	glPushMatrix();
	glTranslatef(0.0,-2.0f,0.0f);				
	glRotatef(lArmL_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(lArmL_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(lArmL_r_z,0.0,0.0,1.0);	//to animate
	glCallList(left_lower_arm_id);
	glDisable(GL_TEXTURE_2D);
	//////////////////////////////hip,torso,upper,lower arm,hand 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glPushMatrix();
	glTranslatef(0.0,-2.0,0);						
	glRotatef(handL_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(handL_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(handL_r_z,0.0,0.0,1.0);	//to animate
	glCallList(left_hand_id);
	glPopMatrix();//left hand 
	glPopMatrix();//lower arm
	glPopMatrix(); //upper arm	
	glDisable(GL_TEXTURE_2D);
	//////////////////////////////////////hip,torso,right upper arm
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glPushMatrix(); 
	glTranslatef(1.0f,3.0f,0.0f);			
	glRotatef(uArmR_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(uArmR_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(uArmR_r_z,0.0,0.0,1.0);	//to animate
	glRotatef(90.0,0.0,0.0,1.0);
	glCallList(right_upper_arm_id);	
	//////////////////////////////////////hip,torso,upper,lower arm		

	glPushMatrix();
	glTranslatef(0.0,-2.0f,0.0f);				
	glRotatef(lArmR_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(lArmR_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(lArmR_r_z,0.0,0.0,1.0);	//to animate
	glCallList(right_lower_arm_id);
	glDisable(GL_TEXTURE_2D);
	/////////////////////////////////////hip,torso,upper,lower arm,hand
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glPushMatrix(); 
	glTranslatef(0.0,-2.0,0);
	glRotatef(handR_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(handR_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(handR_r_z,0.0,0.0,1.0);	//to animate
	glCallList(right_hand_id);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();//right hand
	glPopMatrix();//lower arm
	glPopMatrix(); //upper arm

	////////////////////////////hip,torso,neck

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glPushMatrix();	//hip,torso,neck
	glTranslatef(0.0f,5.0f,0.0f);
	glTranslatef(0.0,-1.0,0.0);
	glRotatef(neck_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(neck_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(neck_r_z,0.0,0.0,1.0);	//to animate
	glTranslatef(0.0,1.0,0.0);
	//  glPushMatrix();	//neck
	glCallList(neck_id);
	glDisable(GL_TEXTURE_2D);
	///////////////////////////////////hip,torso,neck,head
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	//glRotatef(-90,0.0,1.0,0.0);//to align texture properly
	glPushMatrix(); //hip,torso,neck,head
	glTranslatef(0.0f,0.5f,0.0f);
	glTranslatef(0.0,-1.0,0.0);				
	glRotatef(head_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(head_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(head_r_z,0.0,0.0,1.0);	//to animate
	glTranslatef(0.0,1.0,0.0);
	glCallList(head_id);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();//head
	glPopMatrix();//neck
	glPopMatrix();//torso(Cylinder and Upper sphere)

	/////////////////////////////hip,left upper leg
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glPushMatrix(); 
	glRotatef(uLegL_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(uLegL_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(uLegL_r_z,0.0,0.0,1.0);	//to animate
	glTranslatef(-0.5f,0.0f,0.0f);
	glCallList(left_upper_leg_id);
	////////////////////////hip,upper,lower leg		
	glPushMatrix();
	glTranslatef(0.0,-3.0f,0.0f);				
	glRotatef(lLegL_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(lLegL_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(lLegL_r_z,0.0,0.0,1.0);	//to animate
	glCallList(left_lower_leg_id);
	glDisable(GL_TEXTURE_2D);
	///////////////////////////////hip,upper,lower,feet
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glPushMatrix();

	glTranslatef(0.0,-3.0,0);
	glRotatef(feetL_r_x,1.0,0.0,0.0); //to animate
	glRotatef(feetL_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(feetL_r_z,0.0,0.0,1.0);	//to animate
	glCallList(left_feet_id);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();//left feet
	glPopMatrix();//lower leg
	glPopMatrix(); //upper leg 		
	///////////////////////////////////////hip,right upper leg
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);

	glPushMatrix(); 
	glRotatef(uLegR_r_x,1.0,0.0,0.0); 	//to animate
	glRotatef(uLegR_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(uLegR_r_z,0.0,0.0,1.0);	//to animate
	glTranslatef(0.5f,0.0f,0.0f);
	glCallList(right_upper_leg_id);
	//////////////////////////////////////hip,upper,lower
	glPushMatrix();
	glTranslatef(0.0,-3.0f,0.0f);				
	glRotatef(lLegR_r_x,1.0,0.0,0.0); //to animate
	glRotatef(lLegR_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(lLegR_r_z,0.0,0.0,1.0);	//to animate
	glCallList(right_lower_leg_id);
	glDisable(GL_TEXTURE_2D);

	/////////////////////////////////////hip,upper,lower,feet
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glPushMatrix();//right feet
	glTranslatef(0.0,-3.0,0);
	glRotatef(feetR_r_x,1.0,0.0,0.0); //to animate
	glRotatef(feetR_r_y,0.0,1.0,0.0);	//to animate
	glRotatef(feetR_r_z,0.0,0.0,1.0);	//to animate
	glCallList(right_feet_id);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();//right feet
	glPopMatrix();//lower leg
	glPopMatrix(); //upper leg 		
	glPopMatrix(); //torso
	glPopMatrix();//human
	glPopMatrix(); //scene

	glutSwapBuffers();
	//glutPostRedisplay(); this removed and instead glutIdleFunction also set as display function
}

void keyboard( unsigned char key, int x, int y )
{

	switch(key)
	{

		case 's':mode = scene;break;
		case 'h':mode = head; break;
		case 'n':mode = neck; break;
		case 't':mode = torso;break;

		case 'z': mode = uLegL;break;	
		case 'c': mode = lLegL;break;
		case 'a': mode = feetL;break;

		case 'm': mode = uLegR;break;
		case 'b': mode = lLegR;break;
		case 'l':mode = feetR;break;

		case 'q': mode = uArmL;break; 
		case 'w': mode = lArmL;break; 
		case 'e':mode = handL;break;

		case 'p': mode = uArmR;break;
		case 'o': mode = lArmR;break; 
		case 'i':mode = handR;break;
		case '|':mode = human;break;
		case '[':mode = box;break;
		case 'I':mode = initial;break;
		default:
			 switch(mode)
			 {

				 case scene:	
					 switch(key)
					 {
						 case '1':	      scene_r_x++;	      break;
						 case '3':	      scene_r_y++;	      break;
						 case '5':	      scene_r_z++;	      break;
						 case '2':	      scene_r_x--;	      break;
						 case '4':	      scene_r_y--;	      break;
						 case '6':	      scene_r_z--;	      break;
						 case '7':	      scene_z++;	      break;
						 case '8':	      scene_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case human:	
					 switch(key)
					 {
						 case '1':	      human_r_x++;	      break;
						 case '3':	      human_r_y++;	      break;
						 case '5':	      human_r_z++;	      break;
						 case '2':	      human_r_x--;	      break;
						 case '4':	      human_r_y--;	      break;
						 case '6':	      human_r_z--;	      break;
						 case '0': human_r_x=0;human_r_y=0;human_r_z=0;break;
					 }
					 break;
				 case head:	
					 switch(key)
					 {
						 case '1':	      if(head_r_x < 40)head_r_x++;	      break;
						 case '3':	      if(head_r_y < 40)head_r_y++;	      break;
						 case '5':	      if(head_r_z < 40)head_r_z++;	      break;
						 case '2':	      if(head_r_x > -40)head_r_x--;	      break;
						 case '4':	      if(head_r_y > -40)head_r_y--;	      break;
						 case '6':	      if(head_r_z > -40)head_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case neck:	
					 switch(key)
					 {
						 case '1':	      if(neck_r_x < 50)neck_r_x++;	      break;
						 case '3':	      if(neck_r_y < 0)neck_r_y++;	      break;
						 case '5':	      if(neck_r_z < 50)neck_r_z++;	      break;
						 case '2':	      if(neck_r_x > -50)neck_r_x--;	      break;
						 case '4':	      if(neck_r_y > 0)neck_r_y--;	      break;
						 case '6':	      if(neck_r_z > -50)neck_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case torso:	
					 switch(key)
					 {
						 case '1':	      if(torso_r_x<90) torso_r_x++;	      break;
						 case '3':	       if(torso_r_y<50) torso_r_y++;	      break;
						 case '5':	       if(torso_r_z<50) torso_r_z++;	      break;
						 case '2':	      if(torso_r_x>-50)  torso_r_x--;	      break;
						 case '4':	       if(torso_r_y>-50) torso_r_y--;	      break;
						 case '6':	      if(torso_r_z>-50)  torso_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case uLegR:	
					 switch(key)
					 {
						 case '1':	      if(uLegR_r_x < 20)uLegR_r_x++;	      break;
						 case '3':	      if(uLegR_r_y < 90)uLegR_r_y++;	      break;
						 case '5':	      if(uLegR_r_z < 0)uLegR_r_z++;	      break;
						 case '2':	      if(uLegR_r_x > -130)uLegR_r_x--;	      break;
						 case '4':	      if(uLegR_r_y > -90)uLegR_r_y--;	      break;
						 case '6':	      if(uLegR_r_z > -90)uLegR_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case lLegR:	
					 switch(key)
					 {
						 case '1':	      if(lLegR_r_x < 150) lLegR_r_x++;     break;
						 case '2':	      if(lLegR_r_x > 0)	  lLegR_r_x--;     break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
							   /*case '5':	      lLegR_r_z++;	      break;
							     case '3':	      lLegR_r_y++;	      break;
							     case '4':	      lLegR_r_y--;	      break;
							     case '6':	      lLegR_r_z--;	      break;*/
					 }
					 break;
				 case uLegL:	
					 switch(key)
					 {
						 case '1':	      if(uLegL_r_x < 20)uLegL_r_x++;	      break;
						 case '3':	      if(uLegL_r_y < 90)uLegL_r_y++;	      break;
						 case '5':	      if(uLegL_r_z < 0)uLegL_r_z++;	      break;
						 case '2':	      if(uLegL_r_x > -130)uLegL_r_x--;	      break;
						 case '4':	      if(uLegL_r_y > -90)uLegL_r_y--;	      break;
						 case '6':	      if(uLegL_r_z > -90)uLegL_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case lLegL:	
					 switch(key)
					 {
						 case '1':	      if(lLegL_r_x < 150) lLegL_r_x++;     break;
						 case '2':	      if(lLegL_r_x > 0)	  lLegL_r_x--;     break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
							   /* case '5':	      lLegL_r_z++;	      break;
							      case '2':	      lLegL_r_x--;	      break;
							      case '4':	      lLegL_r_y--;	      break;
							      case '6':	      lLegL_r_z--;	      break;*/
					 }
					 break;
				 case uArmR:	
					 switch(key)
					 {
						 case '1':	      if(uArmR_r_x < 90)uArmR_r_x++;	      break;
						 case '3':	      if(uArmR_r_y < 90)uArmR_r_y++;	      break;
						 case '5':	      if(uArmR_r_z < 90 )uArmR_r_z++;	      break;
						 case '2':	      if(uArmR_r_x > -180)uArmR_r_x--;	      break;
						 case '4':	      if(uArmR_r_y > -90)uArmR_r_y--;	      break;
						 case '6':	      if(uArmR_r_z > -90)uArmR_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case lArmR:	
					 switch(key)
					 {
						 case '1':	      if(lArmR_r_x < 0)lArmR_r_x++;	      break;
									      //case '3':	      lArmR_r_y++;	      break;
									      //case '5':	      lArmR_r_z++;	      break;
						 case '2':	      if(lArmR_r_x > -170)lArmR_r_x--;	      break;
									      //case '4':	      lArmR_r_y--;	      break;
									      //case '6':	      lArmR_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case uArmL:	
					 switch(key)
					 {
						 case '1':	      if(uArmL_r_x < 90)uArmL_r_x++;	      break;
						 case '3':	      if(uArmL_r_y < 90)uArmL_r_y++;	      break;
						 case '5':	      if(uArmL_r_z < 90 )uArmL_r_z++;	      break;
						 case '2':	      if(uArmL_r_x > -180)uArmL_r_x--;	      break;
						 case '4':	      if(uArmL_r_y > -90)uArmL_r_y--;	      break;
						 case '6':	      if(uArmL_r_z > -90)uArmL_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case lArmL:	
					 switch(key)
					 {
						 case '1':	      if(lArmL_r_x < 0)lArmL_r_x++;	      break;
									      //case '3':	      lArmL_r_y++;	      break;
									      //case '5':	      lArmL_r_z++;	      break;
						 case '2':	      if(lArmL_r_x > -170)lArmL_r_x--;	      break;
									      //case '4':	      lArmL_r_y--;	      break;
									      //case '6':	      lArmL_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;

				 case feetR:	
					 switch(key)
					 {
						 case '1':	      if(feetR_r_x < 70)feetR_r_x++;	      break;
						 case '3':	      if(feetR_r_y < 45)feetR_r_y++;	      break;
						 case '5':	      feetR_r_z++;	      break;
						 case '2':	      if(feetR_r_x > -45)feetR_r_x--;	      break;
						 case '4':	      if(feetR_r_y > -45)feetR_r_y--;	      break;
						 case '6':	      feetR_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case feetL:	
					 switch(key)
					 {
						 case '1':	      if(feetL_r_x < 70)feetL_r_x++;	      break;
						 case '3':	      if(feetL_r_y < 45)feetL_r_y++;	      break;
						 case '5':	      feetL_r_z++;	      break;
						 case '2':	      if(feetL_r_x > -45)feetL_r_x--;	      break;
						 case '4':	      if(feetL_r_y > -45)feetL_r_y--;	      break;
						 case '6':	      feetL_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;

				 case handR:	
					 switch(key)
					 {
						 case '1':	      if(handR_r_x < 45)handR_r_x++;	      break;
						 case '3':	      if(handR_r_y < 90)handR_r_y++;	      break;
						 case '5':	      if(handR_r_z < 90)handR_r_z++;	      break;
						 case '2':	      if(handR_r_x > -90)handR_r_x--;	      break;
						 case '4':	      if(handR_r_y > -90)handR_r_y--;	      break;
						 case '6':	      if(handR_r_z > -90)handR_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case handL:	
					 switch(key)
					 {
						 case '1':	      if(handL_r_x < 45)handL_r_x++;	      break;
						 case '3':	      if(handL_r_y < 90)handL_r_y++;	      break;
						 case '5':	      if(handL_r_z < 90)handL_r_z++;	      break;
						 case '2':	      if(handL_r_x > -90)handL_r_x--;	      break;
						 case '4':	      if(handL_r_y > -90)handL_r_y--;	      break;
						 case '6':	      if(handL_r_z > -90)handL_r_z--;	      break;
						 case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
					 }
					 break;
				 case box:
					 switch(key)
					 {
						 case '1':	      box_r_x++;	      break;
						 case '3':	      box_r_y++;	      break;
						 case '5':	      box_r_z++;	      break;
						 case '2':	      box_r_x--;	      break;
						 case '4':	      box_r_y--;	      break;
						 case '6':	      box_r_z--;	      break;

						 case '7':
								      if(a<90)a=a++;
								      break;case '8':
									      if(a>=-90)a=a--;
								      break;
						 case '0':
								      a=0;
								      break;			 }
					 break;
				 case initial:
					 scene_x=0; scene_y=0, scene_z=5.0f;
					 scene_r_x=0;scene_r_y=0,scene_r_z=0;
					 human_r_x=0;human_r_y=0,human_r_z=0;
					 head_r_x=0;head_r_y=0,head_r_z=0;
					 box_r_x=0;box_r_y=0,box_r_z=0;
					 neck_r_x=0;neck_r_y=0,neck_r_z=0;
					 uArmL_r_x=0;uArmL_r_y=0,uArmL_r_z=-80;
					 uArmR_r_x=0;uArmR_r_y=0,uArmR_r_z=-80;
					 lArmR_r_x=0;lArmR_r_y=0,lArmR_r_z=0;
					 lArmL_r_x=0;lArmL_r_y=0,lArmL_r_z=0;

					 uLegL_r_x=0;uLegL_r_y=0,uLegL_r_z=0;
					 uLegR_r_x=0;uLegR_r_y=0,uLegR_r_z=0;
					 lLegR_r_x=0;lLegR_r_y=0,lLegR_r_z=0;
					 lLegL_r_x=0;lLegL_r_y=0,lLegL_r_z=0;

					 torso_r_x=0;torso_r_y=0,torso_r_z=0;
					 feetR_r_x = 0;feetR_r_y = 0,feetR_r_z = 0;
					 feetL_r_x = 0;feetL_r_y = 0,feetL_r_z = 0;

					 handR_r_x = 0;handR_r_y = 0,handR_r_z = 0;

					 break;
			 }
	}
	//cout<<mode<<"hello";
	glutPostRedisplay();
}
void init()
{
	head_id=glGenLists(1);
	neck_id=glGenLists(1);
	torso_id=glGenLists(1);
	left_upper_arm_id=glGenLists(1);
	left_lower_arm_id=glGenLists(1);
	left_hand_id=glGenLists(1);
	right_upper_arm_id=glGenLists(1);
	right_lower_arm_id=glGenLists(1);
	right_hand_id=glGenLists(1);
	hip_id=glGenLists(1);
	left_upper_leg_id=glGenLists(1);
	left_lower_leg_id=glGenLists(1);
	left_feet_id=glGenLists(1);
	right_upper_leg_id=glGenLists(1);
	right_lower_leg_id=glGenLists(1);
	right_feet_id=glGenLists(1);
	box_id=glGenLists(1);
	struct_box();
	struct_hip();
	struct_head();
	struct_neck();
	struct_torso();
	struct_left_upper_leg();
	struct_left_lower_leg();
	struct_left_feet();
	struct_right_upper_leg();
	struct_right_lower_leg();
	struct_right_feet();
	struct_left_upper_arm();
	struct_right_upper_arm();
	struct_left_lower_arm();
	struct_right_lower_arm();
	struct_left_hand();
	struct_right_hand();

}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH); 
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,640);
	glutCreateWindow("Animated Cube");

	sceneRender();
	init();
	glClearColor(0.0,0.0,0.0,0.0);
	//glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
