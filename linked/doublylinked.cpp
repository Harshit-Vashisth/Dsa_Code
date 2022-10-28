#include<iostream>
using namespace std;
class Node{
    public:
    Node* prev;
    Node* next;
    int data;
    Node(int val){
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        if(this->next!=NULL){
            this->next=NULL;
            this->prev=NULL;
        }
    }
};
void insertend(Node* &tail,int val){
    Node* temp=new Node(val);
    if(tail==NULL){
        tail=temp;
        return ;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void inserthead(Node* &head,int val){
    Node* temp=new Node(val);
    if(head==NULL){
        head=temp;
        return;
    }
    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
int getlen(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;

    }
    return len;
}
void atpos(Node* &head,Node* &tail,int val,int pos){
    if(pos==1)
    {
        inserthead(head,val);
        return ;
    }else{
        Node* prev=NULL;
        Node* curr=head;
        int cn=1;
        Node* temp=head;
        while(cn<pos-1){
            prev=curr;
            curr=curr->next;
            temp=temp->next;
            cn++;
        }
        Node* nodeput=new Node(val);
        nodeput->next=prev->next;
        prev->next=nodeput;
        nodeput->prev=prev;
        curr->prev=nodeput;
        return ;
            }
}
void deletenode(Node* &head,Node* &tail,int pos){
    if(pos==1)
    {
         Node* temp=head;
         temp->next->prev=NULL;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;
        Node* prevv=NULL;
        int cn=1;
        while(cn<pos){
            prevv=curr;
            curr=curr->next;
            cn++;
        }
        
        curr->prev=NULL;
        prevv->next=curr->next;
        curr->next=NULL;
        delete(curr);
    }
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  -> ";
        temp=temp->next;

    }
    cout<<endl;
}
int main(){
    Node* n=new Node(90);
    inserthead(n,20);
    Node* tail=n;
    inserthead(n,10);
    insertend(tail,30);
    insertend(tail,40);
    insertend(tail,50);
    atpos(n,tail,25,3);
    print(n);
    deletenode(n,tail,2);
    print(n);
    
}
