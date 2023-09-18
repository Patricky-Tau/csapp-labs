# data lab
Know the layout of integers and decimals in memory and implement them with FINITE operators.

To save your reading time, I removed some comments.

```bash
$ ./dlc -e bits.c

dlc:bits.c:12:bitXor: 8 operators
dlc:bits.c:22:tmin: 1 operators
dlc:bits.c:34:isTmax: 8 operators
dlc:bits.c:48:allOddBits: 12 operators
dlc:bits.c:56:negate: 2 operators
dlc:bits.c:69:isAsciiDigit: 12 operators
dlc:bits.c:80:conditional: 7 operators
dlc:bits.c:93:isLessOrEqual: 14 operators
dlc:bits.c:108:logicalNeg: 6 operators
dlc:bits.c:135:howManyBits: 36 operators
dlc:bits.c:172:floatScale2: 17 operators
dlc:bits.c:223:floatFloat2Int: 20 operators
dlc:bits.c:247:floatPower2: 12 operators
```

```bash
$ ./btest

Score	Rating	Errors	Function
 1	1	0	bitXor
 1	1	0	tmin
 1	1	0	isTmax
 2	2	0	allOddBits
 2	2	0	negate
 3	3	0	isAsciiDigit
 3	3	0	conditional
 3	3	0	isLessOrEqual
 4	4	0	logicalNeg
 4	4	0	howManyBits
 4	4	0	floatScale2
 4	4	0	floatFloat2Int
 4	4	0	floatPower2
Total points: 36/36
```

****
Reference:
- [datalab PDF | CMU.EDU](http://csapp.cs.cmu.edu/3e/datalab.pdf)
- [logicla negation for unsigned 32-bit interger | stack overflow](https://stackoverflow.com/a/4971757/18602987)
