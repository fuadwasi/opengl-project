#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<windows.h>

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(0, 100, 0, 100, -100, 100);
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // For the up star
    glColor3ub (43,182,115);
    glBegin(GL_POLYGON);

    glVertex2d (45,75);
    glVertex2d (30,70);
    glVertex2d (45,65);
	glVertex2d (50,50);
	glVertex2d (55,65);
	glVertex2d (70,70);
	glVertex2d (55,75);
	glVertex2d (50,90);
    glEnd();


    // For the Left star
    glColor3ub (70, 188, 236);
    glBegin(GL_POLYGON);

	glVertex2d (25,55);
    glVertex2d (10,50);
    glVertex2d (25,45);
    glVertex2d (30,30);
	glVertex2d (35,45);
	glVertex2d (50,50);
	glVertex2d (35,55);
	glVertex2d (30,70);
    glEnd();


    // For the down star
    glColor3ub (247, 148, 23);
    glBegin(GL_POLYGON);

	glVertex2d (45,35);
    glVertex2d (30,30);
    glVertex2d (45,25);
    glVertex2d (50,10);
	glVertex2d (55,25);
	glVertex2d (70,30);
	glVertex2d (55,35);
	glVertex2d (50,50);
    glEnd();


    // For the Rignt star
    glColor3ub (237, 28, 36);
    glBegin(GL_POLYGON);

	glVertex2d (65,55);
    glVertex2d (50,50);
    glVertex2d (65,45);
    glVertex2d (70,30);
	glVertex2d (75,45);
	glVertex2d (90,50);
	glVertex2d (75,55);
	glVertex2d (70,70);
    glEnd();




glutSwapBuffers();
}

int main(int argc,char **argv){


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
