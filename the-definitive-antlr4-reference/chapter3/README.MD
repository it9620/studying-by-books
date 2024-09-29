# 

```sh
# Run examples by gran:
javac *.java
echo '{99, 3, 451}' | grun ArrayInit init -tokens
echo '{99, 3, 451}' | grun ArrayInit init -tree
echo '{99, 3, 451}' | grun ArrayInit init -gui

echo '{1,{2,3},4}' | grun ArrayInit init -gui

# Run java test aplications:
javac ArrayInit*.java Test.java

echo '{1,{2,3},4}' | java Test
# Test the syntax error report
echo '{1,{2,3}' | java Test
```

---
