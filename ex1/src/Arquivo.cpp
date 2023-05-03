#include <fstream>
#include <iostream>
#include <string>

#include "Arquivo.h"

using namespace std;

Arquivo::Arquivo(){}

Arquivo::Arquivo(std::string local_){
    local = local_;
}

std::vector<std::string> Arquivo::lerLinhas(){
    ifstream file1;
    file1.open(local);
    std::vector<string> v;
    int i = 0;
    while(i == 0) {
        string texto;
        std::getline(file1, texto);
        if(texto == "" || texto == " "){
            i = 1;
        } else {
            v.push_back(texto);
        }
        
    }
    file1.close();

    return v;
}