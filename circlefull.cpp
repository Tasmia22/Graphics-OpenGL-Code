#include<graphics.h>
#include<stdio.h>
int main(void)
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm," ");
    int xm,ym,x,y,d,r;
    printf("Enter value of radius\n");
    scanf("%d",&r);
    //Axis
    xm=getmaxx()/2;
    ym=getmaxy()/2;
    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);
//circle

    x=0;
    y=r;
    d=3-(2*r);

    while(x<=y)
    {
        putpixel(x+xm,ym-y,YELLOW);

        if(d<0)
        {
            d=d+4*x+6;
        }
        else
        {
            d=d+4*(x-y)+10;
            y--;
        }

        x++;
    }

    delay(10);
    getch();
    closegraph();
}
