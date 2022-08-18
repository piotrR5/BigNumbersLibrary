#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <math.h>

// #define INT128SIZE 128
// #define INT256SIZE 256
// #define INT512SIZE 512
// #define INT1024SIZE 1024
// #define INT2048SIZE 2048
// #define INT4096SIZE 4096
// #define INT8192SIZE 8192
// #define INT16384SIZE 16384

std::ostream& operator<<(std::ostream& os, const std::vector<bool>&bin);



class Int{
    std::vector<bool>bin;
    

    bool devide2(std::string& n);
    void resize(size_t goal_size, bool sign);
    void reverse(std::vector<bool>bin);


    //generowanie liczby decymalnej:
    void pow2(size_t power, std::string& num);
    void _add(std::string& s1, std::string s2);

public:

    bool at(size_t index);
    bool at(size_t index, bool value);

    friend std::ostream& operator<<(std::ostream& os, Int i);
    
    const std::vector<bool>& getBin();

    std::string getDec();

    //Int operator=(Int i);
    Int operator+(Int i);
    Int operator-(Int i);
    Int operator*(Int i);
    Int operator/(Int i);   //będziemy robić operatory matematyczne
    Int& operator++();
    Int operator++(int);
    Int& operator--();
    Int operator--(int);
    Int& operator+=(Int i);
    Int& operator-=(Int i);
    Int& operator*=(Int i);
    Int& operator/=(Int i);


    // i logiczne
    bool isZero();
    bool operator==(Int i);
    bool operator!=(Int i);
    bool operator<(Int i);
    bool operator<=(Int i);
    bool operator>(Int i);
    bool operator>=(Int i);


    Int(std::string decimal);


    Int(std::vector<bool> binary);

    Int(const Int& i);

    Int();
};

// using std::string;
// using std::vector;

// struct Bin{
//     //bool sign;
//     vector <bool> binnum;
//     friend std::ostream &operator<<(std::ostream &os, Bin bin);
// };

// class Int{
    

//     size_t bin_length;
//     size_t dec_length;

//     void resize(size_t size);
//     void reverse_num(vector<bool>& foo);

//     bool devide2(string& n);

//     string getDec();
//     string binToDec();
//     void addDec(std::string& str1, std::string& str2);
//     std::string& loadPowOf2(int exp);

//     mutable Bin bin;
// public:  

//     friend std::ostream &operator<<(std::ostream &os, Int i); //Works
    

    

//     Bin getBin();
//     size_t getBinLength();
//     size_t getDecLength();

//     Int operator+(Int integer);
//     Int operator-(Int integer);

//     //TODO:
//     Int operator*(Int inte);
//     Int operator/(Int inte);
//     bool operator>(Int integer);
//     bool operator<(Int integer);
//     bool operator>=(Int integer);
//     bool operator<=(Int integer);
//     bool operator==(Int integer);
//     bool operator!=(Int integer);
    

//     Int(string num);
//     Int(vector<bool>binary, bool sign);
//     Int(Int& integer);
//     Int();
//  };