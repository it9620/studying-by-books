
// Generated from Hello.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "HelloParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by HelloParser.
 */
class  HelloListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterR(HelloParser::RContext *ctx) = 0;
  virtual void exitR(HelloParser::RContext *ctx) = 0;


};

