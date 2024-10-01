#include "ShortToUnicodeString.h"

void ShortToUnicodeString::enterInit(ArrayInitParser::InitContext * /*ctx*/) {
    std::cout << "\"";
}

void ShortToUnicodeString::exitInit(ArrayInitParser::InitContext * /*ctx*/) {
    std::cout << "\"";
}

void ShortToUnicodeString::enterValue(ArrayInitParser::ValueContext * ctx) {
    if (ctx->INT() != nullptr) {
        std::cout << "\\u" << std::hex << std::stoi(ctx->INT()->getText());
    }
}
