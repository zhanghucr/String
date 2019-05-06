#include <iostream>
#include "String.h"

using namespace std;

/* ����Ҫ����ΪString�����Ԫ���� */
ostream& operator<<(ostream& os, String& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        //os << s.buff[i];��ô����,˽�б���.
        os << s[i];
    }
    
    return os;
}

/* ���붨��ΪString�����Ԫ���� */
istream& operator>>(istream& is, String& s)
{
    char c;
    int i = 0;
    int capacity = 20;  /* Ԥ������ */
    
    if (s.buff != NULL)
    {
        free(s.buff);
    }

    s.buff = (char *)malloc(capacity);
    
    while (is.get(c) && isspace(c));  /* �޳�ǰ��Ŀո�� */
    if (is)
    {
        do 
        {
            s.buff[i] = c;
            i++;

            if (i == capacity - 1)
            {
                capacity = capacity * 2;
                s.buff = (char *)realloc(s.buff, capacity);
            }
        } while (is.get(c) && !isspace(c));  /* �����ո���ߺ���û���������˳�ѭ�� */

        //��������հ�,����Ż�.
        if (is)
        {
            is.unget();
        }
    }

    s.size = i;
    s.buff[i] = '\0';
    return is;
}

int main(int argc, char *argv[])
{
    String a = "abcd";
    String b;
    b = "www";
    String c(6, 'l');
    String d;
    String e = a;  //abcd
    String f;
    cout << "input string: ";
    cin >> f;  //input f...
    String g;
    g = a + b;  //abcdwww
    String h("qwerty");
    h += "zxcvb";
    
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
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    cout << "e: " << e << endl;
    cout << "f: " << f << endl;
    cout << "g: " << g << endl;
    cout << "g[0]: " << g[0] << endl;
    cout << "h: " << h << endl;
    return 0;
}

