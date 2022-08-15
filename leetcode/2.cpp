#include <iostream>
#include <cstring>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{
    int n, m;
    cin >> n >> m;
    int x;
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        p1->next = new ListNode(x);
        p1 = p1->next;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        p2->next = new ListNode(x);
        p2 = p2->next;
    }
    l1 = l1->next, l2 = l2->next;

    ListNode *dummy = new ListNode(0);
    ListNode *res = dummy;
    int add = 0;

    while (l1 != nullptr && l2 != nullptr)
    {
        dummy->next = new ListNode((l1->val + l2->val + add) % 10);
        add = (l1->val + l2->val + add) / 10;
        l1 = l1->next;
        l2 = l2->next;
        dummy = dummy->next;
    }
    while (l1 != nullptr)
    {
        dummy->next = new ListNode((l1->val + add) % 10);
        add = (l1->val + add) / 10;
        l1 = l1->next;
        dummy = dummy->next;
    }
    while (l2 != nullptr)
    {
        dummy->next = new ListNode((l2->val + add) % 10);
        add = (l2->val + add) / 10;
        l2 = l2->next;
        dummy = dummy->next;
    }

    if (add)
    {
        dummy->next = new ListNode(add);
    }

    res = res->next;

    while (res != nullptr)
    {
        cout << res->val << " ";
    }
    cout << endl;

    return 0;
}
