# ccc

- 檢查檔案，會發現 ***Arch: i386-32-little***，這很重要因為這樣才會知道等等的 hashes 值要用 ***little-endian*** 方式來存。

    ![](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/ccc/img/checkfile.png)

- 丟進 ghidra 追蹤 verify function 會發現程式只是把 hashes 的值和 crc32() 的結果作比對(一次 3 個字元)，把 hashes 的值抓出來，再把比對的 function 還原(*crc() == hash值*)。

    ![](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/ccc/img/decompile_verify.png)

- 最後進行爆破就可以看到 flag，我的程式： [get_flag.py](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/ccc/get_flag.py)