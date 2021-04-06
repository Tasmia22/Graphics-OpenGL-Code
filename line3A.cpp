#include<stdio.h>
#include<graphics.h>
int main()
{
    int  gm=DETECT,gd;
    initgraph(&gm,&gd," ");
    int xm,ym,x1,x2,y1,y2,dx,dy,w,z,x,y,p;
    xm=getmaxx()/2;
    ym=getmaxy()/2;
    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);
    // printf("xm=%d ym=%d",xm,ym);
    x1=20,y1=20,x2=150,y2=50;
    dx=x2-x1;
    dy=y2-y1;
    w=2*dx;
    z=2*dy;
    p=z-dx;
    x=x1;y=y1;
    do
    {
        putpixel(x+xm,ym-y,YELLOW);
        if(p<0)
        {
            p=p+z;
            x++;
        }
        else
        {
            p=p+z-w;
            x++;
            y++;
        }
    }
    while(x<=x2);
    getch();
    delay(10);
    closegraph();
    return 0;
}
