#
# Makefile
#
#  The Makefile is a rule-based script which is often used to
# facilitate the compilation of source programs. 
#
#  The standard procedure is to compile a source file, such as hello.c, as
# follows:
#
#	make hello
#
#  The CC variable tells the make command what compiler we're going to
# use to compile our files.  In this case, we're using gcc and we're
# passing the parameters that are stored in the string LIBS to it.
#
#  The arguments following `CC' illustrate the commands used to invoke and
# run the compiler, in the default case: gcc. You may also supply any
# additional command-line arguments to gcc, as the `$(LIBS)' argument
# includes any programming libraries during compilation.
#

CC = gcc $(LIBS)

#  If using the C++ compiler, make will work with any source files ending
# with a `.cc' suffix.
#
CXX = g++ $(LIBS)

#  The LIBS variable defines any libraries which will be used during 
# the compilation of the source program(s). 
#
#  By default, it will include the math library, which is required for
# some mathematical functions in various programs (especially when
# using the `math.h' header file.
#
#  Additional libraries may be added, simply by adding additional
# -lLIBRARY, where `LIBRARY' is the name of that particular library (m is
# the math library).
#
#  LIBC is always included, as per compiler defaults.
#
LIBS = -lm
