Q5. Write a program to fill a polygon using the Scan line fill algorithm.

#include <graphics.h>
#include <iostream>
using namespace std;
int main()
{
int n, i, j, k, gd, gm, dy, dx;
int x, y, temp;
int a[20][2], xi[20];
float slope[20];
int temp1 = 0;
cout << "\nEnter the number of edges ";
cin >> n;
for (i = 0; i < n; i++)
{
cout << "Enter the coordinate x" << i + 1 << " ";
cin >> a[i][0];
cout << "Enter the coordinate y" << i + 1 << " ";
cin >> a[i][1];
}
a[n][0] = a[0][0];
a[n][1] = a[0][1];
initgraph(&gd, &gm, NULL);
setcolor(YELLOW);
for (i = 0; i < n; i++)
{
line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
}
for (i = 0; i < n; i++)
{
dy = a[i + 1][1] - a[i][1];
dx = a[i + 1][0] - a[i][0];
if (dy == 0)
slope[i] = 1.0;
if (dx == 0)
slope[i] = 0.0;
if ((dy != 0) && (dx != 0))
{
slope[i] = (float)dx / dy;
}
}
for (y = 0; y < 400; y++)
{
k = 0;
for (i = 0; i < n; i++)
{
if (((a[i][1] <= y) && (a[i + 1][1] > y)) || ((a[i][1] > y) && (a[i + 1][1] <= y)))
{
xi[k] = (int)(a[i][0] + slope[i] * (y - a[i][1]));
k++;
}
}
for (j = 0; j < k; j++)
for (i = 0; i < k; i++)
{
if (xi[i] > xi[i + 1])
{
temp = xi[i];
xi[i] = xi[i + 1];
xi[i + 1] = temp;
}
}
setcolor(YELLOW);
for (i = 0; i < k; i += 2)
{
line(xi[i], y, xi[i + 1] + 1, y);
temp1 = i;
}
}
delay(7000);
return 0;
}
Q6.
