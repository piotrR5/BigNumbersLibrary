 
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
}


