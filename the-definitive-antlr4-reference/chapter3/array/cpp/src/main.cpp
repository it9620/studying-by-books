#include <vector>
#include <iostream>

#include "antlr4-runtime.h"
#include "ArrayInitLexer.h"
#include "ArrayInitParser.h"
#include "ShortToUnicodeString.h"

// =================================================================================================

using namespace antlr4;

int main(int argc, const char* argv[]) {
    
    // std::string input_str = "{1,2,3}";
    // ANTLRInputStream input(input_str);
    
    ANTLRInputStream input(std::cin);

    ArrayInitLexer lexer(&input);

    CommonTokenStream tokens(&lexer);

    ArrayInitParser parser(&tokens);

    tree::ParseTree *tree = parser.init();

    // std::cout << tree->toStringTree(&parser) << std::endl;

    tree::ParseTreeWalker walker;

    ArrayInitBaseListener::ParseTreeListener* listener = new ShortToUnicodeString();

    walker.walk(listener, tree);

    return 0;
}
