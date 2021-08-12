

#include"LinkedList.h"
#include<iostream>
using namespace std;

template< typename Type >
class ConvertableLinkedList{
public:
    ConvertableLinkedList(){
        current = nullptr;
    }

    void insertToLast( const Type &data){
        LinkedList< Type > p;

        p.insertFirst( data );
        List.insertLast( p );

        if( nullptr == current )
            current = List.getHead();
    }

    void insertAtIndex(const Type &data, int index ){
        if( index < List.length() ){
            int i = 0;
            LLNode< LinkedList< Type >> *p = List.getHead();

            for( i; i < index; i++){
                p = p->next;
            }

            (p->data).insertLast( data );
            current = p;
        }
        else{
            LLNode< LinkedList< Type >> * p = List.getHead();

            while( nullptr != p->next )
                p = p->next;
            (p->data).insertLast( data );
            current = p;
        }
    }

    int findNext(const Type& data){

            int f = 0;
            int i = -1;
            LLNode< LinkedList< Type >> *p = current;
            LLNode< Type> *q;
            ConvertToCircular();

        do{
            q = (p->data).search( data );
            if( nullptr != q ){
                i++;
                current = List.getHead();
                while( current != p ){
                    current = current->next;
                    i++;
                }
                f = 1;
            }
            else{
                p = p->next;
            };
        }while( p != current && !f );
        ConvertToSingly();
        return i;

}

    void display() const{

        LLNode< LinkedList< Type >> *p = List.getHead();
        do{
            cout<<p->data << "\n";
            p = p->next;
        }while( nullptr != p);

        cout << endl;

    }
private:
    LinkedList< LinkedList< Type >> List;
    LLNode< LinkedList< Type>> *current;

    void ConvertToCircular(){

            LLNode< LinkedList< Type > >* p = List.getHead();
            LLNode< LinkedList< Type > >* q = List.getHead();

            while( q->next != nullptr )
                q = q->next;
            q->next = p;

    }
    void ConvertToSingly(){

            LLNode< LinkedList< Type > >* p = List.getTail();
            p->next = nullptr;

    }
};

int main(){
    int a;
    ConvertableLinkedList< int > b;
    int data, index;
    cout << "Case 1-Insert value to last\n";
    cout << "Case 2-Insert value to the Index\n";
    cout << "Case 3-Find the value\n";
    cout << "Case 4-Display\n";
    cout << "Case 5-Quit\n";
    cout << "Select a case: ";
    cin >> a;

    while( a != 5 ){
        if( 1 == a ){
            cout << "Enter the value: ";
            cin >> data;
            b.insertToLast( data );
        }

        if(2 == a ){
            cout << "Enter the value: ";
            cin >> data;
            cout << "Enter the index: ";
            cin >> index;
            b.insertAtIndex(data, index);
        }
        if( 3 == a ){
            cout << "Enter the value you want to search: ";
            cin >> data;
            if( b.findNext( data ) != -1 ){
                cout << "Your value was found in index " << b.findNext( data ) << endl;
            }else
                cout << "Your value was not in the list\n";
        }

        if( 4 == a ){
            cout << "List printed:\n";
            b.display();
        }

        cout << "Select a case: ";
        cin >> a;
    }
    return 0;
}


//Erdal Aþýk - 17244710049


























