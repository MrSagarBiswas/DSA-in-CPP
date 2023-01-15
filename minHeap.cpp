#include<iostream>
#include<queue>
using namespace std;

class minHeap {
    public:
    int* arr;
    int size;
    int capacity;
    minHeap(int c){
        arr = new int[c];
        size=0;
        capacity=c;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    void insert(int a){
        if(size==capacity){
            return;
        }
        size++;
        int i = size-1;
        arr[i]=a;
        int parent = this->parent(i);
        while(i!=0 && a<arr[parent]){
            arr[i]=arr[parent];
            arr[parent]=a;
            i = parent;
            parent = this->parent(i);
        }
    }
    void print(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void heapify(int i){
        int l = left(i), r = right(i), smallest = i;
        if(l<size && arr[l]<arr[i])
            smallest = l;
        if(r<size && arr[r]<arr[smallest])
            smallest = r;
        
        if(smallest != i){
            swap(arr[smallest], arr[i]);
            heapify(smallest);
        }
    }
    int extractMin(){
        if(size==0)
            return INT_MAX;
        if(size==1)
            return arr[0];
        swap(arr[0], arr[size-1]);
        size--;
        heapify(0);
        return arr[size-1];
    }
    int decreaseKey(int i, int value){
        arr[i]=value;
        if(i!=0 && value<arr[parent(i)]){
            swap(arr[i], arr[parent(i)]);
            return decreaseKey(parent(i), value);
        }
        return i;
    }
    void Delete1(int i){
        arr[i]=INT_MAX;
        heapify(i);
        size--;
    }
    void Delete(int i){
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

void minHeapify(int arr[], int i, int size){
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;
    if(left<size && arr[left]<arr[i])
        smallest = left;
    if(right<size && arr[right]<arr[smallest])
        smallest = right;
    if(smallest!=i){
        swap(arr[i], arr[smallest]);
        minHeapify(arr, smallest, size);
    }
}

void buildHeap(int arr[], int size){
    for(int i=(size-2)/2; i>=0; i--){
        minHeapify(arr, i, size);
    }
}

int main()
{
    minHeap* a = new minHeap(10);
    a->insert(10);
    a->insert(20);
    a->insert(50);
    a->insert(45);
    a->insert(15);
    a->insert(25);
    a->insert(100);
    a->print();
    cout<<a->extractMin()<<endl;
    a->heapify(0);
    a->print();
    cout<<a->decreaseKey(4, 40)<<endl;
    a->print();
    a->Delete(2);
    a->print();

    int arr[] = {10, 5, 20, 2, 4, 8};
    buildHeap(arr, 6);
    for(int i=0; i<6; i++) cout<<arr[i]<<" ";
    cout<<endl;

    priority_queue<int> maxPQ; //MaxHeap
    maxPQ.push(10);
    maxPQ.push(5);
    maxPQ.push(25);
    maxPQ.push(25);
    maxPQ.push(40);
    cout<<endl<<maxPQ.size()<<endl;
    while(!maxPQ.empty()) {
        cout<<maxPQ.top()<<" ";
        maxPQ.pop();
    }
    
    priority_queue<int, vector<int>, greater<int>> minPQ; //MinHeap
    minPQ.push(10);
    minPQ.push(5);
    minPQ.push(25);
    minPQ.push(25);
    minPQ.push(40);
    cout<<endl<<minPQ.size()<<endl;
    while(!minPQ.empty()) {
        cout<<minPQ.top()<<" ";
        minPQ.pop();
    }
    return 0;
}