#include<bits/stdc++.h>

#define PI acos(-1.0)
#define toradian(degree) (PI*degree)/180
#define todegree(radian) (radian*180)/PI
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI
using namespace std;


const int mx = 1000;
double y[mx];

void calDel(double a,double b,double h, int n)
{
	for(int i=0; i<=n; i++)
	{
		double x = a+i*h;
		y[i] = (PI/2)* exp(todegree(sinD(x)));
	}
}

double simpson13(double h,int n)
{
	double I=0,s1=0,s2=0;
	for(int i=1;i<n;i+=2) s1 += y[i];
	for(int i=2;i<n-1;i+=2) s2 += y[i];
	I += (h/3) * (y[0]+ 4*s1 + 2*s2 +y[n]);
	return I;
}

int main()
{
	double a,b;
	int n;
	cout << "lower & upper limit, a & b : ";
	cin >> a >>b;
	cout << "Number of intervals, n: ";
	cin >> n;

	if(b<a){
		cout << "the entered interval limit [a,b] is not valid" << endl; return 0;
	}

	double h = (b-a)/(n*1.0);
	calDel(a,b,h,n);
	cout << "The approximiate area is = " << simpson13(h,n) << endl;

	return 0;
}
/*
1 10
10
*/