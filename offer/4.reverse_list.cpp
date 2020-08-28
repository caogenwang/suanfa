typedef struct _List
{
    int val;
    struct _List *next;
    struct _List *pre;
}List;

List *reverse(List *head)
{
    if (head == nullptr)
        return head;
    List *p,*q,*t;
    p = head;
    q = nullptr;
    while (p != nullptr)
    {
        t = p->next;
        p->next = q;
        q = p;
        p = t;
    }
    return q;    
}
List *Dreverse(List *head)
{
    if (head == nullptr)
        return head;
    List *p,*q,*t;
    p = head;
    while (p != nullptr)
    {
        t = p->next;
        p->next = q;
        p->pre = t;
        q = p;
        p = t;
    }
    return q;
}

List *deleteDuplicates(List *head) {
    if (!head)
        return head;
    List *p,*q,*t;
    p = head;
    q = p->next;
    while(q != nullptr)
    {
        if (p->val == q->val)
        {
            p->next = q->next;
            q = q->next;
        }
        else
        {
            p = q;
            q = p->next;
        }   
    }
    return head;
}

bool HasCycle(List*head)
{
    if(!head)
        return false;
    List *fast = head;
    List *slow = head;
    while (fast != nullptr && slow != nullptr)
    {
        if(slow == fast)
            return true;
        slow = slow->next;
        if(fast->next != nullptr)
            fast = fast->next->next;
    }
    return false;
}
List* NthFromEnd(List* head, int k)
{
    if(!head)
        return nullptr;
    List *pre = head;
    List *after = head;
    for(int i = 0;i<k;i++)
        pre = pre->next;
    while (pre != nullptr)
    {
        pre = pre->next;
        after = after->next;
    }
    return after;
}

List *Dreverse(List *head)
{
    if(head == nullptr)
        return head;
    List *pre,*pointer,*temp;
    pre = nullptr;
    pointer = head;
    while (pointer != nullptr)
    {
        temp = pointer->next;
        pointer->next = pre;
        pointer->pre = temp;
        pre = pointer;
        pointer = temp;
    }
    return pre;
}