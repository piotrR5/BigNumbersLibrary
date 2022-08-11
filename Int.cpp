 
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

void Int::getBinary(string num){
    vector<bool>foo;
    while(num!=string(num.size(), '0')){
        //cout<<num<<endl;
        foo.push_back(devide2(num));
    }
    
    reverse(foo.begin(),foo.end());
    bin=foo;
}

vector<bool> Int::getBin(){
    return bin;
}

Int::Int(string num){
    getBinary(num);
    int tsize=bin.size();
    int foo=log2(tsize);
    int newSize=pow(2, foo+1)-tsize;
    while(newSize--){
        bin.emplace(bin.begin(), false);
    }

    bin_length=bin.size();
}

Int::Int(std::vector<bool>binary){
    bin=binary;
    bin_length=bin.size();
}

// Int::Int(const Int& integer){
//     bin=integer.bin;
//     bin_length=bin.size();
// }

Int::Int(const Int& integer){
    bin=integer.bin;
    bin_length=bin.size();
}

void Int::resize(size_t size){

    if(size>bin.size()){
        int newSize=size-bin.size();
        while(newSize--){
            bin.emplace(bin.begin(), false);
        }
        bin_length=bin.size();
    }
}

Int Int::operator+(Int inte){
    //std::cout<<"Size of the first Int: "<<bin.size()<<std::endl;
    //std::cout<<"Size of the second Int: "<<inte.bin.size()<<std::endl;
    //std::cout<<std::endl;

    if(bin.size() > inte.bin.size()){
        inte.resize(bin.size());
    }
    else if(bin.size() < inte.bin.size()){
        resize(inte.bin.size());
    }

    Int returned(inte.bin);

    bool temp=0;

    std::cout<<"Size of the first Int: "<<bin.size()<<std::endl;
    std::cout<<"Size of the second Int: "<<inte.bin.size()<<std::endl;
    std::cout<<"Size of the returned Int: "<<returned.bin.size()<<std::endl;
    std::cout<<std::endl;

    int32_t abc=returned.bin.size()-1;

    // if(bin[abc]==1 && inte.bin[abc]==1){
    //     temp=1;
    // }

    for(int32_t i=returned.bin.size()-1;i>=0;i--){
        if(bin[i]==true && inte.bin[i]==true){
            if(temp){
                returned.bin[i]=true;
                temp=true;
            }else{
                returned.bin[i]=false;
                temp=true;
            }
        }
        else if((bin[i]==true && inte.bin[i]==false) ||
                (bin[i]==false && inte.bin[i]==true)){
            if(temp){
                returned.bin[i]=false;
                temp=true;
            }else{
                returned.bin[i]=true;
                temp=false;
            }
        }
        else if(bin[i]==false && inte.bin[i]==false){
            if(temp){
                returned.bin[i]=true;
                temp=false;
            }else{
                returned.bin[i]=false;
                temp=false;
            }
        }
        //std::cout<<i<<std::endl;
    }
    //for(auto i:returned.bin)std::cout<<"["<<i<<"]\n";
    //std::cout<<"TU JESTEM";
    return returned;
}

const Int& Int::operator-(const Int& integer){
    
}

const Int& Int::operator*(const Int& integer){
    
}

const Int& Int::operator/(const Int& integer){
    
}

