# The Definitive ANTLR 4 Reference

## Requirements

1. Install open JDK (for example on macOS command `brew install openjdk`);
1. Download antlr-4.13.2-complete.jar (or newer version) file from (site)[https://www.antlr.org] and run commands on macOS:

```sh
sudo mkdir -p /usr/local/lib
sudo cp ./antlr-4.13.2-complete.jar /usr/local/lib/

# If you use zsh, or use ~/.bashrc if you are using bash
echo 'export CLASSPATH=".:/usr/local/lib/antlr-4.13.2-complete.jar:$CLASSPATH"' >> ~/.zshrc

echo "alias antlr4='java -jar /usr/local/lib/antlr-4.13.2-complete.jar'" >> ~/.zshrc
echo "alias grun='java org.antlr.v4.gui.TestRig'" >> ~/.zshrc

source ~/.zshrc # Just reload your shell's configuration file
```

---

## Make parsers for different languages:

To make parsers for C++ add a flag: `antlr4 -Dlanguage=Cpp Formula.g4`

To make parsers for C# use a flag: `antlr4 -Dlanguage=CSharp Formula.g4`

---

## Testing grammar with grun (TestRig)

The test rig takes a grammar name, a starting rule name kind of like a main() method, and various options that dictate the output we want.

To use grun (TestRig) you need run:

```sh
antlr4 Formula.g4 # Generate
javac *.java # Compile ANTLR-generated code (it's neccesary to use grun)

# Variant 1:
grun Hello r -tokens # start the TestRig on grammar Hello at rule r
# Type a text for a formula and at the end press Ctrl+D for send EOF

# Variant 2:
# Or alternativly redirect input:
echo 'hello part' | grun Hello r -tokens
```

In Variant 1, after you hit a newline on the grun command, the computer will patiently wait for you to type in hello parrt followed by a newline. At that point, you must type the end-of-file character to terminate reading from standard input; otherwise, the program will stare at you for eternity.

Other grun options:
-tokens prints out the token stream.
-tree prints out the parse tree in LISP form.
-gui displays the parse tree visually in a dialog box.
-ps file.ps generates a visual representation of the parse tree in PostScript and stores it in file.ps. The parse tree figures in this chapter were generated with -ps.
-encoding encodingname specifies the test rig input file encoding if the current locale would not read the input properly. For example, we need this option to parse a Japanese-encoded XML file in Section 12.4, Parsing and Lexing XML, on page 224.
-trace prints the rule name and current token upon rule entry and exit. -diagnostics turns on diagnostic messages during parsing. This generates mes-
sages only for unusual situations such as ambiguous input phrases.
-SLL uses a faster but slightly weaker parsing strategy.

---
