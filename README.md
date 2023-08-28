HELLO!  

The premise of this awful program is to compile PACL code.  

PACL is a language I had the idea for with a friend and then took it upon myself to create.  The basis of the language are a C/C++/Java-esque syntax but with a variety of features I find useful as well as a suite of libraries aimed at GUI development.

When you place // inside of /* */ comment blocks it reads as executable code.  There is also no intellisense and it will not compile if there is.

PROGRAM FLOW FOR ME SO I DONT LOSE MY MIND:

1. Read File 

Fundamental idea past here is that lexer deals with characters, parser deals with words, and AST deals with sentences/paragraphs.
Lexer gives each character or character group a basic numerical identifier so the parser can give it an AST legibile value which actually says anything important about it. These 3 steps also shouldn't necessarily be thought as "in order" it does technically do this in order, but for EACH TOKEN.  So yes, it does go LEX, PARSE, AST, but its a loop so it does it continually until EOF is reached and the AST can be converted into machine code or an intermediary code (not sure yet what my goal is)
2. Lex file 
    A. Go char by char and split into tokens (EG: all "punctuation" gets a specfic token to denote its type.  Multi-character tokens provide a much more difficult challenge. Everything that isnt a constant (as in a variable declaration value) is passed into the parser as an identifier.)

3. Parse File
    A. Take the output tokens, and sort them into the AST

4. Semantic Analysis (scope)
    A. Now this im really not too sure about.
    B. I beleive I perform syntactical checks at this stage

