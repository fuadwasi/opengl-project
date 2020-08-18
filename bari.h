int building_color[6][3]={
                        {249,240,128},
                        {83,225,178},
                        {141,198,63},
                        {241,90,41},
                        {155,133,121},
                        {255,242,125},
                        };
int window_weidth[]={84,62};
int window_column[]={3,4};



void bari_draw(int x, int y,int ind)
{

    glColor3ub (building_color[ind][0],building_color[ind][1],building_color[ind][2]);
    glBegin(GL_POLYGON);
    glVertex2d (0+x,610);
	glVertex2d (250+x,610);
	glVertex2d (250+x,610-y);
	glVertex2d (0+x,610-y);
    glEnd();

    int window_row=y/50;
    int win_in=ind;
    for(int w=1;w<=window_row;w++)
    {
        glColor3ub (building_color[ind][0]-20,building_color[ind][1]-20,building_color[ind][2]-20);
        glLineWidth(4.0);
        glBegin(GL_LINES);
        glVertex2d (x,610-w*50);
        glVertex2d (x+250,610-w*50);
        glEnd();
        int win_len=window_weidth[win_in%2];


        for(int win_col=1;win_col<window_column[win_in%2];win_col++)
        {

            glBegin(GL_LINES);
            glVertex2d (x+win_len,610-(w-1)*50);
            glVertex2d (x+win_len,610-w*50);
            win_len+=window_weidth[win_in%2];
            glEnd();
        }
        win_in++;

    }

}

