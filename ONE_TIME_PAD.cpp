#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;
const int ch_MAX = 26;

string RandomString(int ch)
{
 char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 
                           'i', 'j', 'k', 'l', 'm', 'n','o', 'p',
                           'q', 'r','s', 't', 'u','v', 'w', 'x', 
                           'y', 'z' };
    string result = "";
    for (int i = 0; i<ch; i++){
    result = result + alpha[rand() % ch_MAX];
    }
    return result;
}

string stringEncryption(string text, string key)
{
    string cipherText = "";
    int cipher[key.length()];
    for (int i = 0; i < key.length(); i++) {
        cipher[i] = (text.at(i) - 'A') + (key.at(i) - 'A');
    }
    for (int i = 0; i < key.length(); i++) {
        if (cipher[i] > 25) {
            cipher[i] = cipher[i] - 26;
        }
    }

    for (int i = 0; i < key.length(); i++) {
        int x = cipher[i] + 'A';
        cipherText += (char)x;
    }
     return cipherText;
}

static string stringDecryption(string s, string key_stored)
{
    string key = key_stored;
    string plainText = "";
    int plain[key.length()];
 
    for (int i = 0; i < key.length(); i++) {
        plain[i] = (s.at(i) - 'A') - (key.at(i) - 'A');
    }
 
    for (int i = 0; i < key.length(); i++) {
        if (plain[i] < 0) {
            plain[i] = plain[i] + 26;
        }
    }

    for (int i = 0; i < key.length(); i++) {
        int x = plain[i] + 'A';
        plainText += (char)x;
    }
 
    return plainText;
    
}

int main(){
    cout<<"********************ONE TIME PAD ENCRYPTION********************"<<endl<<endl;
    string plaintext;
    ifstream in("plaintext.txt");
    //in>>plaintext;
    getline(in, plaintext);
    cout<<"Plaintext read from the file is-> "<<plaintext;
    cout<<endl;
    srand(time(NULL));


    int ch = plaintext.length();
    string key = RandomString(ch);


    for (int i = 0; i < plaintext.length(); i++) {
        plaintext[i] = toupper(plaintext[i]);
    }

    for (int i = 0; i < key.length(); i++) {
        key[i] = toupper(key[i]);
    }

    string encryptedText = stringEncryption(plaintext, key);
    cout << "CipherText-> " << encryptedText << endl;
    cout<<endl;
    string Encryption = encryptedText;

    // connecting our file with hout stream
    ofstream hout("encryption.txt");  
    // writing a string to the file
    hout<<encryptedText;
    cout<<"CIPHER TEXT STORED IN THE FILE"<<endl;
    cout<<endl;
    // disconnecting our file
    hout.close();
    // connecting our file with hin stream
    ifstream hin("encryption.txt");
 
    // creating a content string variable and filling it with string present there in the text file
    string cipher;
    hin>>cipher;
    cout<<"*************************DECRYPTION****************************"<<endl<<endl;
    cout<<"Ciphertext read from the file is-> "<<cipher;
          
    // disconnecting our file
    hin.close();
           
    string key_stored = key;
    cout<<endl;
    cout << "PlainText After Decryption-> " << stringDecryption(cipher, key_stored)<<endl;
    cout<<endl;
    cout<<"***************************************************************"<<endl;
           

    return 0;
}