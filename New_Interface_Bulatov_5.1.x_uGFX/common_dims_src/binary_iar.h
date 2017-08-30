#ifndef BINARY_IAR_H		// ��������� ��������� ��������� ����� ������
#define BINARY_IAR_H


/* ����� ��� ������������� ��������� ������� ����� (�� 16 ���) */
/* ������������ ���: BIN(01010101) ��� BIN(0101010101010101) */

#define _BITSET(bits) \
  ((uint16_t) ( \
  (bits % 010) | \
  (bits / 010 % 010) << 1 | \
  (bits / 0100 % 010) << 2 | \
  (bits / 01000 % 010) << 3 | \
  (bits / 010000 % 010) << 4 | \
  (bits / 0100000 % 010) << 5 | \
  (bits / 01000000 % 010) << 6 | \
  (bits / 010000000 % 010) << 7 | \
  (bits / 0100000000 % 010) << 8 | \
  (bits / 01000000000 % 010) << 9 | \
  (bits / 010000000000 % 010) << 10 | \
  (bits / 0100000000000 % 010) << 11 | \
  (bits / 01000000000000 % 010) << 12 | \
  (bits / 010000000000000 % 010) << 13 | \
  (bits / 0100000000000000 % 010) << 14 | \
  (bits / 01000000000000000 % 010) << 15))
#define BIN(bits) _BITSET(0##bits)


#endif