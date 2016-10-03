#include <cstdio>
#include "MyList.h"
#include "MyPageManager.h"

int main(){
    MyList* myList = new MyList();
    for(int i=0; i < 1; i++)
        myList->add(i+100);         
    myList->imprimir();
    int n = myList->getSize();
    for(int i = 0; i < n; i++)
        myList->deleteElem(0);    
    myList->levantarLista("file.txt", n);
    myList->imprimir();
    return 0;
}