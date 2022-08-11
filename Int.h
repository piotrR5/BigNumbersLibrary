#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

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



class Int{

    bool devide2(string& n);

    void getBinary(string num);

    public:  
    vector<bool>bin;
    size_t bin_length;
    size_t dec_length;
    Int& operator+(Int inte);
    const Int& operator-(const Int& integer);
    const Int& operator*(const Int& integer);
    const Int& operator/(const Int& integer);
    
    void resize(size_t size);
    vector<bool>getBin();

    string binToDec();

    Int(string num);
    Int(vector<bool>binary);
    Int(const Int& integer);
 };