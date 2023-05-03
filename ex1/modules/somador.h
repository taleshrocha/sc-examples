#include "systemc.h"

SC_MODULE(somador) {
  sc_in<short> A, B;
  sc_out<short> res;
  
  void do_somador(){
    res.write(A.read() + B.read());
  }
  
  SC_CTOR(somador) {
    SC_METHOD(do_somador);
    sensitive << A << B;
  }
  
};