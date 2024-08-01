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
        cout<<"memory free at value "<<value<<endl;
    }

};

void insertatposition(node*&tail,int element,int data)
{
    if(tail==NULL){
        node*temp=new node(data);
        tail=temp;
        temp->next=temp;

    }
    else{
      node*current=tail;
      node*temp=new node(data);

      while(current->data!=element){
        current=current->next;
      }
      temp->next=current->next;
      current->next=temp;

    }

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
void deletenode(int element,node*&tail){
   node*prev=tail;
   node*current=prev->next;
   int cnt=1;
   while(current->data!=element)
   {
    prev=current;
    current=current->next;
   }
   prev->next=current->next;
   if(current==prev)
   {
    tail=NULL;
   }
   if(tail==current)
   {
    tail=prev;
   }
   current->next=NULL;
   delete current;
}
void print(node*&tail){
    node*temp=tail;
   do
   {
    cout<<tail->data<<" ";
    tail=tail->next;
   } while (tail!=temp);
   cout<<endl;
   
    
   
}
int main()
{
    
    // cout<<node1->data<<endl;
    // cout<<node1->next;
    node*tail=NULL;
   
    insertatposition(tail,3,22);
     insertatposition(tail,22,26);
     insertatposition(tail,22,2);
     if(iscircular(tail))
     {
        cout<<"ll is circular";
     }
     else{
        cout<<"ll is not circular";
     }
   
    
    // cout<<"tail "<<tail->data;
    // cout<<"after deleted node";
    // deletenode(26,tail);
    print(tail);
}