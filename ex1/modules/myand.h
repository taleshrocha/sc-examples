#include "systemc.h"

SC_MODULE(myand) {
  sc_in<bool> A, B;
  sc_out<bool> res;
  
  void do_myand(){
    res.write(A.read() && B.read());
  }
  
  SC_CTOR(myand) {
    SC_METHOD(do_myand);
    sensitive << A << B;
  }
  
};