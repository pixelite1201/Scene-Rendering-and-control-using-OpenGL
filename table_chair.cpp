void struct_table()
{


	glNewList(table_id,GL_COMPILE); 
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	glPushMatrix();//top of table
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(2,0.05,1);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix(); //top of table ends

	glPushMatrix(); //leg
	glTranslatef(1.95f,-1.0f,0.95f);	
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(0.05,1,0.05);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix();//leg ends
	
	glPushMatrix(); //leg
	glTranslatef(1.95f,-1.0f,-0.95f);	
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(0.05,1,0.05);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix();//leg ends

	glPushMatrix(); //leg
	glTranslatef(-1.95f,-1.0f,-0.95f);	
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(0.05,1,0.05);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix();//leg ends


	glPushMatrix(); //leg
	glTranslatef(-1.95f,-1.0f,0.95f);	
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(0.05,1,0.05);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix();//leg ends
	

glEndList();

}



void struct_chair()
{


	glNewList(chair_id,GL_COMPILE); 
	quadratic = gluNewQuadric();
	gluQuadricTexture( quadratic, GL_TRUE);
	
	glPushMatrix();//top of chair
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(1,0.05,1);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix(); //top of chair ends

	glPushMatrix(); //leg
	glTranslatef(0.95f,-1.0f,0.95f);	
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(0.05,1,0.05);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix();//leg ends
	
	glPushMatrix(); //leg
	glTranslatef(0.95f,-1.0f,-0.95f);	
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(0.05,1,0.05);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix();//leg ends

	glPushMatrix(); //leg
	glTranslatef(-0.95f,-1.0f,-0.95f);	
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(0.05,1,0.05);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix();//leg ends


	glPushMatrix(); //leg
	glTranslatef(-0.95f,-1.0f,0.95f);	
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(0.05,1,0.05);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix();//leg ends
	
	glPushMatrix(); //back of chair
	glTranslatef(0.0f,1.5f,-0.95f);	
	glTranslatef(-1,1,0);
	glRotatef(a,0,0,1);
	glTranslatef(1,-1,0);
	glScalef(1,1.5,0.05);	
	glCallList(box2_id);
	//glDisable( GL_TEXTURE_2D );
	glPopMatrix();//leg ends
	

glEndList();

}

