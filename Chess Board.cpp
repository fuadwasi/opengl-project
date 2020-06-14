#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<windows.h>

#define For(i,lo,n) 	for(int i = lo; i < n; i++)
#define Forr(i,lo,n) 	for(int i = n-1; i >= lo; i--)
#define Frl(i,n) 	    for(int i = 0; i < n; i++)



void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(0, 8, 0, 8, -100, 100);
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // For the up star




    int cor=0,co_l;
    For(i,0,8){
        co_l=cor;
        cor++;
        cor%=2;
        For(j,0,8)
        {
            if(!co_l)glColor3ub (0,0,0);
            else glColor3ub (255,255,255);
            co_l++;
            co_l%=2;
            glBegin(GL_POLYGON);
            glVertex2d (j,i);
            glVertex2d (j+1,i);
            glVertex2d (j+1,i+1);
            glVertex2d (j,i+1);
            glEnd();

        }


    }










glutSwapBuffers();
}

int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(500,200);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Task-2");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
