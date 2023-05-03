#include "systemc.h"

SC_MODULE(alu) {
	sc_in<short> A, B, r1end;
    sc_in<short> opCode;
    sc_in<bool> clk;
    sc_out<short> res;
  	sc_out<bool> pula;

  void do_alu() {cout<<"Alu "<<opCode.read()<<endl;
    switch (opCode.read()) {
    	case 1: res.write(A.read() && B.read()); break; //AND
    	case 2: res.write(A.read() || B.read()); break; //OR
      	case 3: res.write(A.read() ^ B.read()); break; //XOR
      	case 4: res.write(~A.read()); break; //NOT
      	case 5: res.write(A.read() == B.read()); break; //CMP
      	case 6: res.write(A.read() + B.read()); cout<<"aleu A-"<<A.read()<<"aleu B-"<<B.read()<<endl; break; //ADD
      	case 7: res.write(A.read() - B.read());cout<<"sleu A-"<<A.read()<<"sleu B-"<<B.read()<<endl; break; //SUB
      	case 8: res.write(r1end.read());cout<<"leu A-"<<r1end.read()<<endl; break; //LD
        case 9: res.write(r1end.read()); break; //ST
        case 10: pula.write(true); break; //J
        case 11: pula.write(A.read() < 0); break; //JN
        case 12: pula.write(A.read() == 0); break; //JZ
    }
  }
  
  SC_CTOR(alu) {
  	SC_METHOD(do_alu);
    sensitive << A << B << r1end << opCode;
  }
  
};