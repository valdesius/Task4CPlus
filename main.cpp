# include <iostream>

using namespace std;

int **transformToNewArr(int **mas, int n, int m) {
    int **finalMas = new int *[n / 2];

    for (int i = 0; i < n / 2; ++i) {
        finalMas[i] = new int[m];
    }
    int temp = 0;

    for (int i = 1; i < n; i += 2) {
        for (int j = 0; j < m; j++) {
            finalMas[temp][j] = mas[i][j];
        }
        temp++;
    }

    return finalMas;
}

void readArr(int n, int m, int **mas) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mas[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mas[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

void printNewArr(int n, int m, int **finalMas) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m; j++) {
            cout << finalMas[i][j] << " ";
        }
        cout << "\n";
    }

}

void deleteMas(int n, int **mas, int **newMas) {
    for (int i = 0; i < n; i++)
        delete[] mas[i];
    delete[] mas;

    for (int i = 0; i < n / 2; i++)
        delete[] newMas[i];
    delete[] newMas;
}


int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Enter size X on Y";
    int n, m;
    cin >> n >> m;
    int **mas = new int *[n];
    for (int i = 0; i < n; ++i)
        mas[i] = new int[m];

    cout << "Enter elements\n";
    readArr(n, m, mas);

    int **newMas = transformToNewArr(mas, n, m);

    printNewArr(n, m, newMas);
    deleteMas(n, mas, newMas);
    return 0;
}