// AND, OR, XOR, SHIFT, NOT

/*
AND:
-> All true: true
-> One false: false

OR:
-> One true: true
-> All false: false

XOR:
-> No of 1's odd : 1
-> No of 1's even : 0

SHIFT:
* Right Shift: (>>)

x = 13 >> 1
13 -> 1 1 0 1
After right shifting the last 1 (in the right side) will move away.
means, 0 1 1 0
so, 13 >> 1 => 6

2nd example:
13 >> 2 then, from 1 1 0 1, last 0 and 1 will move away so,
ans: 0 0 1 1 so, 13 >> 2 => 3

** Imp Observation:
13 >> 1 => 6   :-> 13 / 2^1 = 6
13 >> 2 => 3   :-> 13 / 2^2 = 3
13 >> 3 => 1   :-> 13 / 2^3 = 1
13 >> 4 => 0   :-> 13 / 2^4 = 0

=> So, the formula is simple: x >> k = x / 2^k

// Let's see how to get value of INT_MAX and INT_MIN

=> For INT_MAX:
0 1 1 1 1 1 . . . . . 1     1 1 1 1
_ _ _ _ _ _ _ _ _ _ _ _     _ _ _ _
    first 28 bits          last 4 bits

the first 0 is the sign bit.
then the value is: 2^30 + 2^29 + 2^28 + ....... + 2^0
which is nothing but a geometric series:
1 + 2^1 + 2^2 + 2^3 + 2^4 + ........ + 2^30
=> (1 X (2^(30 + 1))-1) / 2 - 1 => (2^31 - 1)/1 => 2^31 - 1 => INT_MAX

=> For INT_MIN:

1 0 0 0 0 0 0 ....... 0 0 0 0
        1's complement
0 1 1 1 1 1 1 ....... 1 1 1 1
                        +   1
        2's Complement
-----------------------------
1 0 0 0 0 0 0 ....... 0 0 0 0 => -2^31 => INT_MIN

* Left Shift: (<<)
13 << 1 => 1 1 0 1 << 1 => 1 1 0 1 0 => 26 => 13 * 2^1
13 << 2 => 1 1 0 1 << 2 => 1 1 0 1 0 0 => 52 => 13 * 2^2
13 << 3 =>                             => 104 => 13 * 2^3

=> Formula comes: n << k => n * 2^k

=> So what will happen in case if I take the biggest number: 2^31 - 1
0 1 1 1 1 1 1 1 1 .... 1 1 1 1 << 1
  * -> This *th positioned 1 will try to move to the left but it can't.
So, here comes the overflow condition, which we have to take care
We have to do all the operations b/w the boundary.


NOT(~):
x = ~(5)

Step: 1         Flip

Step: 2         Check(-ve)
        _____Yes_____|__________No______
        |                              |
    stores 2's complement            STOP

5 => 0 0 0 0 0 0 0 ..... 0 1 0 1
        After flipping
  => 1 1 1 1 1 1 1 ..... 1 0 1 0 => here the sign bit is 1. So, it means -ve. So, it will convert rest bits it into 2's complement.
  =>   0 0 0 0 0 0 ..... 0 1 0 1
  => + 0 0 0 0 0 0 ..... 0 0 0 1
    -----------------------------
     1 0 0 0 0 0 0 ..... 0 1 1 0  => which is -6 and this the value which computer stores.

so, ~(5) => (-6)

-> Let's see how -ve numbers are treated:
x = ~(-6)

// How, -6 is stores

6 => 0 0 0 0 0 0 0 ..... 0 1 1 0
            1's comp
  => 1 1 1 1 1 1 1 ..... 1 0 0 1
  =>                        +  1
    ----------------------------
     1 1 1 1 1 1 1 ..... 1 0 1 0 => -6

-> Now (~) operator will be applied on it

-6 => 1 1 1 1 1 1 1 ..... 1 0 1 0
           After flipping
      0 0 0 0 0 0 0 ..... 0 1 0 1 => Now the sign bit is not 1. So, no need to proceed further. STOP here.

We have got the result as 5. That's how computer stores it.
so, ~(-6) => (5)
*/