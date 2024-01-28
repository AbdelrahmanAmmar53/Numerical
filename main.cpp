#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

/* In this example we are solving
   x + 5y - z = 10
   x +y + 8z = 20
   4x + 2y +z = 14
*/
/* Arranging given system of linear
   equations in diagonally dominant
   form:
    4x + 2y +z = 14
   x + 5y - z = 10
    x + y + 8z = 20
*/
/* Equations:
   x = (-2y-z+14)/4
   y = (-x+z+10)/5
   z = (-x-y+20)/8
*/
/* Defining function */
#define f1(x,y,z)  (-2*y-z+14)/4
#define f2(x,y,z)  (-x+z+10)/5
#define f3(x,y,z)  (-x-y+20)/8



/* Main function */
int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int step=1;

 /* Setting precision and writing floating point values in fixed-point notation. */
 cout<< setprecision(6)<< fixed;

 /* Input */
 /* Reading tolerable error */
 cout<<"Enter tolerable error: ";
 cin>>e;

 cout<< endl<<"Count\tx\t\ty\t\tz"<< endl;

 do
 {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);

  cout<< step<<"\t"<< x1<<"\t"<< y1<<"\t"<< z1<< endl;

  /* Error */
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  step++;

  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;

 }while(e1>e && e2>e && e3>e);

 cout<< endl<<"Solution: x = "<< x1<<", y = "<< y1<<" and z = "<< z1;

}
