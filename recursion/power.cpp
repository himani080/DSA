#include<iostream>
using namespace std;
int powerr(int number,int power){
    if(power==0){
        return 1;
    }
    if(power==1){
        return number;
    }
    else{
        int square=number*number;
        return powerr(number,power-1);
    }

}




