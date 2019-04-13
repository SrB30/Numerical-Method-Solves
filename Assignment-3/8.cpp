#include <bits/stdc++.h>
using namespace std;

double a[4][4], con[4];
double tempA[4][5];
double det[4];

double detfun(int col)
{
	if(col!=0){
		for(int i=1; i<4; i++)
			for(int j=0; j<4; j++)
				tempA[i][j] = a[i][j];
		for(int i=1; i<4; i++)	tempA[i][col] = con[i];
	}

    return (tempA[1][1]*(tempA[2][2]*tempA[3][3] - tempA[2][3]*tempA[3][2]) - tempA[1][2]*(tempA[2][1]*tempA[3][3] - tempA[2][3]*tempA[3][1]) + tempA[1][3]*(tempA[2][1]*tempA[3][2] - tempA[2][2] * tempA[3][1]));
}

int main()
{
	cout << "Enter the coefficient & constant values :\n";
    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            cin >> a[i][j];
            tempA[i][j] = a[i][j];
        }
        cin >> con[i];
    }

    det[0] = detfun(0);
    det[1] = detfun(1);
    det[2] = detfun(2);
    det[3] = detfun(3);

    if(det[0]==0){
        cout << "No unique solution" << endl << endl; return 0;
    }

    double x = det[1]/det[0];
    double y = det[2]/det[0];
    double z = det[3]/det[0];

    cout << "Unique solution: " << setprecision(3) << fixed << x << " " << y << " " << z << endl << endl;

    

    return 0;
}
/*
27 6 -1 85
6 15 2 72
1 1 54 110
*/