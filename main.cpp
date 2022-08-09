 #include "Int.h"
 #include <iostream>
 #include <string>
 #include <vector>

std::ostream& operator<<(std::ostream& stream, vector<bool>bin){
    for(bool i:bin)stream<<i;
    stream<<"\r";
    return stream;
}

 int main(int argc, char* argv[]){
    std::string s="";

    Int integer((argc>1 ? s+argv[1] : "0"));
    std::cout<<integer.getBin();

    return 0;
 }
