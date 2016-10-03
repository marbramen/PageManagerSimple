#ifndef MYLIST_H
#define MYLIST_H

struct node{
    node* next;
    int valor;
    int id;
};


class MyList{
    public:         
        MyList(void);        
        void add(int);
        int getSize();
        void deleteElem(int);
        void levantarLista(char*,int);
        void imprimir();
   private:
        int tam;
        node* root;
};
#endif /*MYLIS_H*/