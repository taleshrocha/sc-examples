#include "systemc.h"

SC_MODULE(control) {
    sc_in<short> opCode;
    sc_in<bool> clk;
    sc_out<bool> escReg, escMem, lerMem, pular;
    sc_out<short> oc_out;

  void do_control() {
    oc_out.write(opCode.read());cout << oc_out.read() << endl;
    if(opCode.read() == 0) {
    escReg.write(false); 
    escMem.write(false); 
    lerMem.write(false); 
    pular.write(false);
    } else if(opCode.read() < 8) {
    escReg.write(true); 
    escMem.write(false); 
    lerMem.write(false); 
    pular.write(false);
    } else if(opCode.read() == 8) {
    escReg.write(true); 
    escMem.write(false); 
    lerMem.write(true); 
    pular.write(false);
    } else if(opCode.read() == 9) {
    escReg.write(false); 
    escMem.write(true); 
    lerMem.write(false); 
    pular.write(false);
    } else {
    escReg.write(false); 
    escMem.write(false); 
    lerMem.write(false); 
    pular.write(true);
    }
    
  }
  
  SC_CTOR(control) {
  	SC_METHOD(do_control);
    //sensitive << clk.pos();
    sensitive << opCode;
  }
  
};