#include <iostream>

using namespace std;

class element
{
    public:
    int nr;
    element *next;

    element()
    {
        next = 0;
    }
};



class kolekcja
{
    public:
    element *first;;

    kolekcja()
    {
        first = 0;
    }
    void add(int i)
    {
        element *tmp= new element;
        tmp->nr = i;
        if (first==0)
        {
            first = tmp;
        }
        else
        {
            element *temp = first;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = tmp;
            tmp->next = 0;
        }
    }

    void del (int i)
    {
        if (i==1)
        {
            element *temp = first;
            first = temp->next;
            delete temp;
        }
        else if (i>=2)
        {
            int j = 1;
            element *temp = first;
            while (temp)
            {
                if ((j+1)==i) break;
                temp = temp->next;
                j++;
            }
            if (temp->next->next==0)
            {
            delete temp->next;
            }
            else
            {
                element *deleted = temp->next;
                temp->next = temp->next->next;
                delete deleted;
            }
        }
    }

    void show()
    {
        element *temp = first;
        while (temp)
        {
            cout << temp->nr << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
















int main()
{
    //int n;
    //cout << "Podaj liczbe wierzcholkow: ";
    //cin >> n;

    kolekcja *S = new kolekcja;
    kolekcja *L = new kolekcja;

    S->add(1);
    S->add(2);
    S->add(3);
    S->add(4);
    S->add(5);

    S->show();
    cout << endl << endl;

    S->del(1);
    S->del(1);
    S->del(1);
    S->del(1);
    //S->del(1);

    S->show();



}
