void save()
{
  ofstream savef;
  savef.open("key.txt",ios::app);
  if(!savef)
    {
      cerr<<"Error opening file";
      exit(1);
    }
  savef<<a<<" "<<human_r_x<<" "<<human_r_y<<" "<<human_r_z<<" "<<head_r_x<<" "<<head_r_y<<" "<<head_r_z<<" ";
  savef<<neck_r_x<<" "<<neck_r_y<<" "<<neck_r_z<<" "<<uArmL_r_x<<" "<<uArmL_r_y<<" "<<uArmL_r_z<<" ";
  savef<<uArmR_r_x<<" "<<uArmR_r_y<<" "<<uArmR_r_z<<" "<<lArmR_r_x<<" "<<lArmR_r_y<<" "<<lArmR_r_z<<" ";
  savef<<lArmL_r_x<<" "<<lArmL_r_y<<" "<<lArmL_r_z<<" "<<uLegL_r_x<<" "<<uLegL_r_y<<" "<<uLegL_r_z<<" ";
  savef<<uLegR_r_x<<" "<<uLegR_r_y<<" "<<uLegR_r_z<<" "<<lLegR_r_x<<" "<<lLegR_r_y<<" "<<lLegR_r_z<<" ";
  savef<<lLegL_r_x<<" "<<lLegL_r_y<<" "<<lLegL_r_z<<" "<<torso_r_x<<" "<<torso_r_y<<" "<<torso_r_z<<" ";
  savef<<handR_r_x<<" "<<handR_r_y<<" "<<handR_r_z<<" "<<handL_r_x<<" "<<handL_r_y<<" "<<handL_r_z<<" "<<endl;
  savef.close();
}

fstream savef;
void read()
{
  savef.open("key.txt",ios::in);
  if(!savef)
    {
      cerr<<"Error opening file";
      exit(1);
    }
}
int read_next()
{
  if(!savef.eof())
{
  savef>>a1>>human_r_x1>>human_r_y1>>human_r_z1>>head_r_x1>>head_r_y1>>head_r_z1;
  savef>>neck_r_x1>>neck_r_y1>>neck_r_z1>>uArmL_r_x1>>uArmL_r_y1>>uArmL_r_z1;
  savef>>uArmR_r_x1>>uArmR_r_y1>>uArmR_r_z1>>lArmR_r_x1>>lArmR_r_y1>>lArmR_r_z1;
  savef>>lArmL_r_x1>>lArmL_r_y1>>lArmL_r_z1>>uLegL_r_x1>>uLegL_r_y1>>uLegL_r_z1;
  savef>>uLegR_r_x1>>uLegR_r_y1>>uLegR_r_z1>>lLegR_r_x1>>lLegR_r_y1>>lLegR_r_z1;
  savef>>lLegL_r_x1>>lLegL_r_y1>>lLegL_r_z1>>torso_r_x1>>torso_r_y1>>torso_r_z1;
  savef>>handR_r_x1>>handR_r_y1>>handR_r_z1>>handL_r_x1>>handL_r_y1>>handL_r_z1;
return 1;
}
else
{
savef.close();
return 0;
}
}

