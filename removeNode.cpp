#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct ListNode
{
   int val;
   ListNode* next;
   ListNode(int x):val(x),next(NULL){}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    cout<<"从后向前数"<<n<<endl;
    ListNode* temp=head;
    int count=0;
    while(temp!=NULL)
    {
         count++;
         temp=temp->next;
    }
    cout<<"个数:"<<count<<endl;
    n=count-n+1;
    cout<<"从前向后数第"<<n<<endl;
    if(n==1)
    {
        return head->next;
    }
    //if(n==count)
    //{
    //    temp=head;
    //    int i=1;
    //    while(i<=n-1)
    //    {
    //        temp=temp->next;
    //        i++;
    //    }
    //    temp=NULL;
    //    return head;
    //}
    ListNode* pre=head;
    int j=1;
    while(j<n-1)
    {
        pre=pre->next;
        j++;
    }
    ListNode* del=pre->next;
    pre->next=del->next;
    del=NULL;
    return head;
}
 
int main()
{
    ListNode* head;
    ListNode* temp=new ListNode(1);
    head=temp;
    for(int i=1;i<4;i++)
    {
        temp->next=new ListNode(2*i+1);
        temp=temp->next;
    }
    head=removeNthFromEnd(head,1);
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
