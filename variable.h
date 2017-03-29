bool recording=true;
unsigned int framenum=0;
unsigned char *pRGB;

int SCREEN_WIDTH=1200;
int SCREEN_HEIGHT=800;


float ratio;
int lamp=1;
int wall=0;
int count=-1;
enum modes{head,neck,uLegR,uArmR,uArmL, uLegL,lLegR,lArmR,lArmL, lLegL,feetR, feetL,handR,handL,torso ,scene,initial,box,human}mode;


///////////////////////////////////////
GLfloat light_position[]={0.0, 30.0, -30.0, 1.0};//wall light
GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
GLfloat light_specular[]={0.7 ,0.7, 0.7, 0.0};
GLfloat light_attenuation[]={0.1 ,0.1, 0.1};

GLfloat light_position2[]={-10.0, 0.0, -5, 1.0}; //lamp
GLfloat light_diffuse2[]={1.0, 0.9, 0.5, 1.0};
GLfloat light_specular2[]={0.7 ,0.7, 0.7, 0.0};
GLfloat light_attenuation2[]={0.1 ,0.1, 0.1};

GLfloat light_position3[]={0.0, 0.0, 0.0, 1.0};//box light
GLfloat light_diffuse3[]={1.0, 1.0, 1.0, 1.0};
GLfloat light_specular3[]={0.7 ,0.7, 0.7, 0.0};
GLfloat light_attenuation3[]={0.1 ,0.1, 0.1};

GLint head_id=0,neck_id=0,torso_id=0,left_upper_leg_id=0,right_upper_leg_id=0,left_lower_leg_id=0,right_lower_leg_id=0,
      left_feet_id=0,right_feet_id=0,left_upper_arm_id=0,right_upper_arm_id=0,left_lower_arm_id=0,right_lower_arm_id=0,
      left_hand_id=0,right_hand_id=0,hip_id=0,box_id=0;
GLint box2_id=0 ,table_id = 0 , chair_id = 0, room_id = 0,cupboard_id = 0, lamp_id;
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
GLfloat a=-1;
GLfloat scene_x=0, scene_y=0, scene_z=-4.0f;
GLfloat scene_r_x=0,scene_r_y=0,scene_r_z=0;

GLfloat human_r_x=-1,human_r_y=-27,human_r_z=0;
GLfloat head_r_x=18,head_r_y=0,head_r_z=0;
GLfloat box_r_x=0,box_r_y=-30,box_r_z=0;
GLfloat neck_r_x=0,neck_r_y=0,neck_r_z=0;

//GLfloat uArmL_r_x=-41,uArmL_r_y=-66,uArmL_r_z=80;
//GLfloat uArmR_r_x=-41,uArmR_r_y=66,uArmR_r_z=-80;
//GLfloat lArmR_r_x=0,lArmR_r_y=0,lArmR_r_z=-85;
//GLfloat lArmL_r_x=0,lArmL_r_y=0,lArmL_r_z=85;

GLfloat uArmL_r_x=0,uArmL_r_y=0,uArmL_r_z=0;
GLfloat uArmR_r_x=0,uArmR_r_y=0,uArmR_r_z=0;
GLfloat lArmR_r_x=0,lArmR_r_y=0,lArmR_r_z=0;
GLfloat lArmL_r_x=0,lArmL_r_y=0,lArmL_r_z=0;

GLfloat uLegL_r_x=0,uLegL_r_y=0,uLegL_r_z=0;
GLfloat uLegR_r_x=0,uLegR_r_y=0,uLegR_r_z=0;
GLfloat lLegR_r_x=0,lLegR_r_y=0,lLegR_r_z=0;
GLfloat lLegL_r_x=0,lLegL_r_y=0,lLegL_r_z=0;

GLfloat torso_r_x=13,torso_r_y=0,torso_r_z=0;
GLfloat feetR_r_x = 0,feetR_r_y = 0,feetR_r_z = 0;
GLfloat feetL_r_x = 0,feetL_r_y = 0,feetL_r_z = 0;

GLfloat handR_r_x = 0,handR_r_y = 0,handR_r_z = 0;
GLfloat handL_r_x = 0,handL_r_y = 0,handL_r_z = 0;

