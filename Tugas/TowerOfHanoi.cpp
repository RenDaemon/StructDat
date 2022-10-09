#include <iostream>
#include<conio.h>
#include<math.h>

using namespace std;

//membuat struktur Tower of Hanoi
struct stick1{
    int dat1;
    stick1 *next1;
}*top1 = NULL, *isi1 = NULL, *baru1 = NULL;

struct stick2{
    int dat2;
    stick2 *next2;
}*top2 = NULL, *isi2 = NULL, *baru2 = NULL;

struct stick3{
    int dat3;
    stick3 *next3;
}*top3 = NULL, *isi3 = NULL, *baru3 = NULL;

void push1(int dat){
    baru1 = new stick1;
    baru1->dat1 = dat;
    baru1->next1 = NULL;
    if (top1 == NULL)
    {
        top1 = baru1;
    }
    else
    {
        baru1->next1 = top1;
        top1 = baru1;
    }
}
int pop1(){
    int b = 999;
    if (top1 == NULL)
    {
        return b;
    }
    else
    {
        isi1 = top1;
        top1 = top1->next1;
        return(isi1->dat1);
        delete(isi1);
    }
}
void push2(int dat){
    baru2 = new stick2;
    baru2->dat2 = dat;
    baru2->next2 = NULL;
    if (top2 == NULL)
    {
        top2 = baru2;
    }
    else
    {
        baru2->next2 = top2;
        top2 = baru2;
    }
}
int pop2(){
    int b = 999;
    if (top2 == NULL)
    {
        return b;
    }
    else
    {
        isi2 = top2;
        top2 = top2->next2;
        return(isi2->dat2);
        delete(isi2);
    }
}
void push3(int dat){
    baru3 = new stick3;
    baru3->dat3 = dat;
    baru3->next3 = NULL;
    if (top3 == NULL)
    {
        top3 = baru3;
    }
    else
    {
        baru3->next3 = top3;
        top3 = baru3;
    }
}
int pop3(){
    int b = 999;
    if (top3 == NULL)
    {
        return b;
    }
    else
    {
        isi3 = top3;
        top3 = top3->next3;
        return(isi3->dat3);
        delete(isi3);
    }
}

//melakukan pengecekan data paling ataas di setiap stick
int topstick(){
    if (top1 != NULL && top1->dat1 == 1 )
    {
        return 1;
    }
    else if (top2 != NULL && top2->dat2 == 1)
    {
        return 2;
    }
    else if (top3 != NULL && top3->dat3 == 1)
    {
        return 3;
    }
}
void print1(){
    cout<<endl;
    stick1 *isi1;
    isi1 = top1;
    cout<<"Tower1-> "<<"\t";
    while (isi1 != NULL)
    {
        cout<<isi1->dat1<<"\t";
        isi1 = isi1->next1;
    }
    cout<<endl;
}
void print2(){
    stick2 *isi2;
    isi2 = top2;
    cout<<"Tower2-> "<<"\t";
    while (isi2 != NULL)
    {
        cout<<isi2->dat2<<"\t";
        isi2 = isi2->next2;
    }
    cout<<endl;
}
void print3(){
    stick3 *isi3;
    isi3 = top3;
    cout<<"Tower3-> "<<"\t";
    while (isi3 != NULL)
    {
        cout<<isi3->dat3<<"\t";
        isi3 = isi3->next3;
    }
    cout<<endl;
    cout<<endl;
}

//Operasi Hanoi
void Hanoi(int n){
    int i, x, a, b;
    for (i = 0; i < (pow(2,n)); i++){
        print1();
        print2();
        print3();
        x = topstick();
        if (i % 2 == 0){
            if (x == 1){
                push3(pop1());
            }
            else if (x == 2){
                push1(pop2());
            }
            else if (x == 3){
                push2(pop3());
            }
        }
        else
        {
            if (x == 1){
                a = pop2();
                b = pop3();
                if (a < b && b != 999)
                {
                    push3(b);
                    push3(a);
                }
                else if (a > b && a != 999)
                {
                    push2(a);
                    push2(b);
                }
                else if (b == 999)
                {
                    push3(a);
                }
                else if (a == 999)
                {
                    push2(b);
                }
            }
            else if (x == 2){
                a = pop1();
                b = pop3();
                if (a < b && b != 999)
                {
                    push3(b);
                    push3(a);
                }
                else if (a > b && a != 999)
                {
                    push1(a);
                    push1(b);
                }
                else if (b == 999)
                {
                    push3(a);
                }
                else if (a == 999)
                {
                    push1(b);
                }
            }
            else if (x == 3){
                a = pop1();
                b = pop2();
                if (a < b && b != 999)
                {
                    push2(b);
                    push2(a);
                }
                else if (a > b && a != 999)
                {
                    push1(a);
                    push1(b);
                }
                else if (b == 999)
                {
                    push2(a);
                }
                else if (a == 999)
                {
                    push1(b);
                }
            }
        }
    }
}

int main(){
    int n, i;
    cout<<"======Masukkan Jumlah Disk======\n";
    cin>>n;
    for (i = n; i >= 1; i--)
    {
        push1(i);
    } 
    Hanoi(n);
    getch();
}
