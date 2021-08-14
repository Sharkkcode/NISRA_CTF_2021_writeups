from binascii import crc32
from itertools import product

hashes = [0xd641596f, 0x80a3e990, 0xc98d5c9b, 0x0d05afaf, 0x1372a12d, 0x5d5f117b, 0x4001fbfd, 0xa7d2d56b, 0x7d04fb7e, 0x2e42895e, 0x61c97eb3, 0x84ab43c3, 0x9fc129dd, 0xf4592f4d]

# 所有可視字元
chars = []
for i in range(ord(' '), ord('~') + 1):
    chars.append(chr(i))

flag = ''

for h_val in hashes:
    # 3 個可視字元的排列組合
    for t in product(chars, chars, chars):
        ch3 = ''.join(t)
        # 比對 crc32() 與 hash 的值
        if crc32(bytearray(flag + ch3, 'ascii')) == h_val:
            flag += ch3
            break

    print(flag)