void calculate_delta()
{
  da=(a1-a)/24.0;
  dhuman_r_x=(human_r_x1-human_r_x)/24.0;
  dhuman_r_y=(human_r_y1-human_r_y)/24.0;
  dhuman_r_z=(human_r_z1-human_r_z)/24.0;
  dhead_r_x=(head_r_x1-head_r_x)/24.0;
  dhead_r_y=(head_r_y1-head_r_y)/24.0;
  dhead_r_z=(head_r_z1-head_r_z)/24.0;
  dneck_r_x=(neck_r_x1-neck_r_x)/24.0;
  dneck_r_y=(neck_r_y1-neck_r_y)/24.0;
  dneck_r_z=(neck_r_z1-neck_r_z)/24.0;
  duArmL_r_x=(uArmL_r_x1-uArmL_r_x)/24.0;
  duArmL_r_y=(uArmL_r_y1-uArmL_r_y)/24.0;
  duArmL_r_z=(uArmL_r_z1-uArmL_r_z)/24.0;
  duArmR_r_x=(uArmR_r_x1-uArmR_r_x)/24.0;
  duArmR_r_y=(uArmR_r_y1-uArmR_r_y)/24.0;
  duArmR_r_z=(uArmR_r_z1-uArmR_r_z)/24.0;
  dlArmR_r_x=(lArmR_r_x1-lArmR_r_x)/24.0;
  dlArmR_r_y=(lArmR_r_y1-lArmR_r_y)/24.0;
  dlArmR_r_z=(lArmR_r_z1-lArmR_r_z)/24.0;
  dlArmL_r_x=(lArmL_r_x1-lArmL_r_x)/24.0;
  dlArmL_r_y=(lArmL_r_y1-lArmL_r_y)/24.0;
  dlArmL_r_z=(lArmL_r_z1-lArmL_r_z)/24.0;
  duLegL_r_x=(uLegL_r_x1-uLegL_r_x)/24.0;
  duLegL_r_y=(uLegL_r_y1-uLegL_r_y)/24.0;
  duLegL_r_z=(uLegL_r_z1-uLegL_r_z)/24.0;
  duLegR_r_x=(uLegR_r_x1-uLegR_r_x)/24.0;
  duLegR_r_y=(uLegR_r_y1-uLegR_r_y)/24.0;
  duLegR_r_z=(uLegR_r_z1-uLegR_r_z)/24.0;
  dlLegR_r_x=(lLegR_r_x1-lLegR_r_x)/24.0;
  dlLegR_r_y=(lLegR_r_y1-lLegR_r_y)/24.0;
  dlLegR_r_z=(lLegR_r_z1-lLegR_r_z)/24.0;
  dlLegL_r_x=(lLegL_r_x1-lLegL_r_x)/24.0;
  dlLegL_r_y=(lLegL_r_y1-lLegL_r_y)/24.0;
  dlLegL_r_z=(lLegL_r_z1-lLegL_r_z)/24.0;
  dtorso_r_x=(torso_r_x1-torso_r_x)/24.0;
  dtorso_r_y=(torso_r_y1-torso_r_y)/24.0;
  dtorso_r_z=(torso_r_z1-torso_r_z)/24.0;
  dhandR_r_x=(handR_r_x1-handR_r_x)/24.0;
  dhandR_r_y=(handR_r_y1-handR_r_y)/24.0;
  dhandR_r_z=(handR_r_z1-handR_r_z)/24.0;
  dhandL_r_x=(handL_r_x1-handL_r_x)/24.0;
  dhandL_r_y=(handL_r_y1-handL_r_y)/24.0;
  dhandL_r_z=(handL_r_z1-handL_r_z)/24.0;
  mode1=6;
  count=20;
}
void update(int value) {
  if(mode1==5)
    {
      if(read_next())
      calculate_delta();
	else
	mode1=0;
    }
  if(count>0)
    {
      if(mode1==6)
	{
	
	  human_r_x=human_r_x+dhuman_r_x;
	  human_r_y=human_r_y+dhuman_r_y;
	  human_r_z=human_r_z+dhuman_r_z;
	  head_r_x=head_r_x+dhead_r_x;
	  head_r_y=head_r_y+dhead_r_y;
	  head_r_z=head_r_z+dhead_r_z;
	  neck_r_x=neck_r_x+dneck_r_x;
	  neck_r_y=neck_r_y+dneck_r_y;
	  neck_r_z=neck_r_z+dneck_r_z;
	  uArmL_r_x=uArmL_r_x+duArmL_r_x;
	  uArmL_r_y=uArmL_r_y+duArmL_r_y;
	  uArmL_r_z=uArmL_r_z+duArmL_r_z;
	  uArmR_r_x=uArmR_r_x+duArmR_r_x;
	  uArmR_r_y=uArmR_r_y+duArmR_r_y;
	  uArmR_r_z=uArmR_r_z+duArmR_r_z;
	  lArmR_r_x=lArmR_r_x+dlArmR_r_x;
	  lArmR_r_y=lArmR_r_y+dlArmR_r_y;
	  lArmR_r_z=lArmR_r_z+dlArmR_r_z;
	  lArmL_r_x=lArmL_r_x+dlArmL_r_x;
	  lArmL_r_y=lArmL_r_y+dlArmL_r_y;
	  lArmL_r_z=lArmL_r_z+dlArmL_r_z;
	  uLegL_r_x=uLegL_r_x+duLegL_r_x;
	  uLegL_r_y=uLegL_r_y+duLegL_r_y;
	  uLegL_r_z=uLegL_r_z+duLegL_r_z;
	  uLegR_r_x=uLegR_r_x+duLegR_r_x;
	  uLegR_r_y=uLegR_r_y+duLegR_r_y;
	  uLegR_r_z=uLegR_r_z+duLegR_r_z;
	  lLegR_r_x=lLegR_r_x+dlLegR_r_x;
	  lLegR_r_y=lLegR_r_y+dlLegR_r_y;
	  lLegR_r_z=lLegR_r_z+dlLegR_r_z;
	  lLegL_r_x=lLegL_r_x+dlLegL_r_x;
	  lLegL_r_y=lLegL_r_y+dlLegL_r_y;
	  lLegL_r_z=lLegL_r_z+dlLegL_r_z;
	  torso_r_x=torso_r_x+dtorso_r_x;
	  torso_r_y=torso_r_y+dtorso_r_y;
	  torso_r_z=torso_r_z+dtorso_r_z;
	  handR_r_x=handR_r_x+dhandR_r_x;
	  handR_r_y=handR_r_y+dhandR_r_y;
	  handR_r_z=handR_r_z+dhandR_r_z;
	  handL_r_x=handL_r_x+dhandL_r_x;
	  handL_r_y=handL_r_y+dhandL_r_y;
	  handL_r_z=handL_r_z+dhandL_r_z;
	  a=a+da;
	}
    }
  count--;
  if(count==0&&mode1==6)
    mode1=5;
  glutPostRedisplay(); 
	
  glutTimerFunc(100, update, 0);
	
}

