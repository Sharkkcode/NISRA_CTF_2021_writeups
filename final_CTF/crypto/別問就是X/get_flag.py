s = 'CNMSZRJITRSAKZRS'

for i in range(26):
    for j in range(len(s)):
        print(chr((ord(s[j]) + i - ord('A')) % 26 + ord('A')), end='')
    print()