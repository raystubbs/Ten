#ifndef ten_lib_h
#define ten_lib_h
#include "ten_types.h"

void
libInit( State* state );

#ifdef ten_TEST
    void
    libTest( State* state );
#endif

TVal
libRequire( State* state, String* mod );

TVal
libImport( State* state, String* mod );

SymT
libType( State* state, TVal val );

void
libPanic( State* state, TVal err );

void
libAssert( State* state, TVal cond, TVal what );

void
libExpect( State* state, char const* what, SymT type, TVal val );

void
libCollect( State* state );

void
libLoader( State* state, SymT type, Closure* loadr, Closure* trans );

TVal
libLog( State* state, TVal val );

TVal
libInt( State* state, TVal val );

TVal
libDec( State* state, TVal val );

TVal
libSym( State* state, TVal val );

TVal
libStr( State* state, TVal val );

Closure*
libKeys( State* state, Record* rec );

Closure*
libVals( State* state, Record* rec );

Closure*
libPairs( State* state, Record* rec );

Closure*
libStream( State* state, Record* vals );

Closure*
libBytes( State* state, String* str );

Closure*
libChars( State* state, String* str );

Closure*
libItems( State* state, Record* list );

void
libShow( State* state, Record* vals );

void
libWarn( State* state, Record* vals );

String*
libInput( State* state );

TVal
libUcode( State* state, SymT chr );

TVal
libUchar( State* state, IntT code );

String*
libCat( State* state, Record* rec );

String*
libJoin( State* state, Closure* stream );

TVal
libBcmp( State* state, String* str1, SymT opr, String* str2 );

TVal
libCcmp( State* state, String* str1, SymT opr, String* str2 );


void
libEach( State* state, Closure* stream, Closure* what );

TVal
libFold( State* state, Closure* stream, TVal agr, Closure* how );

void
libWhile( State* state, Closure* cond, Closure* what );

void
libUntil( State* state, Closure* cond, Closure* what );

Record*
libExpand( State* state, Closure* stream );

Record*
libCons( State* state, TVal car, TVal cdr );

Record*
libList( State* state, Record* rec );

Fiber*
libFiber( State* state, Closure* cls );

Tup
libCont( State* state, Fiber* fib, Closure* cls );

void
libYield( State* state, Record* rec );

void
libStatus( State* state, Fiber* fib, SymT* st, TVal* err );



#endif
