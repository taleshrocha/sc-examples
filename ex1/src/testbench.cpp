#include "systemc.h"

SC_MODULE(testbench) {
    sc_in<bool> Clk;
    sc_in<short> pc_end, inst_cont;

    void TbGen() {
      	while(pc_end != 30) {        
          wait();
    	}
        sc_stop();
    }

    SC_CTOR(testbench) {
        SC_THREAD(TbGen);
        sensitive << Clk;
    }
};

#include "instmem.h"
#include "pc.h"
#include "alu.h"
#include "dadosmem.h"
#include "regs.h"
#include "control.h"
#include "ifid.h"
#include "idex.h"
#include "exmem.h"
#include "memwb.h"
#include "mux.h"
#include "somador.h"
#include "increm.h"
#include "myand.h"
#include "mynot.h"
#include "Arquivo.h"
#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int sc_main(int argc, char* argv[]) {
    //Inicia os componentes necessários
    sc_clock TestClk("TestClock", SC_NS);
  
  	testbench Tb("Testbench");
  	
	instmem memDeInst("memInst");
	pc proCount("proCo");
  	alu unLoAr("unLoAr");
  	dadosmem memDeDados("memDados");
  	regs regist("registra");
  	control con("controle");
  	ifid regifid("regIfId");
  	idex regidex("regIdEx");
    exmem regexmem("regExMem");
    memwb regmemwb("regMemWb");
    
    mux mux1("mux1_2x1");
    mux mux2("mux2_2x1");
    
    somador som("somador");
    increm inc("incrementador");
  
  	myand e("e");
    mynot inv("inverso");
  
    //Criação de fios
    sc_signal<short> PC_in, PC_out;
    sc_signal<short> IMem_out1, IMem_out2, IMem_out3, IMem_out4;
    sc_signal<short> inc_out;
  	sc_signal<short> ifid_out1, ifid_out2, ifid_out3, ifid_out4, ifid_out5;
    sc_signal<short> con_out1;
    sc_signal<bool> con_out2, con_out3, con_out4, con_out5;
    sc_signal<short> reg_in1, reg_in2, reg_out1, reg_out2;
    sc_signal<bool> reg_in3;
    sc_signal<bool> idex_out1, idex_out2, idex_out3, idex_out4;
    sc_signal<short> idex_out5, idex_out6, idex_out7, idex_out8, idex_out9, idex_out10;
    sc_signal<short> ula_out1;
    sc_signal<bool> ula_out2;
    sc_signal<bool> exmem_out1, exmem_out2, exmem_out3, exmem_out4, exmem_out5;
    sc_signal<short> exmem_out6, exmem_out7, exmem_out8, exmem_out9;
    sc_signal<short> som_out;
    sc_signal<bool> and_out;
    sc_signal<short> memDad_out;
    sc_signal<bool> memwb_out1;
    sc_signal<short> memwb_out2, memwb_out3;
    sc_signal<bool> inv_out, ou_out;
    sc_signal<short> mux3_out;

    //Associação de fios
    proCount.endAnt(PC_in);
    proCount.clk(TestClk);
    proCount.proEnd(PC_out);
    inc.A(PC_out);
    inc.clk(TestClk);
    inc.res(inc_out);
  	memDeInst.end(PC_out);
  	memDeInst.r1end(IMem_out1);
    memDeInst.r2end(IMem_out2);
  	memDeInst.opCode(IMem_out3);
  	memDeInst.rend(IMem_out4);
    memDeInst.clk(TestClk);
  	regifid.clk(TestClk);
  	regifid.r1endin(IMem_out1);
  	regifid.r2endin(IMem_out2);
  	regifid.opCodein(IMem_out3);
  	regifid.rendin(IMem_out4);
  	regifid.pcendin(inc_out);
  	regifid.r1endout(ifid_out1);
  	regifid.r2endout(ifid_out2);
  	regifid.opCodeout(ifid_out3);
  	regifid.rendout(ifid_out4);
  	regifid.pcendout(ifid_out5);
    con.clk(TestClk);
  	con.opCode(ifid_out3);//ifid_out3
  	con.escReg(con_out2);
  	con.escMem(con_out3);
  	con.lerMem(con_out4);
  	con.pular(con_out5);
    con.oc_out(con_out1);
  	regist.r1end(ifid_out1);
  	regist.r2end(ifid_out2);
  	regist.rend(reg_in1);
    regist.escData(reg_in2);
  	regist.escReg(reg_in3);
    regist.r1(reg_out1);
  	regist.r2(reg_out2);
    regist.clk(TestClk);
    regidex.clk(TestClk);
    regidex.escRegin(con_out2);
    regidex.escMemin(con_out3);
    regidex.lerMemin(con_out4);
    regidex.pularin(con_out5);
    regidex.r1in(reg_out1);
    regidex.r2in(reg_out2);
    regidex.rendin(ifid_out4);
    regidex.pcendin(ifid_out5);
    regidex.aluOpin(con_out1);//con_out1
    regidex.r1endin(ifid_out1);
    regidex.escRegout(idex_out1);
    regidex.escMemout(idex_out2);
    regidex.lerMemout(idex_out3);
    regidex.pularout(idex_out4);
    regidex.r1out(idex_out5);
    regidex.r2out(idex_out6);
    regidex.rendout(idex_out7);
    regidex.pcendout(idex_out8);
    regidex.aluOpout(idex_out9);
    regidex.r1endout(idex_out10);
    unLoAr.A(idex_out5);
    unLoAr.B(idex_out6);
    unLoAr.r1end(idex_out10);
    unLoAr.opCode(idex_out9);
    unLoAr.res(ula_out1);
    unLoAr.pula(ula_out2);
    unLoAr.clk(TestClk);
    regexmem.clk(TestClk);
  	regexmem.resin(ula_out1);
  	regexmem.r2in(idex_out6);
  	regexmem.rendin(idex_out7);
  	regexmem.pcendin(idex_out8);
  	regexmem.escRegin(idex_out1);
  	regexmem.escMemin(idex_out2);
  	regexmem.lerMemin(idex_out3);
  	regexmem.pularin(idex_out4);
  	regexmem.pulain(ula_out2);
    regexmem.resout(exmem_out6);
  	regexmem.r2out(exmem_out7);
  	regexmem.rendout(exmem_out8);
  	regexmem.pcendout(exmem_out9);
  	regexmem.escRegout(exmem_out1);
  	regexmem.escMemout(exmem_out2);
  	regexmem.lerMemout(exmem_out3);
  	regexmem.pularout(exmem_out4);
  	regexmem.pulaout(exmem_out5);
    som.A(exmem_out9);
    som.B(exmem_out8);
    som.res(som_out);
    e.A(exmem_out4);
    e.B(exmem_out5);
    e.res(and_out);
    mux1.A(inc_out);
    mux1.B(som_out);
    mux1.X(and_out);
  	mux1.res(PC_in);
    memDeDados.end(exmem_out6);
  	memDeDados.escData(exmem_out7);
    memDeDados.escMem(exmem_out2);
    memDeDados.lerMem(exmem_out3);
  	memDeDados.dadoSaida(memDad_out);
    memDeDados.clk(TestClk);
  	regmemwb.clk(TestClk);
  	regmemwb.escRegin(exmem_out1);
  	regmemwb.lerMemin(exmem_out3);
  	regmemwb.resin(exmem_out6);
  	regmemwb.memDadoin(memDad_out);
  	regmemwb.rendin(exmem_out8);
  	regmemwb.escRegout(reg_in3);
  	regmemwb.lerMemout(memwb_out1);
  	regmemwb.resout(memwb_out2);
  	regmemwb.memDadoout(memwb_out3);
  	regmemwb.rendout(reg_in1);
    inv.A(memwb_out1);
    inv.res(inv_out);
  	mux2.A(memwb_out3);
    mux2.B(memwb_out2);
    mux2.X(inv_out);
    mux2.res(reg_in2);
  	Tb.Clk(TestClk);
    Tb.pc_end(inc_out);
    Tb.inst_cont(IMem_out3);
    
    //Criação de valores para as instruções e de memória
  	for(int x = 0; x<100; x++) {
      //memDeInst
      std::pair<std::pair<short, short>, std::pair<short, short>> vaz;
      std::pair<short, short> vaz2;
      vaz2.first = 0;
      vaz2.second = 0;
      vaz.first = vaz2;
      vaz.second = vaz2;
      memDeInst.dados[x] = vaz;
      //memDeDados
      memDeDados.dados[x] = 0;
      //regist
      regist.dadosr[x] = 0;
  	}
  	
    Arquivo aq1("inst.txt");
    
    //Inst
  	auto r = aq1.lerLinhas();
    auto i = r.begin();
    int x = 0;
    //Carregar instruções
    while(i != r.end()) {
        std::string campoAtual = *i;
        std::stringstream ss1;

        ss1<<campoAtual;
        std::string p;
        ss1 >> p;
      	if(!p.compare("AND")) {
          memDeInst.dados[x].first.first = 1;
        } else if(!p.compare("OR")) {
          memDeInst.dados[x].first.first = 2;
        } else if(!p.compare("XOR")) {
          memDeInst.dados[x].first.first = 3;
        } else if(!p.compare("NOT")) {
          memDeInst.dados[x].first.first = 4;
        } else if(!p.compare("CMP")) {
          memDeInst.dados[x].first.first = 5;
        } else if(!p.compare("ADD")) {
          memDeInst.dados[x].first.first = 6;
        } else if(!p.compare("SUB")) {
          memDeInst.dados[x].first.first = 7;
        } else if(!p.compare("LD")) {
          memDeInst.dados[x].first.first = 8;
        } else if(!p.compare("ST")) {
          memDeInst.dados[x].first.first = 9;
        } else if(!p.compare("J")) {
          memDeInst.dados[x].first.first = 10;
        } else if(!p.compare("JN")) {
          memDeInst.dados[x].first.first = 11;
        } else {
          memDeInst.dados[x].first.first = 12;
        }
        
        ss1 >> memDeInst.dados[x].second.first;
        ss1 >> memDeInst.dados[x].second.second;
        ss1 >> memDeInst.dados[x].first.second;

        ++i;
        ++x;
    }
  
    Arquivo aq2("mem.txt");
    
    //Mem
    auto r1 = aq2.lerLinhas();
    auto i1 = r1.begin();
    //Carregar valores para memória
    while(i1 != r1.end()) {
        std::string campoAtual = *i1;
        std::stringstream ss1;

        ss1<<campoAtual;
        short xe;
        
        ss1 >> xe;
        ss1 >> memDeDados.dados[xe];

        ++i1;
    }
  
    
  	//Inicialização dos testes
  	///========================= waveform
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("wave");
	fp->set_time_unit(1, sc_core::SC_NS);
	sc_trace(fp,proCount.proEnd,"PC");
	sc_trace(fp,TestClk,"CLK");
	//=========================
  
	sc_start();
  
  	sc_close_vcd_trace_file(fp);

	return 0;
}
