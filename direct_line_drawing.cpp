#include<graphics.h>
#include<stdio.h>
int main(void)
{
    int gd=DETECT,gm;
     initgraph(&gd,&gm,"");
    int xm,ym,x1,y1,x2,y2,x,y;
    float m,b;
    xm=getmaxx()/2;
     ym=getmaxy()/2;
    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);

     x1=20; y1=20;
     x2=150; y2=-80;


      m=1.0*(y2-y1)/(x2-x1);
     b=y1-m*x1;
     x=x1;  y=y1;
 if(abs(m)<1)
     {

    do
    {
        putpixel(x+xm,ym-y,YELLOW);
        x++;
        y=int(m*x+b);
    }while(x<=x2);

     }
     else  if(abs(m)>1)
     {
         do
    {
        putpixel(x+xm,ym-y,YELLOW);
        y++;
        x=int((y-b)/m);
    }while(y<=y2);
     }
    delay(10);
    getch();
    closegraph();

}
