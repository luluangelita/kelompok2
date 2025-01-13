#include <iostream>
#include <cmath>
using namespace std;

// Fungsi untuk menghitung mean (rata-rata)
double hitungMean(double data[], int n)
{
    double jumlah = 0;
    for (int i = 0; i < n; i++)
    {
        jumlah += data[i];
    }
    return jumlah / n;
}

// Fungsi untuk mengurutkan array (Bubble Sort)
void urutkanData(double data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                // Tukar posisi
                double temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk menghitung median (nilai tengah)
double hitungMedian(double data[], int n)
{
    // Salin array dan urutkan
    double dataCopy[100];  // Anggap maksimal 100 data
    for (int i = 0; i < n; i++)
    {
        dataCopy[i] = data[i];
    }
    urutkanData(dataCopy, n);

    // Cek jika jumlah data genap atau ganjil
    if (n % 2 == 0)
    {
        return (dataCopy[n / 2 - 1] + dataCopy[n / 2]) / 2;
    }
    else {
        return dataCopy[n / 2];
    }
}

// Fungsi untuk menghitung standar deviasi
double hitungStandarDeviasi(double data[], int n)
{
    double mean = hitungMean(data, n);
    double jumlahKuadrat = 0;

    for (int i = 0; i < n; i++) {
        jumlahKuadrat += pow(data[i] - mean, 2);
    }

    return sqrt(jumlahKuadrat / (n - 1));
}

int main() {
    int n;
    double data[100];  // Maksimal 100 data

    cout << "Masukkan jumlah data: ";
    cin >> n;

    cout << "Masukkan " << n << " nilai:\n";
    for (int i = 0; i < n; i++) {
        cout << "Nilai ke-" << (i + 1) << ": ";
        cin >> data[i];
    }

    cout << "\nHasil Perhitungan:\n";
    cout << "Mean           = " << hitungMean(data, n) << endl;
    cout << "Median         = " << hitungMedian(data, n) << endl;
    cout << "Standar Deviasi = " << hitungStandarDeviasi(data, n) << endl;

    return 0;
}