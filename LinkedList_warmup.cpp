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

//=============DELETE A NODE AT i======================

bool deleteAt(Node* &head, int i){
    if (i < 0 || head==nullptr) return false;

    if (i==0){
        Node* todelete = head;
        head = head->next;
        delete todelete;
        return true;
    }

    Node* temp = head;

    for(int j=0; j < i-1; j++){
        if (temp == nullptr) return false;
        temp = temp->next;
    }

    //CHECK IF THE NODE TO DELETE EXISTS

    if (temp == nullptr || temp->next==nullptr){
        return false;
    }

    Node* todelete = temp->next;

    Node* tojoin = temp->next->next;
    temp->next = tojoin;

    delete todelete;
    return true;


};
//=============INSERTING A LINKED LIST=================
bool insertAt(Node* &head, int i, int num){
    if (i < 0){
        return false;
    }
    if (i==0){
        Node* newnode = new Node{num, nullptr};
        newnode->next= head;
        head = newnode;
        return true;
    }

    Node* temp = head;
     
    if (temp == nullptr) return false;

    // INSERTING NODE AT ith POSITION

    for(int j=0; j < i-1; j++){

        temp = temp->next;
    }
    Node* newnode = new Node{num, temp->next};
    temp->next = newnode;
    
    return true;

};
//=========================================================


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

    //temp->data = 100;
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

    int count1 =0;
    Node* temp1 = head;
    while(temp1 != nullptr){
        cout << temp1->data << endl;
        sum += temp1->data;
        temp1 = temp1->next;
        count1 +=1;
        
    }
    cout<<"=========================="<<endl;

    //INSERT A NODE AT POS 2
    insertAt(head, 2, 100);
    Node* temp2 = head;

    int count2 =0;
    while(temp2 != nullptr){
        cout << temp2->data << endl;
        //sum += temp2->data;
        temp2 = temp2->next;
        count2 +=1;
        
    }

    cout << count1 << "; "<< count2 << endl;
    cout << "AFTER DELETION" << endl;
    
    deleteAt(head, 2);

    Node* temp3 = head;
    int count3=0;
    while(temp3 != nullptr){
        cout << temp3->data << endl;
        //sum += temp2->data;
        temp3 = temp3->next;
        count3 +=1;
        
    }
    cout << count1 << "; "<< count3 << endl;
    
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }

    
    
    return 0;
}