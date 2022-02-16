#include <iostream>
#include <clocale>
#include <Windows.h>
using namespace std;

int step[8][2] = { {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2} };
int k = 0;

void print_desk(int** D, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < n; j++)
            cout << D[i][j] << "\t";
    }
}

int err_n() {
    int m, ival = 1;
    cin >> m;
    while (ival == 1) {
        if (cin.fail() || m < 3) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте еще раз: ";
            cin >> m;
        }
        else
            ival = 0;
    }
    return m;
}

bool set_knight(int** D, int x, int y, int n) {

    if ((x < 0) || (x >= n) || (y < 0) || (y >= n)) return false;

    if ((x >= 0 & x < n) & (y >= 0 & y < n))
        if (D[x][y] != 0) return false;

    //следующий ход
    k++;
    D[x][y] = k;

    if (k == n * n) {
        print_desk(D, n);
        return true;
    }

    for (int i = 0; i < 8; i++) {
        if (set_knight(D, x + step[i][0], y + step[i][1], n)) return true;
    }

    //возвращение
    k--;
    D[x][y] = 0;

    return false;
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x0, y0, n;

    cout << "Введите размер доски: ";
    n = err_n();

    int** desk = new int* [n];
    for (int i = 0; i < n; i++)
        desk[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            desk[i][j] = 0;

    cout << "Введите первую координату: ";
    while (1) {
        cin >> x0;
        if (cin.fail() || x0 < 1 || x0 > n) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте еще раз: ";
        }
        else
            break;
    }
    cout << "Введите вторую координату: ";
    while (1) {
        cin >> y0;
        if (cin.fail() || y0 < 1 || y0 > n) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте еще раз: ";
        }
        else
            break;
    }

    set_knight(desk, x0 - 1, y0 - 1, n);
}