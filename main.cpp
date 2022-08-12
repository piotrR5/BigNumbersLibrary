 #include "Int.h"
 #include <iostream>
 #include <string>
 #include <vector>
 #include <list>


std::ostream& operator<<(std::ostream& stream, std::vector<bool>&bin){
    //int foo=0;
    for(auto i:bin){
        //if(foo++%64==0)stream<<"\n";
        stream<<i;
    }
    return stream;
}

void debugInt(const std::list<Int>& arg){
    for(auto& i:arg){
        std::cout<<"number: ["<<i.bin.binnum<<"]\n"<<" sign: ["<<i.bin.sign<<"]";
        std::cout<<std::endl;
        std::cout<<"size: ["<<i.bin_length<<"]"<<std::endl;
    }
}

void debugInt(const Int& i){
    std::cout<<"number: ["<<i.bin.binnum<<"]\n"<<" sign: ["<<i.bin.sign<<"]";
    std::cout<<std::endl;
    std::cout<<"size: ["<<i.bin_length<<"]"<<std::endl;
}

 int main(int argc, char* argv[]){

    // Int integer("10");
    // Int integer2("9");
    // debugInt(integer);
    // debugInt(integer2);


    // Int int2=integer+integer2;
    // Int int3=integer-integer2;
    // debugInt(int2);
    // debugInt(int3);


    // debugInt(integer+integer2+int2+int3);

    Int int1("100");
    Int int2("101");
    debugInt({int1,int2});
    //debugInt(int2);
    std::cout<<"Equal? "<<(int1==int2)<<std::endl;
    std::cout<<"Diffrent? "<<(int1!=int2)<<std::endl;



    return 0;
 }
