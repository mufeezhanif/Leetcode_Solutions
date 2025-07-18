class MyCircularQueue {
public:
    int* circularQueue;
    int front = 0;
    int rear = -1;
    int maxSize;
    int currSize = 0;
    MyCircularQueue(int k) {
        circularQueue = new int[k];
        maxSize = k;
    }

    bool enQueue(int value) {
        if (currSize == maxSize)
            return false;
        rear = (rear + 1) % maxSize;
        circularQueue[rear] = value;
        currSize++;
        return true;
    }

    bool deQueue() {
        if (currSize == 0)
            return false;
        front = (front + 1) % maxSize;
        currSize--;
        return true;
    }

    int Front() {
        if(currSize ==0) return -1;
         return circularQueue[front]; }

    int Rear() { 
        if(currSize ==0) return -1;
        return circularQueue[rear]; }

    bool isEmpty() {
        if (currSize == 0)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (currSize == maxSize)
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