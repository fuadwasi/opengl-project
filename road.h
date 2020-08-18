

void roadDraw(int y1,int y2)
{
    glColor3ub (125,127,120);
    glBegin(GL_POLYGON);
    glVertex2d (0,y1);
	glVertex2d (1500,y1);
	glVertex2d (1500,y2);
	glVertex2d (0,y2);
    glEnd();
    int mid=(y1+y2)/2;
    int dy1=mid-10,dy2=mid+10;
    //printf("%d %d\n",dy1,dy2);

    int dif = 130,dx=75;

    for(int i=0; i<4; i++)
    {
        glColor3ub (255,255,255);
        glBegin(GL_POLYGON);
        glVertex2d (dx,dy2);
		glVertex2d (dx+90,dy2);
		glVertex2d (dx+90,dy1);
		glVertex2d (dx,dy1);
        glEnd();
        dx+=dif;
    }
    dx=880;
    for(int i=0; i<4; i++)
    {
        glColor3ub (255,255,255);
        glBegin(GL_POLYGON);
        glVertex2d (dx,dy2);
		glVertex2d (dx+90,dy2);
		glVertex2d (dx+90,dy1);
		glVertex2d (dx,dy1);
        glEnd();
        dx+=dif;
    }
    int wei=(y2-y1)/7;
    dif=wei+5;

    int dy=y1;
    for(int i=0; i<10; i++)
    {
        glColor3ub (255,255,255);
        glBegin(GL_POLYGON);
        glVertex2d (670,dy+wei);
		glVertex2d (790,dy+wei);
		glVertex2d (790,dy);
		glVertex2d (670,dy);
        glEnd();
        dy+=dif;
    }


}

