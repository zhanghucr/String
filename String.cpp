/* String.cpp */
#include "String.h"

String::String():buff(NULL), size(0)
{
}

String::String(int n, char c)
{
    buff = (char *)malloc(n + 1);
    if (buff != NULL)
    {
        memset(buff, c, n);
        buff[n] = '\0';
        size = n;
    }
}

String::String(const char *source)
{
    if (source == NULL)
    {
        buff = NULL;
        size = 0;
    }
    else
    {
        size = strlen(source);
        buff = (char *)malloc(size + 1);
        if (buff != NULL)
        {
            strcpy(buff, source);
        }
    }
}

String::String(const String& s)
{
    size = s.size;
    buff = (char *)malloc(size + 1);
    if (buff != NULL)
    {
        strcpy(buff, s.buff);
    }
}

String::~String()
{
    if (buff != NULL)
    {
        free(buff);
    }
}

String& String::operator=(const char *s)
{
    if (buff == s)
    {
        return *this;
    }

    if (buff != NULL)
    {
        free(buff);
        buff = NULL;
    }

    if (s == NULL)
    {
        size = 0;
    }
    else
    {
        size = strlen(s);
        buff = (char *)malloc(size + 1);
        if (buff != NULL)
        {
            strcpy(buff, s);
        }
    }
    
    return *this;
}

String& String::operator=(const String& s)
{
    if (this == &s)
    {
        return *this;
    }
    else
    {
        size = s.size;
        buff = (char *)realloc(buff, size + 1);
        if (buff != NULL)
        {
            strcpy(buff, s.buff);
        }
        
        return *this;
    }
}

bool String::operator==(const String& s)
{
    if (0 == strcmp(buff, s.buff))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool String::operator!=(const String& s)
{
    if (0 == strcmp(buff, s.buff))
    {
        return false;
    }
    else
    {
        return true;
    }
}

String& String::operator+=(const char *s)
{
    if (buff == s || s == NULL)
    {
        return *this;
    }
    
    buff = (char *)realloc(buff, size + 1 + strlen(s));
    if (buff != NULL)
    {
        strcpy(&buff[size], s);
    }

    size += strlen(s);
    return *this;
}

String& String::operator+=(const String& s)
{
    buff = (char *)realloc(buff, size + s.size);
    if (buff != NULL)
    {
        strcpy(&buff[size], s.buff);
    }

    size += s.size;
    
    return *this;
}

bool String::operator>(const String& s)
{
    if (0 < strcmp(buff, s.buff))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool String::operator<(const String& s)
{
    if (0 < strcmp(buff, s.buff))
    {
        return false;
    }
    else
    {
        return true;
    }
}

String String::operator+(const String& s)
{
    String temp(*this);
    temp += s;
    return temp;
}

int String::length()
{
    return size;
}

/* end of String.cpp */
