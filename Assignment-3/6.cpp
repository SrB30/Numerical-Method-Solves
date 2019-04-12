#include<bits/stdc++.h>
using namespace std;

double a[5][5];
double b[4][4];

double calculateDet3(int col)
{
	for(int i=2, bi=1; i<5; i++, bi++)
	{
		for(int j=1, bj=1;j<5;j++)
		{
			if(j==col) continue;
			b[bi][bj] = a[i][j];
			bj++;
		}
	}

	return (b[1][1]*(b[2][2]*b[3][3] - b[2][3]*b[3][2]) - b[1][2]*(b[2][1]*b[3][3] - b[2][3]*b[3][1]) + b[1][3]*(b[2][1]*b[3][2] - b[2][2] * b[3][1]));
}
double calculateDet4()
{
	double det = a[1][1]*calculateDet3(1) - a[1][2]*calculateDet3(2) + a[1][3]*calculateDet3(3) - a[1][4]*calculateDet3(4);
	return det;
}

int main()
{
	cout << "Enter the values of 4x4 matrix:\n";
	for (int i = 1; i < 5; ++i)
	{
		for (int j = 1; j < 5; ++j)
			cin >> a[i][j];
	}
	cout << "Determinant of the entered matrix is = "<< calculateDet4() << endl;
	return 0;
}
/*
2 -1 3 0
-3 1 0 4
-2 1 4 1
-1 3 0 -2
*/