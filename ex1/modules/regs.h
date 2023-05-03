#include "systemc.h"
#include <utility>

SC_MODULE(regs) {
  	sc_in<short> r1end, r2end, rend, escData;
  	sc_in<bool> escReg, clk;
    sc_out<short> r1, r2;
  
  	short dadosr[100];
  
  void do_regs() {
    if(escReg) {
      dadosr[rend] = escData.read();cout<<"reg-"<<rend<<" escrito "<<dadosr[rend]<<endl;
    }
  	r1.write(dadosr[r1end]);cout<<"reg1-"<<r1end<< " lido "<<dadosr[r1end]<<endl;
    r2.write(dadosr[r2end]);cout<<"reg2-"<<r2end<< " lido "<<dadosr[r2end]<<endl;
    
  }
  
  SC_CTOR(regs) {
    SC_METHOD(do_regs);
    //sensitive << clk.neg();
    sensitive << r1end << r2end << rend << escData << escReg;
  }
};