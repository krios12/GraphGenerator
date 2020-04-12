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

    S->show();
    cout<< endl;
    L->show();





}
