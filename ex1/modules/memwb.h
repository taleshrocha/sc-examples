#include "systemc.h"
#include <vector>


SC_MODULE(memwb) {
  sc_in<bool> clk;
  sc_in<short> resin, memDadoin, rendin;
  sc_in<bool> escRegin, lerMemin;
  sc_out<short> resout, memDadoout, rendout;
  sc_out<bool> escRegout, lerMemout;
  
  short dados[3] = {0 ,0, 0};
  bool dadosb[2];
  
  void do_memwb(){ 
    if(clk == 0){
      for(short x = 0; x < 3; x++){cout<<dados[x]<<" ";}
      for(short x = 0; x < 2; x++){cout<<dadosb[x]<<" ";} cout << endl;
      resout.write(dados[0]);
      memDadoout.write(dados[1]);
      rendout.write(dados[2]);
      escRegout.write(dadosb[0]);
      lerMemout.write(dadosb[1]);
    }
    if(clk == 1){
      dados[0] = resin.read();
      dados[1] = memDadoin.read();
      dados[2] = rendin.read();
      dadosb[0] = escRegin.read();
      dadosb[1] = lerMemin.read();
    }
  }
  
  SC_CTOR(memwb) {
    SC_METHOD(do_memwb);
    sensitive << clk.pos() << clk.neg();
  }
  
};