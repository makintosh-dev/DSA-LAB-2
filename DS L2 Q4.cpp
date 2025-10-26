/*
In this code i am assuming we need 2 1d arrays one with porduct amount 
and other that takes record of no of products sold
*/

#include <iostream>
#include <cstdlib>
using namespace std;

float calc_avg(int* prod,int size){
    float avg=0;

    for(int i=0;i<size;i++){
        avg += *(prod+i);
    }

    avg/=size;

return avg;
}

void low(int* prod, int size,float* avg){
    for(int i=0;i<size;i++){
        if(*(prod+i)<*avg){
            cout<<"\n\n Product no. "<<i+1<<" is critically low, considering restocking !";
        }
    }
}

int findtopsell(int* sales,int size){
    int top=0;
    int index;
    for(int i=0;i<size;i++){
        if(*(sales+i)>top){
            top = *(sales+i);
            index = i;
        }
    }

    cout<<"\n\n\t Product "<<index+1<<" is the top selling one. with "<<*(sales+index)<<" no. of Sales";

return index;
}

int find_secondtopsell(int* sales,int size,int top){
    int index =0;
    int second = 0;

    for(int i=0;i<size;i++){
        if(i == top){continue;}
        else if(*(sales+i)>second){
            second = *(sales+i);
            index = i;
        }
    }

    cout<<"\n\n\t Product "<<index+1<<" is the SECOND top selling one. with "<<*(sales+index)<<" no. of Sales";

return index;
}

void sort_popularity(int *prod,int *sales,int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(*(sales+i)<*(sales+j)){
                swap(*(sales+j),*(sales+i));
                swap(*(prod+j),*(prod+i));
            }
        }
    }
}


int main(){

    cout<<"\n\t MASHAAL KHAN 24P-3112 \n\n";

    int size;
    cout<<"\n\t Enter No. of products: ";
    cin>>size;

    int *prod = new int[size]; 
    int *sales = new int[size];
    
    //randomizer
    for(int i=0;i<size;i++){
        *(prod+i) = rand()%100+1;
        *(sales+i) = rand()%100+1;
    }

    cout<<"\n\n PRODUCT: ";
    for(int i=0;i<size;i++){
        cout<<" "<<*(prod+i);
    }
    cout<<"\n SALES  : ";
    for(int i=0;i<size;i++){
        cout<<" "<<*(sales+i);
    }

    float *avg = new float;
    *avg = calc_avg(prod,size);
    cout<<"\n\n AVERAGE: "<<*avg;

    low(prod,size,avg);

    int top = findtopsell(sales,size);

    int second = find_secondtopsell(sales,size,top);

    sort_popularity(prod,sales,size);

    cout<<"\n\n SORTED ARRAY: ";
    cout<<"\n PRODUCT: ";
    for(int i=0;i<size;i++){
        cout<<" "<<*(prod+i);
    }
    cout<<"\n SALES  : ";
    for(int i=0;i<size;i++){
        cout<<" "<<*(sales+i);
    }

cout<<"\n\n\n";


delete[] prod;
delete[] sales;
delete avg;

return 0;
}