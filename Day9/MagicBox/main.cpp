#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;


void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

using namespace std;
class Magic
{
int col;
int row;
int size;
int last_num;

public:
//default constructor
Magic()
{
col=0;
row=0;
size=0;
last_num=0;
}
//constructor
Magic(int num)
{
col=num / 2 + 1;
row=1;
size=num;
last_num=0;
}
//parameterized constructor
Magic(int _col,int _row,int num)
{
col= _col;
row= _row;
size= num*num;
last_num=0;
}
//set rows
void set_rows(int value)
{
row = value;
}
//set columns
void set_colum(int value)
{
col = value;
}
//set last_num
void set_lastnum(int value)
{
last_num = value;
}
//getter
int get_rows()
{
return row;
}
//set columns
int get_colum()
{
return col;
}
int get_lastnum()
{
return last_num;
}
void generate_and_display() {
    int spacing = 4;
    int digits = 2;
    int num = 1;

    row = 1;
    col = size / 2;
    last_num = 0;

    while (num <= size * size) {
        gotoxy(col * spacing, row);
        cout << setw(digits) << num;


        if (get_lastnum() % size == 0) {
            row = row + 1;
        } else {
            row = row - 1;
            col = col - 1;
        }


        if (row < 1) row = size;
        if (col < 1) col = size;
        if (row > size) row = 1;
        if (col > size) col = 1;

        set_lastnum(num);
        num++;
        Sleep(40);
    }
}
};
int main() {
    int size;
    do {
        cout << "Enter an odd number for size: ";
        cin >> size;
    } while (size % 2 == 0);

    Magic M1(size);
    M1.generate_and_display();
    return 0;
}
