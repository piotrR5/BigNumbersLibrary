 #include "Int.h"
 #include <iostream>
 #include <string>
 #include <vector>


std::ostream& operator<<(std::ostream& stream, std::vector<bool>&bin){
    int foo=0;
    for(auto i:bin){
        if(foo++%64==0)stream<<std::endl;
        stream<<i;
    }
    stream<<"\r";
    return stream;
}

 int main(int argc, char* argv[]){

    Int integer("1");
    std::cout<<integer.bin;
    //for(auto i:integer.bin)std::cout<<i;
    std::cout<<std::endl;
    std::cout<<integer.bin_length<<std::endl;
    //integer.resize(INT1024SIZE);
    //std::cout<<Int(integer+Int("12423424")).bin;
    Int integer2("0");
    std::cout<<integer2.bin<<std::endl;
    std::cout<<integer2.bin_length<<std::endl;
    Int int2=integer+integer2;
    std::cout<<int2.bin<<std::endl;

    return 0;
 }
