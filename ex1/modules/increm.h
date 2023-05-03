#include "systemc.h"

SC_MODULE(increm) {
  sc_in<short> A;
  sc_in<bool> clk;
  sc_out<short> res;
  
  void do_increm(){
      if(A.read() == 99) {
        //Faz nada...
      } else {
        short end = A.read() + 1;
        res.write(end);
      }
  }
  
  SC_CTOR(increm) {
    SC_METHOD(do_increm);
    sensitive << clk.neg();
  }
  
};