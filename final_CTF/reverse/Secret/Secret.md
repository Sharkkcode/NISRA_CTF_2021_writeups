# Secret
![](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/Secret/imgs/q.png)
- 題目給了一個執行檔，起手先蒐集一下資訊

    ![](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/Secret/imgs/checkfile.png)

- 執行一下，大概猜到是要我們輸入正確 flag 才會跳出正確結果

    ![](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/Secret/imgs/run_test.png)

- 接著丟進 ghidra，追蹤 check function

    ![](https://github.com/Sharkkcode/NISRA_CTF_2021_writeups/blob/main/final_CTF/reverse/Secret/imgs/decompile.png)

- 發現 check 其實只是用了一堆很簡單的字元比對... 把對應的字元填入 param_1，param_1 就是 flag (不過要注意 param_1 的 index 是用什麼進位法)
- flag 長度是 0x1d，前面的比對 0x1e 可能是因為輸入會有 '\n'

