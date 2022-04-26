#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::istream;


/**
* @brief Class containing array and member functions/operators
*/
class CMyString
{
private:
    char* arr;
    int SizeOfArray;

public:
    CMyString();
    CMyString(const char*);
    CMyString(int);
    CMyString(int size, const CMyString& s);
    ~CMyString();

    int getSizeStr(const char*);
    int getSizeArr();
    void copy(char* oldArr, char* newArr)
    {
        for (int i = 0;oldArr[i] != '\0';i++)
            newArr[i] = oldArr[i];
    }


    bool operator == (const CMyString& s2);
    bool operator != (const CMyString& s2);
    bool operator>(CMyString& s2);
    bool operator<(CMyString& s2);
    CMyString& operator()(int firstSize, int secSize)
    {
        int size = secSize - firstSize + 1;

        CMyString temp(size);
        cout << "\n" << size;

        for (int i = firstSize; i < secSize; i++)
            temp.arr[i] = this->arr[i];

        temp.arr[size] = '\0';

        cout << temp.arr;
        return temp;
    }



    CMyString& operator<<(int size)
    {
        CMyString* temp = new CMyString(size);
        for (int i = 0;i < size;i++)
            temp->arr[i] = this->arr[i];            //assigning elements that are shifted

        temp->arr[size] = '\0';

        for (int i = 0; this->arr[i] != '\0'; i++)
            this->arr[i] = this->arr[i + size];     //shifting source array

        return *temp;
    }

    CMyString& operator>>(int loc) 
    //{

    //    for (int i = size; i != SizeOfArray; i++)
    //        this->arr[i] = 0;
    //    return *this;
    //}
    {
        int size = getSizeStr(this->arr);

        CMyString* temp = new CMyString(loc);
        int j = 0;
       
        for (int i = size;i >= size - loc;i--, j++)
        {
            temp->arr[j] = this->arr[i];
            cout << temp->arr[j] << std::endl << j;
            this->arr[i] = 0;                    //clearing array
        }
        //temp->arr[j] = '\0';
        cout << "\ncout" << temp->arr;
        return *temp;
    }

    char& operator [](int a)
    {
        return *(arr + a);      //a reference to the element
    }
    CMyString& operator=(CMyString& source)
    {
        if (this == &source)          
            return *this;

        //// if data exists in the current string, delete it
        //if (arr) delete[] arr;

        char* temp = new char[source.getSizeArr() + 1];
        copy(source.arr, temp);

        delete[] this->arr;
        this->arr = temp;
        this->SizeOfArray = source.SizeOfArray;
        arr[source.getSizeArr()] = '\0';
        return *this;
    }

    CMyString& operator+(CMyString& s2)
    {

        int ResSize = getSizeArr() + s2.getSizeArr();                  //size of resultant will be sum of size of both arrays
        int i = getSizeArr();                                          //start of 2nd loop

        CMyString* result = new CMyString(ResSize, *this);


        for (int j = 0;i < ResSize;j++, i++)
            result->arr[i] = s2.arr[j];

        result->arr[ResSize] = '\0';

        return *result;
    }


    CMyString& operator+=(CMyString& s2)
    {
        CMyString temp(SizeOfArray + s2.SizeOfArray, *this);                                 // create a temporary arr 

        for (int i = SizeOfArray, j = 0; i < SizeOfArray + s2.SizeOfArray; i++, j++)         // copy elements from s2(source) to temp array
            temp.arr[i] = s2.arr[j];
        *this = temp;                                                                        // assign and return

        return *this;
    }

    friend ostream& operator<<(ostream& print, const CMyString& c);
    friend istream& operator>>(istream& input, CMyString& c);

};
int main()
{
    string aa = "ABCDEFG", bb = "1234567";
    CMyString a(&aa[0]), b(&bb[0]), c;

    c = a >> 3;
    cout << std::endl << c;
    cout << std::endl << a;


    return 0;
}


