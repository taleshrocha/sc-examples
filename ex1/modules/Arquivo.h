#ifndef Arquivo_hpp
#define Arquivo_hpp

#include <vector>
#include <iostream>

class Arquivo{
    private:
        std::string local; //<! String que aponta para o local do arquivo

    public:
        //! Construtor vazio para objeto do tipo Arquivo
        Arquivo();

        /*! Construtor do objeto do tipo Arquivo
                @param local_ string que indica o local do arquivo
        */
        Arquivo(std::string local_);

        /*! Método que retorna as linhas de um arquivo
                @return Um vetor de strings contendo as linhas do arquivo
        */
        std::vector<std::string> lerLinhas();
};
#endif //Arquivo_hpp