#include <iostream>
using namespace std;

int main() {
	int n, i, j, A[3][3];
	float det, kof[3][3], M[3][3], adj[3][3], inv[3][3];
	n = 3;

	cout << "Program Menghitung Invers Matriks 3x3" << endl;

	cout << " Masukkan elemen matriks A " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "Elemen A : " << i + 1 << j + 1 << " = ";
			cin >> A[i][j];
		}
		cout << endl;
	}

	cout << "Matriks A :" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;



	cout << "===============================================" << endl;
	det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
		A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
		A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

	cout << "|A| = " << det << endl << endl;

	cout << "=====================================" << endl;
	cout << "Minor Matriks :" << endl;
	M[0][0] = A[1][1] * A[2][2] - A[1][2] * A[2][1];
	M[0][1] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]);
	M[0][2] = A[1][0] * A[2][1] - A[1][1] * A[2][0];

	M[1][0] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]);
	M[1][1] = A[0][0] * A[2][2] - A[0][2] * A[2][0];
	M[1][2] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]);

	M[2][0] = A[0][1] * A[1][2] - A[0][2] * A[1][1];
	M[2][1] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]);
	M[2][2] = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << M[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;
	cout << " Tampilkan Kofaktor Matriks \n" << endl;

	kof[0][0] = 1 * M[0][0];
	kof[0][1] = -1 * M[0][1];
	kof[0][2] = 1 * M[0][2];
	kof[1][0] = -1 * M[1][0];
	kof[1][1] = 1 * M[1][1];
	kof[1][2] = -1 * M[1][2];
	kof[2][0] = 1 * M[2][0];
	kof[2][1] = -1 * M[2][1];
	kof[2][2] = 1 * M[2][2];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << kof[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "Tampilkan Adjoin Matriks \n" << endl;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			adj[i][j] = kof[j][i];
			cout << adj[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << " Tampilkan Invers Matriks \n" << endl;

	if (det != 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				inv[i][j] = 1 / det * adj[i][j];
				cout << inv[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Matriks tidak memiliki invers " << endl;

	}
	cout << endl << endl;

	return 0;
}