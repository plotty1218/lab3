#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){

	int weight,i,size,insert,moveItem,sum;
	vector<int> cow;
	i=0;
	size=0;
	sum=0;
	ifstream inFile("file.in",ios::in);
	if(!inFile){
		cerr << "Failed opening" << endl;
		exit(1);
	}
	while(inFile >> weight){
		size++;
		cow.push_back(weight);
		i++;
	}
	for(int next=2;next<size;next++){
		insert=cow.at(next);
		moveItem=next;
		while ((moveItem>1) && (cow.at(moveItem-1)<insert)){
			cow.at(moveItem)=cow.at(moveItem-1);
			moveItem--;
		}
		cow.at(moveItem)=insert;
	}

	for(int i=1;i<6;i++){
		sum=sum+cow.at(i);
	}
	cout << sum << endl ;

	return 0;
}

