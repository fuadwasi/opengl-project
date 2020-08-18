void star_draw(int x,int y){

     glColor3ub (255,255,255);
    glBegin(GL_POLYGON);
//	glVertex2d (x-5,y+8);
//	glVertex2d (x-20,y+9);
//	glVertex2d (x-10,y+23);
//	glVertex2d (x-13,y+37);
//	glVertex2d (x,y+30);
//	glVertex2d (x+13,y+37);
//	glVertex2d (x+10,y+23);
//	glVertex2d (x+20,y+9);
//	glVertex2d (x+5,y+8);
//    glVertex2d (x,y);

    glVertex2d (x-2,y+5);
	glVertex2d (x-10,y+6);
	glVertex2d (x-5,y+11);
	glVertex2d (x-6,y+18);
	glVertex2d (x,y+15);
	glVertex2d (x+6,y+18);
	glVertex2d (x+5,y+11);
	glVertex2d (x+10,y+6);
	glVertex2d (x+2,y+5);
    glVertex2d (x,y);
    glEnd();
}
