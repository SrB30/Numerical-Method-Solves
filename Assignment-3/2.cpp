#include<bits/stdc++.h>
using namespace std;

double del[5][5];
double x[5],y[5];

void forwardDiff()
{
	for(int i=0; i<5; i++)	del[0][i] = y[i];
		
	for(int i=1; i<5; i++)
	{
		for(int j=0; j<5-i; j++)
			del[i][j] = del[i-1][j+1]-del[i-1][j];
	}
}

double cal1stOrder(double u, double h)
{
	return (1/h) * (del[1][0] + (((2*u-1)/2)*del[2][0]) + (((3*u*u-6*u+2)/6)*del[3][0]) + (((4*u*u*u-18*u*u+22*u-6)/24)*del[4][0]));
}

double cal2ndOrder(double u, double h)
{
	return (1/(h*h)) * (del[2][0] + ((u-1)*del[3][0]) + (((12*u*u-36*u+22)/24)*del[4][0]));
}
int main()
{
	cout << "Enter the x values: ";
	for(int i=0; i<5; ++i) cin >> x[i];
	cout << "Enter the y values: ";
	for(int i=0; i<5; i++) cin >> y[i];

	double xp;
	cout << "Enter the point: ";
	cin >> xp;	//xp=1.5

	forwardDiff();

	double h = x[1]-x[0];
	double u = (xp-x[0])/h;
	cout << "1st order derivative = "<< cal1stOrder(u,h) << endl << "2nd order derivative = " << cal2ndOrder(u,h) << endl;
	return 0;
}
/*
1 2 3 4 5
1 8 27 64 125
1.5
*/
