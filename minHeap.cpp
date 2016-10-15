//+++++++++++++++++++++++++++++++++
// Author: Luis D. Chaparro
// Course: CSCE 3110_001
// Date: April 9th, 2016
// Description:
//+++++++++++++++++++++++++++++++++
#include "minHeap.h"
using namespace std;
 
// Main Function
int main(){	
	MinHeap Heap;
	
	ifstream file("commands.txt");
	while(!file.eof()){
		string line;
		stringstream ss;
		char command;
		int node, nodeChange;
		
		getline(file, line);
		ss << line;
		ss >> command;
		//cout << command;
		//SLEEP;
		if(command == 'C' || command == 'c'){
			ss >> node >> nodeChange;
			//cout << " " << node << " " << nodeChange << endl;
			//SLEEP;
			Heap.change(node, nodeChange);
		}
		else if(command == 'P' || command == 'p'){
			//cout << endl;
			continue;
		}
		else
			ss >> node;
		if(command == 'I' || command == 'i'){
			//cout << " " << node << endl;
			//SLEEP;
			Heap.insert(node);
		}
		else if(command == 'D' || command == 'd')
			Heap.deleteNode(node);
		else if(command == 'C' || command == 'c')
			Heap.printPostOrder();
    }
    return 0;
}