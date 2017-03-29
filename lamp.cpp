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

