#include "systemc.h"
#include <vector>


SC_MODULE(exmem) {
  sc_in<bool> clk;
  sc_in<short> resin, r2in, rendin, pcendin;
  sc_in<bool> escRegin, escMemin, lerMemin, pularin, pulain;
  sc_out<short> resout, r2out, rendout, pcendout;
  sc_out<bool> escRegout, escMemout, lerMemout, pularout, pulaout;
  
  short dados[4] = {0 ,0, 0, 0};
  bool dadosb[5];
  
  void do_exmem(){
    if(clk == 0){
      for(short x = 0; x < 4; x++){cout<<dados[x]<<" ";} for(short x = 0; x < 5; x++){cout<<dadosb[x]<<" ";} cout << endl;
    resout.write(dados[0]);
    r2out.write(dados[1]);
    rendout.write(dados[2]);
    pcendout.write(dados[3]);
    escRegout.write(dadosb[0]);
    escMemout.write(dadosb[1]);
    lerMemout.write(dadosb[2]);
    pularout.write(dadosb[3]);
    pulaout.write(dadosb[4]);
    }
    if(clk == 1){
    dados[0] = resin.read();
    dados[1] = r2in.read();
    dados[2] = rendin.read();
    dados[3] = pcendin.read();
    dadosb[0] = escRegin.read();
    dadosb[1] = escMemin.read();
    dadosb[2] = lerMemin.read();
    dadosb[3] = pularin.read();
    dadosb[4] = pulain.read();
    }
  }
  
  SC_CTOR(exmem) {
    SC_METHOD(do_exmem);
    sensitive << clk.pos() << clk.neg();
  }
  
};