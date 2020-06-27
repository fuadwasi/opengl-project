#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<windows.h>

#include<stdio.h>
#include<math.h>
/* *********************************************************** */
//
#include<bits/stdc++.h>
#include<string>

#include <windows.h>

#include <iostream>
#include <shlobj.h>
#include <time.h>
#include <cstdlib>

#include <sstream>


using namespace std;

/* *********************************************************** */

/* ******************* Type Define *************************** */

#define sc              scanf
#define pr              printf
#define ll              long long
#define ull             unsigned long long
#define FastIO	        ios_base::sync_with_stdio(false); cin.tie(NULL)
#define so(a,n)         sort(a,a+n)
#define br              puts("")
#define pb(a)           push_back(a)
#define pbk()           pop_back()
#define ln              length()
#define sz              size()
#define mset(v,d)       memset(v, d, sizeof(v))
#define rn              return
#define ps()            pr(" ")


/* ******************* int scan *************************** */

#define sc1(a)          sc("%d",&a)
#define sc2(a,n)        sc("%d%d",&a,&n)
#define sc3(a,n,m)      sc("%d%d%d",&a,&n,&m)


/* ******************* long long scan *************************** */

#define scl1(a)          sc("%lld",&a)
#define scl2(a,n)        sc("%lld%lld",&a,&n)
#define scl3(a,n,m)      sc("%lld%lld%lld",&a,&n,&m)

/* ******************* File I/O *************************** */

#define fin             freopen("in.txt","r",stdin)
#define fou             freopen("ou.txt","w",stdout)

/* ******************* print int *************************** */
#define psd(a)          pr("%d ",a)
#define prs(a)          pr("%d ",a)
#define pr1(a)          pr("%d\n",a)
#define pr2(a,n)        pr("%d %d\n",a,n)
#define pr3(a,n,m)      pr("%d %d %d\n",a,n,m)

/* ******************* Loop *************************** */

#define For(i,lo,n) 	for(int i = lo; i < n; i++)
#define Forr(i,lo,n) 	for(int i = n-1; i >= lo; i--)
#define Frl(i,n) 	    for(int i = 0; i < n; i++)

/* ******************* array input *************************** */

#define acin(a,n)  	    for(int i = 0; i < n; i++)  cin>>a[i]
#define ain(a,n)  	    for(int i = 0; i < n; i++)  scanf("%d",&a[i])
#define aou(a,n)        for(int i = 0; i < n; i++)  pr("%d ",a[i])


/* ************************************************************/



void fm(){
    #ifndef ONLINE_JUDGE
        fin;
        fou;
    #endif
}



int x1,x2,yy1,yy2,x0,yy0,p;
float step,dx,dy,ix,iy,x,y;

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(0, 500, 0, 500, -100, 100);
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // For the up star

    glColor3ub (255,255,255);
    glBegin(GL_POINTS);





    dx=abs(x2-x1);
    dy=abs(yy2-yy1);

    step = max(dx,dy);

    ix=dx/step;
    iy=dx/step;
    pr("%.2f\n",dy/dx);
    float m=dy/dx;

    x=x1,y=yy1;
    glVertex2d(x,y);
    int l=step;

    pr("s=%d x=%.2f y=%.2f\n",1,x,y);
    For(i,0,l)
    {
        x+=(1/m);
        y++;
        glVertex2d(x,y);
        pr("s=%d x=%.2f y=%.2f\n",i+2,x,y);
    }


    glEnd();







glutSwapBuffers();
}

int main(int argc,char **argv){

    pr("Enter co-ordinates of 1st point: ");
    sc2(x0,yy0);
    pr("Enter co-ordinates of 2nd point: ");
    sc2(x1,yy1);

    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
