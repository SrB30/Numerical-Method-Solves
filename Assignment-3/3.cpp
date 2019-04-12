#include<bits/stdc++.h>
using namespace std;

const int mx = 1000;
double y[mx];

void calDel(double a,double b,double h, int n)
{
	for(int i=0; i<=n; i++)
	{
		double x = a+i*h;
		y[i] = 5*log10(x);
//		cout << x << " " << y[i] << " " << log10(x) << " ";
	}
}

double trapezoid(double h,int n)
{
	double I=0;
	for(int i=1;i<n;i++) I += y[i];
	I += (h/2) * (y[0]+2*I+y[n]);
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

	if(a<1 || b<1 || b<a){
		cout << "the entered interval limit [a,b] is not valid" << endl; return 0;
	}

	double h = (b-a)/(n*1.0);
	calDel(a,b,h,n);
	cout << "The approximiate area is = " << trapezoid(h,n) << endl;

	return 0;
}
/*
1 100
10
*/