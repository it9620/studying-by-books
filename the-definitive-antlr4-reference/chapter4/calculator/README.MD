# Chapter 4.3

```sh
antlr4 -no-listener -visitor -o java LabeledExpr.g4
cd java
ls LabeledExpr*.java
javac Calc.java LabeledExpr*.java
cat ../t.expr
java Calc ../t.expr
```

```sh
```

```sh
```
