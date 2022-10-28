#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data=val;
        this->next=NULL;
    }
    ~Node(){
      if(this->next!=NULL)
      this->next=NULL;
    }
};
void deletenode(Node* &tail,int ele){
  if(tail==NULL){
  cout<<"CAN't DELETE";
  return;
  }
  else{
    Node* prev=NULL;
    Node* curr=tail;
    while(curr->data!=ele&&curr->next!=tail){
      prev=curr;
      curr=curr->next;

    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
  }
}
void insertpos(Node* &tail,int ele,int d){
  if(tail==NULL){
    Node* n=new Node(d);
    tail=n;
    n->next=n;
  }
  else{
    Node* curr=tail;
    while(curr->data!=ele){
      curr=curr->next;
    }
    Node* temp=new Node(d);
    temp->next=curr->next;
    curr->next=temp;
  }
}
void print(Node* tail){
    Node* temp=tail;
      do{
        cout<<temp->data<<" -> ";
        temp=temp->next;
    } while( temp!=tail);
    cout<<endl;
}
int main() {
  cout << "Hello World!\n";
  Node* tail=NULL;
  insertpos(tail,3,1); 
  insertpos(tail,1,2);
  insertpos(tail,2,4);
  insertpos(tail,4,3);
  print(tail);
  deletenode(tail,3);
  print(tail);
}