

void car1_Draw(int x,int y,int c1x,int color_ind)
{
    //c1x = horizontal movement

    int car_color[4][3]={
                        {255,176,64},
                        {28,149,188},
                        {240,55,64},
                        {121,12,125},
                        };

    int a=215,b=45,c=95,d=165;
    glColor3ub (car_color[color_ind][0],car_color[color_ind][1],car_color[color_ind][2]);
    glBegin(GL_POLYGON);
    glVertex2d (c1x+x-a,y-b);
	glVertex2d (c1x+x-a,y);
	glVertex2d (c1x+x,y);
	glVertex2d (c1x+x,y-b);
	glVertex2d (c1x+x-45,y-b);
	glVertex2d (c1x+x-c,y-c);
	glVertex2d (c1x+x-d,y-c);
    glEnd();



    int e=58,f=86;

    /* Right window */
    glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2d (c1x+x-132,y-e);
	glVertex2d (c1x+x-72,y-e);
	glVertex2d (c1x+x-100,y-f);
	glVertex2d (c1x+x-132,y-f);
    glEnd();

    /* right window*/
    glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2d (c1x+x-183,y-e);
	glVertex2d (c1x+x-140,y-e);
	glVertex2d (c1x+x-140,y-f);
	glVertex2d (c1x+x-157,y-f);
    glEnd();

    /* Head Light */
    glColor3ub (255,255,0);
    glBegin(GL_POLYGON);
    glVertex2d (c1x+x,y-25);
	glVertex2d (c1x+x+10,y-25);
	glVertex2d (c1x+x+10,y-40);
	glVertex2d (c1x+x,y-40);
    glEnd();

    /* Front Bumper */
    glColor3ub (0,0,0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2d (c1x+x-2,y-5);
	glVertex2d (c1x+x+8,y-5);

    glEnd();

    /* Head Light */
    glColor3ub (255,255,0);
    glBegin(GL_POLYGON);
    glVertex2d (c1x+x-215,y-25);
	glVertex2d (c1x+x-225,y-25);
	glVertex2d (c1x+x-225,y-40);
	glVertex2d (c1x+x-215,y-40);
    glEnd();

    /* Front Bumper */
    glColor3ub (0,0,0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2d (c1x+x-213,y-5);
	glVertex2d (c1x+x-226,y-5);

    glEnd();





//
//    glColor3ub (0,0,0);
//    glBegin(GL_POLYGON);
//    glVertex2d (x-a,y-b);
//	glVertex2d (x-a,y);
//	glVertex2d (x,y);
//	glVertex2d (x,y-b);
//	glVertex2d (x-c,y-c);
//	glVertex2d (x-d,y-c);
//    glEnd();


/* **************************** Car Wheel ************************** */





/* ********** For Front Wheel ************** */
    glColor3ub (0,0,0);
    glBegin(GL_POLYGON);

    int p=-20,cx=0, cy=21;
    int dx=x-45+c1x,dy=y;
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


    /* ********** For Back Wheel ************** */
    glColor3ub (0,0,0);
    glBegin(GL_POLYGON);

    p=-20,cx=0, cy=21;
    dx=x+c1x-165,dy=y;
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
