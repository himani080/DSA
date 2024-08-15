#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
    }

};
void insertathead(node*&head,int data)
{
   node*temp=new node(data);
   temp->next=head;
   head->prev=temp;
   head=temp;

}
void insertattail(node*&tail,int data)
{
    node*temp=new node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;

}
void insertatposition(node*&head,node*&tail,int position,int data)
{
    int cnt=1;
    node*temp=head;
    //firstposition
    if(position==1)
    {
        insertathead(head,data);
        return;
        
    }
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertattail(tail,data);
        return;
    }
    node*nodetoinsert=new node(data);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
    
    

}
void deletenode(int position,node*&head){
    node*prev=NULL;
    node*current=head;
    if(position==1){
       current->next->prev=NULL;
       head=current->next;
       current->next=NULL;
       delete current;
    }
    else{
        int cnt=1;
        while(cnt<position){
            prev=current;
            current=current->next;
            cnt++;
        }
       current->prev=NULL;
       prev->next=current->next;
       current->next=NULL;
       delete current;
    }
}
void print(node*&head){
    node*temp=head;
    while(temp!=NULL)
    {
     cout<<temp->data<<" ";
    temp=temp->next;
    }
   
}
int main()
{
    node* node1=new node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next;
    node*head=node1;
    node*tail=node1;
    insertattail(tail,12);
    insertatposition(head,tail,3,22);
   
    print(head);
    cout<<"head "<<head->data;
    cout<<"tail "<<tail->data;
     insertatposition(head,tail,4,31);
    //  print(head);
    cout<<"after deleted node";
    deletenode(3,head);

    print(head);
     cout<<"head "<<head->data;
    cout<<"tail "<<tail->data;
}