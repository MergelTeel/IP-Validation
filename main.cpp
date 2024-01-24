#include <iostream>
#include <math.h>

bool checkZero(std::string ipForCheck){
    bool check= true;

        if(ipForCheck[0] =='0' && ipForCheck[1]==0 || ipForCheck[0]=='0' &&ipForCheck[1]!=0){
            check = false;
    }

    return (check);
}

bool checkCount(std::string ipForcheck){
    bool check = true;
    int count = 0;

    for(int i = 0; i<ipForcheck.length(); i++){
        count += (ipForcheck[i] - 48) *pow(10,i);
    }
    if (count >255 ){
        check = false;
    }
    return (check);
}

bool checkSymbol(std::string ipForCheck){

    bool check;

    for (int i =0; i<ipForCheck.length()-1; ++i){
        if(ipForCheck[i] >='0' && ipForCheck[i] <= '9' ){
            check = true;
        } else {check = false;}
    }
    return (check);
}

bool checkDot (std::string ipForCheck){
    bool check = true;
    int dotCount =0;
    for(int i=0; i< ipForCheck.length(); ++i) {
        if (ipForCheck[i] == '.') {
            ++dotCount;
        }
    }

    if(dotCount>3){
        check= false;
    }
    return (check);
}

bool checkOktet(std::string oktetForCheck){
    bool check = true;

    check = checkCount(oktetForCheck) && checkSymbol(oktetForCheck)&& checkZero(oktetForCheck);

    return(check);
}

bool ipCheck( std::string ipForValid ){

    std::string firstOktet;
    std::string secundOktet;
    std::string thirdOktet;
    std::string fourOktet;

    bool check= true;
    int i =-1;

   while( ipForValid[i+1]!='.'&& i <3){
       ++i;
       firstOktet += ipForValid[i];
   }
   ++i;
    while(ipForValid[i+1]!= '.' && i < 7){
        ++i;
        secundOktet += ipForValid[i];
    }
    ++i;
    while(ipForValid[i+1] !='.'  && i < 11) {
        ++i;
        thirdOktet += ipForValid[i];

    }
    ++i;
    while(i<ipForValid.length()){
    ++i;
     fourOktet += ipForValid[i];
    }

    check = checkOktet(firstOktet)&& checkOktet(secundOktet)&&
            checkOktet(thirdOktet)&& checkOktet(fourOktet);

    return (check);
}

int main() {
    std::string ipAddress;

    std::cout << "Enter IP-address" << std::endl;
    std::cin >> ipAddress;

    bool valid = ipCheck(ipAddress)&& ipCheck(ipAddress);
    if(valid == 1){
        std::cout << "IP-address is Valid" << std::endl;
    } else{std::cout<<"IP-address is Invalid"<< std::endl; }

    return 0;
}
