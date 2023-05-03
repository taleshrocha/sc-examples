#include "systemc.h"

SC_MODULE(mux) {
  sc_in<short> A, B;
  sc_in<bool> X;
  sc_out<short> res;
  
  void do_mux(){
    if(X.read() == false) {
      res.write(A.read());
    } else {
      res.write(B.read());
    }
  }
  
  SC_CTOR(mux) {
    SC_METHOD(do_mux);
    sensitive << A << B << X;
  }
  
};