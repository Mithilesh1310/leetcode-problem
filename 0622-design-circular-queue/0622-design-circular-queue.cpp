
class MyCircularQueue {
public:
int count;
    int size;
    int front;
    int rear;
    vector<int>mmyCircularQueue;

    MyCircularQueue(int k) {
      
      mmyCircularQueue.resize(k);
      count = 0;
      front = 0;
      rear = 0;
      size = k;

    }
    
    bool enQueue(int value) {
        if(count == size)
        return false;
        mmyCircularQueue[rear] = value;
        rear = (rear+1) %size;
        count++;
        return true;

    }
    
    bool deQueue() {
        if(count == 0)
        return false;
        
        front = (front+1) % size;
        count--;
        return true;
        
    }
    
    int Front() {
        if(!count)
        return -1;
        return mmyCircularQueue[front];
        
        

        
    }
    
    int Rear() {
        if(count == 0)
        return -1;
        return mmyCircularQueue[(rear-1+size)%size];
        
    }
    
    bool isEmpty() {
        if(count ==0 )
        {
            return true;
        }
        
        return false;
    }
    
    bool isFull() {
        if(count == size)
        return true;
        
        return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */