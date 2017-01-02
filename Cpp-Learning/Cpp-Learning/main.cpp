#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;
bool isNotFactable(unsigned long n){
    if(n<2)return false;
    double max=sqrt(n);
    for(unsigned long i=2;i<=max;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int getBits(long long n){
    n=abs(n);
    int m=0;
    for(;n>0;n/=10)m++;
    return m;
}
int getBit(long long n,int m){
    long long a,b;
    for(;getBits(n)!=m;n/=10);
    a=n;
    b=a/10;
    return a-b*10;
}
int main(){
    unsigned int l,l2;
    cin>>l;
    if(l==2){
        cout<<"1"<<endl;
        cout<<"11";
        return 0;
    }
    if(l%2==0){
        cout<<"0"<<endl;
        return 0;
    }
    vector <long long> nums;
    l2=(l-1)/2;

    long long num,num2,base=pow(10,l2);
    int temp;
    for(int i=(base/10);i<base;i++){
        num=i*10;
        temp=i;
        while(temp){
            num*=10;
            num+=temp%10;
            // num+=getBit(temp,getBits(temp));
            temp/=10;
        }
        /*
        num=i*base*10;
        temp=i;
        int len=getBits(i);
        for(int k=1;k<=len;k++){
            num+=pow(10,k)*getBit(i,k);
        }*/
        for(int j=0;j<=9;j++){
            num2=num+j*base;
            if(isNotFactable(num2))
                nums.push_back(num2);
        }
    }

    cout<<nums.size()<<endl;
    for(unsigned int i=0;i<nums.size();i++){
        cout<<nums[i];
        if(i!=nums.size()-1)cout<<" ";
    }
}
