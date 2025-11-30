#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    char word;
    int count_char=0;
    int count_words=0;
    int temp=0;
    int flag=0;
    bool last_space = false;
    cout<<"enter the words and press Enter to exit:";
    while(flag==0)
    {
        word=getche();
        temp++;
        if(word==13)
        {
            flag=1;
        }
        else if(word==' ')
        {
            if(!last_space&&count_char>=1)
                {
                count_char=0;
                last_space=true;
                }
        }
        else
        {
             if(count_char==0)
                    {
                    count_words++;
                    }
            count_char++;
            last_space=false;
        }
    }
    cout<<endl<<"the count of character is "<<temp;
    cout<<endl<<"the count of words is "<<count_words;
    return 0;
}
