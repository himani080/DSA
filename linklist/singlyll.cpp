#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for value:"<<value<<endl;
    }

};
void insertathead(node*&head,int data)
{
   node*temp=new node(data);
   temp->next=head;
   head=temp;

}
void insertattail(node*&tail,int data)
{
    node*temp=new node(data);
    tail->next=temp;
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
    temp->next=nodetoinsert;
    

}
int lengthh(node*&head)
{
    int len=0;
    
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}
node*middle(node*&head)
{
    node*temp=head;
    int cnt=1;
    int len=lengthh(head);
    int mid=len/2;
    while(cnt<mid){
        temp=temp->next;
        cnt++;
    }
    return temp;
}
node* kreverse(node*&head,int k)
{
    int count=0;
    node* forward=NULL;
    node*prev=NULL;
    node*current=head;
    if(head==NULL)
    {
        return NULL;
    }

   while(current!=NULL && count<k){
    forward=current->next;
    current->next=prev;
    prev=current;
    current=forward;
    count++;
   }
   if(forward!=NULL)
   {
    head->next=kreverse(forward,k);
   }

   return prev;


}
bool floyddetect(node*&head)
{
    node*slow=head;
    node*fast=head;
    while(slow!=NULL&&fast!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast)
        {
            return true;
        }

    }
    return false;



}
bool iscircular(node*&head)
{
    node*temp=head->next;
    if(head==NULL)
    {
        return true;
    }
    while(temp!=NULL&& temp!=head)
    {
        temp=temp->next;
    }
    if(temp==head)
    {
        return true;
    }
    return false;
}
node* reverse(node*&head)
{
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*prev=NULL;
    node*current=head;
    node*forward=NULL;
    while(current!=NULL)
    {
       forward=current->next;
       current->next=prev;
       prev=current;
       current=forward;
    }
    return prev;
}
// node*middlenew(node*&head)
// {
//     if(head==NULL){
        
//     }
// }
void deletenode(int position,node*&head){
    node*prev=NULL;
    node*current=head;
    if(position==1){
        head= current->next;
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
    node*temp=NULL;
    insertattail(tail,12);
    insertatposition(head,tail,3,234);
    insertatposition(head,tail,3,24);
    insertatposition(head,tail,4,45);
    print(head);
    cout<<"head "<<head->data;
    cout<<"tail "<<tail->data;
    cout<<"after reversing"<<endl;
    // deletenode(3,head);
//   temp=middle(head);
 head=kreverse(head,2);
    print(head);
    if(iscircular(head)==true)
     {
        cout<<"ll is circular";
     }
     else{
        cout<<"ll is not circular";
     }
//   cout<<temp->data<<endl;
}