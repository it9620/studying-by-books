#pragma once

#include "ArrayInitBaseListener.h"

class ShortToUnicodeString : public ArrayInitBaseListener {
public:
    void enterInit(ArrayInitParser::InitContext * /*ctx*/) override;
    
    void exitInit(ArrayInitParser::InitContext * /*ctx*/) override;
    
    void enterValue(ArrayInitParser::ValueContext * ctx) override;
};
