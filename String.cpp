/* String.cpp */
#include "String.h"

String::String()
{
    m_buff = new char[1];
    m_buff[0] = '\0';
    m_size = 0;
}

String::String(int n, char c)
{
    m_buff = new char[n + 1];
    memset(m_buff, c, n);
    m_buff[n] = '\0';
    m_size = n;
}

String::String(const char *source)
{
    if (source == NULL)
    {
        m_buff = new char[1];
        m_buff[0] = '\0';
        m_size = 0;
    }
    else
    {
        m_size = strlen(source);
        m_buff = new char[m_size + 1];
        strcpy(m_buff, source);
    }
}

String::String(const String& s)
{
    m_size = strlen(s.m_buff);  //���Է���˽�б���. 
    m_buff = new char[m_size + 1];
    strcpy(m_buff, s.m_buff);
}

String::~String()
{
    delete[] m_buff;
}

String& String::operator=(const String& s)
{
    if (this == &s)
    {
        return *this;
    }
    
    delete[] m_buff;
    m_size = strlen(s.m_buff);
    m_buff = new char[m_size + 1];
    strcpy(m_buff, s.m_buff);
    return *this;
}

String& String::operator+=(const String& s)
{
    int total_size = strlen(m_buff) + strlen(s.m_buff);
    char *tmp = new char[total_size + 1];
    strcpy(tmp, m_buff);
    strcpy(&tmp[strlen(tmp)], s.m_buff);
    delete[] m_buff;
    m_buff = tmp;
    return *this;
}

int String::length()
{
    return strlen(m_buff);
}

/* end of String.cpp */