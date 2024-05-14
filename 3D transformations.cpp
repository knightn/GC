Q7. Write a program to apply various 3D transformations on a 3D object and then apply parallel and perspective projection on it.

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
int gm;
int gd=DETECT;
int x1,x2,x3,y1,y2,y3,z1,z2,z3,nx1,nx2,nx3,ny1,ny2,ny3,nz1,nz2,nz3,c;
int tx, ty, tz, sx, sy, sz, rx, ry, rz;
float theta_x, theta_y, theta_z, shear_xy, shear_xz, shear_yx, shear_yz, shear_zx, shear_zy;
initgraph(&gd,&gm,"c:\\tc\\bg:");
cout<<"\t Program for basic 3D transformations :";
cout<<"\n\t Enter the points of triangle (x, y, z):\n";
cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3;
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);
cout<<("\n 1. Translation\n 2. Rotation\n 3. Scaling\n 4. Reflection\n 5. Shearing\n 6.
Exit");
cout<<"\nEnter your choice:";
cin>>c;
switch(c)
{
case 1:
cout<<"\n Enter the translation factors (tx, ty, tz): ";
cin>>tx>>ty>>tz;
nx1=x1+tx;
ny1=y1+ty;
nz1=z1+tz;
nx2=x2+tx;
ny2=y2+ty;
nz2=z2+tz;
nx3=x3+tx;
ny3=y3+ty;
nz3=z3+tz;
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
break;
case 2:
cout<<"\n Enter the rotation angles (theta_x, theta_y, theta_z): ";
cin>>theta_x>>theta_y>>theta_z;
theta_x = (theta_x * 3.14) / 180;
theta_y = (theta_y * 3.14) / 180;
theta_z = (theta_z * 3.14) / 180;
nx1 = x1*cos(theta_y)*cos(theta_z) +
x2*(sin(theta_x)*sin(theta_y)*cos(theta_z)-cos(theta_x)*sin(theta_z)) +
x3*(cos(theta_x)*sin(theta_y)*cos(theta_z)+sin(theta_x)*sin(theta_z));
ny1 = y1*cos(theta_y)*cos(theta_z) +
y2*(sin(theta_x)*sin(theta_y)*cos(theta_z)-cos(theta_x)*sin(theta_z)) +
y3*(cos(theta_x)*sin(theta_y)*cos(theta_z)+sin(theta_x)*sin(theta_z));
nz1 = z1*cos(theta_y)*cos(theta_z) +
z2*(sin(theta_x)*sin(theta_y)*cos(theta_z)-cos(theta_x)*sin(theta_z)) +
z3*(cos(theta_x)*sin(theta_y)*cos(theta_z)+sin(theta_x)*sin(theta_z));
nx2 = x1*cos(theta_y)*sin(theta_z) +
x2*(sin(theta_x)*sin(theta_y)*sin(theta_z)+cos(theta_x)*cos(theta_z)) +
x3*(cos(theta_x)*sin(theta_y)*sin(theta_z)-sin(theta_x)*cos(theta_z));
ny2 = y1*cos(theta_y)*sin(theta_z) +
y2*(sin(theta_x)*sin(theta_y)*sin(theta_z)+cos(theta_x)*cos(theta_z)) +
y3*(cos(theta_x)*sin(theta_y)*sin(theta_z)-sin(theta_x)*cos(theta_z));
nz2 = z1*cos(theta_y)*sin(theta_z) +
z2*(sin(theta_x)*sin(theta_y)*sin(theta_z)+cos(theta_x)*cos(theta_z)) +
z3*(cos(theta_x)*sin(theta_y)*sin(theta_z)-sin(theta_x)*cos(theta_z));
nx3 = x1*-sin(theta_y) + x2*sin(theta_x)*cos(theta_y) +
x3*cos(theta_x)*cos(theta_y);
ny3 = y1*-sin(theta_y) + y2*sin(theta_x)*cos(theta_y) +
y3*cos(theta_x)*cos(theta_y);
nz3 = z1*-sin(theta_y) + z2*sin(theta_x)*cos(theta_y) +
z3*cos(theta_x)*cos(theta_y);
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
break;
case 3:
cout<<"\n Enter the scaling factors (sx, sy, sz): ";
cin>>sx>>sy>>sz;
nx1=x1*sx;
ny1=y1*sy;
nz1=z1*sz;
nx2=x2*sx;
ny2=y2*sy;
nz2=z2*sz;
nx3=x3*sx;
ny3=y3*sy;
nz3=z3*sz;
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
break;
case 4:
cout<<"\n Reflection about XY-plane";
nx1 = x1;
ny1 = y1;
nz1 = -z1;
nx2 = x2;
ny2 = y2;
nz2 = -z2;
nx3 = x3;
ny3 = y3;
nz3 = -z3;
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
break;
case 5:
cout<<"\n Shearing along X-axis: ";
cout<<"\n Enter the shearing factors (shear_xy, shear_xz): ";
cin>>shear_xy>>shear_xz;
nx1 = x1 + shear_xy * y1 + shear_xz * z1;
ny1 = y1;
nz1 = z1;
nx2 = x2 + shear_xy * y2 + shear_xz * z2;
ny2 = y2;
nz2 = z2;
nx3 = x3 + shear_xy * y3 + shear_xz * z3;
ny3 = y3;
nz3 = z3;
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
break;
case 6:
break;
default:
cout<<"Enter the correct choice";
}
getch();
closegraph();
}
