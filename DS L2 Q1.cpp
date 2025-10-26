#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int m=3;
	int** A = new int*[m];
	
	for(int i=0;i<m;i++){
		*(A+i)= new int[m];
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*(*(A+i)+j)= rand()%100;
		}
	}
	
    cout<<"MASHAAL KHAN 24P-3112";

	cout<<"\n\n Initial Array: \n";
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<" "<<*(*(A+i)+j);
		}
		cout<<"\n";
	}
	
	//rows sum
	int row[3] = {0};
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*(row+i) += *(*(A+i)+j);
		}
	}
	
	int col[3] = {0};
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*(col+i) += *(*(A+j)+i);
		}
	}
	
	cout<<"\n\t row sum: \n";
	for(int i=0;i<3;i++){
	cout<<"\n "<<*(row+i);
	}
	
	cout<<"\n\t col sum: \n";
	for(int i=0;i<3;i++){
	cout<<" "<<*(col+i);
	}
	
	
	
	//deleting
	for(int i=0;i<m;i++){
		delete[] *(A+i);
	}
	delete[] A;
return 0;
}
