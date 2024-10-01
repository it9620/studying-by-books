#include <vector>
#include <iostream>

#include "antlr4-runtime.h"
#include "ArrayInitLexer.h"
#include "ArrayInitParser.h"

// =================================================================================================

using namespace antlr4;

int main(int argc, const char* argv[]) {
    
    std::string input_str = "{1,2,3}";
    
    // ANTLRInputStream input(std::cin);
    ANTLRInputStream input(input_str);

    ArrayInitLexer lexer(&input);

    CommonTokenStream tokens(&lexer);

    ArrayInitParser parser(&tokens);

    std::unique_ptr<tree::ParseTree> tree (parser.init());

    std::cout << tree->toStringTree(&parser) << std::endl;    

    return 0;
}
