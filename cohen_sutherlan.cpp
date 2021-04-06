#include<graphics.h>
#include <iostream>
using namespace std;

const int INSIDE = 0,LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;

const int x_max = 200;
const int y_max = 180;
const int x_min = 50;
const int y_min = 50;


// Function to compute region code for a point(x, y)
int computeCode(double x, double y)
{
    // initialized as being inside
    int code = INSIDE;

    if (x < x_min)	 // to the left of rectangle
        code =code| LEFT;
    else if (x > x_max) // to the right of rectangle
        code |= RIGHT;
    if (y < y_min)	 // below the rectangle
        code |= BOTTOM;
    else if (y > y_max) // above the rectangle
        code |= TOP;

    return code;
}

// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
void cohenSutherlandClip(double x1, double y1,
                         double x2, double y2)
{
    int code1 = computeCode(x1, y1);                                 // Compute region codes for P1, P2
    int code2 = computeCode(x2, y2);

    // Initialize line as outside the rectangular window
    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;                        // If both endpoints lie within rectangle
            break;
        }
        else if (code1 & code2)            //and of them is not 0000
        {
            break;                                    // If both endpoints are outside rectangle,in same region
        }

        else
        {
            int code_out;
            double x, y;
            // At least one endpoint is outside the   rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point;                      // using formulas y = y1 + slope * (x - x1),     x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);             // point is above the clip rectangle
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {

                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);       // point is below the rectangle
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);                        // point is to the right of rectangle
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);                          // point is to the left of rectangle
                x = x_min;
            }

            // Now intersection point x,y is found
            // We replace point outside rectangle  by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout <<"Line accepted from " << x1 << ", "
             << y1 << " to "<< x2 << ", " << y2 << endl;
        // Here the user can add code to display the rectangle
        // along with the accepted (portion of) lines
    }
    else
        cout << "Line rejected" << endl;
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm," ");
    int xm,ym;//Axis
    xm=getmaxx()/2;
    ym=getmaxy()/2;
    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);

    rectangle(x_min+xm,ym-y_max,x_max+xm,ym-y_min);
    cohenSutherlandClip(5, 5, 7, 7);          // P11 = (5, 5), P12 = (7, 7)
    cohenSutherlandClip(7, 9, 11, 4);         // P21 = (7, 9), P22 = (11, 4)
    cohenSutherlandClip(1, 5, 4, 1);               // P31 = (1, 5), P32 = (4, 1)
    delay(10);
    getch();
    closegraph();
    return 0;
}

