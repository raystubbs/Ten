TVal arg1 = regs.sp[-2];
TVal arg2 = regs.sp[-1];
regs.sp--;
if( tvIsDec( arg1 ) && tvIsDec( arg2 ) ) {
    DecT denom = tvGetDec( arg2 );
    if( denom == 0.0 )
        stateErrFmtA(
            state, ten_ERR_ARITH,
            "Division by zero"
        );
    
    double mod = fmod( tvGetDec( arg1 ), denom );
    if( isnan( mod ) )
        stateErrFmtA(
            state, ten_ERR_ARITH,
            "fmod() function returned NaN"
        );
    
    regs.sp[-1] = tvDec( mod );
}
else
if( tvIsInt( arg1 ) && tvIsInt( arg2 ) ) {
    IntT denom = tvGetInt( arg2 );
    if( denom == 0 )
        stateErrFmtA(
            state, ten_ERR_ARITH,
            "Division by zero"
        );
    
    regs.sp[-1] = tvInt( tvGetInt( arg1 ) % denom );
}
else {
    if( tvIsTup( arg1 ) || tvIsTup( arg2 ) )
        stateErrFmtA(
            state, ten_ERR_TYPE,
            "Passed tuple to operator."
        );
    else
        stateErrFmtA(
            state, ten_ERR_TYPE,
            "Wrong types (%t % %t), expected (Dec % Dec) or (Int % Int)",
            arg1, arg2
        );
}
