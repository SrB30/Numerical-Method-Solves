#include<bits/stdc++.h>
using namespace std;

double x[6],y[6];
double xi,yi,xi2,xy;
double a,b;

void calculateSums()
{
	for (int i = 1; i < 6; ++i)
	{
		xi += x[i];
		yi += y[i];
		xi2 += x[i]*x[i];
		xy += x[i]*y[i];
	}
}

void calculateLine(int n)
{
	calculateSums();

	b = ((n*xy - xi*yi)/(n*xi2 - xi*xi));
	a = (yi/n) - b*(xi/n);
}

int main()
{
	cout << "X values are : ";
	for (int i = 1; i < 6; ++i)	cin >> x[i];
	cout << "Y values are : ";
	for (int i = 1; i < 6; ++i)	cin >> y[i];

	calculateLine(5);
	cout << "The line is = " << a << " + " << b << "x" << endl;
	return 0;
}
