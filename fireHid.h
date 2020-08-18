

void fireHid_draw(int x,int y){


        glColor3ub (255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d (x,y);
        glVertex2d (x+45,y);
        glVertex2d (x+45,y-130);
        glVertex2d (x,y-130);
        glEnd();


        glColor3ub (130,17,30);
        glBegin(GL_POLYGON);
        glVertex2d (x-10,y-80);
        glVertex2d (x+55,y-80);
        glVertex2d (x+55,y-100);
        glVertex2d (x-10,y-100);
        glEnd();

        glColor3ub (255,00,0);
        glBegin(GL_POLYGON);
        glVertex2d (x+15,y-130);
        glVertex2d (x+30,y-130);
        glVertex2d (x+30,y-145);
        glVertex2d (x+15,y-145);
        glEnd();




    for(int i=0; i<=4; i++)
    {
        glLineWidth(2.0);
        glColor3ub (130,17,30);
        glBegin(GL_LINES);
        glVertex2d (x+(i*11),y);
        glVertex2d (x+(i*11),y-80);
        glEnd();
    }




}
