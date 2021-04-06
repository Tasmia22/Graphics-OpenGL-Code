#include <iostream>
#include<stdio.h>
#include<graphics.h>
#include <conio.h>
using namespace std;
int main()
{
    int gd = DETECT,gm;
    int xm,ym;
    int xmin,xmax,ymin,ymax,h,k;
    int ax,ay,bx,by;
    int bita1,bita2,bita3,bita4;
    int bitb1,bitb2,bitb3,bitb4;
    initgraph(&gd,&gm,"C:\\tc\\bgi");

    h=getmaxx()/2;
    k=getmaxy()/2;
    line(0,k,2*h,k);
    line(h,0,h,2*k);

    xmin=10,xmax=190;
    ymin=20,ymax=180;
    ax=60,ay=60,bx=180,by=210;

        setcolor(GREEN);
    delay(1000);
    line(h+xmin,k-ymin,h+xmax,k-ymin);

    setcolor(RED);
    delay(1000);
    line(h+xmin,k-ymin,h+xmin,k-ymax);

    setcolor(BLUE);
    delay(1000);
    line(h+xmin,k-ymax,h+xmax,k-ymax);



    setcolor(YELLOW);
    delay(1000);
    line(h+xmax,k-ymax,h+xmax,k-ymin);


    setcolor(BROWN);
    delay(1000);
    line(h+ax,k-ay,h+bx,k-by);

    bita1=ay-ymax;
    bita2=ymin-ay;
    bita3=ax-xmax;
    bita4=xmin-ax;

    if(bita1<0)
        bita1=0;
    else
        bita1=1;

    if(bita2<0)
        bita2=0;
    else
        bita2=1;

    if(bita3<0)
        bita3=0;
    else
        bita3=1;

    if(bita4<0)
        bita4=0;
    else
        bita4=1;


    bitb1=by-ymax;
    bitb2=ymin-by;
    bitb3=bx-xmax;
    bitb4=xmin-bx;


    if(bitb1<0)
        bitb1=0;
    else
        bitb1=1;

    if(bitb2<0)
        bitb2=0;
    else
        bitb2=1;

    if(bitb3<0)
        bitb3=0;
    else
        bitb3=1;

    if(bitb4<0)
        bitb4=0;
    else
        bitb4=1;


    if((bita1==0 && bita2==0 && bita3==0 && bita4==0)&&(bitb1==0 && bitb2==0 && bitb3==0 && bitb4==0))
        cout<<"Visible"<<endl;
    else if(((bita1==bitb1)&&(bita1==1))||((bita2==bitb2)&&(bita2==1))||((bita3==bitb3)&&(bita3==1))||((bita4==bitb4)&&(bita4==1)))
        cout<<"Not visible"<<endl;
    else
    {
        cout<<"Candidate for clipping"<<endl;
        cout<<"Clipping points"<<endl;
        if(bitb1==1)
        {
            double cx,cy,m,d;
            m=(double(by)-double(ay))/(double(bx)-double(ax));
            cy=ymax;
            d=(double(ymax)-double(by));
            cx=double(bx)+d/m;

            putpixel(h+cx,k-cy,YELLOW);
            setcolor(BLACK);
            delay(2000);
            line(h+cx,k-cy,h+bx,k-by);
        }
        if(bitb2==1)
        {
            double cx,cy,m,d;
            m=(double(by)-double(ay))/(double(bx)-double(ax));
            cy=ymin;
            d=(double(ymin)-double(by));
            cx=double(bx)+d/m;
            cout<<"(x,y):("<<cx<<","<<cy<<")"<<endl;
            putpixel(h+cx,k-cy,YELLOW);
            setcolor(BLACK);
            delay(1000);
            line(h+cx,k-cy,h+bx,k-by);
        }

        if(bitb3==1)
        {
            double cx,cy,m,d;
            m=(double(by)-double(ay))/(double(bx)-double(ax));
            cy=xmax;
            d=(double(xmax)-double(bx));
            cx=double(by)-(m*d);

            cout<<"(x,y):("<<cx<<","<<cy<<")"<<endl;
            putpixel(h+cx,k-cy,YELLOW);
            setcolor(BLACK);
            delay(1000);
            line(h+cx,k-cy,h+bx,k-by);
        }

        if(bitb4==1)
        {
            double cx,cy,m,d;
            m=(double(by)-double(ay))/(double(bx)-double(ax));
            cy=xmin;
            d=(double(xmin)-double(bx));
            cx=double(by)-(m*d);

            cout<<"(x,y):("<<cx<<","<<cy<<")"<<endl;
            putpixel(h+cx,k-cy,YELLOW);
            setcolor(BLACK);
            line(h+cx,k-cy,h+bx,k-by);
        }


    }


    getch();
    closegraph();


}




