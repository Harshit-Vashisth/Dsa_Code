#include<iostream>
using namespace std;
 class Node{
    public:
    int data;
    Node* next=NULL;
    Node(int val){
        data=val;
        next=NULL;
    }
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        
    }
 };
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<" NULL\n";
}
void inserthead(Node* &head,int val){
     Node* temp=new Node(val);
    if(head==NULL){
       
        head=temp;
        return;
    }
    temp->next=head; 
    head=temp;
    
}
void deleteNode(Node* &head,int pos ,Node* &tail){
    if(pos==1)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    else
    {
        int cnt=1;
        Node* prev=NULL;
        Node* curr=head;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        return ;
    }
}
void inserttail(Node* &tail,int val){
    Node* temp=new Node(val);
    if(tail==NULL)
    {
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}
void atpos(Node* &head,Node* &tail,int pos,int val){
    int cnt=1;  
    if(pos==1){
    inserthead(head,val);
    return;
    }
    Node* temp=head;
    //for last /if(len==pos-1)
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }

    Node* insertNo=new Node(val);
    if(temp->next==NULL){
        inserttail(tail,val);
    }
    insertNo->next=temp->next;
    temp->next=insertNo;
    
}
int main(){
    Node* n;
    n=new Node(10); 
    Node* tail=n;
    print(n);
    inserthead(n,7);
    inserthead(n,3);
    print(n);
    inserttail(tail,20);
    inserttail(tail,30);
    inserttail(tail,40);
    print(n);
    atpos(n,tail,3,90);
    print(n);
    deleteNode(n,3,tail);
    print(n);
}
