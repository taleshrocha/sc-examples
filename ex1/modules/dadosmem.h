#include "systemc.h"
#include <utility>
#include <iostream>

SC_MODULE(dadosmem) {
  	sc_in<short> end, escData;
  	sc_in<bool> escMem, lerMem, clk;
    sc_out<short> dadoSaida;
  
  	short dados[100];
  
  void do_dadosmem() { 
    if(escMem.read()) {
      dados[end] = escData.read();
      cout <<"dado-"<<end<<" escrito: " <<dados[end]<<endl;
    } else if(lerMem.read()) {
      dadoSaida.write(dados[end]);
      cout <<"dado-"<<end<<" lido: " <<dados[end]<<endl;
    } 
  }
  
  SC_CTOR(dadosmem) {
    SC_METHOD(do_dadosmem);
    sensitive << end << escData << escMem << lerMem;
  }
};