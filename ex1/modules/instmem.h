#include "systemc.h"
#include <utility>

SC_MODULE(instmem) {
  	sc_in<short> end;
    sc_in<bool> clk;
    sc_out<short> r1end, r2end, opCode, rend;
  
  	std::pair<std::pair<short, short>, std::pair<short, short>> dados[100];
  
  void do_instmem() {
  	opCode.write(dados[end].first.first);
    r1end.write((dados[end]).second.first);
    r2end.write((dados[end]).second.second);
      rend.write((dados[end]).first.second);
  }
  
  SC_CTOR(instmem) {
    SC_METHOD(do_instmem);
    sensitive <<  clk.neg();
  }
};