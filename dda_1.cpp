#include<graphics.h>
#include<stdio.h>
int main(void)
{
    int gd=DETECT,gm;
     initgraph(&gd,&gm,"");
    int xm,ym,x1,y1,x2,y2,x,y;
    float m,b,z;
    xm=getmaxx()/2;
     ym=getmaxy()/2;
    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);

     x1=10; y1=20;
     x2=60; y2=30;


      m=1.0*(y2-y1)/(x2-x1);
     //b=y1-m*x1;
     x=x1;  y=y1;
     z=y1;
     do{
         putpixel(x+xm,ym-y,YELLOW);
         x++;
         z=z+m;
         y=int (z);

        }while(x<=x2);
        getch();
        delay(10);
        closegraph();
        return 0;
}
