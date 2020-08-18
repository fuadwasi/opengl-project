#include<windows.h>
#include<bits/stdc++.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
//#include<iostream>
#include<mmsystem.h>



#include"bari.h"
#include"road.h"
#include"star.h"
#include"background_design.h"
#include"car.h"
#include"car2.h"
#include"road_light.h"
#include"shaphead.h"
#include"fireHid.h"




#pragma comment(lib, "winmm.lib")


#define sc              scanf
#define pr              printf
#define br              puts("")
#define For(i,lo,n) 	for(int i = lo; i < n; i++)
#define Forr(i,lo,n) 	for(int i = n-1; i >= lo; i--)
#define Frl(i,n) 	    for(int i = 0; i < n; i++)




using namespace std;


int light_color_index1=2,light_color_index2=2;
int car_wait;


int tmp=0;



int building_high[]={400,500,450,350,450,350};


int footPath_color[2][3]={
                        {120,202,227},
                        {195,153,108}
                        };

static GLfloat tx = 0.0,tx1 = 0.0,mx=5,mx1=-5;




void init(void)
{
  glClearColor(1,1,1,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(0, 1500, 1000, 0, -100, 100);
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic represent ation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void shap()
{

    // For the left hand box
    glColor3ub (0,0,255);
    glBegin(GL_POLYGON);
    glVertex2d (-60+tx,550);
	glVertex2d (-50+tx,550);
	glVertex2d (-50+tx,450);
	glVertex2d (-60+tx,450);
    glEnd();

}



void footPath(int y,int redi,int col_in)
{
    glColor3ub (footPath_color[col_in][0],footPath_color[col_in][1],footPath_color[col_in][2]);
    glBegin(GL_POLYGON);
    glVertex2d (0,y+redi);
	glVertex2d (1500,y+redi);
	glVertex2d (1500,y);
	glVertex2d (0,y);
    glEnd();
}










void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    /* ***************** Background ********************* */

    background_design();

    if(back_color_ind)
    {
        star_draw(10,120);
        star_draw(80,30);
        star_draw(150,70);
        star_draw(230,50);
        star_draw(100,120);
        star_draw(310,15);
        star_draw(350,70);
        star_draw(420,50);
        star_draw(490,15);
        star_draw(520,70);
        star_draw(574,47);
        star_draw(619,100);
        star_draw(653,58);
        star_draw(710,10);
        star_draw(730,90);
        star_draw(780,220);
        star_draw(790,50);
        star_draw(790,150);
        star_draw(830,80);
        star_draw(830,180);
        star_draw(870,100);
        star_draw(880,180);
        star_draw(890,50);
        star_draw(930,220);
        star_draw(930,100);
        star_draw(970,10);
        star_draw(970,150);
        star_draw(1000,80);
        star_draw(1020,150);
        star_draw(1050,80);
        star_draw(1080,180);
        star_draw(1130,100);
        star_draw(1160,180);
        star_draw(1140,50);
        star_draw(1180,220);
        star_draw(1200,100);
        star_draw(1230,10);
        star_draw(1270,150);
        star_draw(1300,80);
        star_draw(1330,100);
        star_draw(1360,180);
        star_draw(1340,50);
        star_draw(1380,220);
        star_draw(1400,100);
        star_draw(1430,10);
        star_draw(1470,150);
        star_draw(1450,80);
        star_draw(1480,10);
    }


    int bari_dis=0;
    for(int ba=0;ba<6;ba++)
    {
        bari_draw(bari_dis,building_high[ba],ba);
        bari_dis+=250;
    }


    footPath(610,15,0);
    roadDraw(625,925);



    light_draw(560,500,625,light_color_index1);



    footPath(925,15,0);
    footPath(940,60,1);


/** ************ Car Draw ************** */
/* ************ towards right Car Draw ************** */
    int c1x=515,car_color=0,car_dis=305;
    for(int i=0;i<4;i++)
    {
        car1_Draw(c1x,690,tx,car_color++);
        car_color%=4;
        c1x-=car_dis;
    }
/* ************ towards Left Car Draw ************** */
    c1x=925;car_color=2;
    for(int i=0;i<4;i++)
    {
        car2_Draw(c1x,860,tx1,car_color++);
        car_color%=4;
        c1x+=car_dis;
    }


    light_draw(850,800,925,light_color_index2);
    fireHid_draw(328,950);
    fireHid_draw(1328,950);


    glutSwapBuffers();
}


void update(int value) {
	tx+=mx;
	tx1+=mx1;
    if(tx>2300)tx=-520;
    if(tx1<-2000)tx1=450;
    if(car_wait==1)
    {
        //printf("%d\n",car_wait);
        mx=5;
        mx1=-5;
        light_color_index1=2;
        light_color_index2=2;
        car_wait=0;
        //printf("%d\n",car_wait);
    }
    else if(car_wait)
    {
        //printf("%d\n",car_wait);
        mx=0;
        mx1=0;
        light_color_index1=1;
        light_color_index2=1;
        car_wait--;
    }


    //Beep(100,500);
    back_color_cou++;
    if(back_color_cou==200)
    {
        back_color_cou=1;
        back_color_ind++;
        back_color_ind%=2;
        //system("cls");
    }
    //printf("%d\n",back_color_cou);

	glutPostRedisplay(); ////Tell GLUT that the scene has changed
	glutTimerFunc(25, update, 0);
}

void spin_hand(void)
{
        glutPostRedisplay();

}


void spe_key(int key, int x, int y)
{

    Beep(100,50);
    switch (key)
    {

    case GLUT_KEY_LEFT:
        light_color_index2=2;
        mx1=-5;
        light_color_index1=0;
        mx=0;
        break;

    case GLUT_KEY_RIGHT:
        light_color_index1=2;
        mx=5;
        light_color_index2=0;
        mx1=0;
        break;
    case GLUT_KEY_UP:
        light_color_index1=2;
        mx=5;
        light_color_index2=2;
        mx1=-5;
        break;
    default:
        mx=0;
        mx1=0;
        light_color_index1=0;
        light_color_index2=0;

        break;
//			glutPostRedisplay();
	}
}



void my_keyboard(unsigned char key, int nx, int ny)
{

    Beep(100,50);
	switch (key) {
        case 'w':
        //cout<<key<<endl;
        car_wait=20;

        case 's':
        mx=0;
        mx1=0;
        light_color_index1=0;
        light_color_index2=0;
        case 'd':
            back_color_ind=0;
            back_color_cou=1;
            break;
        case 'n':
            back_color_ind=1;
            //cout<<back_color_ind<<endl;
            back_color_cou=1;

        break;
        default:
			break;



	}
}



int main(int argc,char **argv){

    //printf("%d\n",fun);

//    string audiofile_str="street_sound.wav";
//    fstream fp;
//    char audiofile_char[]={"street_sound.wav"};
//    fp.open(audiofile_char, ios::in);
//
//
//    if (fp != NULL)
//    {
//        /* open function doesn't work with a variable of string type and PlaySound function doesn't work with char array hence first we used char array and here we are converting it to a string. so that we can use it in PlaySound function */
//
//        /* PlaySound function is used to play a sound specified by the given file name. */
//        /* SND_SYNC : play sound synchronously */
//        /* .c_str() function is used to return a pointer to an array that contains a null-terminated sequence of characters representing the current value of the string object. */
//        PlaySound(audiofile_str.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//    }
//    else
//    {
//        cout<<"\nAudio file couldn't run..!!";
//        cout<<"\nCheck the following things: \n 1. Your file is an original .wav audio file. \n 2. You have mentioned '.wav' extension in the name of file. \n 3. It is present in the folder where your program is saved.";
//    }
//    system("pause");


    //PlaySound("trs.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
    //sndPlaySound("file_example_WAV_1MG.wAV", SND_FILENAME | SND_ASYNC | SND_LOOP);
    //cout<<pla<<endl;
    Beep(100,500);
    pr("****************************************************");br;
    pr("****************************************************");br;
    pr("***************** Welcome Everyone *****************");br;
    pr("****************************************************");br;
    pr("****************************************************");br;br;br;
    pr("******************* About Myself *******************");br;
    pr("****************************************************");br;br;
    pr("Name: Fuad Hasan\nID:171-15-9400");br;
    pr("Course: CSE422      Section: 01");br;
    pr("Course Teacher: Mst. Eshita Khatun(EK)");br;br;br;
    pr("****************************************************");br;
    pr("****************************************************");br;br;br;
    pr("******************* Instructions *******************");br;
    pr("****************************************************");br;br;
    pr("Up Arrow:           Cars move towards both direction");br;
    pr("Down Arrow / s:     All Cars stop Moving");br;
    pr("Left Arrow:         Cars move towards left direction");br;
    pr("Right Arrow:        Cars move towards Right direction");br;
    pr("w:                  Cars will wait for a moment then start to run again");br;
    pr("d:                  Change the background to Day mode");br;
    pr("n:                  Change the background to Night mode");br;br;
    pr("****************************************************");br;
    pr("****************************************************");br;
    pr("****************************************************");br;br;br;


    system("pause");

    Beep(100,500);
    PlaySound(TEXT("street_sound.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1200,800);
    glutCreateWindow("Lab Final");


    init();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(my_keyboard);
    glutTimerFunc(25, update, 0);
    glutMainLoop();



    return 0;
}
