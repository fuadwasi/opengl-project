#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<windows.h>

int col[]={170,124,80,0,197,225},g=0;
static GLfloat spin = 0.0;

void init(void)
{
  glClearColor(1,1,1,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(-50, 50, -50, 50, -100, 100);
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic represent ation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

/* ********************* For Stand ******************** */
    // For the stand square



    // For the left stand
    glColor3ub (255,0,0);
    glBegin(GL_POLYGON);
    glVertex2d (-3,-5);
	glVertex2d (-25,-50);
	glVertex2d (-18,-50);
	glVertex2d (0,-5);
    glEnd();
//    // For the right stand
    glColor3ub (255,0,0);
    glBegin(GL_POLYGON);
    glVertex2d (3,-5);
	glVertex2d (25,-50);
	glVertex2d (18,-50);
	glVertex2d (0,-5);
    glEnd();
//
//    // For the left stand box
    glColor3ub (250,166,26);
    glBegin(GL_POLYGON);
    glVertex2d (-28,-50);
	glVertex2d (-13,-50);
	glVertex2d (-13,-45);
	glVertex2d (-28,-45);
    glEnd();

    // For the right stand box
    glColor3ub (250,166,26);
    glBegin(GL_POLYGON);
    glVertex2d (28,-50);
	glVertex2d (13,-50);
	glVertex2d (13,-45);
	glVertex2d (28,-45);
    glEnd();









    /* ********************* For Spin Hands ******************** */

    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    // For the left hand box
    glColor3ub (col[g],col[g+1],col[g+2]);
    glBegin(GL_POLYGON);
    glVertex2d (-47,-10);
	glVertex2d (-27,-10);
	glVertex2d (-27,10);
	glVertex2d (-47,10);
    glEnd();


//    // For the left hand Bar
    glColor3ub (col[g+3],col[g+4],col[g+5]);
    glBegin(GL_POLYGON);
    glVertex2d (-27,-2);
	glVertex2d (-5,-2);
	glVertex2d (-5,2);
	glVertex2d (-27,2);
    glEnd();







    // For the Right hand box
    glColor3ub (col[g],col[g+1],col[g+2]);
    glBegin(GL_POLYGON);
    glVertex2d (47,-10);
	glVertex2d (27,-10);
	glVertex2d (27,10);
	glVertex2d (47,10);
    glEnd();
//
//
//    // For the Right hand Bar
    glColor3ub (col[g+3],col[g+4],col[g+5]);
    glBegin(GL_POLYGON);
    glVertex2d (27,-2);
	glVertex2d (5,-2);
	glVertex2d (5,2);
	glVertex2d (27,2);
    glEnd();

    glPopMatrix();

    glColor3ub (0,255,0);
    glBegin(GL_POLYGON);
	glVertex2d (-5,-5);
	glVertex2d (5,-5);
	glVertex2d (5,5);
	glVertex2d (-5,5);
    glEnd();

    glutSolidTorus(1.00, 6.4, 10, 100);








    glutSwapBuffers();
}

void spin_hand(void)
{
        glutPostRedisplay();

}


void spe_key(int key, int x, int y)
{


	switch (key) {

		case GLUT_KEY_LEFT:
                for(int i=0;i<5;i++){
                    col[i]+=1;
                    col[i]%=255;
                }
				spin+=1;
				spin_hand();
				break;

		case GLUT_KEY_RIGHT:
                for(int i=0;i<5;i++){
                    col[i]+=1;
                    col[i]%=255;
                }
				spin-=1;
				spin_hand();
//				glutPostRedisplay();
				break;

	  default:
			break;
	}
}



int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Lab Final");


    init();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutMainLoop();

    return 0;
}
