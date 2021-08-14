# ccc

- 檢查檔案

    ![](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/ccc/img/checkfile.png)

- 丟進 ghidra 追蹤 verify function 會發現程式只是把 hashes 的值和 crc32() 的結果作比對(一次 3 個字元)，把 hashes 的值抓出來，再把比對的 function 還原(*crc() == hash值*)，最後進行爆破就可以看到 flag。

    -[](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/ccc/img/decompile_verify.png)

- 我的程式： [get_flag.py](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/ccc/get_flag.py)