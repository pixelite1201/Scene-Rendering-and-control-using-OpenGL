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


