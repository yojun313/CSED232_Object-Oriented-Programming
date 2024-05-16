#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void)
{
    string line      = ""; // 사용자로부터 입력받은 각 줄을 저장할 문자열
    string inputText = ""; // 전체 입력 텍스트를 저장할 문자열
    string HexaDigit = ""; // 추출된 16진수 문자들을 저장할 문자열
    string result    = ""; // 복호화 결과를 저장할 문자열
    string ascii     = ""; // 16진수 문자열을 ASCII 문자로 변환하기 위한 임시 문자열

    int    index          = 0;   // HexaDigit 문자열 내에서 현재 처리중인 위치
    int    HexaDigitCount = 0;   // 추출된 16진수 문자의 개수
    long   intValue       = 0L;  // 16진수 문자열을 10진수로 변환한 값
    double noizeCount     = 0.0; // 노이즈 문자의 개수
    double noizeRate      = 0.0; // 노이즈 문자의 비율
    double inputCount     = 0.0; // 전체 입력 문자의 개수

    cout << "Enter a cyphertext" << endl;
    while (true)
    {
        getline(cin, line);                  // 사용자로부터 한 줄씩 입력 받음
        inputText += line + "\n";            // 입력받은 줄을 전체 텍스트에 추가
        if (line.find("..") != string::npos) // ".." 문자열을 발견하면 입력 종료
        {
            break;
        }
    }

    // 전체 입력 텍스트를 순회하며 노이즈 문자 카운트와 유효한 16진수 문자 추출
    for (char c : inputText)  // 범위기반 for loop
    {
        if (c == '#' or c == '$' or c == '%' or c == '&' or c == '*')
            noizeCount++;      // 노이즈 문자 발견 시 카운트 증가  

        if (isdigit(c) || (c >= 'A' && c <= 'F'))
        {
            HexaDigit += c;    // 16진수 문자 추가
            HexaDigitCount++;  // 카운트 증가
        }

        inputCount++;          // 전체 입력 문자 카운트 증가
    }
    inputCount--;              // 마지막 줄바꿈 문자 제외

    noizeRate = noizeCount / inputCount * 100;                     // 노이즈 비율 계산

    cout.precision(5);                                             // 소수점 이하 자릿수 설정
    cout << "Ciphertext noise rate: " << noizeRate << "%" << endl; // 노이즈 비율 출력
    cout << "Hexadecimal digits: " << HexaDigit << endl;           // 추출된 16진수 문자열 출력

    // 16진수 문자열의 길이 검증
    if (HexaDigitCount % 2 != 0) // 홀수인 경우 오류 메시지 출력 후 종료
    {
        cout << "Undecryptable: the number of hexadecimal digits is odd!\nDecryptor turn off!" << endl;
        return 0;
    }
    else if (HexaDigitCount == 0) // 16진수 문자가 없는 경우 오류 메시지 출력 후 종료
    {
        cout << "Undecryptable: where are the hexadecimal digits!\nDecryptor turn off!" << endl;
        return 0;
    }
    // 16진수 문자열을 ASCII 문자로 변환
    for (char c : HexaDigit)  // 범위기반 for loop
    {
        ascii += c;           // 현재 문자를 ascii 문자열에 추가
        index++;              // 위치 인덱스 증가
        if (index == 2)
        {
            intValue = stoi(ascii, nullptr, 16); // 16진수 문자열을 10진수 정수로 변환

            // 변환된 정수 값이 ASCII 코드 범위를 벗어나는 경우 오류 메시지 출력 후 종료
            if (intValue < 0 or intValue > 127)
            {
                cout << "Undecryptable: where are the hexadecimal digits!\nDecryptor turn off!" << endl;
                return 0;
            }
            // ASCII 코드 범위 내에 있는 경우 결과 문자열에 해당 문자 추가
            result += static_cast<char>(intValue);
            // 다음 문자 변환을 위해 인덱스와 임시 문자열 초기화
            index = 0;
            ascii = "";
        }
    }
    cout << "Decryption result: " << result << endl;
    cout << "Decryptor turn off!" << endl;

    return 0;
}