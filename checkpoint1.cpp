#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{

    string cypher = "ftqcguowndaizrajvgybeahqdftudfqqzxmlkpase";

    for (int k = 1; k <=26; k++)
    {
        printf("for k=%d \t",k);
        for (int i = 0; i < sizeof(cypher); i++)
        {
            int t = cypher[i] + k;
            char ch;
            if(t>122)ch=t-26;
            else ch=t;
            printf("%c",ch);
        }
        cout<<endl;
    }

    printf("\ncorrect answer is for k = 14");
    
    return 0;
}