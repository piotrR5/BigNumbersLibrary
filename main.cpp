 #include "Int.h"
 #include <iostream>
 #include <string>
 #include <vector>
 #include <list>
 #include <unistd.h>


int main(){
std::ios_base::sync_with_stdio(false);

    Int i("340282366920938463463374607431768211455");
    std::cout<<i<<"\n"<<i.getBin()<<"\n"<<i.getBin().size()<<"\n";
    i++;
    std::cout<<i<<"\n"<<i.getBin()<<"\n"<<i.getBin().size()<<"\n";


    return 0;
}