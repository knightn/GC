Q8. Write a program to draw the Hermite/Bezier curve.

Bezier Curve
#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;
int main(){
int x[4], y[4], i, gd = DETECT, gm;
float u, px, py;
initgraph(&gd, &gm, "");
for (i = 0; i < 4; i++) {
cout << "Enter x and y coordinates: ";
cin >> x[i] >> y[i];
putpixel(x[i], y[i], 4);
}
for (u =0; u <= 1.0; u = u + 0.001) {
px = pow(1 - u, 3) * x[0] + 3*u*pow(1-u, 2) * x[1] + 3* pow(u, 2) * (1 - u) *
x[2] + pow(u, 3) * x[3];
py = pow(1 - u, 3) * y[0] + 3*u*pow(1-u, 2) * y[1] + 3* pow(u, 2) * (1 - u) *
y[2] + pow(u, 3) * y[3];
putpixel(px, py, 7);
}
getch();
return 0;
}


Hermite Curve
#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;
int main() {
int x[4], y[4], i, gd = DETECT, gm;
float t, px, py;
initgraph(&gd, &gm, "");
for (i = 0; i < 4; i++) {
cout << "Enter x and y coordinates: ";
cin >> x[i] >> y[i];
putpixel(x[i], y[i], 4);
}
for (t =0; t <= 1.0; t = t + 0.001) {
px = (2*pow(t,3)-3*pow(t,2) +1)*x[0] + (-2*pow(t,3)+3*pow(t,2))*x[1] +
(pow(t,3) -2*pow(t,2) + t)*x[2]+(pow(t,3)-pow(t,2))*x[3];
py = (2*pow(t,3)-3*pow(t,2) +1)*y[0] + (-2*pow(t,3)+3*pow(t,2))*y[1] +
(pow(t,3)-2*pow(t,2) + t)*y[2]+(pow(t,3)-pow(t,2))*y[3];
putpixel(px, py, 7);
}
getch();
return 0;
}
