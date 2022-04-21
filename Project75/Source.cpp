#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
using namespace std;

struct psix
{
    char familia[50];
    char name[50];
    char otchestvo[50];
    char mania[50];
    int day;
    int month;
    int year;
    int zatraty;
};
void print(psix* f, int count);
void print_menu();
int load(const char* file, psix* a);
void find_cheap(psix* f, int count);
int sum(psix* f, int count);
void setData(const char* fileName, int size);
int napal(psix* f, int count);


int main()
{
    setlocale(LC_ALL, "RUS");

    psix f[15];
    int count = 0;
    while (true)
    {
        print_menu();
        char ch = _getch();
        switch (ch)
        {
        case '1':
            count = load("TXT.txt", f);
            if (count < 0)
            {
                return 0;
            }
            break;
        case '2':
            print(f, count);
            break;
        case '3':
            int c = 0;
            cout << "Enter num: ";
            cin >> c;
            setData("TXT.txt", c);
            break;
        case '4':
            cout << "Napoleons: " << napal(f, count);
            break;
        case '5':
            cout << "All money: " << sum(f, count);
            break;
        case '6':
            find_cheap(f, count);
            break;
        case '0':
            return 0;
            break;
        default:
            cout << "Noname command!!!" << endl;
        }
        cout << "..." << endl;
        _getch();
    }

}
void print(psix* f, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "Psix #" << i + 1 << endl;
        cout << "F.N.O " << f[i].familia << " " << f[i].name << " " << f[i].otchestvo << endl;
        cout << "mania " << f[i].mania << endl;
        cout << "Date of breakouts: " << f[i].day << "." << f[i].month << "." << f[i].year << endl;
        cout << "Bribe  " << f[i].zatraty << endl;
        cout << endl;
    }
}

int napal(psix* f, int count) {
    int i = 0;
    for (int i = 0; i < count; i++) {
        if (f[i].mania == "napoleon") {
            i++;
        }
    }
    return i;
}

void print_menu()
{
    cout << endl;
    cout << "1 - Downloading psycho data" << endl;
    cout << "2 - Output data" << endl;
    cout << "3 - Input new data" << endl;
    cout << "4 - How many napoleons are in the asylum" << endl;
    cout << "5 - Expenses" << endl;
    cout << "6 - Cheap" << endl;
    cout << "0 - Exit" << endl;
    cout << "Enter your answer: ";
}

int load(const char* file, psix* a)
{
    ifstream f;
    f.open(file);
    if (!f.is_open())
    {
        cout << "File is not open: " << file << endl;
        return -1;
    }

    char buff[100];
    f.getline(buff, 99);
    int count = atoi(buff);

    for (int i = 0; i < count; i++)
    {
        if (f.eof())
        {
            f.close();
            return -1;
        }
        f.getline(a[i].familia, 49);

        f.getline(a[i].name, 49);

        f.getline(a[i].otchestvo, 49);

        f.getline(a[i].mania, 49);

        char date_d[49] = {};
        f.getline(date_d, 49);
        a[i].day = atoi(date_d);

        char date_m[49] = {};
        f.getline(date_m, 49);
        a[i].month = atoi(date_m);

        char date_y[49] = {};
        f.getline(date_y, 49);
        a[i].year = atoi(date_y);

        char zatraty[49] = {};
        f.getline(zatraty, 49);
        a[i].zatraty = atoi(zatraty);
    }
    f.close();
    return count;
}
void find_cheap(psix* f, int count)
{
    cout << "" << endl;
    cout << "Output cheap" << endl;

    int min = f->zatraty;

    for (int i = 0; i < count; i++)
    {
        if (min > f[i].zatraty)
        {
            min = f[i].zatraty;
        }
    }
    for (int i = 0; i < count; i++)
    {
        if (f[i].zatraty == min) {
            cout << "Psix #" << i + 1 << endl;
            cout << "F.N.O " << f[i].familia << " " << f[i].name << " " << f[i].otchestvo << endl;
            cout << "mania " << f[i].mania << endl;
            cout << "Date of breakouts: " << f[i].day << "." << f[i].month << "." << f[i].year << endl;
            cout << "Bribe  " << f[i].zatraty << endl;
            cout << endl;
        }
    }
}

int sum(psix* f, int count) {
    int summ = 0;
    for (int i = 0; i < count; i++)
    {
        summ = summ + f[i].zatraty;
    }
    return summ;
}


void setData(const char* fileName, int size) {
    psix* dataBase = new psix[size];
    std::ofstream file;
    file.open(fileName, ios::app);
    if (file.is_open()) {
        cout << "Enter psix details" << std::endl;
        for (int i = 0; i < size; i++) {
            cout << "Enter name: " << std::endl;
            std::cin >> dataBase[i].name;
            std::cout << "Enter familia: " << std::endl;
            std::cin >> dataBase[i].familia;
            std::cout << "Otchestvo: " << std::endl;
            std::cin >> dataBase[i].otchestvo;
            std::cout << "Mania: " << std::endl;
            std::cin >> dataBase[i].mania;

            std::cout << "Day: " << std::endl;
            std::cin >> dataBase[i].day;
            for (; dataBase[i].day > 31;) {
                std::cout << "Day: " << std::endl;
                std::cin >> dataBase[i].day;
            }

            std::cout << "Month: " << std::endl;
            std::cin >> dataBase[i].month;
            for (; dataBase[i].month > 12;) {
                std::cout << "Month: " << std::endl;
                std::cin >> dataBase[i].month;
            }

            std::cout << "Year: " << std::endl;
            std::cin >> dataBase[i].year;
            for (; dataBase[i].year > 2030 || dataBase[i].year < 2021;) {
                std::cout << "Year: " << std::endl;
                std::cin >> dataBase[i].year;
            }

            std::cout << "Zatraty: " << std::endl;
            std::cin >> dataBase[i].zatraty;

            file << dataBase[i].familia << std::endl
                << dataBase[i].name << std::endl
                << dataBase[i].otchestvo << std::endl
                << dataBase[i].mania << std::endl
                << dataBase[i].day << std::endl
                << dataBase[i].month << std::endl
                << dataBase[i].year << std::endl
                << dataBase[i].zatraty << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "Fatal error! Try again.." << std::endl;
    }
    delete[]dataBase;
}