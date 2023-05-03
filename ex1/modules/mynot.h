#include "systemc.h"

SC_MODULE(mynot) {
  sc_in<bool> A;
  sc_out<bool> res;
  
  void do_mynot(){
    res.write(!A.read());cout<<"not="<<(!A.read())<<endl;
  }
  
  SC_CTOR(mynot) {
    SC_METHOD(do_mynot);
    sensitive << A;
  }
  
};