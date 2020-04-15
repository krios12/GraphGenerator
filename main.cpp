#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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
    int licznik;
    kolekcja()
    {
        first = 0;
        licznik = 0;
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
        licznik++;
    }

    void del (int i) // nie sprawdzam sobie zakresów liczby elementow
    {                // listy bo nie ma takiej potrzeby jeœli wiem co usuwam
        if (i==0)
        {
            element *temp = first;
            first = temp->next;
            delete temp;
        }
        else if (i>=1)
        {
            int j = 0;
            element *temp = first;
            while (temp)
            {
                if ((j+1)==i)
                {
                    break;
                }
                temp = temp->next;
                j++;
            }
            if (temp->next==0)
            {
                delete temp;
            }
            else
            {
                element *deleted = temp->next;
                temp->next = temp->next->next;
                delete deleted;
            }
        }
        licznik--;
    }

    void show()
    {
        element *temp = first;
        while (temp)
        {
            cout << temp->nr << " " ;
            temp = temp->next;
        }
        cout << endl;
    }

    int getNumber(int i)
    {
        element *temp = first;
        int x =0;
        while (temp)
        {
            if(i == x)
            {
                return temp->nr;
            }
            temp = temp->next;
            x++;
        }
    }

    bool isEmpty()
    {
        if(licznik == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};



int ** G;

void input(int p, int k, int w)
{
    G[p][k] = w;
    G[k][p] = w;
}

//n* (n-1) - TO JEST LICZA WSZYSTKICH MOZLIWYCH KRAWEDZI W GRAFIE, n to liczba wierzcholkow
int lok(int n, int licznik, int mianownik) // wyznaczam liczbę krawedzi dla danego procenta, czyli dla 50% mam licznik =1, mianownik =2
{
    int x =n*(n-1);
    x = x * licznik / mianownik;
    return x;
}

int main()
{
    srand(time( 0 ));
    int N=10;
    //cout << "Podaj liczbe wierzcholkow: ";
    //cin >> N;
    int M = lok(N,1,2);

    G = new int *[N];
    for(int i = 0; i  < N ; i++)
    {
        G[i]= new int [N];
    }

    kolekcja *S = new kolekcja;
    kolekcja *L = new kolekcja;

    int fw = (rand()%(N-1))+0;//numer pierwszego wierzcholka

    S->add(fw);

    for(int i=0; i<N;i++)
    {
        if(i!=fw)
        {
            L->add(i);
        }
    }

    int randS;
    int randL;
    int randW;

    while(!L->isEmpty())
    {
        randS = (rand()%S->licznik)+0;
        randL = (rand()%L->licznik)+0;
        randW = (rand()%100)+1;

        input(S->getNumber(randS),L->getNumber(randL),randW);

        S->add(L->getNumber(randL));
        L->del(randL);
    }

    S->show();
    L->show();
}
