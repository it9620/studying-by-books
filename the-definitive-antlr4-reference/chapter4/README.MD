# Chapter 4

```sh
antlr4 -o java Expr.g4
ls Expr*.java

javac Expr*.java
grun Expr prog -gui ../t.expr
```

```sh
javac ExprJoyRide.java Expr*.java
java ExprJoyRide ../t.expr
```

```sh
antlr4 -o java LibExpr.g4
javac LibExpr*.java

echo 3+4 | grun LibExpr prog -tree
```

```sh
echo (1+2\n3\n | java ExprJoyRide
```