//Constructors

/**
*@brief default constructor
*/
CMyString::CMyString()
{
    SizeOfArray = 50;
    arr = new char[SizeOfArray];
    //cout << "\nEnter array\n>>\t";
    //cin.getline(arr, SizeOfArray);
}

/**
* @brief Overloaded constructor
* @param string to be copied
*/
CMyString::CMyString(const char* s)
{
    SizeOfArray = getSizeStr(s);
    //cout <<SizeOfArray;
    arr = new char[SizeOfArray + 1];
    int i = 0;

    for (;i < SizeOfArray;i++)
        arr[i] = s[i];
    arr[SizeOfArray] = '\0';
    //cout << arr;
}

/**
* @brief Overloaded constructor
* @param size of new array
*/
CMyString::CMyString(int newSize)
{
    SizeOfArray = newSize;
    arr = new char[SizeOfArray + 1];
    arr[SizeOfArray] = '\0';
    for (int i = 0;i < SizeOfArray;i++)
        arr[i] = 0;
}

/**
* @brief Copy constructor
* @param size of new array
* @param array to be copied into new
*/
CMyString::CMyString(int size, const CMyString& s)
{
    SizeOfArray = size;
    arr = new char[SizeOfArray + 1];
    for (int i = 0;s.arr[i] != '\0';i++)
        arr[i] = s.arr[i];
    arr[SizeOfArray] = '\0';
}
/**
* @brief Destructor
*/
CMyString::~CMyString() { delete[] arr;cout << "\nDeleted"; }







/**
* @brief Function to find size of character array
*/
int CMyString::getSizeArr() { return SizeOfArray; }

/**
* @brief Function to find size of string
* @param string
*/
int CMyString::getSizeStr(const char* s)
{
    int i = 0;
    for (;s[i] != '\0';i++);

    return i;
}








/**
* @brief overlaoded ostream operator
* couts array
*/
ostream& operator<<(ostream& print, const CMyString& c)
{
    print << c.arr;
    return print;
}

/**
* @brief overlaoded equality operator
* checks if given 2 strings are equal to each other
*/
bool CMyString::operator == (const CMyString& s2)
{
    int thisSize = this->SizeOfArray, compSize = s2.SizeOfArray;

    if (thisSize == compSize)
    {
        for (int i = 0;i < thisSize;i++)
            if (this->arr[i] != s2.arr[i])
                return 0;
        return 1;
    }
    else
        return 0;

}

/**
* @brief overlaoded inequality operator
* checks if given 2 strings are not equal to each other
*/
bool CMyString::operator != (const CMyString& s2)
{
    int thisSize = this->SizeOfArray, compSize = s2.SizeOfArray;

    if (thisSize == compSize)
    {
        for (int i = 0;i < thisSize;i++)
            if (this->arr[i] == s2.arr[i])
                return 0;
        return 1;
    }
    else
        return 1;

}

/**
* @brief overlaoded greater than operator
* checks if string 1 is greater than string 2
*/
bool CMyString::operator>(CMyString& s2)
{
    int minLen = ((this->getSizeArr() > s2.getSizeArr()) ? this->getSizeArr() : s2.getSizeArr());
    for (int i = 0; i < minLen; i++)
    {
        if (this->arr[i] < s2.arr[i])
            return 0;
        else if (this->arr[i] > s2.arr[i])
            return 1;
    }
    return 0;
}

/**
* @brief overlaoded less than operator
* checks if string 1 is less than string 2
*/
bool CMyString::operator<(CMyString& s2)
{
    int minLen = ((this->getSizeArr() > s2.getSizeArr()) ? this->getSizeArr() : s2.getSizeArr());
    for (int i = 0; i < minLen; i++)
    {
        if (this->arr[i] > s2.arr[i])
            return 0;
        else if (this->arr[i] < s2.arr[i])
            return 1;
    }
    return 0;

}