GLfloat a1=0;
GLfloat scene_x1=0, scene_y1=0, scene_z1=-10.0f;
GLfloat scene_r_x1=0,scene_r_y1=0,scene_r_z1=0;
GLfloat human_r_x1=0,human_r_y1=0,human_r_z1=0;
GLfloat head_r_x1=0,head_r_y1=0,head_r_z1=0;
GLfloat box_r_x1=0,box_r_y1=0,box_r_z1=0;
GLfloat neck_r_x1=0,neck_r_y1=0,neck_r_z1=0;
GLfloat uArmL_r_x1=0,uArmL_r_y1=0,uArmL_r_z1=80;
GLfloat uArmR_r_x1=0,uArmR_r_y1=0,uArmR_r_z1=-80;
GLfloat lArmR_r_x1=0,lArmR_r_y1=0,lArmR_r_z1=0;
GLfloat lArmL_r_x1=0,lArmL_r_y1=0,lArmL_r_z1=0;

GLfloat uLegL_r_x1=0,uLegL_r_y1=0,uLegL_r_z1=0;
GLfloat uLegR_r_x1=0,uLegR_r_y1=0,uLegR_r_z1=0;
GLfloat lLegR_r_x1=0,lLegR_r_y1=0,lLegR_r_z1=0;
GLfloat lLegL_r_x1=0,lLegL_r_y1=0,lLegL_r_z1=0;

GLfloat torso_r_x1=0,torso_r_y1=0,torso_r_z1=0;
GLfloat feetR_r_x1 = 0,feetR_r_y1 = 0,feetR_r_z1 = 0;
GLfloat feetL_r_x1 = 0,feetL_r_y1 = 0,feetL_r_z1 = 0;

GLfloat handR_r_x1 = 0,handR_r_y1 = 0,handR_r_z1 = 0;
GLfloat handL_r_x1 = 0,handL_r_y1 = 0,handL_r_z1 = 0;

GLfloat da=0;
GLfloat dscene_x=0, dscene_y=0, dscene_z=0;
GLfloat dscene_r_x=0,dscene_r_y=0,dscene_r_z=0;
GLfloat dhuman_r_x=0,dhuman_r_y=0,dhuman_r_z=0;
GLfloat dhead_r_x=0,dhead_r_y=0,dhead_r_z=0;
GLfloat dbox_r_x=0,dbox_r_y=0,dbox_r_z=0;
GLfloat dneck_r_x=0,dneck_r_y=0,dneck_r_z=0;
GLfloat duArmL_r_x=0,duArmL_r_y=0,duArmL_r_z=0;
GLfloat duArmR_r_x=0,duArmR_r_y=0,duArmR_r_z=0;
GLfloat dlArmR_r_x=0,dlArmR_r_y=0,dlArmR_r_z=0;
GLfloat dlArmL_r_x=0,dlArmL_r_y=0,dlArmL_r_z=0;

GLfloat duLegL_r_x=0,duLegL_r_y=0,duLegL_r_z=0;
GLfloat duLegR_r_x=0,duLegR_r_y=0,duLegR_r_z=0;
GLfloat dlLegR_r_x=0,dlLegR_r_y=0,dlLegR_r_z=0;
GLfloat dlLegL_r_x=0,dlLegL_r_y=0,dlLegL_r_z=0;

GLfloat dtorso_r_x=0,dtorso_r_y=0,dtorso_r_z=0;
GLfloat dfeetR_r_x = 0,dfeetR_r_y = 0,dfeetR_r_z = 0;
GLfloat dfeetL_r_x = 0,dfeetL_r_y = 0,dfeetL_r_z = 0;

GLfloat dhandR_r_x = 0,dhandR_r_y = 0,dhandR_r_z = 0;
GLfloat dhandL_r_x = 0,dhandL_r_y = 0,dhandL_r_z = 0;

GLuint _textureId1;
GLuint _textureId;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;
GLuint _textureId7;
GLuint _textureId8;
GLuint _textureId9;
GLuint _textureId10;
GLuint _textureId11;
GLuint _textureId12;
GLuint _textureId13;
GLuint _textureId14;
GLuint _textureId15;
GLuint _textureId16;
GLuint _textureId17;

GLUquadricObj *quadratic;
