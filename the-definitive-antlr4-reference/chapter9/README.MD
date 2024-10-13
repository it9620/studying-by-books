# Chapter 9 - Error Reporting and Recovery

## Errors

```sh
antlr4 -o java Simple.g4

cd java
javac Simple*.java

# Check with no errors:
echo "class T { int i; } " | grun Simple prog

# Errors check:
echo "class T { int f(x) {a = 3 4 5; } } " | grun Simple prog
# The same error but with GUI
echo "class T { int f(x) {a = 3 4 5; } } " | grun Simple prog -gui

# Second error
echo "class T; { int i; } " | grun Simple prog
echo "class T; { int i; } " | grun Simple prog -gui


# Third error
echo "class T {\n int f(x) { a = 3; } " | grun Simple prog

# Fourth error
echo "class T { int ; }  " | grun Simple prog

# Fifth error
echo "class # { int i; }  " | grun Simple prog
```

```sh
javac *.java

echo "class T T { int ; }" | java TestE_Listener
```

```sh
javac *.java

echo "class T T { int ; }" | java TestE_Listener
echo "class T T { int ; }" | java TestE_Dialog
echo "class T XYZ { int ; }" | java TestE_Listener2
```

## Ambiguous

```sh
antlr4 Ambig.g4
javac Ambig*.java

echo "f();" | grun Ambig stat
# Spicial ambiguity detection:
echo "f();" | grun Ambig stat -diagnostics
```

---
