#include<graphics.h>
#include<stdio.h>
int main(void)
{
    int gd=DETECT,gm;
     initgraph(&gd,&gm,"");
    int xm,ym;
    xm=getmaxx()/2;
     ym=getmaxy()/2;
    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);

    int x1=20, y1=50;
    int x2=150;
    int x=x1; int y=y1;

    do
    {
        putpixel(x+xm,ym-y,YELLOW);
        x++;
    }while(x<=x2);
    delay(10);
    getch();
    closegraph();

}
