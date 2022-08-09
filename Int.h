 #include <vector>
 #include <string>
 #include <iostream>
 #include <algorithm>


using std::string;
using std::vector;

class Int{
    vector<bool>bin;
    size_t bin_length;
    size_t dec_length;
    size_t wight;

    
    bool devide2(string& n);

    void getBinary(string num);

    public:

    
    vector<bool>getBin();

    string binToDec();

    Int(string num);
 };