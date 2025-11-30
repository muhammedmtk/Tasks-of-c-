#include <iostream>

using namespace std;
class String
{
    int size;
    char*arr;
public:
    //default constructor
    String()
    {
        size=20;
        arr=new char[size];
    }
    //parameterized constructor
    String(int _size)
    {
        size= _size;
        arr=new char[size];
    }
    //setter
    void set_arr(const char *arr1)
    {
        int i=0;
              for (i=0; i<size&&arr1[i]!='\0'; i++)
        {
            arr[i]=arr1[i];
        }
        arr[i]='\0';
    }
    //to upper
    void strtoupper(char &str)
    {
        if(str >= 'a' && str <= 'z')
            str = 'A' + (str - 'a');
    }
    //to lower
    void strtolower(char &str)
    {
        if(str >= 'A' && str <= 'Z')
            str = 'a' + (str - 'A');
    }
    //function convert string upper to lower
    void stringtoupper(char *str)
    {
        for(int i=0; i<size; i++)
        {
            strtoupper(str[i]);
        }
    }
    //function convert string upper to lower
    void stringtolower(char*str)
    {
        for(int i=0; i<size; i++)
        {
            strtolower(str[i]);
        }
    }
    //length of string
    int strlength(const char*str)
    {
        int i=0;
        for(i=0; str[i]; i++)
        {}
        return i;
    }
    //print string
    void stringprint(const char*str)
    {
        for(int i=0; str[i]; i++)
        {
            cout<<str[i];
        }
    }
    //compare string with string
    int ascii_str(char str1,char str2)
    {
        if(str1-'a'==str2-'A'||str1-'A'==str2-'a')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    //ascii
    int asciichar(char c)
    {
        if(c >= 'A' && c <= 'Z')
            return c - 'A';
        else if(c >= 'a' && c <= 'z')
            return c - 'a';
        return -1;
    }

    //string compare 2
    int string_compare(char*str1,char*str2)
    {
        int len1=strlength(str1);
        int len2=strlength(str2);
        if(len1!=len2)
        {
            cout<<"they are not the same"<<endl;
            return 0;
        }
        for(int i = 0; i < len1; i++)
        {
            if(!ascii_str(str1[i], str2[i]))
            {
                cout << "They are not the same\n";
                return 0;
            }
        }
        cout << "They are the same\n";
        return 1;
    }
    //string compare 2
    void stringcompare2(char*str1,char*str2)
    {
        int num1=asciichar(str1[0]);
        int num2=asciichar(str2[0]);
        if(num1 > num2)
            cout << "First string > second string\n";
        else if(num1 < num2)
            cout << "First string < second string\n";
        else
            cout << "First char equal\n";
    }
    //string concatenation
    char* concat(char* str1, char* str2)
    {
        int len1 = strlength(str1);
        int len2 = strlength(str2);


        char* result = new char[len1 + len2 + 1];


        for (int i = 0; i < len1; i++)
            result[i] = str1[i];


        for (int i = 0; i < len2; i++)
            result[len1 + i] = str2[i];

        result[len1 + len2] = '\0';

        return result;
    }

    ~String()
    {
        delete[] arr;
    }
};
int main()
{
    String s;

    char str1[] = "Hello";
    char str2[] = "World";

    cout << "str1 = ";
    s.stringprint(str1);
    cout << "\nstr2 = ";
    s.stringprint(str2);
    cout << "\n";

    //concatenation
    char* result = s.concat(str1, str2);
    cout << "Concatenated = ";
    s.stringprint(result);
    cout << endl;

    s.string_compare(str1, str2);

    s.stringcompare2(str1, str2);

    //string after using string to upper
    s.stringtoupper(str1);
    cout << endl<<"str1 after convert into uppercases= ";
    s.stringprint(str1);
    //string after using string to lower
    s.stringtolower(str1);
    cout << endl<<"str1 after convert into lowercases= ";
    s.stringprint(str1);
    delete[] result; // delete result after concat

    return 0;
}
