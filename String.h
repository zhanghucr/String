/* String.h */
#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class String
{
public:
    String();
    String(int n, char c);
    String(const char *source);
    String(const String& s);
    ~String();
    char& operator[](int i) {return m_buff[i];}
    const char& operator[](int i) const {return m_buff[i];}  //�Գ���������.
    String operator+(const String& right);
    String& operator=(const char *right);
    String& operator=(const String& right);
    String& operator+=(const String& right);
    friend istream& operator>>(istream& is, String& s);  //���彫>>����Ϊ��Ԫ������ԭ��. 
    bool operator==(const String& right);
    bool operator!=(const String& right);
    bool operator>(const String& right);
    bool operator<(const String& right);
    int length();
private:
    char *m_buff;
    int   m_size;
};
#endif  /* STRING_H */

/* end of String.cpp */
