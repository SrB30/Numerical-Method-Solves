#include<bits/stdc++.h>
using namespace std;

double x[6],y[6];
double xi[4][4], tempA[4][4], con[4];
double a,b,c;

void calculateSums()
{
	xi[1][1] = 5;
	for (int i = 1; i < 6; ++i)
	{
		xi[1][2] += x[i];
		xi[2][1] = xi[1][2];

		xi[1][3] += x[i]*x[i];
		xi[2][2] = xi[3][1]= xi[1][3];

		xi[2][3] += x[i]*x[i]*x[i];
		xi[3][2] = xi[2][3];


		xi[3][3] += x[i]*x[i]*x[i]*x[i];

		con[1] += y[i];
		con[2] += x[i]*y[i];
		con[3] += x[i]*x[i]+y[i];
	}
}

double detfun(int col)
{
	for(int i=1; i<4; i++)
		for(int j=0; j<4; j++)
			tempA[i][j] = xi[i][j];
	if(col>0)
		{ for(int i=1; i<4; i++)	tempA[i][col] = con[i]; }

    return (tempA[1][1]*(tempA[2][2]*tempA[3][3] - tempA[2][3]*tempA[3][2]) - tempA[1][2]*(tempA[2][1]*tempA[3][3] - tempA[2][3]*tempA[3][1]) + tempA[1][3]*(tempA[2][1]*tempA[3][2] - tempA[2][2] * tempA[3][1]));
}

void solveEq()
{
	double det[4];
	det[0] = detfun(0);
    det[1] = detfun(1);
    det[2] = detfun(2);
    det[3] = detfun(3);

    a = det[1]/det[0];
  	b = det[2]/det[0];
    c = det[3]/det[0];
}

void calculateParabolla(int n)
{
	calculateSums();
	solveEq();
}

int main()
{
	cout << "X values are : ";
	for (int i = 1; i < 6; ++i)	cin >> x[i];
	cout << "Y values are : ";
	for (int i = 1; i < 6; ++i)	cin >> y[i];

	calculateParabolla(5);
	cout << "The parabolla is = " << a << " + " << b << "x " << c << "x^2" << endl;
	return 0;
}

/*
-2 1 0 1 2
1 2 3 4 5
*/