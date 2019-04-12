#include<bits/stdc++.h>
using namespace std;

double a[4][4], con[4];
double c[4][4], x[4], b[3][3];

double calculateDet3()
{
	return (a[1][1]*(a[2][2]*a[3][3] - a[2][3]*a[3][2]) - a[1][2]*(a[2][1]*a[3][3] - a[2][3]*a[3][1]) + a[1][3]*(a[2][1]*a[3][2] - a[2][2] * a[3][1]));
}

double cofactor(int row,int col)
{
	for(int i=1, bi=1; i<4; i++)
	{
		if(i==row) continue;
		for(int j=1, bj=1;j<4;j++)
		{
			if(j==col) continue;
			b[bi][bj] = a[i][j];
			bj++;
		}
		bi++;
	}

	return (pow(-1,row+col) * (b[1][1]*b[2][2] - b[1][2]*b[2][1]));
}

void getAInverse(double det)
{
	for(int i=1; i<4; i++)	///get C matrix
	{
		for(int j=1;j<4;j++) c[i][j] = cofactor(i,j);
	}
	for(int i=1; i<4; i++)	///get Adjoint of A = Transpose of C
	{
		for(int j=i;j<4;j++) swap(c[i][j],c[j][i]);
	}
	for(int i=1; i<4; i++)
	{
		for(int j=0; j<4; j++)
			c[i][j] /= det;
	}
}

void solveX(double det)
{
	getAInverse(det);
	for (int i = 1; i < 4; ++i)
		x[i] = c[i][1]*con[1] + c[i][2]*con[2] + c[i][3]*con[3];
}

int main()
{
	cout << "Enter the coefficient & constant values :\n";
	for (int i = 1; i < 4; ++i)
	{
		for (int j = 1; j < 4; ++j)
			cin >> a[i][j];
		cin >> con[i];
	}

	double detA = calculateDet3();
	if(detA == 0) { cout << "The solution is not possible since the det is 0."; return 0; }
	solveX(detA);

	cout << "x = " << x[1] << endl;
	cout << "y = " << x[2] << endl;
	cout << "z = " << x[3] << endl;
	return 0;
}
/*
1 1 1 1
1 2 3 6
1 3 4 6
*/