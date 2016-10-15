#include "minHeap.h"

//_____________insert()____________________
// Insert node into heap
void MinHeap::insert(int node){
    heap.push_back(node);
    heapifyUp(heap.size() -1);
}
//_____________delete(int)____________________
// Delete node from heap
void MinHeap::deleteNode(int nodeDel){
	int index = search(nodeDel);
	heap.erase(heap.begin() + index);
	heapifyDown(0);
}
//_____________change(int, int)____________________
// Changes a node's value for a new one
void MinHeap::change(int node1, int node2){	
	int index;
	//cout << node1 << " " << node2 << endl;
	while((index = search(node1)) != -1){
		heap[index] = node2;
		heapifyDown(0);
	}
}
//_____________search(int)____________________
// Searches for a node in the heap & returns index
int MinHeap::search(int nodeSearch){
	int index = -1;
	
	vector<int>::iterator it = find(heap.begin(), heap.end(), nodeSearch);
	if(it == heap.end())
		return index;
	index = distance(heap.begin(), it);
	//cout << "Index for : " << nodeSearch << " Index: " << index << endl;
	//SLEEP;
	return index;
	
}
//____________heapifyUp(int)___________________
// Heapify up
void MinHeap::heapifyUp(int index){
    if (index >= 0 && parentNode(index) >= 0 && heap[parentNode(index)] > heap[index]){
        int temp = heap[index];
        heap[index] = heap[parentNode(index)];
        heap[parentNode(index)] = temp;
        heapifyUp(parentNode(index));
    }
}
//___________heapifyDown(int)___________________
// Heapify Down
void MinHeap::heapifyDown(int index){
 
    int child = leftistNode(index);
    int child1 = rightistNode(index);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]){
       child = child1;
    }
    if (child > 0){
        int temp = heap[index];
        heap[index] = heap[child];
        heap[child] = temp;
        heapifyDown(child);
    }
}

//_____________parentNode(int)____________________
// Get parentNode 
int MinHeap::parentNode(int child){
    int p = (child - 1)/2;
    if (child == 0)
        return -1;
    else
        return p;
}
//_____________leftistNode(int)_____________________
// Get Left Child
int MinHeap::leftistNode(int parentNode){
    int l = 2 * parentNode + 1;
    if (l < heap.size())
        return l;
    else
        return -1;
}
//_____________rightistNode(int, int)____________________
// Get Right Child
int MinHeap::rightistNode(int parentNode){
    int r = 2 * parentNode + 2;
    if (r < heap.size())
        return r;
    else
        return -1;
}

//_____________display()___________________
// Display Heap in POSTORDER Traversal
void MinHeap::printPostOrder(){	
	if(heap.size() == 0)
        return;
    int pos = 0;
    while (pos != heap.size()-1){

    	cout << heap[pos] << ", ";
    }
}