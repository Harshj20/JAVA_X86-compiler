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
# Object file
OBJECT = myASTGenerator

# Build rule for the object file
$(OBJECT): $(LEXER) $(PARSER)
	$(FLEX) $(LEXER)
	$(BISON) $(BFLAGS) $(PARSER)
	$(CC) -c $(SYMBOL_TABLE)
	$(CC) SymTable.o lex.yy.c parser.tab.c -o $(OBJECT)
	rm -f lex.yy.c parser.tab.c parser.tab.h parser.output SymTable.o

# Clean rule
clean:
	rm -f $(OBJECT) *.dot *.csv *.ps *.svg


	
