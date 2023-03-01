# Compiler settings
CC = g++

# Flex and Bison settings
FLEX = flex
BISON = bison
BFLAGS = -d -t -v

# Source files
LEXER = lexer.l
PARSER = parser.y

# Object file
OBJECT = myASTGenerator

# Build rule for the object file
$(OBJECT): $(LEXER) $(PARSER)
	$(FLEX) $(LEXER)
	$(BISON) $(BFLAGS) $(PARSER)
	$(CC) lex.yy.c parser.tab.c -o $(OBJECT)

# Clean rule
clean:
	rm -f $(OBJECT) lex.yy.c parser.tab.c parser.tab.h parser.output myASTGenerator parse_tree.dot
	
