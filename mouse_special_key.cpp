void mouse(int btn, int state, int x, int y)
{

	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		flag=1;
		ctrlpoints[cp1][0]=(x-width/2)/height;
		ctrlpoints[cp1][1]=(height/2-y)/height;
		ctrlpoints[cp1][2]=currentZ;
		cp1++;
	}
	if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	cp1--;
	}
	glutPostRedisplay();
}

void orientMe(float ang) 
{
	lx = sin(ang);
	lz = -cos(ang);  
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i) 
{
	x = x + i*(lx)*0.2;

	z = z + i*(lz)*0.2;
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f,1.0f,0.0f);
}
void inputKey(int key, int x, int y) 
{
	switch (key) {
		case GLUT_KEY_LEFT : mode1=3;angle -= 0.01f;orientMe(angle);break;
		case GLUT_KEY_RIGHT :mode1=3; angle +=0.01f;orientMe(angle);break;
		case GLUT_KEY_UP : mode1=3;moveMeFlat(1);currentZ-=0.2;if(flag==0)initial1+=0.2;break;
		case GLUT_KEY_DOWN :mode1=3; moveMeFlat(-1);currentZ+=0.2;break;
	}
}

