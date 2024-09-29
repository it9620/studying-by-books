grammar Hello;

r : 'hello' ID ;         // match keyword hello followed by an identifier
ID : [a-zA-Z]+ ;         // match identifiers
WS : [ \t\r\n]+ -> skip ; // skip spaces, tabs, newlines