#include <iostream>
#include <vector>
using namespace std;

struct Particle{
        double mass;
        double velocity;

        Particle(double m, double v) : mass(m), velocity(v) {}

        double KE(){
            return 0.5*mass*velocity*velocity;
        }
    };
 
struct Node{
    int data;
    Node* next;
};

int main(){
    
    //Particle p1(2.0,7.0);
    //cout << "The Kinetic energy is " << p1.KE() << endl;
    //cout << "The mass is " << p1.mass << endl;

    Node* head = new Node{5, nullptr};
    Node* second = new Node{15, nullptr};
    Node* third = new Node{25, nullptr};
    Node* fourth = new Node{30, nullptr};

    //====THE STEP BELOW LINKS THE NODES===
    head->next=second;
    second->next = third;
    third->next = fourth;

    cout << head->data <<endl;
    cout << head->next->data <<endl;
    cout << "MEMORY ADDRESS OF SECOND NODE : " << head->next <<endl;

    cout <<"LETS TRAVERSE A LINK LIST\n";

    Node* temp = head;

    temp->data = 100;
    int sum = 0;
    
    //TRAVERSING A LINKED LIST
    while(temp != nullptr){
        cout << temp->data << endl;
        sum += temp->data;
        temp = temp->next;
        
    }

    cout << "THE SUM OF THE ELEMETS OF LL IS " << sum <<endl;

    //=========ADD NEW NODE AT THE BEGINNING============
    cout << "ADD NEW NODE AT THE BEGINNING\n";

    Node* newnode = new Node{2,nullptr};
    newnode->next = head;
    head = newnode;

    Node* temp1 = head;
    while(temp1 != nullptr){
        cout << temp1->data << endl;
        sum += temp1->data;
        temp1 = temp1->next;
        
    }

    delete temp;
    delete head;
    delete second;
    delete third;
    delete fourth;

    
    return 0;
}