#include <iostream>
#include <Windows.h>
using namespace std;

union Extra {
    int year;
    char owner[50];
};

struct Housing {
    int type;
    int ownership;    // 1 - частный, 2 - государственный
    int area;
    Extra info;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int N = 100;
    Housing arr[N];
    int n;

    cout << "Введите количество записей: ";
    cin >> n;

    int minArea;
    cout << "Введите минимальную площадь: ";
    cin >> minArea;

    for (int i = 0; i < n; i++) {
        cout << "\nЗапись " << i + 1 << ":\n";
        cout << "Тип (1 - квартира, 2 - дом): ";
        cin >> arr[i].type;
        cout << "Собственность (1 - частная, 2 - государственная): ";
        cin >> arr[i].ownership;
        cout << "Общая площадь: ";
        cin >> arr[i].area;

        if (arr[i].type == 1) {
            cout << "Год сдачи: ";
            cin >> arr[i].info.year;
        }
        else {
            cout << "Фамилия владельца: ";
            cin >> arr[i].info.owner;
        }
    }

    char owners[N][50];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i].type == 2 && arr[i].ownership == 1 && arr[i].area >= minArea) {
            strcpy_s(owners[count], arr[i].info.owner);
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(owners[j], owners[j + 1]) > 0) {
                char temp[50];
                strcpy_s(temp, owners[j]);
                strcpy_s(owners[j], owners[j + 1]);
                strcpy_s(owners[j + 1], temp);
            }
        }
    }

    cout << "\nВладельцы частных домов (площадь >= " << minArea << "):\n";
    if (count == 0) {
        cout << "Нет подходящих домов.\n";
    }
    else {
        for (int i = 0; i < count; i++) {
            cout << owners[i] << endl;
        }
    }

    return 0;
}