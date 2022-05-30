#include <iostream>
using namespace std;
class Stack{
    private:
        int* p;
        int index = 0;
    public:
        Stack(){
            p = new int[5];
        }

	~Stack () {
	    delete [] p;
	}
        void push(int x){
            if(isfull()){
                allocateMem();
                p[index++]=x;
                cout<<"stack is full"<<endl;
            } else {
                p[index++]=x;
            }
        }
        int pop(){
            if(isEmpty()){
                return -1;
            }
            return p[index--];
        }
        void print(){
            for(int i = 0; i < index; i++){
                cout << p[i] << " ,";
            }
            cout << endl;
        }
        void allocateMem() {
            int* a = p;
            p = new int[10];
            for (int i = 0; i < 5; i++){
                p[i] = a[i];
            }
	    delete [] a;
            print();
        }
        bool isEmpty(){
	    return (!index);
        }

        bool isfull(){
	    return (index==5);
        }
};
int main () {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.push(15);
    s.push(14);
    s.push(4);
    s.push(24);
    s.push(64);
    s.print();
    return 0;
}
