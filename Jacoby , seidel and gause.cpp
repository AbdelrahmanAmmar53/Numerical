#include<iostream>
#include<iomanip>
#include<math.h>

#define f1(x,y,z)  (17-y+2*z)/20
#define f2(x,y,z)  (-18-3*x+z)/20
#define f3(x,y,z)  (25-2*x+3*y)/20

#define f4(x,y,z)  (-2*y-z+14)/4
#define f5(x,y,z)  (-x+z+10)/5
#define f6(x,y,z)  (-x-y+20)/8

#define f7(x,y,z)  (13-z)/3
#define f8(x,y,z)  (7+2*x)/3
#define f9(x,y,z)  (-9+x+3*y)/10
using namespace std;
void JacobiMethod1(float &x0,float &y0,float &z0,float &x1,float &y1,float &z1,float &e1,float &e2,float &e3,float &e,int &step)
{
 cout<<"This is Jacobi Method"<<endl<<"Count\tx\t\ty\t\tz"<< endl;
 do
 {
  x1 = f1(x0,y0,z0);
  y1 = f2(x0,y0,z0);
  z1 = f3(x0,y0,z0);
  cout<< step<<"\t"<< x1<<"\t"<< y1<<"\t"<< z1<< endl;
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);
  step++;
  x0 = x1;
  y0 = y1;
  z0 = z1;
 }while(e1>e && e2>e && e3>e);
 cout<< endl<<"Solution: x = "<< x1<<", y = "<< y1<<" and z = "<< z1;
}
void SeidelMethod1(float &x0,float &y0,float &z0,float &x2,float &y2,float &z2,float &e4,float &e5,float &e6,float &e,int &step)
{
    cout<< "By Gauss elemation:-"<<endl;
    double N[3][3] = {20,17,-2,3,20,-1,2,-3,20};
    double M[3] = {17,-18,25};
    for (int k = 0; k < 3; k++)
    {
        for (int i = k + 1; i < 3; i++)
        {
            double factor = N[i][k] / N[k][k];
            for (int j = k; j < 3; j++)
            {
                N[i][j] -= factor * N[k][j];
            }
            M[i] -= factor * M[k];
        }
    }
    double x[3];
    for (int i = 2; i >= 0; i--)
        {
        x[i] = M[i];
        for (int j = i + 1; j < 3; j++)
        {
            x[i] -= N[i][j] * x[j];
        }
        x[i] /= N[i][i];
    }
    cout << "Solution for the system of equations:" <<endl;
    cout << "x = " << x[0] <<endl;
    cout << "y = " << x[1] <<endl;
    cout << "z = " << x[2] <<endl;
    x0=0;
    y0=0;
    z0=0;
    step=1;
 cout<<"By Seidel Method"<<endl<<"Count\tx\t\ty\t\tz"<< endl;
 do
 {
  x2 = f1(x0,y0,z0);
  y2 = f2(x2,y0,z0);
  z2 = f3(x2,y2,z0);
  cout<<step<<"\t"<< x2<<"\t"<< y2<<"\t"<< z2<< endl;
  e4 = fabs(x0-x2);
  e5 = fabs(y0-y2);
  e6 = fabs(z0-z2);
  step++;;
  x0 = x2;
  y0 = y2;
  z0 = z2;
 }while(e4>e && e5>e && e6>e);
 cout<<endl<<"Solution: x = "<< x2<<", y = "<< y2<<" and z = "<< z2;
}

void JacobiMethod2(float &x0,float &y0,float &z0,float &x1,float &y1,float &z1,float &e1,float &e2,float &e3,float &e,int &step)
{
 cout<<"This is Jacobi Method"<<endl<<"Count\tx\t\ty\t\tz"<< endl;
 do
 {
  x1 = f4(x0,y0,z0);
  y1 = f5(x0,y0,z0);
  z1 = f6(x0,y0,z0);
  cout<< step<<"\t"<< x1<<"\t"<< y1<<"\t"<< z1<< endl;
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);
  step++;
  x0 = x1;
  y0 = y1;
  z0 = z1;
 }while(e1>e && e2>e && e3>e);
 cout<< endl<<"Solution: x = "<< x1<<", y = "<< y1<<" and z = "<< z1;
}
void SeidelMethod2(float &x0,float &y0,float &z0,float &x2,float &y2,float &z2,float &e4,float &e5,float &e6,float &e,int &step)
{
    cout<< "By Gauss elemation:-"<<endl;
    double N[3][3] = {4,2,1,1,5,-1,1,1,8};
    double M[3] = {14,10,20};
    for (int k = 0; k < 3; k++)
    {
        for (int i = k + 1; i < 3; i++)
        {
            double factor = N[i][k] / N[k][k];
            for (int j = k; j < 3; j++)
            {
                N[i][j] -= factor * N[k][j];
            }
            M[i] -= factor * M[k];
        }
    }
    double x[3];
    for (int i = 2; i >= 0; i--)
        {
        x[i] = M[i];
        for (int j = i + 1; j < 3; j++)
        {
            x[i] -= N[i][j] * x[j];
        }
        x[i] /= N[i][i];
    }
    cout << "Solution for the system of equations:" <<endl;
    cout << "x = " << x[0] <<endl;
    cout << "y = " << x[1] <<endl;
    cout << "z = " << x[2] <<endl;
    x0=0;
    y0=0;
    z0=0;
    step=1;
 cout<<"By Seidel Method"<<endl<<"Count\tx\t\ty\t\tz"<< endl;
 do
 {
  x2 = f4(x0,y0,z0);
  y2 = f5(x2,y0,z0);
  z2 = f6(x2,y2,z0);
  cout<<step<<"\t"<< x2<<"\t"<< y2<<"\t"<< z2<< endl;
  e4 = fabs(x0-x2);
  e5 = fabs(y0-y2);
  e6 = fabs(z0-z2);
  step++;;
  x0 = x2;
  y0 = y2;
  z0 = z2;
 }while(e4>e && e5>e && e6>e);
 cout<<endl<<"Solution: x = "<< x2<<", y = "<< y2<<" and z = "<< z2;
}

