#include <iostream>

char symbol (char sym, char begin, int s)
{
    int index = (int (sym) - int (begin) + s) % 26;
    index = (index>=0) ? index+begin :  index+begin+26;
    return char (index);
}

std::string encrypt_caesar(std::string str_Encrypt, int s)
{
    std::string result;
    for (int i=0; i <= str_Encrypt.length(); i++)
    {
        if (str_Encrypt[i] >= 'A' && str_Encrypt[i] <= 'Z')
        {
            result += symbol (str_Encrypt[i], 'A', s);
        }
        else if (str_Encrypt[i] >= 'a' && str_Encrypt[i] <= 'z')
        {
            result += symbol (str_Encrypt[i], 'a', s);
        }
        else {
            result += str_Encrypt[i];
        }
    }
    return result;
}

std::string decrypt_caesar(std::string str_Decrypt, int s)
{
    return encrypt_caesar(str_Decrypt, -s);
}
int main() {
    std::cout << "------------Caesar Code------------\n" << std::endl;
//  while (true)
//  {
        std::string text;
        std::cout << "Enter your message please: ";
        std::getline(std::cin, text);

        int bias;
        std::cout << "Enter code: ";
        std::cin >> bias;
        bias = bias%26;

        int operation;
        std::cout << "Enter '1' for encrypt or '0' for decrypt: ";
        std::cin >> operation;

        if (operation == 1)
        {
            std::cout <<"Result: " << encrypt_caesar(text, bias) << std::endl;
        }
        else if (operation == 0)
        {
            std::cout <<"Result: " << decrypt_caesar(text, bias) << std::endl;
        }
        else
        {
            std::cout <<"Operation input error!" << std::endl;
        }
//  }
}