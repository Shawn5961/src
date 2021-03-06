#include <stdio.h>
#include "LOGIC.hpp"

int main()
{
	Logic logicTester;
	srand(time(NULL));

	printf("1 AND 1: %c\n", logicTester.AND('1', '1'));
	printf("1 AND 0: %c\n", logicTester.AND('1', '0'));
	printf("0 AND 1: %c\n", logicTester.AND('0', '1'));
	printf("0 AND 0: %c\n", logicTester.AND('0', '0'));

	printf("\n1 OR 1: %c\n", logicTester.OR('1', '1'));
	printf("1 OR 0: %c\n", logicTester.OR('1', '0'));
	printf("0 OR 1: %c\n", logicTester.OR('0', '1'));
	printf("0 OR 0: %c\n", logicTester.OR('0', '0'));

	printf("\nNOT 1: %c\n", logicTester.NOT('1'));
	printf("NOT 0: %c\n", logicTester.NOT('0'));

	printf("1 NAND 1: %c\n", logicTester.NAND('1', '1'));
	printf("1 NAND 0: %c\n", logicTester.NAND('1', '0'));
	printf("0 NAND 1: %c\n", logicTester.NAND('0', '1'));
	printf("0 NAND 0: %c\n", logicTester.NAND('0', '0'));

	printf("\n1 NOR 1: %c\n", logicTester.NOR('1', '1'));
	printf("1 NOR 0: %c\n", logicTester.NOR('1', '0'));
	printf("0 NOR 1: %c\n", logicTester.NOR('0', '1'));
	printf("0 NOR 0: %c\n", logicTester.NOR('0', '0'));

	printf("\n1 XOR 1: %c\n", logicTester.XOR('1', '1'));
	printf("1 XOR 0: %c\n", logicTester.XOR('1', '0'));
	printf("0 XOR 1: %c\n", logicTester.XOR('0', '1'));
	printf("0 XOR 0: %c\n", logicTester.XOR('0', '0'));

	printf("\n1 HALFSUM 1: %c\n", logicTester.HALFSUM('1', '1'));
	printf("1 HALFSUM 0: %c\n", logicTester.HALFSUM('1', '0'));
	printf("0 HALFSUM 1: %c\n", logicTester.HALFSUM('0', '1'));
	printf("0 HALFSUM 0: %c\n", logicTester.HALFSUM('0', '0'));

	printf("\n1 HALFCARRY 1: %c\n", logicTester.HALFCARRY('1', '1'));
	printf("1 HALFCARRY 0: %c\n", logicTester.HALFCARRY('1', '0'));
	printf("0 HALFCARRY 1: %c\n", logicTester.HALFCARRY('0', '1'));
	printf("0 HALFCARRY 0: %c\n", logicTester.HALFCARRY('0', '0'));

	printf("\n1 FULLSUM 1 CARRY 1: %c\n", logicTester.FULLSUM('1', '1', '1'));
	printf("1 FULLSUM 1 CARRY 0: %c\n", logicTester.FULLSUM('1', '1', '0'));
	printf("1 FULLSUM 0 CARRY 1: %c\n", logicTester.FULLSUM('1', '0', '1'));
	printf("1 FULLSUM 0 CARRY 0: %c\n", logicTester.FULLSUM('1', '0', '0'));
	printf("0 FULLSUM 1 CARRY 1: %c\n", logicTester.FULLSUM('0', '1', '1'));
	printf("0 FULLSUM 1 CARRY 0: %c\n", logicTester.FULLSUM('0', '1', '0'));
	printf("0 FULLSUM 0 CARRY 1: %c\n", logicTester.FULLSUM('0', '0', '1'));
	printf("0 FULLSUM 0 CARRY 0: %c\n", logicTester.FULLSUM('0', '0', '0'));

	printf("\n1 FULLCARRY 1 CARRY 1: %c\n", logicTester.FULLCARRY('1', '1', '1'));
	printf("1 FULLCARRY 1 CARRY 0: %c\n", logicTester.FULLCARRY('1', '1', '0'));
	printf("1 FULLCARRY 0 CARRY 1: %c\n", logicTester.FULLCARRY('1', '0', '1'));
	printf("1 FULLCARRY 0 CARRY 0: %c\n", logicTester.FULLCARRY('1', '0', '0'));
	printf("0 FULLCARRY 1 CARRY 1: %c\n", logicTester.FULLCARRY('0', '1', '1'));
	printf("0 FULLCARRY 1 CARRY 0: %c\n", logicTester.FULLCARRY('0', '1', '0'));
	printf("0 FULLCARRY 0 CARRY 1: %c\n", logicTester.FULLCARRY('0', '0', '1'));
	printf("0 FULLCARRY 0 CARRY 0: %c\n", logicTester.FULLCARRY('0', '0', '0'));

	printf("\nMULTIPLEX| a |x0 |x1 |out|\n");
	printf("--------------------------\n");
	printf("MULTIPLEX| 1 | 1 | 1 | %c |\n", logicTester.MULTIPLEX('1', '1', '1'));
	printf("MULTIPLEX| 0 | 1 | 1 | %c |\n", logicTester.MULTIPLEX('0', '1', '1'));
	printf("MULTIPLEX| 1 | 1 | 0 | %c |\n", logicTester.MULTIPLEX('1', '1', '0'));
	printf("MULTIPLEX| 0 | 1 | 0 | %c |\n", logicTester.MULTIPLEX('0', '1', '0'));
	printf("MULTIPLEX| 1 | 0 | 1 | %c |\n", logicTester.MULTIPLEX('1', '0', '1'));
	printf("MULTIPLEX| 0 | 0 | 1 | %c |\n", logicTester.MULTIPLEX('0', '0', '1'));
	printf("MULTIPLEX| 1 | 0 | 0 | %c |\n", logicTester.MULTIPLEX('1', '0', '0'));
	printf("MULTIPLEX| 0 | 0 | 0 | %c |\n", logicTester.MULTIPLEX('0', '0', '0'));

	printf("\nDEMUX| a |in |out0 |out1 |\n");
	printf("--------------------------\n");
	logicTester.DEMUX('1', '1');
	printf("DEMUX| 1 | 1 |  %c  |  %c  |\n", logicTester.getOut0(), logicTester.getOut1());
	logicTester.DEMUX('1', '0');
	printf("DEMUX| 1 | 0 |  %c  |  %c  |\n", logicTester.getOut0(), logicTester.getOut1());
	logicTester.DEMUX('0', '1');
	printf("DEMUX| 0 | 1 |  %c  |  %c  |\n", logicTester.getOut0(), logicTester.getOut1());
	logicTester.DEMUX('0', '0');
	printf("DEMUX| 0 | 0 |  %c  |  %c  |\n", logicTester.getOut0(), logicTester.getOut1());
	
	printf("\nRSNANDL| s | r | q |qbar |\n");
	printf("--------------------------\n");
	logicTester.NANDL('0', '0');
	printf("RSNANDL| 0 | 0 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NANDL('0', '1');
	printf("RSNANDL| 0 | 1 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NANDL('1', '1');
	printf("RSNANDL| 1 | 1 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NANDL('0', '1');
	printf("RSNANDL| 0 | 1 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NANDL('1', '0');
	printf("RSNANDL| 1 | 0 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NANDL('1', '1');
	printf("RSNANDL| 1 | 1 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NANDL('1', '0');
	printf("RSNANDL| 1 | 0 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NANDL('0', '1');
	printf("RSNANDL| 0 | 1 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());

	printf("\nRSNORL| s | r | q |qbar |\n");
	printf("-------------------------\n");
	logicTester.NORL('1', '1');
	printf("RSNORL| 1 | 1 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NORL('0', '1');
	printf("RSNORL| 0 | 1 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NORL('0', '0');
	printf("RSNORL| 0 | 0 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NORL('0', '1');
	printf("RSNORL| 0 | 1 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NORL('1', '0');
	printf("RSNORL| 1 | 0 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NORL('0', '0');
	printf("RSNORL| 0 | 0 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NORL('1', '0');
	printf("RSNORL| 1 | 0 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());
	logicTester.NORL('0', '1');
	printf("RSNORL| 0 | 1 | %c |  %c  |\n", logicTester.getQ(), logicTester.getQBar());

	printf("\nRandom Clock tests:\n");
	printf("Result 1: %c\n", logicTester.CLOCK());
	printf("Result 2: %c\n", logicTester.CLOCK());
	printf("Result 3: %c\n", logicTester.CLOCK());
	printf("Result 4: %c\n", logicTester.CLOCK());
	printf("Result 5: %c\n", logicTester.CLOCK());
	printf("Result 6: %c\n", logicTester.CLOCK());

	printf("\nCLOCKRSNAND| s | r |clock| q |qbar |\n");
	printf("------------------------------------\n");
	logicTester.CLOCKRSNAND('0', '0', logicTester.CLOCK());
	printf("CLOCKRSNAND| 0 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.CLOCKRSNAND('0', '1', logicTester.CLOCK());
	printf("CLOCKRSNAND| 0 | 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.CLOCKRSNAND('1', '0', logicTester.CLOCK());
	printf("CLOCKRSNAND| 1 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.CLOCKRSNAND('1', '1', logicTester.CLOCK());
	printf("CLOCKRSNAND| 1 | 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.CLOCKRSNAND('1', '0', logicTester.CLOCK());
	printf("CLOCKRSNAND| 1 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.CLOCKRSNAND('1', '1', logicTester.CLOCK());
	printf("CLOCKRSNAND| 1 | 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.CLOCKRSNAND('1', '0', logicTester.CLOCK());
	printf("CLOCKRSNAND| 1 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());

	printf("\nEDGEFLIPFLOP| s | r |clock| q |qbar |\n");
	printf("------------------------------------\n");
	logicTester.EDGEFLIPFLOP('0', '0', logicTester.CLOCK());
	printf("EDGEFLIPFLOP| 0 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.EDGEFLIPFLOP('0', '1', logicTester.CLOCK());
	printf("EDGEFLIPFLOP| 0 | 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.EDGEFLIPFLOP('1', '0', logicTester.CLOCK());
	printf("EDGEFLIPFLOP| 1 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.EDGEFLIPFLOP('1', '1', logicTester.CLOCK());
	printf("EDGEFLIPFLOP| 1 | 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.EDGEFLIPFLOP('1', '0', logicTester.CLOCK());
	printf("EDGEFLIPFLOP| 1 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.EDGEFLIPFLOP('1', '1', logicTester.CLOCK());
	printf("EDGEFLIPFLOP| 1 | 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.EDGEFLIPFLOP('1', '0', logicTester.CLOCK());
	printf("EDGEFLIPFLOP| 1 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());

	printf("\nVAND\n");
	printf("1, 1, 1: %c\n", logicTester.VAND(3, '1', '1', '1'));
	printf("1, 0, 1: %c\n", logicTester.VAND(3, '1', '0', '1'));

	printf("\nJKFLIPFLOP| s | r |clock| q |qbar |\n");
	printf("------------------------------------\n");
	logicTester.JKFLIPFLOP('0', '0', logicTester.CLOCK());
	printf("JKFLIPFLOP| 0 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.JKFLIPFLOP('0', '1', logicTester.CLOCK());
	printf("JKFLIPFLOP| 0 | 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.JKFLIPFLOP('1', '0', logicTester.CLOCK());
	printf("JKFLIPFLOP| 1 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.JKFLIPFLOP('1', '1', logicTester.CLOCK());
	printf("JKFLIPFLOP| 1 | 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.JKFLIPFLOP('1', '0', logicTester.CLOCK());
	printf("JKFLIPFLOP| 1 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.JKFLIPFLOP('1', '1', logicTester.CLOCK());
	printf("JKFLIPFLOP| 1 | 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.JKFLIPFLOP('1', '0', logicTester.CLOCK());
	printf("JKFLIPFLOP| 1 | 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());

	printf("\nDLATCH| d |clock| q |qbar |\n");
	printf("---------------------------\n");
	logicTester.DLATCH('0', logicTester.CLOCK());
	printf("DLATCH| 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.DLATCH('1', logicTester.CLOCK());
	printf("DLATCH| 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.DLATCH('0', logicTester.CLOCK());
	printf("DLATCH| 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.DLATCH('1', logicTester.CLOCK());
	printf("DLATCH| 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.DLATCH('0', logicTester.CLOCK());
	printf("DLATCH| 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.DLATCH('1', logicTester.CLOCK());
	printf("DLATCH| 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());

	printf("\nDFLIPFLOP| d |clock| q |qbar |\n");
	printf("------------------------------\n");
	logicTester.DFLIPFLOP('0', logicTester.CLOCK());
	printf("DFLIPFLOP| 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.DFLIPFLOP('1', logicTester.CLOCK());
	printf("DFLIPFLOP| 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.DFLIPFLOP('0', logicTester.CLOCK());
	printf("DFLIPFLOP| 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.DFLIPFLOP('1', logicTester.CLOCK());
	printf("DFLIPFLOP| 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.DFLIPFLOP('0', logicTester.CLOCK());
	printf("DFLIPFLOP| 0 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());
	logicTester.DFLIPFLOP('1', logicTester.CLOCK());
	printf("DFLIPFLOP| 1 |  %c  | %c |  %c  |\n", logicTester.getCLOCK(), logicTester.getQ(), logicTester.getQBar());

	return 0;

}
