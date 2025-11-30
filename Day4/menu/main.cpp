#include <iostream>
#include <conio.h>
#include <windows.h>
#include <limits>
using namespace std;

//-----------------------------------------
// دوال للتحكم في واجهة الكونسول
//-----------------------------------------
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//-----------------------------------------
// تعريف هيكل (struct) الموظف
//-----------------------------------------
struct employee
{
    char name[20];
    int age;
    int id;
};

//-----------------------------------------
// دوال التعامل مع بيانات الموظفين
//-----------------------------------------

// دالة لإضافة موظف جديد عبر العنوان
void employee_scanByAddress(employee* ps)
{
    cout << "Enter the ID of employee: ";
    while (!(cin >> ps->id)) // التحقق من صحة الإدخال
    {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the age of employee: ";
    while (!(cin >> ps->age) || ps->age <= 0)
    {
        cout << "Invalid input. Please enter a valid positive age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(); // لمسح newline قبل قراءة الاسم
    cout << "Enter the name of employee: ";
    cin.getline(ps->name, 20);

    cout << "\nEmployee was added successfully.\n";
}

// عرض بيانات موظف
void display_employee(employee* ps)
{
    cout << "\n------------------------------\n";
    cout << "Employee ID: " << ps->id << endl;
    cout << "Employee Age: " << ps->age << endl;
    cout << "Employee Name: " << ps->name << endl;
    cout << "------------------------------\n";
}

//-----------------------------------------
// الدالة الرئيسية
//-----------------------------------------
int main()
{
    int size;
    cout << "Enter the number of employees: ";
    while (!(cin >> size) || size <= 0)
    {
        cout << "Invalid input. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    employee* emp = new employee[size]; // مصفوفة ديناميكية للموظفين

    char names[3][10] = {"Add", "Display", "Exit"};
    int hindex = 0;
    int num_of_employee;
    char ch;
    int flag = 0;
    int filledata[10] = {0}; // لتخزين الفهارس المستخدمة
    int count = 0;           // عدد الموظفين الذين تم إدخالهم فعلاً
    int top=-1;
    do
    {
        system("cls");
        // رسم القائمة الرئيسية
        for (int i = 0; i < 3; i++)
        {
            gotoxy(10, 5 + i);
            textattr(hindex == i ? 0x04 : 0x07);
            cout << names[i];
        }

        ch = getch();

        switch (ch)
        {
        case -32: // الأسهم
            ch = getch();
            switch (ch)
            {
            case 72: // سهم لأعلى
                hindex = (hindex - 1 + 3) % 3;
                break;
            case 80: // سهم لأسفل
                hindex = (hindex + 1) % 3;
                break;
            case 71: // Home
                hindex = 0;
                break;
            }
            break;

        case 13: // Enter
            system("cls");
            if (hindex == 0) // اختيار "Add"
            {
                cout << "You chose: Add / Edit\n";
                cout << "1 - Add New Employee\n";

                int num;
                cin >> num;

                if (num == 1)
                {
                    system("cls");
                    cin >> num_of_employee;
                    // التحقق من أن العنوان لم يُستخدم من قبل
                        employee_scanByAddress(&emp[num_of_employee]);
                        filledata[count++] = num_of_employee;
                    }
                }

            }
            else if (hindex == 1) // اختيار Display
            {
                cout << "You chose: Display\n";
                if (count == 0)
                {
                    cout << "No employees to display.\n";
                }
                else
                {
                    for (int i = 0; i < count; i++)
                    {
                        display_employee(&emp[filledata[i]]);
                    }
                }
            }
            else // Exit
            {
                cout << "Exiting program...\n";
                flag = 1;
            }

            cout << "\nPress any key to return to the main menu...";
            getch();
            break;
        }
    }
    while (ch != 27 && flag == 0);   // Esc للخروج

    delete[] emp; // تحرير الذاكرة
    return 0;
}
