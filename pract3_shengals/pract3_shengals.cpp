#include <iostream>
#include <Windows.h>
using namespace std;

union Extra {
    int year;         
    char owner[50];   
};

struct Housing {
    int type;         
    int area;         
    Extra info;       
};

int main() {
    setlocale(0, "rus"); 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int N = 100;     
    Housing arr[N];        
    int n;                 

    cout << "Введите количество записей: ";
    cin >> n;

    int minArea;           // минимальная площадь для отбора
    cout << "Введите минимальную площадь: ";
    cin >> minArea;

    for (int i = 0; i < n; i++) {
        cout << "\nЗапись " << i + 1 << ":\n";
        cout << "Тип (1 - квартира, 2 - дом): ";
        cin >> arr[i].type;   
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

    char owners[N][50];    // массив фамилий отобранных домов
    int count = 0;         

    for (int i = 0; i < n; i++) {
        if (arr[i].type == 2 && arr[i].area >= minArea) { // проверка типа и площади
            int k = 0;
            while (arr[i].info.owner[k] != '\0') {
                owners[count][k] = arr[i].info.owner[k]; // копирование фамилии
                k++;
            }
            owners[count][k] = '\0';
            count++;
        }
    }

    // Сортировка пузырьком
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(owners[j], owners[j + 1]) > 0) {
                char temp[50];
                strcpy(temp, owners[j]);
                strcpy(owners[j], owners[j + 1]);
                strcpy(owners[j + 1], temp);
            }
        }
    }

    cout << "\nВладельцы частных домов (площадь >= " << minArea << "):\n";
    if (count == 0) {
        cout << "Нет подходящих домов.\n";
    }
    else {
        for (int i = 0; i < count; i++) {
            cout << owners[i] << endl; // вывод фамилии
        }
    }

    return 0;
}