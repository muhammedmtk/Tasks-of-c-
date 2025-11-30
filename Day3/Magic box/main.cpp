#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cmath>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

int main()
{
    int size;
    int sum = 0;
    int col = 0;
    int row = 0;
    int last_num = 0;
    int num = 1;

    // ألوان مميزة
    int textColor = 14; // أصفر فاتح
    int bgColor = 1;    // أزرق غامق

    // ضبط الألوان
    setColor(textColor, bgColor);

    do
    {
        cout << "Enter odd number for size: ";
        cin >> size;
    } while (size % 2 == 0);

    sum = size * size;

    col = size / 2 + 1;
    row = 1;

    // حساب المسافة بين الأعمدة
    int digits = to_string(sum).length();
    int spacing = digits + 2;

    gotoxy(col * spacing, row);
    cout << setw(digits) << num; //يعني لما يطبع الرقم، يسيب مساحة مقدارها digits خانات.
    last_num = num;

    for (num = 2; num <= sum; num++)
    {
        if (last_num % size == 0)
        {
            row = row + 1;
        }
        else
        {
            row = row - 1;
            col = col - 1;
        }

        if (row < 1)
            row = size;
        if (col < 1)
            col = size;
        if (row > size)
            row = 1;
        if (col > size)
            col = 1;

        gotoxy(col * spacing, row);
        cout << setw(digits) << num;

        last_num = num;
        Sleep(40);
    }
    return 0;
}