void keyboard( unsigned char key, int x, int y )
{

  switch(key)
    {	case 'W':wall=(1-wall); break;
    case 'L':lamp=(1-lamp);break;
    case 'S':save();break;
    case 'R':read();break;
    case 'P':mode1=5;recording=true;break;
    case 27: 
      exit(0); 
    case 'f'://change the mode to initialize the curve function
      mode1=1;break;
		
    case 's':mode = scene;break;
    case 'h':mode = head; break;
    case 'n':mode = neck; break;
    case 't':mode = torso;break;

    case 'z': mode = uLegL;break;	
    case 'c': mode = lLegL;break;
    case 'a': mode = feetL;break;

    case 'm': mode = uLegR;break;
    case 'b': mode = lLegR;break;
    case 'l':mode = feetR;break;

    case 'q': mode = uArmL;break; 
    case 'w': mode = lArmL;break; 
    case 'e':mode = handL;break;

    case 'p': mode = uArmR;break;
    case 'o': mode = lArmR;break; 
    case 'i':mode = handR;break;
    case '|':mode = human;break;
    case '[':mode = box;break;
    case 'I':mode = initial;break;
    default:
      switch(mode)
	{
	case initial:




a=-1;
scene_x=0, scene_y=0, scene_z=-4.0f;
scene_r_x=0,scene_r_y=0,scene_r_z=0;

human_r_x=-1,human_r_y=-27,human_r_z=0;
head_r_x=18,head_r_y=0,head_r_z=0;
box_r_x=0,box_r_y=-30,box_r_z=0;
neck_r_x=0,neck_r_y=0,neck_r_z=0;
uArmL_r_x=-41,uArmL_r_y=-66,uArmL_r_z=80;
uArmR_r_x=-41,uArmR_r_y=66,uArmR_r_z=-80;
lArmR_r_x=0,lArmR_r_y=0,lArmR_r_z=-85;
lArmL_r_x=0,lArmL_r_y=0,lArmL_r_z=85;

 uLegL_r_x=0,uLegL_r_y=0,uLegL_r_z=0;
uLegR_r_x=0,uLegR_r_y=0,uLegR_r_z=0;
lLegR_r_x=0,lLegR_r_y=0,lLegR_r_z=0;
lLegL_r_x=0,lLegL_r_y=0,lLegL_r_z=0;

torso_r_x=13,torso_r_y=0,torso_r_z=0;
feetR_r_x = 0,feetR_r_y = 0,feetR_r_z = 0;
 feetL_r_x = 0,feetL_r_y = 0,feetL_r_z = 0;
 handR_r_x = 0,handR_r_y = 0,handR_r_z = 0;
 handL_r_x = 0,handL_r_y = 0,handL_r_z = 0;

	  break;

	case scene:	
	  switch(key)
	    {
	    case '1':	      scene_r_x++;	      break;
	    case '3':	      scene_r_y++;	      break;
	    case '5':	      scene_r_z++;	      break;
	    case '2':	      scene_r_x--;	      break;
	    case '4':	      scene_r_y--;	      break;
	    case '6':	      scene_r_z--;	      break;
	    case '7':	      scene_z++;	      break;
	    case '8':	      scene_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case human:	
	  switch(key)
	    {
	    case '1':	      human_r_x++;	      break;
	    case '3':	      human_r_y++;	      break;
	    case '5':	      human_r_z++;	      break;
	    case '2':	      human_r_x--;	      break;
	    case '4':	      human_r_y--;	      break;
	    case '6':	      human_r_z--;	      break;
	    case '0': human_r_x=0;human_r_y=0;human_r_z=0;break;
	    }
	  break;
	case head:	
	  switch(key)
	    {
	    case '1':	      if(head_r_x < 40)head_r_x++;	      break;
	    case '3':	      if(head_r_y < 40)head_r_y++;	      break;
	    case '5':	      if(head_r_z < 40)head_r_z++;	      break;
	    case '2':	      if(head_r_x > -40)head_r_x--;	      break;
	    case '4':	      if(head_r_y > -40)head_r_y--;	      break;
	    case '6':	      if(head_r_z > -40)head_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case neck:	
	  switch(key)
	    {
	    case '1':	      if(neck_r_x < 50)neck_r_x++;	      break;
	    case '3':	      if(neck_r_y < 0)neck_r_y++;	      break;
	    case '5':	      if(neck_r_z < 50)neck_r_z++;	      break;
	    case '2':	      if(neck_r_x > -50)neck_r_x--;	      break;
	    case '4':	      if(neck_r_y > 0)neck_r_y--;	      break;
	    case '6':	      if(neck_r_z > -50)neck_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case torso:	
	  switch(key)
	    {
	    case '1':	      if(torso_r_x<90) torso_r_x++;	      break;
	    case '3':	       if(torso_r_y<50) torso_r_y++;	      break;
	    case '5':	       if(torso_r_z<50) torso_r_z++;	      break;
	    case '2':	      if(torso_r_x>-50)  torso_r_x--;	      break;
	    case '4':	       if(torso_r_y>-50) torso_r_y--;	      break;
	    case '6':	      if(torso_r_z>-50)  torso_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case uLegR:	
	  switch(key)
	    {
	    case '1':	      if(uLegR_r_x < 20)uLegR_r_x++;	      break;
	    case '3':	      if(uLegR_r_y < 90)uLegR_r_y++;	      break;
	    case '5':	      if(uLegR_r_z < 90)uLegR_r_z++;	      break;
	    case '2':	      if(uLegR_r_x > -130)uLegR_r_x--;	      break;
	    case '4':	      if(uLegR_r_y > -90)uLegR_r_y--;	      break;
	    case '6':	      if(uLegR_r_z > 0)uLegR_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case lLegR:	
	  switch(key)
	    {
	    case '1':	      if(lLegR_r_x < 150) lLegR_r_x++;     break;
	    case '2':	      if(lLegR_r_x > 0)	  lLegR_r_x--;     break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	      /*case '5':	      lLegR_r_z++;	      break;
		case '3':	      lLegR_r_y++;	      break;
		case '4':	      lLegR_r_y--;	      break;
		case '6':	      lLegR_r_z--;	      break;*/
	    }
	  break;
	case uLegL:	
	  switch(key)
	    {
	    case '1':	      if(uLegL_r_x < 20)uLegL_r_x++;	      break;
	    case '3':	      if(uLegL_r_y < 90)uLegL_r_y++;	      break;
	    case '5':	      if(uLegL_r_z < 0)uLegL_r_z++;	      break;
	    case '2':	      if(uLegL_r_x > -130)uLegL_r_x--;	      break;
	    case '4':	      if(uLegL_r_y > -90)uLegL_r_y--;	      break;
	    case '6':	      if(uLegL_r_z > -90)uLegL_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case lLegL:	
	  switch(key)
	    {
	    case '1':	      if(lLegL_r_x < 150) lLegL_r_x++;     break;
	    case '2':	      if(lLegL_r_x > 0)	  lLegL_r_x--;     break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	      /* case '5':	      lLegL_r_z++;	      break;
		 case '2':	      lLegL_r_x--;	      break;
		 case '4':	      lLegL_r_y--;	      break;
		 case '6':	      lLegL_r_z--;	      break;*/
	    }
	  break;
	case uArmR:	
	  switch(key)
	    {
	    case '1':	      /*if(uArmR_r_x < 90)*/uArmR_r_x++;	      break;
	    case '3':	     /* if(uArmR_r_y < 90)*/uArmR_r_y++;	      break;
	    case '5':	     /* if(uArmR_r_z < 90 )*/uArmR_r_z++;	      break;
	    case '2':	     /* if(uArmR_r_x > -180)*/uArmR_r_x--;	      break;
	    case '4':	     /* if(uArmR_r_y > -90)*/uArmR_r_y--;	      break;
	    case '6':	     /* if(uArmR_r_z > -90)*/uArmR_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case lArmR:	
	  switch(key)
	    {
	    case '1':	     /* if(lArmR_r_z < 0)*/lArmR_r_z++;	      break;
	      case '3':	      lArmR_r_y++;	      break;
	      case '5':	      lArmR_r_z++;	      break;
	    case '2':	     /* if(lArmR_r_z > -170)*/lArmR_r_z--;	      break;
	      case '4':	      lArmR_r_y--;	      break;
	      case '6':	      lArmR_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case uArmL:	
	  switch(key)
	    {
	    case '1':	     /* if(uArmL_r_x < 90)*/uArmL_r_x++;	      break;
	    case '3':	     /* if(uArmL_r_y < 90)*/uArmL_r_y++;	      break;
	    case '5':	     /* if(uArmL_r_z < 90 )*/uArmL_r_z++;	      break;
	    case '2':	     /* if(uArmL_r_x > -180)*/uArmL_r_x--;	      break;
	    case '4':	     /* if(uArmL_r_y > -90)*/uArmL_r_y--;	      break;
	    case '6':	     /* if(uArmL_r_z > -90)*/uArmL_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case lArmL:	
	  switch(key)
	    {
	    case '1':	     /* if(lArmL_r_z < 170)*/lArmL_r_z++;	      break;
	      case '3':	      lArmL_r_y++;	      break;
	      case '5':	      lArmL_r_z++;	      break;
	    case '2':	    /*  if(lArmL_r_z > 0)*/lArmL_r_z--;	      break;
	      case '4':	      lArmL_r_y--;	      break;
	      case '6':	      lArmL_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;

	case feetR:	
	  switch(key)
	    {
	    case '1':	      if(feetR_r_x < 70)feetR_r_x++;	      break;
	    case '3':	      if(feetR_r_y < 45)feetR_r_y++;	      break;
	    case '5':	      feetR_r_z++;	      break;
	    case '2':	      if(feetR_r_x > -45)feetR_r_x--;	      break;
	    case '4':	      if(feetR_r_y > -45)feetR_r_y--;	      break;
	    case '6':	      feetR_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case feetL:	
	  switch(key)
	    {
	    case '1':	      if(feetL_r_x < 70)feetL_r_x++;	      break;
	    case '3':	      if(feetL_r_y < 45)feetL_r_y++;	      break;
	    case '5':	      feetL_r_z++;	      break;
	    case '2':	      if(feetL_r_x > -45)feetL_r_x--;	      break;
	    case '4':	      if(feetL_r_y > -45)feetL_r_y--;	      break;
	    case '6':	      feetL_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;

	case handR:	
	  switch(key)
	    {
	    case '1':	      if(handR_r_x < 45)handR_r_x++;	      break;
	    case '3':	      if(handR_r_y < 90)handR_r_y++;	      break;
	    case '5':	      if(handR_r_z < 90)handR_r_z++;	      break;
	    case '2':	      if(handR_r_x > -90)handR_r_x--;	      break;
	    case '4':	      if(handR_r_y > -90)handR_r_y--;	      break;
	    case '6':	      if(handR_r_z > -90)handR_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case handL:	
	  switch(key)
	    {
	    case '1':	      if(handL_r_x < 45)handL_r_x++;	      break;
	    case '3':	      if(handL_r_y < 90)handL_r_y++;	      break;
	    case '5':	      if(handL_r_z < 90)handL_r_z++;	      break;
	    case '2':	      if(handL_r_x > -90)handL_r_x--;	      break;
	    case '4':	      if(handL_r_y > -90)handL_r_y--;	      break;
	    case '6':	      if(handL_r_z > -90)handL_r_z--;	      break;
	    case '0': scene_r_x=0;scene_r_y=0;scene_r_z=0;break;
	    }
	  break;
	case box:
	  switch(key)
	    {
	    case '1':	      box_r_x++;	      break;
	    case '3':	      box_r_y++;	      break;
	    case '5':	      box_r_z++;	      break;
	    case '2':	      box_r_x--;	      break;
	    case '4':	      box_r_y--;	      break;
	    case '6':	      box_r_z--;	      break;

	    case '7':	      if(a<90)a++;	      break;
	    case '8':	      if(a>=0)a--;	      break;
	    case '0':	      a=0;	      break;			
	    }
	  break;
	}
    }
  //cout<<mode<<"hello";
  glutPostRedisplay();
}
