#include <iostream>
using namespace std;
class Deque{
    private:
        int* a = nullptr;
        int indFirst = 5;
        int indLast  = 5;
        int size = 10;
    public:
        Deque () {
            a = new int[size];
        }
        
	~Deque () {
	   delete [] a;
	}

	void pushBack(int x){
            if(isFull()){
                cout<<"stack is full 1st : "<< indLast << endl;
                allocateMem();
            } else if(isBackfull()) {
	    	cout <<"is Back full" << endl;
	    } else {
            	a[indLast++]=x;
	    }
        }

        void pushFirst(int x){
            if(isFull()){
                cout<<"stack is full"<<endl;
                allocateMem();
            } else if (isFrontfull()) {
	    	cout<<"Is Front full" <<endl;
	    } else {
            	a[indFirst--]=x;
	    }
        }
        int popBack(){
            if(isEmpty()){
                return -1;
            }
            indLast--;
            indCheck();
            return a[indLast];
        }
        int popFirst(){
            if(isEmpty()){
                return -1;
            }
            indFirst++;
	    indCheck();
            return a[indFirst];
        }
        void print(){
            for(int i = indFirst; i < indLast; i++){
                cout << a[i] << " ,";
            }
            cout << endl;
        }
        bool isEmpty(){
            return (indLast==5 && indFirst==5);
        }
	    bool isFull(){
            return (indLast==size && indFirst==0);
	    }

        bool isFrontfull(){
            return (indFirst==0);
        }

        bool isBackfull(){
	    return (indLast== size);	
        }

        void indCheck(){
            if (indLast == indFirst ){
                cout << "indexes are equal"<<endl;
                indLast  = 5;
                indFirst = 5;
            }
        }
        
        void allocateMem() {
            int* p = a;
            a = new int[size*2];
            for (int i = 0; i < size; i++){
                a[i+2] = p[i];
            }
	    delete [] p;
	    indFirst= indFirst+2;
	    indLast = indLast+2;
	    size= size*2;
	    cout << "After allocation" <<endl;
        }
};
int main () {
    Deque s;
    for (int i = 0; i < 8; i++) {
        s.pushBack(i);
        s.print();
        s.pushFirst(i);
    }
    cout<< "print1" << endl;
    s.print();
    //for (int i = 0; i < 4; i++) {
    //    cout << s.popBack() << " , ";
    //}
    //cout<< "print2" << endl;
    //s.print();
    return 0;
}
