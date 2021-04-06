#include<stdio.h>
#include<graphics.h>
int main()
{
    int  gm=DETECT,gd;
     initgraph(&gm,&gd," ");

 int xm,ym,x1,y1,x,y,x2,y2;
     xm=getmaxx()/2;
     ym=getmaxy()/2;
    printf("xm=%d ym=%d",xm,ym);

    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);


    x1=50;y1=-50,y2=50;
    x=x1;y=y1;
    do{

          putpixel(x+xm,ym-y,YELLOW);
          y++;


    }while(y<=y2);

    getch();
    closegraph();
    return 0;
}
