void struct_lamp()
{

	glNewList(lamp_id,GL_COMPILE); 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId12);
		glPushMatrix(); //top
			glRotatef(-90,1,0,0);
			GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();
			gluCylinder(quadratic,2.5f,0.8f,3.0f,50,50);
		glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId13);
		glPushMatrix(); //middle
			glRotatef(90,1,0,0);
			//GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();
			gluCylinder(quadratic,0.1f,0.1f,3.0f,50,50);
		glPopMatrix();
		glPushMatrix(); //base disks
			glTranslatef(0,-3,0);
			glRotatef(90,1,0,0);
			//GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();
 	  	gluDisk(quadratic, 0.1, 2.5, 50, 50);
		glTranslatef(0,0.0,0.2);
		gluDisk(quadratic, 0.1, 2.5, 50, 50);
		glPopMatrix();
		glPushMatrix(); //base
			glTranslatef(0,-3,0);
			glRotatef(90,1,0,0);
			//GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();
 	  	gluCylinder(quadratic,2.5f,2.5f,0.2f,50,50);
		glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEndList();


}

void struct_room()
{
	glNewList(room_id,GL_COMPILE); 
	glTranslatef(-25,-15,-15.0);	
	glScalef(70,50,50);	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId7);
		
	glBegin(GL_QUADS);
		
	glTexCoord2f( 0, 0 );glVertex3f(0.0,0.0,0.0); //back wall
	glTexCoord2f( 0, 1 );glVertex3f(0.0,1.0,0.0);
	glTexCoord2f( 1, 1 );glVertex3f(1.0,1.0,0.0);
	glTexCoord2f( 1, 0 );glVertex3f(1.0,0.0,0.0);

	glTexCoord2f( 0, 0 );glVertex3f(0.0,0.0,0.0); //left wall
	glTexCoord2f( 0, 1 );glVertex3f(0.0,0.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(0.0,1.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(0.0,1.0,0.0);
	
	glTexCoord2f( 0, 0 );glVertex3f(0.0,0.0,1.0);//front wall - left
	glTexCoord2f( 0, 1 );glVertex3f(0.0,1.0,1.0);
	glTexCoord2f( 0.4, 1 );glVertex3f(0.4,1.0,1.0);
	glTexCoord2f( 0.4, 0 );glVertex3f(0.4,0.0,1.0);


	glTexCoord2f( 0.4, 0.6 );glVertex3f(0.4,0.6,1.0);//front wall - middle
	glTexCoord2f( 0.4, 1 );glVertex3f(0.4,1.0,1.0);
	glTexCoord2f( 0.6, 1 );glVertex3f(0.6,1.0,1.0);
	glTexCoord2f( 0.6, 0.6 );glVertex3f(0.6,0.6,1.0);


	glTexCoord2f( 0.6, 0 );glVertex3f(0.6,0.0,1.0);//front wall - right
	glTexCoord2f( 0.6, 1 );glVertex3f(0.6,1.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(1.0,1.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(1.0,0.0,1.0);


	glTexCoord2f( 0, 0 );glVertex3f(1.0,0.0,0.0);//right wall
	glTexCoord2f( 0, 1 );glVertex3f(1.0,0.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(1.0,1.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(1.0,1.0,0.0);
	glEnd();
	
glDisable(GL_TEXTURE_2D);
glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId15);
		
	glBegin(GL_QUADS);
		
	glTexCoord2f( 0, 0 );glVertex3f(0.4,0,1.0);//door
	glTexCoord2f( 0, 1 );glVertex3f(0.4,0.6,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(0.6,0.6,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(0.6,0,1.0);

	glEnd();
	
	


glDisable(GL_TEXTURE_2D);
glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId16);
		
	glPushMatrix();
	glTranslatef(0.58,0.3,1.0);
	GLUquadricObj *quadratic;	
	quadratic = gluNewQuadric();
	gluSphere( quadratic, 0.01, 100, 100);
	glPopMatrix();
glDisable(GL_TEXTURE_2D);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, _textureId8);

glBegin(GL_QUADS);
	glTexCoord2f( 0, 0 );glVertex3f(0.0,1.0,0.0);//roof
	glTexCoord2f( 0, 1 );glVertex3f(0.0,1.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(1.0,1.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(1.0,1.0,0.0);
glEnd();	

glDisable(GL_TEXTURE_2D);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, _textureId9);
	glBegin(GL_QUADS);
	glTexCoord2f( 0, 0 );glVertex3f(0.0,0.0,0.0);//floor
	glTexCoord2f( 0, 1 );glVertex3f(0.0,0.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(1.0,0.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(1.0,0.0,0.0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEndList();
}
