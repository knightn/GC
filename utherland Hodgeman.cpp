Q4. Write a program to clip a polygon using Sutherland Hodgeman algorithm.


#include <iostream>
#include <graphics.h>
#define round(a) ((int)(a+0.5))
using namespace std;
int xmin = 100, xmax = 500, ymin = 100, ymax = 500, arr[20], m;
int k;
void clipLeft(int x1, int y1, int x2, int y2) {
if (x2 - x1) {
m = (y2 - y1)/(x2 - x1);
}
else {
m = 10000;
}
if (x1 >= xmin && x2 >= xmin) {
arr[k] = x2;
arr[k+1] = y2;
k += 2;
}
if (x1 < xmin && x2 >= xmin) {
arr[k] = xmin;
arr[k+1] = y1 + m*(xmin - x1);
arr[k+2] = x2;
arr[k+3] = y2;
k+=4;
}
if (x1 >= xmin && x2 < xmin) {
arr[k] = xmin;
arr[k+1] = y1 + m*(xmin - x1);
k += 2;
}
}
void clipTop(int x1, int y1, int x2, int y2) {
if (y2 - y1) {
m = (x2 - x1)/(y2 - y1);
}
else {
m = 10000;
}
if (y1<=ymax && y2 <= ymax) {
arr[k] = x2;
arr[k+1] = y2;
k += 2;
}
if (y1 > ymax && y2 <= ymax) {
arr[k] = x1 + m*(ymax - y1);
arr[k+1] = ymax;
arr[k+2] = x2;
arr[k+3] = y2;
k += 4;
}
if (y1 <= ymax && y2 > ymax) {
arr[k] = x1 + m * (ymax - y1);
arr[k+1] = ymax;
k += 2;
}
}
void clipRight(int x1, int y1, int x2, int y2){
if(x2-x1){
m = (y2-y1)/(x2 -x1);
}
else{
m = 10000;
}
if(x1<=xmax && x2<= xmax){
arr[k] = x2;
arr[k+1]= y2;
k +=2;
}
if(x1>xmax && x2<=xmax){
arr[k]= xmax;
arr[k+1]= y1+m*(xmax-x1);
arr[k+2] = x2;
arr[k+3] = y2;
k +=4;
}
if(x1<=xmax && x2>xmax){
arr[k] = xmax;
arr[k+1] = y1 + m*(xmax- x1);
k +=2;
}
}
void clipBottom(int x1, int y1, int x2, int y2){
if(y2-y1){
m = (x2-x1)/(y2-y1);
}
else{
m = 10000;
}
if (y1>=ymin && y2 >= ymin) {
arr[k] = x2;
arr[k+1] = y2;
k += 2;
}
if (y1 >= ymin && y2 >= ymin) {
arr[k] = x1 + m*(ymin - y1);
arr[k+1] = ymin;
arr[k+2] = x2;
arr[k+3] = y2;
k += 4;
}
if (y1 >= ymax && y2 < ymin) {
arr[k] = x1 + m * (ymin - y1);
arr[k+1] = ymin;
k += 2;
}
}
int main() {
int poly[20];
int window1 = initwindow(800, 800);
int n, i;
cout << "Enter the number of edges: " << endl;
cin >> n;
cout << "Enter the coordinates: " << endl;
for (i = 0; i < 2 * n; i++)
cin>>poly[i];
poly[i] = poly[0];
poly[i+1] = poly[1];
rectangle(xmin, ymax, xmax, ymin);
fillpoly(n , poly);
delay(1000);
cleardevice();
k = 0;
for(i =0; i<2*n; i +=2)
clipLeft(poly[i], poly[i+1], poly[i+2], poly[i+3]);
n = k/2;
for(i = 0; i <k; i++)
poly[i]= arr[i];
poly[i]= poly[0];
poly[i+1]= poly[1];
k = 0;
for(int i =0; i<2*n; i +=2)
clipRight(poly[i], poly[i+1], poly[i+2], poly[i+3]);
n = k/2;
for(int i = 0; i <k; i++)
poly[i]= arr[i];
poly[i]= poly[0];
poly[i+1]= poly[1];
k = 0;
for(int i =0; i<2*n; i +=2)
clipBottom(poly[i], poly[i+1], poly[i+2], poly[i+3]);
for(int i = 0; i <k; i++)
poly[i]= arr[i];
rectangle(xmin, ymax, xmax, ymin);
if(k)
fillpoly(k/2,poly);
system("pause");
return 0;
}
