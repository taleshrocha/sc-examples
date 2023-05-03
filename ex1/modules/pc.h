#include "systemc.h"

SC_MODULE(pc) {
	sc_in<short> endAnt;
    sc_in<bool> clk;
    sc_out<short> proEnd;
  void do_pc() {
    proEnd.write(endAnt.read());
  }
  
  SC_CTOR(pc) {
  	SC_METHOD(do_pc);
    sensitive << endAnt;
  }
};