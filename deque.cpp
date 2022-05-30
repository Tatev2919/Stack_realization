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
        int getSiz(){
            return size;
        }
        void pushBack(int x){
            if(isBackfull()==true){
                cout<<"stack is full 1st : "<< indLast << endl;
                allocateMem();
            } else {
            	a[indLast++]=x;
	    }
        }
        void pushFirst(int x){
            if(isFrontfull()==true){
                cout<<"stack is full"<<endl;
                allocateMem();
            }
            a[indFirst--]=x;
        }
        int popBack(){
            //if(isEmpty()){
             //   return -1;
            //}
            indLast--;
            indCheck();
            return a[indLast];
        }
        int popFirst(){
            //if(isEmpty()){
            //    return -1;
            //}
            indFirst++;
	    //indCheck();
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
        bool isFrontfull(){
            return (indFirst==0);
        }
        bool isBackfull(){
	    if (indLast==size) {
	    	return true;
	    }
            return false;
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
            //a = new int[20];
            //for (int i = 0; i < size; i++){
            //    a[i+3] = p[i];
            //}
            //delete[] p;
            //for(int i = 0; i < size*2; i++){
            //    cout << a[i] << " ,";
            //}
            cout << "print" << endl;
            //indFirst=indFirst+3;
            //indLast=indLast+3;
            //size = size*2;
        }
};
int main () {
    Deque s;
    //cout << s.isEmpty() << endl;
    for (int i = 0; i < 8; i++) {
        s.pushBack(i);
        s.print();
        //s.pushFirst(i);
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
