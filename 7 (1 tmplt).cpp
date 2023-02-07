#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 500;

template <typename T>
class Queue
{
public:
    T a[MAX_SIZE];
    int l,r;

    Queue()
    {
        l = 0;
        r = -1;
    }
    // O(1)
    void enqueue(T value)
    {
        if(r+1 >= MAX_SIZE)
        {
            cout<<"Queue is full\n";
            return;
        }
        r++;
        a[r] = value;
    }

    // O(1)
    void dequeue()
    {
        if(l > r)
        {
            cout<<"Queue is empty\n";
            return;
        }
        l++;
    }
    //O(1)
    T front()
    {
        if(l>r)
        {
            cout<<"Queue is empty\n";
            return T();
        }
        return a[l];
    }
    //O(1)
    int size()
    {
        return r-l+1;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    cout<<"Q size : "<<q.size()<<"\n";
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();

    cout<<"Q size : "<<q.size()<<"\n";
    return 0;
}
