#include <iostream>
using namespace std;

struct Nasabah {
    string name;
    string rekening;
    string phone;
    int number;
    Nasabah* next;
};

struct Queue {
    Nasabah* _front, *_rear;
    unsigned _size;
};

void init(Queue* queue) {
    queue->_front = NULL;
    queue->_rear = NULL;
    queue->_size = 0;
}

bool isEmpty(Queue *queue) {
  return (queue->_front == NULL && queue->_rear == NULL);
}

void push(Queue *queue, string name, string rekening, string phone) {
  Nasabah* newNasabah = new Nasabah;
  if (newNasabah) {
    queue->_size++;
    newNasabah->name = name;
    newNasabah->rekening = rekening;
    newNasabah->phone = phone;
    newNasabah->next = NULL;
    
    if (isEmpty(queue)) {
        newNasabah->number = 1;
        queue->_front = queue->_rear = newNasabah;
    } else {
        newNasabah->number = queue->_rear->number + 1;
        queue->_rear->next = newNasabah;
        queue->_rear = newNasabah;
    }
  }
}

void pop(Queue *queue) {
    if(!isEmpty(queue)) {
        Nasabah *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);

        if(queue->_front == NULL) {
            queue->_rear = NULL;
        }
        queue->_size--;
    }
}

string peak(Queue *queue) {
    if(!isEmpty(queue)) {
        return queue->_front->name;
    }
    return 0;
}

void printQueue(Queue *queue) {
    Nasabah* current = queue->_front;

    while(current != NULL) {
        cout << "Urutan ke-" << current->number << "\t : ";
        cout << current->name << " ";
        cout << "[" << current->rekening << "]" << " ";
        cout << "[" << current->phone << "]" << endl;
        current = current->next;
    }
}

void option(Queue *Teller,  Queue *CS) {
    while(true) {
        system("cls");
        cout << "````````````````````````````````````"<< endl;
        cout << "|            Bank Queue            |" << endl;
        cout << "````````````````````````````````````"<< endl;
        cout << "| option :                         |" << endl;
        cout << "| 1. Enqueue                       |" << endl;
        cout << "| 2. Deque                         |" << endl;
        cout << "| 3. Show Queue                    |" << endl;
        cout << "| 0. Exit                          |" << endl;
        cout << "````````````````````````````````````"<< endl;
        int option;
        cout << "$> Select an Option : ";
        cin >> option;
        
        if (option == 1) {
            system("cls");
            cout << "````````````````````````````````````"<< endl;
            cout << "|          Add Queue               |" << endl;
            cout << "````````````````````````````````````"<< endl;
            cout << "| option :                         |" << endl;
            cout << "| 1. Teller                        |" << endl;
            cout << "| 2. CS                            |" << endl;
            cout << "| 0. Back                          |" << endl;
            cout << "````````````````````````````````````"<< endl;
            int addoption;
            cout << "$> Select an option : ";
            cin >> addoption;
            
            string name, rekening, phone;
            cout << "$> Masukkan Nama Nasabah : ";
            cin.ignore();
            getline(cin, name);

            cout << "$> Masukkan No. Rekening Nasabah : ";
            getline(cin, rekening);

            cout << "$> Masukkan No. HP Nasabah : ";
            getline(cin, phone);

            if (addoption == 1) {
                    push(Teller, name, rekening ,phone);
                    cout << "Berhasil menambahkan \"" << name << "\" ke antrian teller" << endl;

            } else if (addoption == 2) {
                    push(CS, name, rekening, phone);
                    cout << "Berhasil menambahkan \"" << name << "\" ke antrian CS" << endl;
            } else {
                continue;
            }
        } else if (option == 2) {
            if(!isEmpty(Teller)) {
                pop(Teller);
                cout << "Berhasil melayani satu antrian pada Teller " << endl;
            }

            if(!isEmpty(CS)) {
                pop(CS);
                cout << "Berhasil melayani satu antrian pada Teller" << endl;
            }

            cin.ignore();
        } else if (option == 3) {
            if(!isEmpty(Teller)) {
                cout << "Antrian Teller" << endl;
                printQueue(Teller);
                cout << endl;
            } else {
                cout << "Sedang tidak ada antrian untuk Teller No. 1" << endl;
            }


            if(!isEmpty(CS)) {
                cout << "Antrian CS" << endl;
                printQueue(CS);
                cout << endl;
            } else {
                cout << "Sedang tidak ada antrian untuk CS No. 1" << endl;
            }


            cin.ignore();
        } 
        cout << "Press Any Key to continue..." << endl;
        getchar();
    }
}

int main()
{
    Queue Teller, CS;
    init(&Teller);
    init(&CS);

    option(&Teller, &CS);
    return 0;
}
