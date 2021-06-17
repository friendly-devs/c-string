#include "CMyString.h"

// ************************** Utils **************************

/**
 * Tra ve mot chuoi la gia tri cua s1 + s2
 * @param s1
 * @param s2
 * @return
 */
char *concat(const char *s1, const char *s2) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int length = l1 + l2;

    char *s = new char[length];

    for (int i = 0; i < l1; ++i) {
        s[i] = s1[i];
    }

    for (int i = 0; i < l2; ++i) {
        s[l1 + i] = s2[i];
    }

    return s;
}

/**
 * Tra ve mot chuoi copy cua s1
 * @param s1
 * @return
 */
char *copy(const char *s1) {
    int length = strlen(s1);
    char *s = new char[length];

    for (int i = 0; i < length; ++i) {
        s[i] = s1[i];
    }

    return s;
}

/**
 * Tra ve ket qua so sanh chuoi giua s1 va s2
 * 0 Tuc la hai chuoi bang nhau
 * < 0 Chuoi s1 be hon s2
 * > 0 Chuoi s1 lon hon s2
 * @param s1
 * @param s2
 * @return
 */
int compare(const char *s1, const char *s2) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);

    int min = l1 > l2 ? l2 : l1;

    for (int i = 0; i < min; ++i) {
        if (s1[i] != s2[i]) {
            return (s1[i] > s2[i]) ? 1 : -1;
        }
    }

    if (l1 == l2) {
        return 0;
    }

    return (l1 > l2) ? 1 : -1;
}

char toLowerCase(char c) {
    return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}

char *toLowerCase(const char *s1) {
    int length = strlen(s1);
    char *s = new char[length];

    for (int i = 0; i < length; ++i) {
        s[i] = toLowerCase(s1[i]);
    }

    return s;
}

char toUpperCase(char c) {
    return (c >= 'a' && c <= 'z') ? (c - 'a' + 'A') : c;
}

char *toUpperCase(const char *s1) {
    int length = strlen(s1);
    char *s = new char[length];

    for (int i = 0; i < length; ++i) {
        s[i] = toUpperCase(s1[i]);
    }

    return s;
}

// ************************** End Utils **************************

CMyString::CMyString() {
    this->m_iLength = 0;
    this->m_pString = new char[0];
}

CMyString::CMyString(const CMyString &target) {
    this->m_iLength = target.m_iLength;
    this->m_pString = copy(target.m_pString);
}


CMyString::CMyString(const char *target) {
    this->m_iLength = strlen(target);
    this->m_pString = copy(target);
}

CMyString::CMyString(char c, int length) {
    this->m_iLength = length;
    this->m_pString = new char[length];

    for (int i = 0; i < length; i++) {
        this->m_pString[i] = c;
    }
}

CMyString::~CMyString() {
    delete this->m_pString;
}

void CMyString::Output() {
    for (int i = 0; i < this->m_iLength; ++i) {
        std::cout << this->m_pString[i];
    }
    std::cout << std::endl;
}

int CMyString::operator==(const CMyString &target) {
    return compare(this->m_pString, target.m_pString) == 0;
}

int CMyString::operator>(const CMyString &target) {
    return compare(this->m_pString, target.m_pString) > 0;
}

int CMyString::operator<(const CMyString &target) {
    return compare(this->m_pString, target.m_pString) < 0;
}

CMyString CMyString::operator+(const CMyString &target) {
    char *s = concat(this->m_pString, target.m_pString);
    return CMyString(s);
}

CMyString CMyString::operator+=(const CMyString &target) {
    char *s = concat(this->m_pString, target.m_pString);
    this->m_iLength = strlen(s);
    this->m_pString = s;
    return *this;
}

char CMyString::operator[](const int &index) {
    if (index < 0 && index >= this->m_iLength) {
        throw "Index must be great than 0 or less than length";
    }

    return this->m_pString[index];
}

CMyString CMyString::operator=(const CMyString &target) {
    this->m_iLength = target.m_iLength;
    this->m_pString = copy(target.m_pString);
}

int CMyString::operator==(char *target) {
    return compare(this->m_pString, target) == 0;
}

int CMyString::operator>(char *target) {
    return compare(this->m_pString, target) > 0;
}

int CMyString::operator<(char *target) {
    return compare(this->m_pString, target) < 0;
}

