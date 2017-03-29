void struct_room()
{
	glNewList(room_id,GL_COMPILE); 
	glTranslatef(-25,-15,-15.0);	
	glScalef(70,50,50);	
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, _textureId7);
	glColor3f(0.0,0.8,1.0);	
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
	glColor3f(1,1,1);	
//glDisable(GL_TEXTURE_2D);
glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId15);
	
	glPushMatrix();	
	glTranslatef( 0.4,0.0 , 1.0);	
	glRotatef(-70,0,1,0);	
	glTranslatef( -0.4,0.0 , -1.0);
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

glPopMatrix();

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
