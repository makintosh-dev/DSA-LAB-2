#include <iostream>
#include <cstdlib>
using namespace std;

bool prime(int n){
    for(int i=3;i<n/2;i++){
        if(n%i ==0){return false;}
    }
return true;
}

int** goldbach_pairs(int* evens, int n, int* newsize){

    
    int **pairs = new int*[n*3];
    for(int i=0;i<n*3;i++){
        *(pairs+i) = new int[2]{-1};
    }


int m=0;
int in=0;
    for(int i=0;i<n;i++){
        int j=3;
        
        
        for (int j = 3; j <= evens[i]/2; j+=2){
            in=0;
        if(prime(j)&&prime(*(evens+i) - j)){
           *(*(pairs +m) + in) = j;
           in++;
           *(*(pairs +m) + in) = (*(evens+i) - j);
           m++;
        }}

        if(i==n-1){
            in=0;
             *(*(pairs +m) + in) = -1;
           in++;
           *(*(pairs +m) + in) = -1;
           m++;
        }

    }
*newsize = m;
return pairs;
}


int main(){
    cout<<"\n\t MASHAAL KHAN 24P-3112 \n\n";

    int *evens = new int[100]; //just to be save
    int n=1;

    int *i= new int(0);
    while(*i!=-1){
      cout<<"\n\t enter an even number: ";
        cin>>*i;
        *(evens+n)=*i;
        n++;
    }
    delete i;

int newsize =0;

    int **gbpair = goldbach_pairs(evens, n, &newsize);

    for(int i=0;i<newsize;i++){
        cout<<"(";
        for(int j=0;j<2;j++){
           cout<<" "<<*(*(gbpair+i)+j);
        }
        cout<<")\n";
    }




return 0;
}