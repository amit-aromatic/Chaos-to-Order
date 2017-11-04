//	That order eventually comes out of chaos...

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include"graphics.cpp"

#define SPEED 0.37

int meanofia(int a[],int n)  // mean(arrayname,arraysize)
{                             //returns arith. mean of elements of a[]
 int t=0;
for(int i=0;i<n;i++)
{
t+=a[i];
}

return (t/n);
}

int maxinarray(int a[],int n)
{
 int m=0;
 for (int i=1;i<n;i++)
  if (a[i]>a[m]) m=i;
 return a[m];
}

int mininarray(int a[],int n)
{
 int m=0;
 for (int i=1;i<n;i++)
  if (a[i]<a[m]) m=i;
 return a[m];
}


void main()
{
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax,x[20],y[20];
   int meanx,meany;

   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   errorcode = graphresult();

   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   setcolor(getmaxcolor());
   xmax = getmaxx();
   ymax = getmaxy();
   /////////////////////////////////////////////////////////////
   cleardevice();
   setcolor(YELLOW);

   cout<<"\n\t\t\tTHE WORLD IS AN ELLIPSE\n\n\t` Heard melodies are sweet, but those unheard are sweeter '\n\n\n\n\n\tIf a polygon is drawn with random sides, and from this polygon if a new polygon is derived by joining MID POINTS of its sides, and the process is \ncontinued so on, then an ellipse like figure will always result eventually.\n\n\n\tThis is a perfect example of order coming out of chaos.\n\n\n\tThis computer program generates a RANDOM starting polygon and animates \nsubsequent iterations to show the effect.\n\n\tSince the figure keeps on becoming small, I've incorporated AUTO-ZOOM to enlarge it when needed. This may make animation look discontinuous at times.\n\n\tI've assumed no. of sides as 20, but it works with any no. of sides.\n\n\t\t\t\t\t\t- Amit Bhola\n\n\n\tPRESS ANY KEY TO SEE STARTING POLYGON\n\tTHEN PRESS ANY KEY TO START ANIMATION\n\tTHEN PRESS ANY KEY TO STOP IT AND EXIT";
   getch();
   cleardevice();
   randomize();
   char ch;

   for(int i=0;i<20;i++)
    {
     x[i]=random(xmax/2)+xmax/8;
     y[i]=random(ymax/2)+ymax/8;
    }

   x[19]=x[0];
   y[19]=y[0];

     meanx=meanofia(x,20);
     meany=meanofia(y,20);

     for( i=0;i<20;i++)
      {
       x[i]=x[i]-(meanx-xmax/2);
       y[i]=y[i]-(meany-ymax/2);
      }
   for(i=0;i<19;i++)
    {
     line(x[i],y[i],x[i+1],y[i+1]);
    }

   getch();

  while (!kbhit() )
  {

   for(i=0;i<19;i++)
    {
     line(x[i],y[i],x[i+1],y[i+1]);
    }
   for(int i=0;i<20;i++)
    {
     x[i]= (x[i]+x[i+1])/2;
     y[i]= (y[i]+y[i+1])/2;
    }
   x[19]=x[0];
   y[19]=y[0];

   if(
      ((maxinarray(x,20) - mininarray(x,20) < xmax/10 )  ||
       (maxinarray(y,20) - mininarray(y,20) < ymax/10 )     )   &&!
      ((maxinarray(x,20) - mininarray(x,20) > xmax/5 )  ||
       (maxinarray(y,20) - mininarray(y,20) > ymax/5 )     )
     )
    {

     for( i=0;i<20;i++)
      {
       x[i]=x[i]*5;
       y[i]=y[i]*5;
      }

     //meanx=meanofia(x,20);
     //meany=meanofia(y,20);
     //note: so mathematically mean x is now midpointx, i.e. center of the figure
     meanx=(maxinarray(x,20)+mininarray(x,20))/2;
     meany=(maxinarray(y,20)+mininarray(y,20))/2;

     for( i=0;i<20;i++)
      {
       x[i]=x[i]-(meanx-xmax/2);
       y[i]=y[i]-(meany-ymax/2);
      }
    }
   waitp(SPEED);
   cleardevice();
  }

   //getch();
   closegraph();
}

