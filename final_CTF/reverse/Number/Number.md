# Number

- 檢查檔案

    ![](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/Number/imgs/checkfile.png)

- 丟進 ghidra 追蹤 check function，會發現 27~47 行並沒有 iVar2 出現，所以直接 patch 掉 26 行，就可以直接印出 flag。

    ![](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/Number/imgs/decompile_check.png)