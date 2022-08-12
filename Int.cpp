 
#include "Int.h"

// std::ostream& operator<<(std::ostream& stream, vector<bool>bin){
//     for(bool i:bin)stream<<i;
//     stream<<"\r";
//     return stream;
// }



bool Int::devide2(string& n){
    string ret(n.size(),'0');
    bool returned = (n[n.size()-1]-48)%2;
    for(int i=1;i<n.size();i++){
        ret[i]=((n[i-1]-48)*10+n[i]-48)/2+48;
        n[i]=(n[i]-48)%2+48;
    }
    
    if(n.size()==1){
        n[0]=(n[0]-48)/2+48;
        return returned;
    }
    
    n=ret;
    return returned;
}

void reverse_num(vector<bool> &foo){
    for(auto i: foo) i=!i;
    vector<bool> temp(1, 1);
    Int intiger(foo, 0), intiger2(temp, 0);
    Int ret=intiger+intiger2;
    foo=ret.bin.binnum;
}

void Int::getBinary(string num){
    bin.sign=0;
    if(num[0]=='-'){
        bin.sign=1;
        num.erase(0, 1);
        std::cout<<"[ "<<num<<" ]\n\n";
    }

    vector<bool>foo;
    while(num!=string(num.size(), '0')){
        foo.push_back(devide2(num));
    }

    reverse(foo.begin(),foo.end());

    if(bin.sign) reverse_num(foo);

    bin.binnum=foo;
}

vector<bool> Int::getBin(){
    return bin.binnum;
}

Int::Int(string num){
    bool sign;
    getBinary(num);
    sign=bin.sign;
    int tsize=bin.binnum.size();
    int foo=log2(tsize);
    int newSize=pow(2, foo+1)-tsize;
    while(newSize--){
        bin.binnum.emplace(bin.binnum.begin(), sign);
    }

    bin_length=bin.binnum.size();
}

Int::Int(std::vector<bool>binary, bool sign){
    bin.binnum=binary;
    bin.sign=sign;
    bin_length=bin.binnum.size();
}

Int::Int(const Int& integer){
    bin.binnum=integer.bin.binnum;
    bin.sign=integer.bin.sign;
    bin_length=bin.binnum.size();
}

void Int::resize(size_t size, bool sign){

    if(size>bin.binnum.size()){
        int newSize=size-bin.binnum.size();
        while(newSize--){
            bin.binnum.emplace(bin.binnum.begin(), sign);
        }
        bin_length=bin.binnum.size();
    }
}

Int& Int::operator+(Int inte){
    if(bin.binnum.size() > inte.bin.binnum.size()){
        inte.resize(bin.binnum.size(), bin.sign);
    }
    else if(bin.binnum.size() < inte.bin.binnum.size()){
        resize(inte.bin.binnum.size(), bin.sign);
    }


    bool temp=0;


    for(int32_t i=bin.binnum.size()-1;i>=0;i--){
        if(bin.binnum[i]==true && inte.bin.binnum[i]==true){
            if(temp){
                bin.binnum[i]=true;
                temp=true;
            }else{
                bin.binnum[i]=false;
                temp=true;
            }
        }
        else if((bin.binnum[i]==true && inte.bin.binnum[i]==false) ||
                (bin.binnum[i]==false && inte.bin.binnum[i]==true)){
            if(temp){
                bin.binnum[i]=false;
                temp=true;
            }else{
                bin.binnum[i]=true;
                temp=false;
            }
        }
        else if(bin.binnum[i]==false && inte.bin.binnum[i]==false){
            if(temp){
                bin.binnum[i]=true;
                temp=false;
            }else{
                bin.binnum[i]=false;
                temp=false;
            }
        }
    }


    return *this;
}

Int& Int::operator-(Int inte){
    inte.bin.sign!=inte.bin.sign;
    reverse_num(inte.bin.binnum);
    static Int returned=(*this)+inte;

    return *this+inte;
}

Int Int::operator*(Int integer){
    
}

Int Int::operator/(Int integer){
    
}

