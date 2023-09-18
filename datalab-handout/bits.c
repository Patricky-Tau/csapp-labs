int bitXor(int x, int y) { return ~(~(x & ~y) & ~(~x & y)); }

int tmin(void) { return 1 << 31; }

int isTmax(int x) { return !(~(x + 1) ^ x) & !!(x + 1); }

int allOddBits(int x) {
  int M = 0XAA;
  return !(((x & M) & ((x >> 8) & M) & ((x >> 16) & M) & ((x >> 24) & M)) ^ M);
}

int negate(int x) { return ~x + 1; }

int isAsciiDigit(int x) {
  int minimum = 1 << 31;
  return !((x + ~0X30 + 1) & minimum) & !((0X39 + ~x + 1) & minimum);
}

int conditional(int x, int y, int z) {
  int sign = ~(!x) + 1;
  return (y & ~sign) | (z & sign);
}

int isLessOrEqual(int x, int y) {
  int xsign = x >> 31;
  int ysign = y >> 31;
  int xxory = xsign ^ ysign;
  return !!((xsign & xxory) | (~xxory & (~(y + (~x + 1)) >> 31)));
}

int logicalNeg(int x) {
  // if unsigned: ((x >> 1) | (x & 1) + ~0) >> 31,
  // which means to convert all numbers except `0` to positive, then subtract 1
  return ((x >> 31) | ((~x + 1) >> 31)) + 1;
}

int howManyBits(int x) {
  int sign = x >> 31;
  int b16, b8, b4, b2, b1, b0;
  x = (sign & ~x) | (~sign & x);  // get highest bit

  // check if any set in high `16` bits, need at least `16`. shr 16 if needed.
  x >>= b16 = !!(x >> 16) << 4;
  x >>= b8 = !!(x >> 8) << 3;
  x >>= b4 = !!(x >> 4) << 2;
  x >>= b2 = !!(x >> 2) << 1;
  b0 = x >>= b1 = !!(x >> 1);

  return b16 + b8 + b4 + b2 + b1 + b0 + 1;  // `1` for sign bit
}

unsigned floatScale2(unsigned uf) {
  unsigned s = uf >> 31;
  unsigned exp = uf >> 23 & 0XFF;
  unsigned frac = uf & 0X7FFFFF;

  // 0
  if (exp == 0 && frac == 0) {
    return uf;
  }

  // Inf or NaN
  if (exp == 0XFF) {
    return uf;
  }

  // denormalized
  if (exp == 0) {
    frac <<= 1;
    return (s << 31) | frac;
  }

  // normalizd
  exp++;
  return (s << 31) | (exp << 23) | frac;
}

int floatFloat2Int(unsigned uf) {
  unsigned s = uf >> 31;
  unsigned exp = uf >> 23 & 0XFF;
  unsigned frac = uf & 0X7FFFFF;
  int E = exp - 127;

  if (exp == 0 && frac == 0) {
    return 0;
  }

  if (exp == 0XFF) {
    return 0X80000000U;
  }

  if (exp == 0) {
    return 0;
  }

  frac = frac | 0X800000U;  // 1<<23

  if (E > 31) {  // overflow
    return 0X80000000U;
  } else if (E < 0) {  // very closed to 0
    return 0;
  }

  if (E >= 23) {
    frac <<= E - 23;
  } else {
    frac >>= 23 - E;
  }

  if (s) {
    return ~frac + 1;
  }

  return frac;
}

unsigned floatPower2(int x) {
  if (x < (-23 - 127)) {
    return 0;
  } else if (x < -126) {
    return 1 << (23 + x + 126);
  } else if (x <= 127) {
    return (x + 127) << 23;
  } else {
    return 0XFF << 23;
  }
}
