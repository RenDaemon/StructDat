#include <iostream>>

using namespace std;

struct Dat {
    string data;
    Dat *next;
};

struct queued{
    Dat *_front, *_rear;
    unsigned _size;
};

void init(queued *queue) {
   queue->_size = 0;
   queue->_front = NULL;
   queue->_rear = NULL;
}

bool isNULL(queued *queue ){
    return (queue->_front == NULL && queue->_rear == NULL);
}

void push(queued *queue, string value){
            Dat *baru = new Dat;
        if (baru) {
            queue->_size++;
            baru->data = value;
            baru->next = NULL;
            
            if (isNULL(queue))                 
                queue->_front = queue->_rear = baru;
            else {
                queue->_rear->next = baru;
                queue->_rear = baru;
            }
        }
}

void pop(queued *queue){
    if(isNULL(queue)){
        Dat *tmp = queue->_front;
        queue->_front = queue->_front->next;
        free(tmp);
    }
    if (queue->_front == NULL){
        queue-> _rear = NULL;
        queue-> _size--;
    }

} 

string front(queued *queue){
    if(!isNULL(queue)) {
        return queue->_front->data;
    }
    return 0;
}

void print(queued *queue){
    Dat *cur = queue->_front;

        if (cur->data.length() > 100) {
    cout << "Jumlah String terlalu banyak" << endl;
    return;
   }
    while (cur!= NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }

}

int main() {
    queued queue;
    init(&queue);

    push(&queue, "Jikalau");
    push(&queue, "Ditembak");
    push(&queue, "Ga mempan");
    push(&queue, "Wajar");
    push(&queue, "Kalau");
    push(&queue, "Ente");
    push(&queue, "Nyaman");

    print(&queue);

    return 0;
}


