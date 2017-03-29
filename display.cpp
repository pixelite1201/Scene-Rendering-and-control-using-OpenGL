void capture_frame(unsigned int framenum)
{
  //global pointer float *pRGB
  pRGB = new unsigned char [3 * (SCREEN_WIDTH+1) * (SCREEN_HEIGHT + 1) ];


  // set the framebuffer to read
  //default for double buffered
  glReadBuffer(GL_BACK);

  glPixelStoref(GL_PACK_ALIGNMENT,1);//for word allignment
  
  glReadPixels(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pRGB);
  char filename[200];
  sprintf(filename,"frames/frame_%04d.ppm",framenum);
  std::ofstream out(filename, std::ios::out);
  out<<"P6"<<std::endl;
  out<<SCREEN_WIDTH<<" "<<SCREEN_HEIGHT<<" 255"<<std::endl;
  out.write(reinterpret_cast<char const *>(pRGB), (3 * (SCREEN_WIDTH+1) * (SCREEN_HEIGHT + 1)) * sizeof(int));
  out.close();

  //function to store pRGB in a file named count
  delete pRGB;
}



void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glEnable(GL_LIGHTING);
	if(wall==1){glEnable(GL_LIGHT0);glEnable(GL_LIGHT2);}else {glDisable(GL_LIGHT0);glDisable(GL_LIGHT2);}
	if(lamp==1)glEnable(GL_LIGHT1);else glDisable(GL_LIGHT1);
	glEnable(GL_LIGHT3);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
	//gluLookAt(scene_x,scene_y,scene_z,0,0,-1,0,1,0);
	
	if(mode1==3)
{
		gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f,1.0f,0.0f);
	glColor3f(0,1,0);
	glPointSize(4);
	glBegin(GL_LINE_STRIP);                                                                            
	for(int i=0;i<cp1;i++)
	glVertex3f(ctrlpoints[i][0],ctrlpoints[i][1],ctrlpoints[i][2]);
	glEnd();
}
	else
		gluLookAt(ax[imn], ay[imn], az[imn], ax[imn] + lx1,ay[imn] + ly1,az[imn] + lz1, 0.0f,1.0f,0.0f); 
	
	
	
	if(mode1==1)
		curve();
	if(mode1==2)
		moveMe();
	
	glColor3f(1,1,1);
	//scene
	glPushMatrix();
	glTranslatef(-1,0,scene_z);
	glScalef(0.1,0.1,0.1);
	glRotatef(scene_r_x,1.0,0.0,0.0); 
	glRotatef(scene_r_y,0.0,1.0,0.0);
	glRotatef(scene_r_z,0.0,0.0,1.0);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);	 //light moves with the scene
glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
	glPushMatrix(); 	//room geometry	
	glCallList(room_id);
	glPopMatrix();	

	//table
	glPushMatrix();		//20*10 table top ; height 10 origin of table at centre of table top
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId10);
	glTranslatef(5,-5,-3.0);	
	//glTranslatef(-15,-5,0);	
	glScalef(5,5,5);
	glCallList(table_id);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//stool
	glPushMatrix();		//20*10 table top ; height 10 origin of table at centre of table top
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId10);
	glTranslatef(-15,-9,0.0);	
	//glTranslatef(-15,-5,0);	
	glScalef(1,3,3);
	glCallList(table_id);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//chair
	glPushMatrix();	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId11);
	glTranslatef(5,-8,-11);	
	glScalef(3.5,3.5,3.5);
	glCallList(chair_id);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
		//baby chair
	glPushMatrix();	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId11);
	glTranslatef(-20,-11,0);	
	glRotatef(90,0,1,0);
	glScalef(2,2,2);
	glCallList(chair_id);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//cupboard
	glPushMatrix();	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId14);
		
	glTranslatef(44,-14.8,-10);	
	glScalef(10,23,10);
	glRotatef(-90,0,1,0);	
	glCallList(cupboard_id);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//lamp
	glPushMatrix();	
	
	glTranslatef(-2,-1.5,-5.0);
	glCallList(lamp_id);
	
	glPopMatrix();
	
//box+human
	glPushMatrix();
	glTranslatef(9,-3,5);
	glRotatef(-90,0,1,0);	
	glScalef(2,2,2);
	glLightfv(GL_LIGHT3, GL_POSITION, light_position3);

	/*//drawing a sphere at light position to check where light is
	glPushMatrix();		
	//glTranslatef(9,-3,5);
	GLUquadricObj *quadratic;	
	quadratic = gluNewQuadric();
	gluSphere( quadratic, 0.2, 100, 100);
	glPopMatrix();
*/
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId17);
	//glColor3f(1.0,0.0,0.0);	
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
	//glColor3f(1.0,1.0,1.0);
	glDisable( GL_TEXTURE_2D );
	
	//glPopMatrix();
	/////////////////////////////////////////////////human
	glPushMatrix();
	glTranslatef(0,0.05+(a-5)/45,0);
	glRotatef(90,0,1,0);
	glScalef((a*0.0008+0.08),(a*0.0008+0.08),(a*0.0008+0.08));
	//glScalef(0.08,0.08,0.08);
	//glScalef(0.08,0.08,0.08);
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
	//glRotatef(-90.0,0.0,0.0,1.0);
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
	//glRotatef(90.0,0.0,0.0,1.0);
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
	glPopMatrix();//box+human
	glPopMatrix(); //scene

	if (recording && (mode1==6 || mode1==2))
  		capture_frame(framenum++);


	glutSwapBuffers();
}

