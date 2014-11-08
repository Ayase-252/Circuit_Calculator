#Circuit Calculator

##Overview

I'm an electronic engineering student. So there are a lot of problems related to circuit to do. When questions come to parallel connection, the formula to retain resistance of circuit could be extremely complex.
We have resistance when two circuits are connected parallel. The total is equal to the reciprocal of the sum of all the reciprocal of the resistance of the branch. The formula will be `R=1/(1/R1+1/R2)`.
It would be very unhappy expirence when it combines comprehensive operation. Hence, I decided to design a simple calculator which is optimized for circuit calculation.

##Features

+ Normal Mathematics Expression
+ Interactive Environmemt

##Support Operation

### Arithmatic Operators

+ `lhs+rhs` Add
+ `lhs-rhs` Substract
+ `lhs*rhs` Multiply
+ `lhs/rhs` Divide
+ `()`      Bracket
+ [s]`lhs^rhs` pow[/s]

### Operator Specialized for circuit

+ `lhs|rhs`  which products the parallel resistance of lhs and rhs. The piority equals to `* and /`

##Compile

The code is included in single file `expression.cpp` temperarily. You can just use g++ to compile it with `-std=c++11` option.

`g++ expression -o yourfilename -std=c++11`

`yourfilename` is dicided by yourself.
