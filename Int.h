#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

#define INT128SIZE 128
#define INT256SIZE 256
#define INT512SIZE 512
#define INT1024SIZE 1024
#define INT2048SIZE 2048
#define INT4096SIZE 4096
#define INT8192SIZE 8192
#define INT16384SIZE 16384



using std::string;
using std::vector;

struct Bin{
    bool sign;
    vector <bool> binnum;
};

class Int{

    bool devide2(string& n);

    void getBinary(string num);
    std::string& loadPowOf2(int exp);
    void addDec(std::string& str1, std::string& str2);

    public:  
    mutable Bin bin;
    size_t bin_length;
    size_t dec_length;
    std::string getDec();
    Int& operator+(Int integer);
    Int& operator-(Int integer);

    //TODO:
    Int operator*(Int inte);
    Int operator/(Int inte);
    bool operator>(Int integer);
    bool operator<(Int integer);
    bool operator>=(Int integer);
    bool operator<=(Int integer);
    bool operator==(Int integer);
    bool operator!=(Int integer);
    //
    
    void resize(size_t size, bool sign);
    vector<bool>getBin();

    string binToDec();

    Int(string num);
    Int(vector<bool>binary, bool sign);
    //Int(const Int& integer);
    Int(const Int& integer);
 };