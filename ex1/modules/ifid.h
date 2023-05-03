#include "systemc.h"
#include <vector>


SC_MODULE(ifid) {
  sc_in<bool> clk;
  sc_in<short> r1endin, r2endin, rendin, opCodein, pcendin;
  sc_out<short> r1endout, r2endout, rendout, opCodeout, pcendout;
  
  short dados[5] = {0 ,0, 0, 0, 0};
  
  void do_ifid(){
    if(clk == 0) {
      for(short x = 0; x < 5; x++){cout<<dados[x]<<" ";} cout << endl;
      opCodeout.write(dados[0]);
      r1endout.write(dados[1]);
      r2endout.write(dados[2]);
      rendout.write(dados[3]);
      pcendout.write(dados[4]);
    }
    if(clk == 1) {
      dados[0] = opCodein.read();
      dados[1] = r1endin.read();
      dados[2] = r2endin.read();
      dados[3] = rendin.read();
      dados[4] = pcendin.read();
    }
  }
  
  SC_CTOR(ifid) {
    SC_METHOD(do_ifid);
    sensitive << clk.pos() << clk.neg();
  }
  
};