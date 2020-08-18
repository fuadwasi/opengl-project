
int light_color[3][9]={
                    {255,255,255,255,255,255,255,0,0},
                    {255,255,255,255,255,0,255,255,255},
                    {0,255,0, 255,255,255, 255,255,255},
                    };




void light_draw(int x,int y,int y2,int color_index){


        glColor3ub (0,0,0);
        glBegin(GL_POLYGON);
        glVertex2d (x,y+75);
        glVertex2d (x+25,y+75);
        glVertex2d (x+25,y);
        glVertex2d (x,y);
        glEnd();

        glColor3ub (0,0,0);
        glBegin(GL_POLYGON);
        glVertex2d (x+10,y+75);
        glVertex2d (x+15,y+75);
        glVertex2d (x+15,y2);
        glVertex2d (x+10,y2);
        glEnd();


    int y1 =y+73;
    int gap=23;
    int color_count=0;
    for(int i=0;i<3;i++){

    glColor3ub (light_color[color_index][color_count],light_color[color_index][color_count+1],light_color[color_index][color_count+2]);
    color_count+=3;
    //printf("%d %d %d\n", i,i+1,i+2);
    glBegin(GL_POLYGON);
    int r=8;
    int p=1-r,cx=0, cy=r;

    int dx=x+12,dy=y1-10-2;
    while((cx<=cy))
    {

        cx=cx+1;

        if(p<0)
        {
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
    y1-=gap;
    }


}

