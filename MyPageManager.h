#ifndef MYPAGEMANAGER_H
#define MYPAGEMANAGER_H

#include <string>
#include <fstream>

using namespace std;

class MyPageManager{
    private:
        
        fstream myFile;
        bool empty;
        long pageIdCount;

    public:

        MyPageManager(string file){
            myFile.open(file.c_str(), fstream::in | fstream::out | fstream::binary);
            if(!myFile.good())
                myFile.open(file.c_str(), fstream::in | fstream::out | fstream::trunc | fstream::binary);
        }

        ~MyPageManager(){
            myFile.close();
        }

        template<class T>
        void save(long id ,T& reg){
            myFile.seekp(id*sizeof(T), fstream::beg);
            myFile.write(reinterpret_cast<const char*>(&reg), sizeof(reg));
        }

        template<class T>
        T recover(long id, T& reg){
            myFile.seekg(id*sizeof(T), fstream::beg);
            myFile.read(reinterpret_cast<char *>(&reg), sizeof(reg));
            return reg;            
        }

};


#endif /* MYPAGEMANAGER_H */