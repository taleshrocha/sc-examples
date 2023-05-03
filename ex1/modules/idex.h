#include "systemc.h"
#include <vector>


SC_MODULE(idex) {
  sc_in<bool> clk;
  sc_in<short> r1in, r2in, rendin, pcendin, aluOpin, r1endin;
  sc_in<bool> escRegin, escMemin, lerMemin, pularin;
  sc_out<short> r1out, r2out, rendout, pcendout, aluOpout, r1endout;
  sc_out<bool> escRegout, escMemout, lerMemout, pularout;
  
  short dados[6] = {0 ,0, 0, 0, 0, 0};
  bool dadosb[4];
  
  void do_idex(){
    if(clk == 0) {
      for(short x = 0; x < 6; x++){cout<<dados[x]<<" ";} for(short x = 0; x < 4; x++){cout<<dadosb[x]<<" ";} cout << endl;
      r1out.write(dados[0]);
      r2out.write(dados[1]);
      rendout.write(dados[2]);
      pcendout.write(dados[3]);
      aluOpout.write(dados[4]);
      r1endout.write(dados[5]);
      escRegout.write(dadosb[0]);
      escMemout.write(dadosb[1]);
      lerMemout.write(dadosb[2]);
      pularout.write(dadosb[3]);
    }
    if(clk == 1) {
    dados[0] = r1in.read();
    dados[1] = r2in.read();
    dados[2] = rendin.read();
    dados[3] = pcendin.read();
    dados[4] = aluOpin.read();
    dados[5] = r1endin.read();
    dadosb[0] = escRegin.read();
    dadosb[1] = escMemin.read();
    dadosb[2] = lerMemin.read();
    dadosb[3] = pularin.read();
  	}
  }
  
  SC_CTOR(idex) {
    SC_METHOD(do_idex);
    sensitive << clk.pos() << clk.neg();
  }
  
};