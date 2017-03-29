float width,height;
float count2=0;
float initial1=0;
int flag=0;
static float angle=0.0;
static float lx1=0.0f,ly1=0.0f,lz1=-1.0f,currentZ=0;
static float x=0.0f,y=0.0f,z=1.2f;
static float lx=0.0f,ly=0.0f,lz=-1.0f;
GLfloat ctrlpoints[1024][3];
float tim=0;
int imn=0;
int cp1=0;//keep index of ctrlpoints
int mode1=0;
int i1=0;
GLfloat ax[1024]={0},ay[1024]={0},az[1024]={1.2};
float Znear=0.5;
float Zfar = 200.0;
void moveMe();
void curve();