void JacobiMethod3(float &x0,float &y0,float &z0,float &x1,float &y1,float &z1,float &e1,float &e2,float &e3,float &e,int &step)
{
 cout<<"This is Jacobi Method"<<endl<<"Count\tx\t\ty\t\tz"<< endl;
 do
 {
  x1 = f7(x0,y0,z0);
  y1 = f8(x0,y0,z0);
  z1 = f9(x0,y0,z0);
  cout<< step<<"\t"<< x1<<"\t"<< y1<<"\t"<< z1<< endl;
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);
  step++;
  x0 = x1;
  y0 = y1;
  z0 = z1;
 }while(e1>e && e2>e && e3>e);
 cout<< endl<<"Solution: x = "<< x1<<", y = "<< y1<<" and z = "<< z1;
}
void SeidelMethod3(float &x0,float &y0,float &z0,float &x2,float &y2,float &z2,float &e4,float &e5,float &e6,float &e,int &step)
{
    cout<< "By Gauss elemation:-"<<endl;
    double N[3][3] = {3,0,1,2,-3,0,1,3,-10};
    double M[3] = {13,-7,9};
    for (int k = 0; k < 3; k++)
    {
        for (int i = k + 1; i < 3; i++)
        {
            double factor = N[i][k] / N[k][k];
            for (int j = k; j < 3; j++)
            {
                N[i][j] -= factor * N[k][j];
            }
            M[i] -= factor * M[k];
        }
    }
    double x[3];
    for (int i = 2; i >= 0; i--)
        {
        x[i] = M[i];
        for (int j = i + 1; j < 3; j++)
        {
            x[i] -= N[i][j] * x[j];
        }
        x[i] /= N[i][i];
    }
    cout << "Solution for the system of equations:" <<endl;
    cout << "x = " << x[0] <<endl;
    cout << "y = " << x[1] <<endl;
    cout << "z = " << x[2] <<endl;
    x0=0;
    y0=0;
    z0=0;
    step=1;
 cout<<"By Seidel Method"<<endl<<"Count\tx\t\ty\t\tz"<< endl;
 do
 {
  x2 = f7(x0,y0,z0);
  y2 = f8(x2,y0,z0);
  z2 = f9(x2,y2,z0);
  cout<<step<<"\t"<< x2<<"\t"<< y2<<"\t"<< z2<< endl;
  e4 = fabs(x0-x2);
  e5 = fabs(y0-y2);
  e6 = fabs(z0-z2);
  step++;;
  x0 = x2;
  y0 = y2;
  z0 = z2;
 }while(e4>e && e5>e && e6>e);
 cout<<endl<<"Solution: x = "<< x2<<", y = "<< y2<<" and z = "<< z2;
}

int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 float x2,y2,z2,e4,e5,e6;
 int a,step=1;
 cout<< "select one of this three equations: \n 1)20X+17Y-2Z=17 \n 3X+20Y-Z=-18 \n 2X-3Y+20Z=25 "<<endl;
 cout<< "2) 4X+2Y+Z=14 \n X+5Y-Z=10 \n X+Y+8Z=20"<<endl;
 cout<< "3) 3X+Z=13 \n 2X-3Y=-7 \n X+3Y-10Z=9"<<endl;
 cin>> a;
 cout<< setprecision(6)<< fixed;
 cout<<"Enter tolerable error: ";
 cin>>e;
 if (a==1)
 {
     JacobiMethod1(x0,y0,z0,x1,y1,z1,e1,e2,e3,e,step);
     SeidelMethod1(x0,y0,z0,x2,y2,z2,e4,e5,e6,e,step);
 }
 else if(a==2)
 {
     JacobiMethod2(x0,y0,z0,x1,y1,z1,e1,e2,e3,e,step);
     SeidelMethod2(x0,y0,z0,x2,y2,z2,e4,e5,e6,e,step);

 }
 else if(a==3)
 {
   JacobiMethod3(x0,y0,z0,x1,y1,z1,e1,e2,e3,e,step);
   SeidelMethod3(x0,y0,z0,x2,y2,z2,e4,e5,e6,e,step);
 }
 else
    cout<< "ERROR you enter wrong number";
  return 0;
}
