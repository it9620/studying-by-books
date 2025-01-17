grammar Simple;

prog:   classDef+ ; // match one or more class definitions

classDef
    :   'class' ID '{' member+ '}'
        {System.out.println("class "+$ID.text);}
    ;

member
    :   'int' ID ';'                       // field definition
        {System.out.println("var "+$ID.text);}
    |   'int' f=ID '(' ID ')' '{' stat '}' // method definition
        {System.out.println("method: "+$f.text);}
    ;

stat
    :   expr ';'
        {System.out.println("found expr: "+$text);}
    |   ID '=' expr ';'
        {System.out.println("found assign: "+$text);}
    ;

expr
    :   INT 
    |   ID '(' INT ')'
    ;

INT :   [0-9]+ ;
ID  :   [a-zA-Z]+ ;
WS  :   [ \t\r\n]+ -> skip ;
