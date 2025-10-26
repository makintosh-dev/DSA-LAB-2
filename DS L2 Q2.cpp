#include <iostream>
#include <cstdlib>
using namespace std;

int* findintersect(int* arr1,int* arr2,int size,int* resultsize){

    int r_size = 0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(*(arr1+i)==*(arr2+j)){
                r_size++;
            }
        }
    }

    if(r_size==0){
        *resultsize = r_size;
        return NULL;
    }

    *resultsize =r_size;
    int *r_arr = new int[r_size];

    r_size=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(*(arr1+i)==*(arr2+j) && r_size != *resultsize){
                *(r_arr+r_size) = *(arr1+i);
                r_size++;
            }
        }
    }

return r_arr;
}

int main(){

    cout<<"MASHAAL KHAN 24P-3112";


    int size;
    cout<<"\n\t enter arrays size: ";
    cin>>size;

    int *arr1 = new int[size];
    int *arr2 = new int[size];
    int *r_size = new int;

    cout<<"\n\t 1 for random enteries, anyother for enteries urself:  ";
    cin>>*r_size; //utilized becuz it changes anyways in the func. 

if(*r_size == 1){
    for(int i=0;i<size;i++){
        *(arr1+i) = rand()%100;
        
    }
    for(int i=0;i<size;i++){
        *(arr2+i) = rand()%100;
    }
}
else{
    cout<<"\n array 1: \n\t";
    for(int i=0;i<size;i++){
        cout<<"\n"<<i+1<<": ";
        cin>>*(arr1+i);
    }
    cout<<"\n array 2: \n\t";
    for(int i=0;i<size;i++){
        cout<<"\n"<<i+1<<": ";
        cin>>*(arr2+i);
    }
}

    int *r_arr = NULL; 
    r_arr= findintersect(arr1,arr2,size,r_size);

    cout<<"\n array 1: \n\t";
    for(int i=0;i<size;i++){
        cout<<" "<<*(arr1+i);
    }
    cout<<"\n array 2: \n\t";
    for(int i=0;i<size;i++){
        cout<<" "<<*(arr2+i);
    }

if(*r_size){
    cout<<"\n resultant array size: "<<*r_size;
    cout<<"\n resultant array: \n\t";
   for(int i=0;i<*r_size;i++){
       cout<<" "<<*(r_arr+i);
    }
}
else{
    cout<<"\n\n\t NO COMMON ELEMENTS \n\n";
}

    delete[] arr1;
    delete[] arr2;
    delete[] r_size;
    delete[] r_arr;
return 0;
}