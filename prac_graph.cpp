#include<stdio.h>
#include<graphics.h>
int main()
{
    int  gm=DETECT,gd;
    initgraph(&gm,&gd," ");
    putpixel(50,100,YELLOW);
    line(100,50,200,50);
    getch();
    closegraph();
    return 0;
}
