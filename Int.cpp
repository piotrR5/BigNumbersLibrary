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
    string returned="0";
    string powered="1";

    size_t indexOfLastPower=bin.size()-1;
    bool sign=(bin[0]?1:0);
    if(sign)reverse(bin);
    for(size_t i=bin.size()-1;i>0;i--){
        if(bin[i]){
            pow2(indexOfLastPower-i, powered);
            _add(returned, powered);
            indexOfLastPower=i;
            
        }
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
    for(size_t i=1; i<n.size(); i++)
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

void Int::resize(size_t goal_size, bool sign)
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

void Int::_add(string& s1, string s2){
    uint8_t offset='0';
    for(auto& i:s1)i-=offset;
    for(auto& i:s2)i-=offset;

    uint8_t temp=0;
    if(s1.size()!=s2.size()){
        if(s1.size()<s2.size()){
            while(s1.size()<s2.size()){
                s1.insert(0,1,0);
            }
        }
        else{
            while(s1.size()>s2.size()){
                s2.insert(0,1,0);
            }
        }
    }
    
    size_t index=s1.length()-1;

    for(;index>=0;index--){
        uint8_t foo=s1[index]+s2[index]+temp;

        s1[index]=foo%10;
        temp=foo/10;

        if(index==0 && temp!=0){
            s1.insert(0,1,temp);
            for(auto& i:s1)i+=offset;
            return;
        }else if(index==0){
            for(auto& i:s1)i+=offset;
            return;
        }
    }

    for(auto& i:s1)i+=offset;
}

void Int::pow2(size_t power, std::string& num){
    while(power--){
        _add(num,num);
    }
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
    resize(std::max(128, (int)pow(2,log2(b.size()))), false);
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