#ifndef ASIGNMENT01_CMYSTRING_H
#define ASIGNMENT01_CMYSTRING_H


#include<string.h>
#include<malloc.h>
#include<iostream>

class CMyString {
private:
    int m_iLength;
    char *m_pString;

public:
    // Khoi tao
    CMyString();

    CMyString(const CMyString &);

    CMyString(const char *);

    CMyString(char, int);

    // Ham huy
    ~CMyString();

    // Ham xuat ra man hinh
    void Output();

    // Cac toan tu voi tham so la CMyString
    int operator==(const CMyString &);

    int operator>(const CMyString &);

    int operator<(const CMyString &);

    CMyString operator+(const CMyString &);

    CMyString operator+=(const CMyString &);

    char operator[](const int &);

    CMyString operator=(const CMyString &);

    // Cac toan tu voi tham so la char*
    int operator==(char *);

    int operator>(char *);

    int operator<(char *);

    CMyString operator+(char *);

    CMyString operator+=(char *);

    CMyString operator=(char *);

    // Cac phuong thuc
    // Lay chieu dai
    int GetLength();

    // Kiem tra, thiet lap chuoi rong
    int IsEmpty();

    CMyString Empty();

    // Lay ky tu tai vi tri i
    char GetAt(const int &);

    // Thay ky tu tai vi tri i
    CMyString SetAt(const char &, const int &);

    // So sanh
    int Compare(const CMyString &);

    int CompareNoCase(CMyString &);

    // Cat chuoi con
    void Mid(const int &, const int &);//xuat ra chuoi con
    void Left(const int &);//xuat ra chuoi x ky tu ben trai
    void Right(const int &);//xuat ra chuoi x ky tu ben phai

    // Doi kieu chu hoa thuong
    CMyString MakeUpper();

    CMyString MakeLower();

    // Cat bo khoang trang
    CMyString TrimLeft();

    CMyString TrimRight();

    // Tim vi tri xuat hien chuoi con
    int Find(const char *);

    int ReverseFind(const char *);
};


#endif //ASIGNMENT01_CMYSTRING_H