CMyString CMyString::operator+(char *target) {
    char *s = concat(this->m_pString, target);
    return CMyString(s);
}

CMyString CMyString::operator+=(char *target) {
    char *s = concat(this->m_pString, target);
    this->m_iLength = strlen(s);
    this->m_pString = s;
    return *this;
}

CMyString CMyString::operator=(char *target) {
    this->m_iLength = strlen(target);
    this->m_pString = copy(target);
}

int CMyString::GetLength() {
    return this->m_iLength;
}

int CMyString::IsEmpty() {
    return this->m_iLength == 0;
}

CMyString CMyString::Empty() {
    this->m_iLength = 0;
    this->m_pString = new char[0];
}

char CMyString::GetAt(const int &index) {
    return this->operator[](index);
}

CMyString CMyString::SetAt(const char &c, const int &index) {
    if (index < 0 && index >= this->m_iLength) {
        throw "Index must be great than 0 or less than length";
    }
    this->m_pString[index] = c;
    return *this;
}

int CMyString::Compare(const CMyString &target) {
    return compare(this->m_pString, target.m_pString);
}

int CMyString::CompareNoCase(CMyString &target) {
    char *s1 = toLowerCase(this->m_pString);
    char *s2 = toLowerCase(target.m_pString);
    return compare(s1, s2);
}

void CMyString::Mid(const int &left, const int &right) {
    if (left < 0 && left >= this->m_iLength) {
        throw "Index must be great than 0 or less than length";
    }

    if (right < 0 && right >= this->m_iLength) {
        throw "Index must be great than 0 or less than length";
    }

    for (int i = left; i < right; ++i) {
        std::cout << this->m_pString[i];
    }
    std::cout << std::endl;
}

void CMyString::Left(const int &count) {
    for (int i = 0; i < count; ++i) {
        std::cout << this->m_pString[i];
    }
    std::cout << std::endl;
}

void CMyString::Right(const int &count) {
    int left = this->m_iLength - 1 - count;
    int right = this->m_iLength;
    for (int i = left; i < right; ++i) {
        std::cout << this->m_pString[i];
    }
    std::cout << std::endl;
}

CMyString CMyString::MakeUpper() {
    this->m_pString = toUpperCase(this->m_pString);
    return *this;
}

CMyString CMyString::MakeLower() {
    this->m_pString = toLowerCase(this->m_pString);
    return *this;
}

CMyString CMyString::TrimLeft() {
    int count = 0;
    while (
            this->m_pString[count] == ' ' ||
            this->m_pString[count] == '\n' ||
            this->m_pString[count] == '\t'
            ) {
        ++count;
    }

    int length = this->m_iLength - count;
    char *s = new char[length];

    for (int i = count; i < this->m_iLength; ++i) {
        s[i - count] = this->m_pString[i];
    }

    this->m_pString = s;
    this->m_iLength = length;
    return *this;
}

CMyString CMyString::TrimRight() {
    int count = 0;
    int lastIndex = this->m_iLength - 1;

    while (
            this->m_pString[lastIndex - count] == ' ' ||
            this->m_pString[lastIndex - count] == '\n' ||
            this->m_pString[lastIndex - count] == '\t'
            ) {
        ++count;
    }

    int length = this->m_iLength - count;
    char *s = new char[length];

    for (int i = 0; i < length; ++i) {
        s[i] = this->m_pString[i];
    }

    this->m_pString = s;
    this->m_iLength = length;
    return *this;
}

int CMyString::Find(const char *target) {
    int length = strlen(target);
    int lastIndex = this->m_iLength - length - 1;

    for (int i = 0; i <= lastIndex; ++i) {
        bool isContain = true;
        for (int j = 0; j < length; ++j) {
            if (this->m_pString[i + j] != target[j]) {
                isContain = false;
                break;
            }
        }
        if (isContain) return i;
    }

    return -1;
}

int CMyString::ReverseFind(const char *target) {
    int length = strlen(target);
    int lastIndex = this->m_iLength - length - 1;

    for (int i = lastIndex; i >= 0; --i) {
        bool isContain = true;
        for (int j = 0; j < length; ++j) {
            if (this->m_pString[i + j] != target[j]) {
                isContain = false;
                break;
            }
        }
        if (isContain) return i;
    }

    return -1;
}
