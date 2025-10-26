#include <iostream>
#include <cstdlib>
using namespace std;


int main(){

    cout<<"\n\t MASHAAL KHAN 24P-3112 \n\n";

    int m,n;
    cout<<"\n\t Enter M: ";cin>>m;
    cout<<"\n\t Enter N: ";cin>>n;
    
    int **arr = new int*[m];
    for(int i=0;i<m;i++){
        *(arr+i) = new int[n];
    }

    int *newrow = new int(0);
    int *newcol = new int(0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"\n\t enter values "<<i+(j+1)<<" : ";
            cin>>*(*(arr+i)+j);
            if(i==j==0 || i==m-1 && j==0){
                *newrow += *(*(arr+i)+j);
            }
            if(i==0 && j==n-1){
                *newcol += *(*(arr+i)+j);
            }
    }
    }
*newrow +=m;
*newcol+=n;



    int **newarr = new int*[*newrow];
    for(int i=0;i<*newrow;i++){
        *(newarr+i) = new int[*newcol]{0};
    }


    
    int index = 0;
    for(int i=*(*(arr+0)+0);i<m+*(*(arr+0)+0);i++){
        for(int j=0;j<n;j++){
                *(*(newarr+i)+j) = *(*(arr+index)+j);
        }
        index++;
    }

cout<<"\n\n RESIZED ARRAY: \n";
   for(int i=0;i<*newrow;i++){
    cout<<"\t";
       for(int j=0;j<*newcol;j++){
              cout<<" "<< *(*(newarr+i)+j);
        }
        cout<<endl;
   }



//deleting
    delete newrow,newcol;
    for(int i=0;i<m;i++){delete[] 
        *(arr+i);}
        delete arr;
     for(int i=0;i<*newrow;i++){
        delete[] (newarr+i);
    }delete newarr;

return 0;
}