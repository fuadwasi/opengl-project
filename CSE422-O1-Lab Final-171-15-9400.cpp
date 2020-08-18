#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<windows.h>

#define For(i,lo,n) 	for(int i = lo; i < n; i++)
#define Forr(i,lo,n) 	for(int i = n-1; i >= lo; i--)
#define Frl(i,n) 	    for(int i = 0; i < n; i++)

int colo[3][3]={
                {255,255,255},
                {0,0,0},
                {240,130,41},
                };

void init(void)
{
  glClearColor(1,1,1,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(-50,50,-50,50, -100, 100);
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}

void draw_circle(int x,int y, int r,int col_ind)
{
    glColor3ub (colo[col_ind][0],colo[col_ind][1],colo[col_ind][2]);
    glBegin(GL_POLYGON);

    int p=1-r,cx=0, cy=r;
    int dx=x,dy=y;
    while((cx<=cy)){

        cx=cx+1;

        if(p<0){
            cy=cy;
            //printf("%0.2f %0.2f\n",cx,cy);
            p=p+(2*cx)+1;
        }

        else
        {
            cy=cy-1;
            //printf("%0.2f %0.2f\n",cx,cy);
            p=p+(2*cx)+1-(2*cy);
        }
        printf("%d %d\n",dx+cx,dy+cy);
        glVertex2d (dx+cx,dy+cy);
        glVertex2d (dx+cy,dy+cx);
        glVertex2d (dx-cx,dy-cy);
        glVertex2d (dx-cx,dy+cy);
        glVertex2d (dx+cx,dy-cy);
        glVertex2d (dx+cy,dy-cx);
        glVertex2d (dx-cy,dy-cx);
        glVertex2d (dx-cy,dy+cx);


    }
        glEnd();
}

void back_de()
{

    // For the left hand box
    glColor3ub (255,255,255);
    glBegin(GL_POLYGON);
    glVertex2d (-100,-100);
	glVertex2d (100,-100);
	glVertex2d (100,100);
	glVertex2d (-100,100);
    glEnd();

}

void display()
{

    back_de();
    printf("****************1 1***********");
    draw_circle(0,21,25,1);
    /** *************** left hand ***************** **/
    glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2d (-48,-16);
	glVertex2d (-31,-12);
    glVertex2d (-22,6);
    glEnd();

    /** *************** right hand ***************** **/
    glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2d (48,-16);
	glVertex2d (31,-12);
    glVertex2d (22,6);
    glEnd();

/** *************** foot ***************** **/

    /* *************** left foot ***************** **/
    glColor3ub (240,130,41);
    glBegin(GL_POLYGON);
    glVertex2d (-20,-32);
	glVertex2d (-39,-44);
	glVertex2d (-16,-44);
	glVertex2d (-12,-38);
    glEnd();

    /* *************** right foot ***************** **/
    glColor3ub (240,130,41);
    glBegin(GL_POLYGON);
    glVertex2d (20,-33);
	glVertex2d (39,-44);
	glVertex2d (16,-44);
	glVertex2d (12,-38);
    glEnd();


/** *************** Body ***************** **/

/* *************** body black ***************** */
    draw_circle(0,-12,31,1);
/* *************** body white ***************** */
    draw_circle(0,-12,25,0);


/** *************** eye white ***************** **/

/* *************** left eye white ***************** **/
    draw_circle(-7,21,12,0);
/* *************** right eye white ***************** **/
    draw_circle(7,21,12,0);

/** *************** eye black ***************** **/

/* *************** left eye black ***************** **/
    draw_circle(-7,21,4,1);
/* *************** right eye black ***************** **/
    draw_circle(7,21,4,1);

/** *************** Nose ***************** **/

    glColor3ub (240,130,41);
    glBegin(GL_POLYGON);
    glVertex2d (0,4);
	glVertex2d (6,14);
    glVertex2d (-6,14);
    glEnd();






glutSwapBuffers();
}

int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(500,200);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
