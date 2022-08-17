#include "Int.h"

using std::vector;
using std::string;
///////////////////////////////////////////////////////////////////////
//     #user
///////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, Int i){
    os<<i.getDec();
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<bool>&bin){
    for(auto i:bin)os<<i;
    return os;
}

bool Int::at(size_t index){
    return bin[index];
}

bool Int::at(size_t index, bool value){
    bin[index]=value;
    return bin[index];
}

string Int::getDec(){
    bool sign=bin[0];
    if(sign){
        reverse(bin);
    }

    string returned="0";
    string temp="1";
    string power;

    for(size_t i=0;i<bin.size();i++){
        if(bin[i]){
            power="1";
            int foo=i-bin.size()+1;
            while(foo-->0){
                power=_add(power, power);
                std::cout<<foo<<" : "<<power<<std::endl;
            }
            
            std::cout<<i<<" "<<returned<<std::endl;
        }
        returned=_add(returned, power);
        power="0";
        
    }
    if(sign){
        returned.insert(0,1,'-');
    }
    return returned;
}

const std::vector<bool>& Int::getBin(){
    return bin;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//     #utility
///////////////////////////////////////////////////////////////////////

bool Int::devide2(string& n)
{
    string ret(n.size(),'0');
    bool returned = (n[n.size()-1]-48)%2;
    for(int i=1; i<n.size(); i++)
    {
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

void Int::resize(int goal_size, bool sign)
{
    while(bin.size()<goal_size)
    {
        bin.emplace(bin.begin(),sign);
    }
    bin[0]=sign;

}

void Int::reverse(std::vector<bool>bin)
{
    for(auto i:bin) i.flip();
    //std::cout<<bin<<std::endl;
    Int temp(bin);
    *this=temp+Int("1");
}

std::string Int::_add(string s1, string s2){
    int offs=(int)'0';
    int temp=offs;
    for(int i=s1.size()-1;i>=0;i--){
        int foo=s1[i]-offs+s2[i]-offs+temp-offs;
        s1[i]=foo%10+offs;
        temp=foo/10+offs;
        //cout<<foo<<"-"<<foo/10;

        if(i==0 && temp-offs!=0){
            //cout<<str1<<" "<<(temp-offs)<<endl;
            s1.insert(0,1,temp);
        }
    }
    return s1;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//    #arithmetic operators
///////////////////////////////////////////////////////////////////////

Int Int::operator+(Int i)
{
    if(i.bin.size()<bin.size())
    {
        i.resize(bin.size(),i.bin[0]);
    }
    else if(i.bin.size()>bin.size())
    {
       resize(i.bin.size(),bin[0]);
    }
    Int returned(i);
    bool mem=false;


    for(int j=bin.size()-1; j>=0; j--)
    {
        if(mem==true)
        {
            if(bin[j] && i.bin[j])
            {
                returned.bin[j]=true;
            }
            else if(bin[j] || i.bin[j])
            {
                returned.bin[j]=false;
                mem=true;
            }
            else
            {
                returned.bin[j]=true;
                mem=false;
            }
        }
        else
        {
            if(bin[j] && i.bin[j])
            {
                returned.bin[j]=false;
                mem=true;
            }
            else if(bin[j] || i.bin[j])
            {
                returned.bin[j]=true;
                mem=false;
            }
            else
            {
                returned.bin[j]=false;
                mem=false;
            }
        }
    }
    return returned;
}

Int& Int::operator++(){
    *this=*this+Int("1");
    return *this;
}

Int Int::operator++(int){
    Int temp=*this;
    ++*this;
    return temp;
}

Int& Int::operator+=(Int i){
    *this=*this+i;
    return *this;
}

Int Int::operator-(Int i){
    i.reverse(i.bin);
    return *this+i;
}

Int& Int::operator--(){
    *this=*this-Int("1");
    return *this;
}

Int Int::operator--(int){
    Int temp=*this;
    --*this;
    return temp;
}

Int& Int::operator-=(Int i){
    *this=*this-i;
    return *this;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//    #logic operators
///////////////////////////////////////////////////////////////////////

//TODO

bool Int::isZero(){
    for(auto x:bin)if(x)return 0;
    return 1;
}
bool Int::operator==(Int i){
    if(i.bin.size()<bin.size())
    {
        i.resize(bin.size(),i.bin[0]);
    }
    else if(i.bin.size()>bin.size())
    {
       resize(i.bin.size(),bin[0]);
    }

    for(size_t x=0;x<bin.size();x++){
        if(bin[x]!=i.bin[x])return 0;
    }
    return true;
}
bool Int::operator!=(Int i){
    return !(*this==i);
}
bool Int::operator<(Int i){
    if((*this-i).bin[0])return true;
    else return false;
}
bool Int::operator<=(Int i){
    if((*this-i).bin[0] || (*this-i).isZero())return true;
    else return false;
}

bool Int::operator>(Int i){
    if((*this-i).bin[0])return false;
    else return true;
}
bool Int::operator>=(Int i){
    if((*this-i).bin[0])return false;
    else return true;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//    #constructors
///////////////////////////////////////////////////////////////////////

Int::Int(std::string decimal)
{
    bool sign=(decimal[0]=='-'?true:false);
    
    if(sign) decimal.erase(decimal.begin(),decimal.begin()+1);
    vector <bool> b;
    //std::cout<<"CHUJ"<<decimal.size()<<std::endl;

    while(decimal!=string(decimal.size(),'0'))
    {
        //std::cout<<decimal<<std::endl;
        b.emplace(b.begin(),devide2(decimal));  
        //for(auto i:b)std::cout<<i<<std::endl; 
    }
    bin=b;

    //resize(std::max(64.0, pow(2, log2(bin.size())+1)), sign);
    resize(64, false);
    if(sign)reverse(bin);
}

Int::Int(std::vector<bool> binary)
{
    bin=binary;
}

Int::Int(const Int& i)
{
    bin=i.bin;
}

Int::Int()
{
    bin=vector<bool> (64,false);
}


// void Int::addDec(std::string& str1, std::string& str2){
//     int offs=(int)'0';
//     int temp=offs;
//     if(str1.size()>str2.size()){
//         str2.insert(0,str1.size()-str2.size(), '0');
//     }else if(str2.size()>str1.size()){
//         str1.insert(0,str2.size()-str1.size(), '0');
//     }
//     for(int i=str1.size()-1;i>=0;i--){
//         int foo=str1[i]-offs+str2[i]-offs+temp-offs;
//         str1[i]=foo%10+offs;
//         temp=foo/10+offs;
//         //cout<<foo<<"-"<<foo/10;

//         if(i==0 && temp-offs!=0){
//             //cout<<str1<<" "<<(temp-offs)<<endl;
//             str1.insert(0,1,temp);
//         }
//     }
// }

// std::string Int::getDec(){
//     std::string returned="";
//     if(bin.binnum[0]){
//         reverse_num(bin.binnum);
//     }

//     //std::cout<<bin<<std::endl;

//     for(int i=bin.binnum.size()-1;i>0;i--){
//         if(bin.binnum[i]){
//             addDec(returned, loadPowOf2(bin.binnum.size()-i));
//         }
//     }

//     if(bin.binnum[0])returned.insert(0,1,'-');
//     return returned;
// }
// /////////////////////////////////////////////binary to decimal

// ///////////////////////////////////string to bin//////////////
// bool Int::devide2(string& n){
//     string ret(n.size(),'0');
//     bool returned = (n[n.size()-1]-48)%2;
//     for(int i=1;i<n.size();i++){
//         ret[i]=((n[i-1]-48)*10+n[i]-48)/2+48;
//         n[i]=(n[i]-48)%2+48;
//     }
    
//     if(n.size()==1){
//         n[0]=(n[0]-48)/2+48;
//         return returned;
//     }
    
//     n=ret;
//     return returned;
// }

// Int::Int(string num){
//     bool sign=false;
//     if(num[0]=='-')sign=true;
//     //std::cout<<"osdjfsd"<<sign<<std::endl;
//     vector<bool>foo;
//     if(sign){
//         num.erase(num.begin(), num.begin()+1);
//         foo.push_back(sign);
//     }else{
//         foo.push_back(sign);
//     }

//     while(num!=string(num.size(), '0')){
//         foo.emplace(foo.begin()+1, devide2(num));
//     }

//     bin.binnum=foo;

//     if(sign){
//         reverse_num(foo);
//     }

//     double power=log2(bin.binnum.size());
//     size_t binSize=bin.binnum.size();

//     while(bin.binnum.size()< std::max(pow(2, power)-binSize,64.0)){
//         bin.binnum.emplace(bin.binnum.begin()+1, sign);
//     }

//     bin_length=bin.binnum.size();
// }