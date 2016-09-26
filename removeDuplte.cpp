#include <iostream>
#include <vector>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* del(ListNode* head)
{
    if(!head)
        return NULL;
    ListNode* temp=head;
    while(temp->next)
    {
        if(temp->val==temp->next->val)
        {
            temp->next=temp->next->next;
        }else
            temp=temp->next;
    }
    return head;
}
ListNode* create(vector<int>&v)
{
    ListNode*head=new ListNode(v[0]);
    ListNode*temp=head;
    for(int i=1;i<v.size();i++){
        head->next= new ListNode(v[i]);
        head=head->next;
    }
    return temp;
}
void print(ListNode*head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    ListNode*head =create(v);
    print(head);
    head=del(head);
    print(head);
    return 0;
}
