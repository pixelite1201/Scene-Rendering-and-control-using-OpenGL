void struct_cupboard()
{
	glNewList(cupboard_id,GL_COMPILE); 
	//glTranslatef(-25,-15,-15.0);	
	//glScalef(50,30,30);	
	
	glBegin(GL_QUADS);
		
	glTexCoord2f( 0, 0 );glVertex3f(0.0,0.0,0.0); //back 
	glTexCoord2f( 0, 1 );glVertex3f(0.0,1.0,0.0);
	glTexCoord2f( 1, 1 );glVertex3f(1.0,1.0,0.0);
	glTexCoord2f( 1, 0 );glVertex3f(1.0,0.0,0.0);

	glTexCoord2f( 0, 0 );glVertex3f(0.0,0.0,0.0); //left 
	glTexCoord2f( 0, 1 );glVertex3f(0.0,0.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(0.0,1.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(0.0,1.0,0.0);
	glEnd();
	glPushMatrix();	
	glTranslatef(0.0,0.0,1.0);	
	glRotatef(-30,0,1,0);
	glTranslatef(0.0,0.0,-1.0);
	glBegin(GL_QUADS);
	glTexCoord2f( 0, 0 );glVertex3f(0.0,0.0,1.0);//front wall - left
	glTexCoord2f( 0, 1 );glVertex3f(0.0,1.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(0.5,1.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(0.5,0.0,1.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();	
	glTranslatef(1.0,0.0,1.0);	
	glRotatef(30,0,1,0);
	glTranslatef(-1.0,0.0,-1.0);
	glBegin(GL_QUADS);
	glTexCoord2f( 0, 0 );glVertex3f(0.5,0.0,1.0);//front wall - right
	glTexCoord2f( 0, 1 );glVertex3f(0.5,1.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(1.0,1.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(1.0,0.0,1.0);
	glEnd();
	glPopMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f( 0, 0 );glVertex3f(1.0,0.0,0.0);//right wall
	glTexCoord2f( 0, 1 );glVertex3f(1.0,0.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(1.0,1.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(1.0,1.0,0.0);
	glEnd();
	

glBegin(GL_QUADS);
	glTexCoord2f( 0, 0 );glVertex3f(0.0,1.0,0.0);//roof
	glTexCoord2f( 0, 1 );glVertex3f(0.0,1.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(1.0,1.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(1.0,1.0,0.0);
glEnd();	


	glBegin(GL_QUADS);
	glTexCoord2f( 0, 0 );glVertex3f(0.0,0.0,0.0);//floor
	glTexCoord2f( 0, 1 );glVertex3f(0.0,0.0,1.0);
	glTexCoord2f( 1, 1 );glVertex3f(1.0,0.0,1.0);
	glTexCoord2f( 1, 0 );glVertex3f(1.0,0.0,0.0);

	glEnd();
	
	glEndList();
}
