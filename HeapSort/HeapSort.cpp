#include <iostream>

using namespace std;


void Max_Heapify(int aray[], int raiz, int tamanho) 
{
    int filhoEsq = 2*raiz + 1;  
    int filhoDir = 2*raiz + 2; 
    int maior = raiz;  


    if (filhoEsq < tamanho && aray[filhoEsq] > aray[maior]) 
        maior = filhoEsq;


    if (filhoDir < tamanho && aray[filhoDir] > aray[maior]) 
        maior = filhoDir;

    if (maior != raiz)
    {
        swap(aray[raiz], aray[maior]); 

        Max_Heapify(aray, maior, tamanho); 
    }
}

void HeapSort(int aray[], int tamanho)
{
    for (int i = ((tamanho / 2) - 1); i >= 0; i--)
        Max_Heapify(aray, i, tamanho);

    for (int i=(tamanho-1); i>=0; i--)
    {
        swap(aray[0], aray[i]);

        Max_Heapify(aray, 0, i);
    }
}

int main()
{
    int aray[] = {5,1,5,8,9,3,1,8,58,582,84,85,1,0,14,5,888};
    int tamanho = sizeof(aray)/sizeof(aray[0]);

   cout << "Antes de ordenar: \n";
    for (int i=0; i<tamanho; ++i)
        cout << aray[i] << " ";
    cout << "\n";;

    HeapSort(aray, tamanho);

    cout << "Depois de ordenar: \n";
    for (int i=0; i<tamanho; ++i)
        cout << aray[i] << " ";
    cout << "\n";;

    return 0;
}