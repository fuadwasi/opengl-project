
int back_color[2][3]={
                        {255,255,255},
                        {27,120,190}
                        };
int back_color_ind=1,back_color_cou=1;


void background_design(){

    if(back_color_ind==0){
        glColor3ub (255,255,255);
        glBegin(GL_POLYGON);
        glVertex2d (0,1000);
        glVertex2d (1500,1000);
        glVertex2d (1500,0);
        glColor3ub (27,120,190);
        glVertex2d (0,0);
        glEnd();

    }
    //if(back_color_ind==1)
    else
    {
        glColor3ub (165,167,170);
        glColor3ub (200,210,210);
        glBegin(GL_POLYGON);
        glVertex2d (0,1000);
        glVertex2d (1500,1000);

        glColor3ub (0,0,0);
        glVertex2d (1500,0);
        glVertex2d (0,0);
        glEnd();
    }

}
