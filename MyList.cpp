#ifndef MYLIST_CPP
#define MYLIST_CPP

#include <cstdio>
#include "MyList.h"
#include "MyPageManager.h"

MyList::MyList(void){
    tam = 0;
    root = NULL;
}

void MyList::add(int x){
    node *nuevo = new node;
    nuevo->valor = x;
    nuevo->id = tam;
    nuevo->next = NULL;
    if(tam == 0)
        root = nuevo;
    else{
        node* temp = root;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nuevo;
    }

    tam++;
    MyPageManager pageManger("file.txt");
    pageManger.save(tam-1, nuevo);
}

void MyList::deleteElem(int pos){
    if(pos < tam){
        if(pos == 0){
            root = root->next;
        }else{
            int i = 0;
            node* temp = root;
            while (i +1 != pos){
                temp = temp->next;
                i++;
            }
            temp->next = temp->next->next;
        }
        tam--;
     }
}

void MyList::levantarLista(char* nameFile, int cant){    
    MyPageManager pageManager(nameFile);    
    if(cant != 0){
        root = pageManager.recover(0, root);
        node* temp = root;
        node* temp2 = new node;
        for(int i = 1; i < cant; i++){
            node* nuevo = pageManager.recover(i,temp2);
            temp->next = nuevo;
            temp = nuevo;
        }
        tam = cant;
    }
}

void MyList::imprimir(){
    node* temp = root;
    for(int i = 0; i < tam; i++){
        printf("%d%c", temp->valor, i + 1 != tam ? ' ' : '\n');
        temp = temp->next;        
    }
}

int MyList::getSize(){
    return tam;
}

#endif


