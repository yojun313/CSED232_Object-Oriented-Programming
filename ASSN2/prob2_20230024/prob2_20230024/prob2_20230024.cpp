#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void)
{
    string line      = ""; // ����ڷκ��� �Է¹��� �� ���� ������ ���ڿ�
    string inputText = ""; // ��ü �Է� �ؽ�Ʈ�� ������ ���ڿ�
    string HexaDigit = ""; // ����� 16���� ���ڵ��� ������ ���ڿ�
    string result    = ""; // ��ȣȭ ����� ������ ���ڿ�
    string ascii     = ""; // 16���� ���ڿ��� ASCII ���ڷ� ��ȯ�ϱ� ���� �ӽ� ���ڿ�

    int    index          = 0;   // HexaDigit ���ڿ� ������ ���� ó������ ��ġ
    int    HexaDigitCount = 0;   // ����� 16���� ������ ����
    long   intValue       = 0L;  // 16���� ���ڿ��� 10������ ��ȯ�� ��
    double noizeCount     = 0.0; // ������ ������ ����
    double noizeRate      = 0.0; // ������ ������ ����
    double inputCount     = 0.0; // ��ü �Է� ������ ����

    cout << "Enter a cyphertext" << endl;
    while (true)
    {
        getline(cin, line);                  // ����ڷκ��� �� �پ� �Է� ����
        inputText += line + "\n";            // �Է¹��� ���� ��ü �ؽ�Ʈ�� �߰�
        if (line.find("..") != string::npos) // ".." ���ڿ��� �߰��ϸ� �Է� ����
        {
            break;
        }
    }

    // ��ü �Է� �ؽ�Ʈ�� ��ȸ�ϸ� ������ ���� ī��Ʈ�� ��ȿ�� 16���� ���� ����
    for (char c : inputText)  // ������� for loop
    {
        if (c == '#' or c == '$' or c == '%' or c == '&' or c == '*')
            noizeCount++;      // ������ ���� �߰� �� ī��Ʈ ����  

        if (isdigit(c) || (c >= 'A' && c <= 'F'))
        {
            HexaDigit += c;    // 16���� ���� �߰�
            HexaDigitCount++;  // ī��Ʈ ����
        }

        inputCount++;          // ��ü �Է� ���� ī��Ʈ ����
    }
    inputCount--;              // ������ �ٹٲ� ���� ����

    noizeRate = noizeCount / inputCount * 100;                     // ������ ���� ���

    cout.precision(5);                                             // �Ҽ��� ���� �ڸ��� ����
    cout << "Ciphertext noise rate: " << noizeRate << "%" << endl; // ������ ���� ���
    cout << "Hexadecimal digits: " << HexaDigit << endl;           // ����� 16���� ���ڿ� ���

    // 16���� ���ڿ��� ���� ����
    if (HexaDigitCount % 2 != 0) // Ȧ���� ��� ���� �޽��� ��� �� ����
    {
        cout << "Undecryptable: the number of hexadecimal digits is odd!\nDecryptor turn off!" << endl;
        return 0;
    }
    else if (HexaDigitCount == 0) // 16���� ���ڰ� ���� ��� ���� �޽��� ��� �� ����
    {
        cout << "Undecryptable: where are the hexadecimal digits!\nDecryptor turn off!" << endl;
        return 0;
    }
    // 16���� ���ڿ��� ASCII ���ڷ� ��ȯ
    for (char c : HexaDigit)  // ������� for loop
    {
        ascii += c;           // ���� ���ڸ� ascii ���ڿ��� �߰�
        index++;              // ��ġ �ε��� ����
        if (index == 2)
        {
            intValue = stoi(ascii, nullptr, 16); // 16���� ���ڿ��� 10���� ������ ��ȯ

            // ��ȯ�� ���� ���� ASCII �ڵ� ������ ����� ��� ���� �޽��� ��� �� ����
            if (intValue < 0 or intValue > 127)
            {
                cout << "Undecryptable: where are the hexadecimal digits!\nDecryptor turn off!" << endl;
                return 0;
            }
            // ASCII �ڵ� ���� ���� �ִ� ��� ��� ���ڿ��� �ش� ���� �߰�
            result += static_cast<char>(intValue);
            // ���� ���� ��ȯ�� ���� �ε����� �ӽ� ���ڿ� �ʱ�ȭ
            index = 0;
            ascii = "";
        }
    }
    cout << "Decryption result: " << result << endl;
    cout << "Decryptor turn off!" << endl;

    return 0;
}