#include <iostream>
using namespace std;
void patter1(int n)
{
    //    pattern->
    //    * * * *
    //    * * * *
    //    * * * *
    //    * * * *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void patter2(int n)
{
    //    pattern->
    // *
    // * *
    // * * *
    // * * * *
    // * * * * *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void patter3(int n)
{
    // pattern->
    // 1
    // 12
    // 123
    // 1234
    // 12345
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void patter4(int n)
{
    // pattern->
    // 1
    // 12
    // 123
    // 1234
    // 12345
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void patter5(int n)
{
    // pattern->
    // * * * *
    // * * *
    // * *
    // *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void patter6(int n)
{
    // pattern->
    // * * * *
    // * * *
    // * *
    // *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void patter7(int n)
{
    // pattern->
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void patter8(int n)
{
    // pattern->
    // *********
    //  *******
    //   *****
    //    ***
    //     *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * n - (2 * i - 1); j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void patter9(int n)
{
    // pattern->
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    // *********
    //  *******
    //   *****
    //    ***
    //     *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * n - (2 * i - 1); j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void patter10(int n)
{
    // pattern->
    // *
    // **
    // ***
    // ****
    // *****
    // ****
    // ***
    // **
    // *
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        if (i <= n)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }
        }
        else
        {
            for (int j = 1; j <= 2 * n - i; j++)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}
void patter11(int n)
{
    // pattern->
    // *
    // **
    // ***
    // ****
    // *****
    // ****
    // ***
    // **
    // *
    int s = 1;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        if (i % 2 == 0)
            s = 1;
        else
            s - 0;
        for (int j = 1; j <= i; j++)
        {
            cout << s;
            s = 1 - s;
        }
        cout << endl;
    }
}
void patter12(int n)
{
    // pattern->
    // 1        1
    // 12      21
    // 123    321
    // 1234  4321
    // 1234554321
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = 1; j <= 2 * n - 2 * i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << i - j + 1;
        }
        cout << endl;
    }
}
void patter13(int n)
{
    // pattern->
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15
    int s = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << s << " ";
            s++;
        }
        cout << endl;
    }
}
void patter14(int n)
{
    // pattern->
    // A
    // A B
    // A B C
    // A B C D
    // A B C D E

    for (int i = 1; i <= n; i++)
    {
        for (char j = 'A'; j <= 'A' + i - 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void patter15(int n)
{
    // pattern->
    // A B C D E
    // A B C D
    // A B C
    // A B
    // A

    for (int i = 1; i <= n; i++)
    {
        for (char j = 'A'; j <= 'A' + n - i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void patter16(int n)
{
    // pattern->
    // A
    // B B
    // C C C
    // D D D D
    // E E E E E

    for (char i = 'A'; i <= 'A' + n - 1; i++)
    {
        for (char j = 'A'; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void patter17(int n)
{
    // pattern->
    //     A
    //    ABA
    //   ABCBA
    //  ABCDCBA
    // ABCDEDCBA

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        char ch = 'A';
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << ch;
            if (j < i)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void patter18(int n)
{
    // pattern->
    // E
    // D E
    // C D E
    // B C D E
    // A B C D E

    for (int i = 1; i <= n; i++)
    {

        for (char ch = 'A' + n - i; ch <= 'A' + n - 1; ch++)
        {

            cout << ch << " ";
        }
        cout << endl;
    }
}
void patter19(int n)
{
    // pattern->
    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n - i + 1; j++)
        {

            cout << "*";
        }
        for (int j = 1; j <= 2 * i - 2; j++)
        {

            cout << " ";
        }
        for (int j = 1; j <= n - i + 1; j++)
        {

            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {

            cout << "*";
        }
        for (int j = 1; j <= 2 * n - 2 * i; j++)
        {

            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {

            cout << "*";
        }
        cout << endl;
    }
}
void patter20(int n)
{
    // pattern->
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;

        for (int j = 1; j <= stars; j++)
        {

            cout << "*";
        }
        for (int j = 1; j <= spaces; j++)
        {

            cout << " ";
        }
        for (int j = 1; j <= stars; j++)
        {

            cout << "*";
        }
        cout << endl;
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}
void patter21(int n)
{
    // pattern->
    //  *  *  *  *  *
    //  *           *
    //  *           *
    //  *           *
    //  *  *  *  *  *

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n)
            {
                cout << " * ";
            }
            else
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
}
void patter22(int n)
{
    // pattern->
    //  *  *  *  *  *
    //  *           *
    //  *           *
    //  *           *
    //  *  *  *  *  *

    for (int i = 1; i <=2*n-1; i++)
    {
        for (int j = 1; j <= 2*n-1; j++)
        {
           int top=i-1;
           int left=j-1;
           int right=2*n-i-1;
           int bottom=2*n-j-1;
           cout<<n-min(min(top,bottom),min(left,right));
        }
        cout << endl;
    }
}
int main()
{
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int n;
        cin >> n;
        // patter1(n);
        // patter2(n);
        // patter3(n);
        // patter4(n);
        // patter5(n);
        // patter6(n);
        // patter7(n);
        // patter8(n);
        // patter9(n);
        // patter10(n);
        // patter11(n);
        // patter12(n);
        // patter13(n);
        // patter14(n);
        // patter15(n);
        // patter16(n);
        // patter17(n);
        // patter18(n);
        // patter19(n);
        // patter20(n);
        // patter21(n);
        patter22(n);
    }
}
