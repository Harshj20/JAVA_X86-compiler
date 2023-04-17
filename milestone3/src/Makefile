# Compiler settings
CC = g++

# Flex and Bison settings
FLEX = flex
BISON = bison
BFLAGS = -d -t -v

# Source files
LEXER = lexer.l
PARSER = parser.y
SYMBOL_TABLE = SymTable.cpp
CODE_GEN = codeGen.cpp
# Object file
OBJECT = milestone3

# Build rule for the object file
$(OBJECT): $(LEXER) $(PARSER)
	$(FLEX) $(LEXER)
	$(BISON) $(BFLAGS) $(PARSER)
	$(CC) -c $(SYMBOL_TABLE)
	$(CC) -c $(CODE_GEN)
	$(CC) SymTable.o lex.yy.c parser.tab.c codeGen.o -o $(OBJECT)
	rm -f lex.yy.c parser.tab.c parser.tab.h parser.output SymTable.o codeGen.o

# Clean rule
clean:
	rm -f $(OBJECT) *.dot *.csv *.ps *.svg *.txt *.3ac *.s *.o
run:
	gcc -c code.s -o code.o
	gcc code.o -o code

	
