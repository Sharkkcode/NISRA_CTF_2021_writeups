#include<bits/stdc++.h>

using namespace std;


string PTT_popular_netizen[12] = {
    "Patiencel_likes_to_bluff",
    "Leesmart_has_a_good_figure",
    "Asiagodtone_doesnt_like_his_fans_to_laugh",
    "ILoveElsa_likes_to_write_shitpost",
    "Nomorepipe_alert_on_the_epidemic",
    "Typeking_loves_to_make_cheesy_jokes",
    "Eternityring_is_good_at_roadside_banquet",
    "XXXXGAY_four_X_is_equal_to_8000_NTD",
    "Tomchen60229_burns_his_opponent",
    "Ipobar_who_must_not_be_named",
    "Slow_is_the_mother_of_cockroaches",
    "Yoyodiy_can_bypass_the_WinRARs_password"
};

string encrypt_string;

void make_encrypt_string(){
    encrypt_string.clear();
    for (int i = 0; i < 12; i++){
        encrypt_string += PTT_popular_netizen[i];
    }    
}

void switch_sequence(int n){
    if(n == 0 || n == 1 || n == 2){
        for (int i = 0; i < 12; i += 2){
            swap(PTT_popular_netizen[i],PTT_popular_netizen[i+1]);
        }
        
    }else if(n == 3 || n == 4 || n == 5){
        for (int i = 0; i < 6; i++){
            swap(PTT_popular_netizen[i],PTT_popular_netizen[11-i]);
        } 
    }else if(n == 6){
        swap(PTT_popular_netizen[3],PTT_popular_netizen[1]);
        swap(PTT_popular_netizen[4],PTT_popular_netizen[1]);
        swap(PTT_popular_netizen[5],PTT_popular_netizen[9]);
    }else if(n == 7){
        swap(PTT_popular_netizen[2],PTT_popular_netizen[6]);
        swap(PTT_popular_netizen[5],PTT_popular_netizen[3]);
        swap(PTT_popular_netizen[5],PTT_popular_netizen[8]);
    }else if(n == 8){
        swap(PTT_popular_netizen[9],PTT_popular_netizen[7]);
        swap(PTT_popular_netizen[9],PTT_popular_netizen[3]);
        swap(PTT_popular_netizen[2],PTT_popular_netizen[3]);
    }else if(n == 9){
        swap(PTT_popular_netizen[10],PTT_popular_netizen[1]);
        swap(PTT_popular_netizen[11],PTT_popular_netizen[5]);
        swap(PTT_popular_netizen[2],PTT_popular_netizen[3]);
    }
}

int main(){

    // 明文爆破基底
    string plaintext = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    
    // 所求密文
    string ans =       "vvDtf[ATbSl]cFy[grQloWSYatwEIk[eYexigte";
    
    string ciphertext;
    int tmp = 0;
    char cipher_letter;
    
    for (int i = 0; i < plaintext.size(); i++){
        make_encrypt_string();

        cipher_letter = 65 + ((plaintext[i] + encrypt_string[tmp % encrypt_string.size()]) % 58);

        // 檢查，不對就回朔
        if(cipher_letter == ans[i]) {
            ciphertext += cipher_letter;
            cout << plaintext << "\n";
        } else {
            plaintext[i]++;
            i--;
            continue;
        }

        tmp += int(cipher_letter);
        switch_sequence(tmp % 10);
    }

    return 0;
}
