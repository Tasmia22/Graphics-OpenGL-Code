#include<stdio.h>
#include<graphics.h>
int main()
{
    int  gm=DETECT,gd;
     initgraph(&gm,&gd," ");
    int xm,ym;
    xm=getmaxx()/2;
     ym=getmaxy()/2;
    printf("xm=%d ym=%d",xm,ym);

    putpixel(xm,ym,YELLOW);
    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);
    getch();
    closegraph();
    return 0;
}
