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
    String(const char* source);
    String(const String& s);
    ~String();
    char& operator[](int i)
    {
        return buff[i];
    }

    //index for const
    const char& operator[](int i) const
    {
        return buff[i];
    }

    String operator+(const String& s);
    String& operator=(const char *s);
    String& operator=(const String& s);
    String& operator+=(const char *s);
    String& operator+=(const String& s);
    int length();
    friend istream& operator>>(istream& is, String& s);  //need to be set as friend 
    bool operator>(const String& s);
    bool operator<(const String& s);
    bool operator==(const String& s);
    bool operator!= (const String& s);
private:
    char *buff;
    int size;
};
#endif

/* end of String.h */
