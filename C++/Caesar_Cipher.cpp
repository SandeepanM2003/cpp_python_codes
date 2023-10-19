// Ceaser Cipher - monoalphabetic cryptographic algorithm

/*
E.g. plaintext = 'applez'
key=1

FORMULA => cipher = (plain+key) % 26 

(a+1) % 26 = b
(p+1) % 26 = q
(p+1) % 26 = q
(l+1) % 26 = m
(e+1) % 26 = f
(z+1) % 26 = a

ciphertext = 'bqqmfa'
*/

#include <iostream>
using namespace std;
void encrypt()
{
    int i, key, cipher[20];
    string plain;
    cout << "Enter a plaintext: ";
    cin >> plain;
    cout << "Enter a key: ";
    cin >> key;
    key %= 26;
    for (i = 0; i < plain.length(); i++)
    {
        cipher[i] = int(plain[i]);
        if (plain[i] >= 'a' && plain[i] <= 'z')
        {
            cipher[i] = int(plain[i] + key);
            if (cipher[i] > int('z'))
                cipher[i] = cipher[i] % 123 + 97;
        }
        else if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            cipher[i] = int(plain[i] + key);
            if (cipher[i] > int('Z'))
                cipher[i] = cipher[i] % 91 + 65;
        }
    }
    cout << "Encrypted text: ";
    for (i = 0; i < plain.length(); i++)
        cout << char(cipher[i]);
}
void decrypt()
{
    int i, key, plain[20];
    string cipher;
    cout << "Enter a ciphertext: ";
    cin >> cipher;
    cout << "Enter a key: ";
    cin >> key;
    key %= 26;
    for (i = 0; i < cipher.length(); i++)
    {
        plain[i] = int(cipher[i]);
        if (cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            plain[i] = int(cipher[i] - key + 26);
            if (plain[i] > int('z'))
                plain[i] = plain[i] % 123 + 97;
        }
        else if (cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            plain[i] = int(cipher[i] - key + 26);
            if (plain[i] > int('Z'))
                plain[i] = plain[i] % 91 + 65;
        }
    }
    cout << "Decrypted text: ";
    for (i = 0; i < cipher.length(); i++)
        cout << char(plain[i]);
}
int main()
{
    int opt;
    cout << "Choose an option: 1. Encryption 2. Decryption" << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
        encrypt();
        break;
    case 2:
        decrypt();
        break;
    default:
        cout << "Invalid option" << endl;
    }

    return 0;
}