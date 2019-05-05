#include <iostream>
#include "String.h"

using namespace std;

ostream& operator<<(ostream& os, String& s)
{
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        os << s[i];
    }
    
    return os;
}

istream& operator>>(istream& is, String& s)
{
    delete[] s.m_buff;
    s.m_buff = new char[20];
    int m = 20;
    char c;
    int i = 0;

    while (is.get(c) && isspace(c));  /* skip space header */
    
    if (is)
    {
        do 
        {
            s.m_buff[i] = c;
            i++;

            if (i == m - 1)  /* when reach the last space, double the space size */
            {
                s.m_buff[i] = '\0';
                char *b = new char[m];
                strcpy(b, s.m_buff);
                delete[] s.m_buff;
                m = m * 2;
                s.m_buff = new char[m];
                strcpy(s.m_buff, b);
                delete[] b;
            }
        } while (is.get(c) && !isspace(c));

        //如果读到空白,将其放回.
        if (is)
        {
            is.unget();
        }
    }

    s.m_size = i;
    s.m_buff[i] = '\0';
    return is;
}

int main()
{
    String a = "abcd";
    String b;
    b = "www";
    //String c(6,b);这么写不对.
    String c(6, 'l');
    String d;
    String e = a;  //abcd
    String f;
    cout << "input string: ";
    cin >> f;  //need input...
    String g;
    g = a + b;  //abcdwww
    if (a < b)
    {
        cout << "a < b" << endl;
    }
    else
    {
        cout << "a >= b" << endl;
    }
    
    if (e == a)
    {
        cout << "e == a" << endl;
    }
    else
    {
        cout << "e != a" << endl;
    }

    b += a;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    cout << g << endl;
    cout << g[0] << endl;
    return 0;
}

