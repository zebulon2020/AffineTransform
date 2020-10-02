#include <iostream>
#include <string.h>
#include "file_op.h"

using namespace std;

/*仿射变换加密算法*/
string Cryption(string text, int a, int b){
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int len = text.length();  // 字符串的长度
    for(int i=0; i<len; i++){
        text[i] = letters[(a * (text[i]-'a') + b) % 26];
    }
    text[len] = '\0';
    return text;
}

/*求a的逆元*/
int get_a_inverse(int a){
    int x;
    for(x=1; x<26; x++){
        if( (a * x) % 26 == 1 ){
            break;
        }
    }
    return x;
}

/*仿射变换解密算法*/
string Decryption(string text, int a, int b){
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int len = text.length();
    int m = get_a_inverse(a);  // 将a的逆元的值赋给m
    for(int i=0; i<len; i++){
        text[i] = letters[(m * (text[i]-'a' - b +26)) % 26];
    }
    text[len] = '\0';
    return text;
}

int main()
{
    string text;
    int a,b;  // 仿射变换的两个参数
    int choice;
    cout<<"输入a: "<<endl;
    cin>>a;
    cout<<"输入b: "<<endl;
    cin>>b;
    cout<<"加密(0) / 解密(1) / 文件加解密(2) ？ 请输入数字: ";
    cin>>choice;
    if(choice==0){
        // 加密
        cout<<"输入明文字符串："<<endl;
        cin>>text;
        cout<<"密文：\n"<<Cryption(text, a, b)<<endl;
    }

    else if(choice==1){
        // 解密
        cout<<"请输入密文字符串："<<endl;
        cin>>text;
        cout<<"明文：\n"<<Decryption(text, a, b)<<endl;
    }

    else if(choice==2){
        // 文件操作
        int file_choice;
        cout<<"\n加密(0) / 解密(1) ? 请输入数字:  ";
        cin>>file_choice;

        if(file_choice==0){
            // 文件加密
            string file_content;  // 读取的明文的内容
            string cipher_text;  // 密文
            char* file_name = "plain.txt";

            cout<<"将对工程目录下的plain.txt进行加密..."<<endl;
            file_content = read_file(file_name);
            //cout<<file_content<<endl;
            cipher_text = Cryption(file_content, a, b);
            //cout<<cipher_text<<endl;
            write_file(cipher_text);
            cout<<"密文已保存在工程目录下的result.txt内。"<<endl;
        }

        else if(file_choice==1){
            // 文件解密
            string file_content;  // 读取的密文的内容
            string plain_text;    // 明文
            char* file_name = "cipher.txt";
            cout<<"将对工程目录下的cipher.txt进行解密..."<<endl;
            file_content = read_file(file_name);
            plain_text = Decryption(file_content, a, b);
            write_file(plain_text);
            cout<<"明文已保存在工程目录下的result.txt内。"<<endl;
        }

        else{
            cout<<"输入非法!"<<endl;
        }
    }

    else{
        cout<<"Something Wrong!"<<endl;
    }
    return 0;
}
