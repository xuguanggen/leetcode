#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* oddeven(ListNode* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    vector<int>ji;
    vector<int>ou;
    while(head!=NULL)
    {
        int value=head->val;
        if(value%2==1)
        {
            ji.push_back(value);
        }else
            ou.push_back(value);
        head=head->next;
    }
    if(ji.size()!=0)
    {
        ListNode* ji_head=new ListNode(ji[0]);
        ListNode* ji_cur;
        ji_cur=ji_head;
        for(int i=1;i<ji.size();i++)
        {
            ji_cur->next=new ListNode(ji[i]);
            ji_cur=ji_cur->next;
        }
        if(ou.size()==0)
        {
            return ji_head;
        }else{
            ListNode* ou_head=new ListNode(ou[0]);
            ListNode* ou_cur;
            ou_cur=ou_head;
            for(int i=1;i<ou.size();i++)
            {
                ou_cur->next=new ListNode(ou[i]);
                ou_cur=ou_cur->next;
            }
            ji_cur->next=ou_head;
            return ji_head;
        }
    }else{
        ListNode* ou_head=new ListNode(ou[0]);
        ListNode* ou_cur;
        ou_cur=ou_head;
        for(int i=1;i<ou.size();i++)
        {
            ou_cur->next=new ListNode(ou[i]);
            ou_cur=ou_cur->next;
        }
        return ou_head;
    }

}
ListNode *mergeTwoLists(ListNode* l1,ListNode* l2)
{
    if(l1==NULL&&l2==NULL)
    {
        return NULL;
    }else if(l1==NULL&&l2!=NULL)
    {
        return l2;
    }else if(l2==NULL&&l1!=NULL)
    {
        return l1;
    }
    ListNode* head;
    ListNode* current=new ListNode(-1000);
    head=current;
    while(l1!=NULL&&l2!=NULL)
    {
        int val_1=l1->val;
        int val_2=l2->val;
        int value=0;
        if(val_1<=val_2)
        {
            value=val_1;
            l1=l1->next;
        }else{
            value=val_2;
            l2=l2->next;
        }
        current->next=new ListNode(value);
        current=current->next;
    }
    if(l1!=NULL)
    {
        current->next=l1;
    }
    if(l2!=NULL)
    {
        current->next=l2;
    }
    return head->next;


}
int main(){

    ListNode* head1;
    ListNode* temp=new ListNode(1);
    head1=temp;
    for(int i=1;i<10;i++)
    {
        temp->next=new ListNode(2*i+1);
        temp=temp->next;
    }
    //head=oddeven(head);
    //while(head1!=NULL)
    //{
    //    cout<<head1->val<<" ";
    //    head1=head1->next;
    //}
    //cout<<endl;
    ListNode* head2;
    temp=new ListNode(0);
    head2=temp;
    for(int i=1;i<20;i++)
    {
        temp->next=new ListNode(2*i);
        temp=temp->next;
    }
    ListNode* head3=mergeTwoLists(head1,head2);
    while(head3!=NULL)
    {
        cout<<head3->val<<" ";
        head3=head3->next;
    }
    cout<<endl;
    return 0;
}
