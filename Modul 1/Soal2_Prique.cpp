#include <iostream>

using namespace std;

struct Dat {
    int id;
    int urgency;
    Dat *next;
};

struct Prique{
    Dat *_peak;
    unsigned _size;
};

void init(Prique *queue){
    queue->_peak = NULL;
    queue->_size = 0;
}

bool isNULL(Prique *queue){
    return (queue->_peak == NULL);
}

void push(Prique *queue, int id, int urgency){
    Dat *tmp = queue->_peak;
    Dat *baru = new Dat;
    queue->_size++;
    baru->id = id;
    baru->urgency = urgency;
    baru->next = NULL;

    if(isNULL(queue)){
        queue->_peak = baru;
        return;
    }

    if (urgency > queue->_peak->urgency){
        baru->next = queue->_peak;
        queue->_peak = baru;
    } 
    else {
        while (tmp->next != NULL && tmp->next->urgency > urgency){
            tmp = tmp->next;
        }
        baru->next = tmp->next;
        tmp->next = baru;
    }
}

void pop(Prique *queue){
    if(!isNULL(queue)){
        Dat *tmp = queue->_peak;
        queue->_peak = queue->_peak->next;
        queue->_size--;
        free(tmp);
    }
}

Dat *peak (Prique *queue) {
    if(isNULL(queue)){
        return queue->_peak;
    }
    else return 0;
}

void print(Prique *queue){
    Dat *cur = queue->_peak;

    while(cur != NULL){
        cout << cur->id << " " << cur->urgency << endl;
        cur = cur->next;
    }
}

void control(string order, Prique *queue){
    if (order == "MASUK"){
        int id, y;
        cin >> id;
        cin >> y;
        
        push(queue,id,y);
    }else if(order == "LAYANI"){
        if(!isNULL(queue)){
            cout << queue->_peak->id << endl;
            pop (queue); 
        }else{
            cout << "HORE" << endl;
        }

    } else {
        cout << "INVALID QUERY" << endl;
    }
}

int main() {
    Prique queue;
    init(&queue);

    int D;
    cin >> D;

    for (int i =0; i < D; i++){
        string order;
        cin >> order;
        control( order, &queue);
    }

    return 0;
}