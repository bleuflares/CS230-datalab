/* 
 * CS:APP Data Lab 
 * 
 * <Park Kisung 20130242>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	

  return ~(~x|~y);
//returns 1 for both bits in x, y is 1
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return (x>>(n<<3))&0xFF;
//shift x for n bytes and obtain the last 8 bits
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  return (x>>n)&(~(((~0)<<(31+~n+1))<<1));
//shift x arithmatically and then change the leading 1s to 0 for negative x
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
	int a=(((0x55)+(0x55<<8))+((0x55+(0x55<<8))<<16));
	int b=(((0x33)+(0x33<<8))+((0x33+(0x33<<8))<<16));
	int c=(((0x7)+(0x7<<8))+((0x7+(0x7<<8))<<16));
	int d=(0xF+(0xF<<16));
	x=((x&a)+((x>>1)&a));
	//2n & 2n+1 bits represent the sum of 1s in 2n and 2n+1 bits
	x=((x&b)+((x>>2)&b));
	//4n, 4n+1, 4n+2 bits represent the sum of 1s from 4n to 4n+3 bits
	x=((x&c)+((x>>4)&c));
	//8n, 8n+1, 8n+2, 8n+3 bits represent the sum of 1s from 8n to 8n+7 bits
	x=((x&d)+((x>>8)&d));
	//16n, 16n+1, 16n+2, 16n+4 bits represent the sum of 1s from 16n to 16n+15 bits
	x=((x&0x1F)+((x>>16)&0x1F));
	//the last 5 bits represent the sum of 1s in the total bits
	return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  return 1+((x>>31)|((~x+1)>>31));
//x>>31 and -x>>31 are both 0 for x=0
//for x!=0, one of the sign bits in x and (~x+1) is 0 and the other is 1 so (x>>31)|(-x>>31) always returns 0xffffffff
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
// returns 0x80000000
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	int num=n+0xFF;
  return (!((x>>num)+1))|(!(x>>num));
//for positive x bits over n should be 0
//for negative x all the bits over n should be 1
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
   return (x>>n)+((!!((1<<31)&x))&(!!((~(~0<<n))&x)));
//shift x for n and round to zero
//add bit 1 for negative x which contains bits under n
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
//x+~x=0xffffffff x+~x+1=0 so -x=~x+1 for signed integer
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return (!(!x))&(1+(x>>31));
//!(!x) is 0 for 0 and 1 for other values exclude special case 0
//1+(x>>31) checks the sign bit, returns 1 for positive number, returns 0 for negative number
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int m=1<<31;
	int a= !(!(x&m));
	int b= !(!(y&m));
	int c= !(!((y+(~x)+1)&m));	
//obtains MSB of x, y, y-x
	return !((((!a)&b)|c)&(!((!b)&a)));
//returns 0 for x>0, y<0
//returns 1 for x<0, y>0
//returns 1 for x>0, y>0 MSB of y-x==0
//returns 0 for x>o, y>0 MSB of y-x==1
//returns 1 for x<0, y<0 MSB of y-x==0
//retunrs 0 for x<0, y<0 MSB of y-x==1
}


/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	int a=(((0x55)+(0x55<<8))+((0x55+(0x55<<8))<<16));
	int b=(((0x33)+(0x33<<8))+((0x33+(0x33<<8))<<16));
	int c=(((0x7)+(0x7<<8))+((0x7+(0x7<<8))<<16));
	int d=(0xF+(0xF<<16));
	x=x|(x>>1);
	x=x|(x>>2);
	x=x|(x>>4);
	x=x|(x>>8);
	x=x|(x>>16);
//every bits on the right side of the MSB becomes 1
	x=((x&a)+((x>>1)&a));
	x=((x&b)+((x>>2)&b));
	x=((x&c)+((x>>4)&c));
	x=((x&d)+((x>>8)&d));
	x=((x&0x1F)+((x>>16)&0x1F));
//add the number of 1s in x
	return x+~0;
//decrement x by 1
//the result is the position of the MSB
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	if(((uf&0x7f800000)==0x7f800000) && ((uf&0x007fffff)!=0))
		return uf;
//return the argument for NAN case
	else
		return uf^0x80000000;
//change the sign bit of uf
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	int s;
	int e=0;
	int m=0;
	int t=0;
	int i=0;
	int round=0;
	int exp=0;
	int temp;
	if(x==0)
		return 0;
	else if(x==0x80000000)
		return 0xcf000000;	
	//exclude special cases
	s=0x80000000&x;
	if(s==0x80000000)
		x=-x;
	//find sign bit and abs of x
	temp=x;
	while(temp>1)
	{
		temp=(temp>>1);
		e++;
	}
	//find e by counting the bits under the MSB
	exp=1<<e;
	t=x-exp;
	if(e>23)
	{	
		i=(e-23);
		round=exp>>24;
		m=t>>i;
		if((t&round)==round)
			m++;
			if(((t&((1<<i)-1))==round)&&(m&1))
				m--;	
	}
	// if mantissa requires more than 24 bits it requires rounding
	//round up if the 24th bit is 1,
	// however, round toward the point where LSB becomes 0 if 24th bit is 1 and the other bits are 0
	else
		m=t<<(23-e);
	//mantissa requires less than 24 bits put more zeroes
	return s+((127+e)<<23)+m;
	//return the combination of s, e, m
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	
	int s=!(!(uf&0x80000000));
	int e=(uf&0x7f800000)>>23;
	int frac=uf&0x007fffff;
	if(e==0) {
		frac=frac<<1;
		return (s<<31)+(e<<23)+frac;
	}
	//denormalized value for e==0
	else if(e==0xff)
		return uf;
	//denormalized value for e==0xff
	else
		e++;
		return (s<<31)+(e<<23)+frac;
	//normalized value
}

