Disassembler for limited MIPS instruction set written in C

disAssemble is a disassembler for MIPS code. It takes binary dumps from spim as
input and turns them into MIPS instructions based on a limited set of
instructions. The user can set flags for whether they want R-format, I-format,
J-format, or all instructions to be disassembled.

The program uses a different struct to represent each instruction type (and two
structs to represent I-format because some I-format instructions treat the
immediate field as a signed int and others treat it as an unsigned int). All
these structs become part of a union. The program uses fread to read 32 bits
into this union at a time. Each read represents one instruction.

Separate functions process the binary form of the instructions. These functions
determine which registers are being referenced (taken from the spim appendix)
and performs calculations to determine target addresses for branches and jumps.
