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
void insertattail(node*&head,node*&tail,int data)
{
    node*temp=new node(data);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
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
        // insertattail(head,tail,data);
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
    current = head;
        for (int i = 0; i < k; ++i) {
            if (current == NULL) return head; // If less than k nodes, return head
            current = current->next;
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
node* sort012(node*&head)
{
   node*temp=head;
   int count0=0;
   int count1=0;
   int count2=0;

    while(temp!=NULL)
    {
          if(temp->data==0)
          {
            count0++;
          }
          else if(temp->data==1)
          {
            count1++;
          }
          else{
            count2++;
          }
          temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(count0!=0)
        {
               temp->data=0;
               count0--;
        }
        else if(count1!=1)
        {
             temp->data=1;
             count1--;
        }
        else{
            temp->data=2;
            count2--;
        }
        temp=temp->next;
    }
    return head; 
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
node*add(node*&first,node*&second){
    int digit=0;
    int sum=0;
    int carry=0;
    node*addtail=NULL;
    node*addhead=NULL;
    while(first!=NULL&&second!=NULL)
    {
    sum=carry+first->data+second->data;
    digit=sum%10;
    insertattail(addhead,addtail,digit);
    carry=sum/10;
    first=first->next;
    second=second->next;
    }
    while(first!=NULL){
        sum=carry+first->data;
        digit=sum%10;
        insertattail(addhead,addtail,digit);
        carry=sum/10;
        first=first->next;

    }
     while(second!=NULL){
        sum=carry+second->data;
        digit=sum%10;
        insertattail(addhead,addtail,digit);
        carry=sum/10;
        second=second->next;

    }
    while(carry!=0){
        sum=carry;
        digit=sum%10;
       insertattail(addhead,addtail,digit);
        carry=sum/10;

    }
    return addtail;

    
}
node* addtwoll(node*&first,node*&second){
    first=  reverse(first);
    second=  reverse(second);
      node*ans=add(first,second);
     ans= reverse(ans);
      return ans;
     
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
    node* node1=new node(4);
    node* node2=new node(4);
    // cout<<node1->data<<endl;
    // cout<<node1->next;
    node*head=node1;
    node*tail=node1;
    // node*temp=NULL;
    // insertattail(tail,1);
    insertatposition(head,tail,2,2);
    insertatposition(head,tail,3,3);
    insertatposition(head,tail,4,5);
    // insertatposition(head,tail,4,1);
    print(head);
    node*head1=node2;
    node*tail1=node2;
    insertatposition(head1,tail1,2,2);
    insertatposition(head1,tail1,3,4);
    print(head1);
   node*temp= addtwoll(head,head1);
   print(temp);


  
    // cout<<"head "<<head->data;
    // cout<<"tail "<<tail->data;
    // cout<<"after sorting"<<endl;
    // sort012(head);
    // print(head);
    // if(reverse(head)==head)
    //     {
    //         cout<<"true";
    //     }
    //     else{
    //         cout<<"false";
    //     }
// deletenode(3,head);
// temp=middle(head);
// head=kreverse(head,2);
    // print(head);
    // if(iscircular(head)==true)
    //  {
    //     cout<<"ll is circular";
    //  }
    //  else{
    //     cout<<"ll is not circular";
    //  }
//   cout<<temp->data<<endl;
}