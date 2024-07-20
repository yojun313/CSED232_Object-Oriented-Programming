#include <iostream> // 표준 입출력 라이브러리 포함

// 주어진 숫자 x에 대해 특정 계산을 수행하는 함수
int calculate(int x)
{
    return x % 10; // x를 10으로 나눈 나머지 반환
}

// 최종 계산을 위한 함수
int final_cal(int y)
{
    // y에서 1부터 9까지 차례대로 뺀 값을 모두 곱한 후, 1부터 9까지의 곱으로 나눈 결과 반환
    return ((y - 1) * (y - 2) * (y - 3) * (y - 4) * (y - 5) * (y - 6) * (y - 7) * (y - 8) * (y - 9)) / (1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9);
}

int main()
{
    using namespace std;

    char name1[3]; // 첫 번째 이름을 저장할 문자 배열
    char name2[3]; // 두 번째 이름을 저장할 문자 배열

    // 사용자로부터 두 이름을 입력 받음
    cin >> name1 >> name2;

    // 두 이름의 첫 번째 및 두 번째 글자에 대해 calculate 함수를 사용하여 첫 번째 줄의 값 계산
    int first_line_1 = calculate(name1[0]);
    int first_line_2 = calculate(name2[0]);
    int first_line_3 = calculate(name1[1]);
    int first_line_4 = calculate(name2[1]);

    // 첫 번째 줄의 계산 결과를 바탕으로 두 번째 줄의 값 계산
    int second_line_1 = calculate(first_line_1 + first_line_2);
    int second_line_2 = calculate(first_line_2 + first_line_3);
    int second_line_3 = calculate(first_line_3 + first_line_4);

    // 두 번째 줄의 계산 결과를 바탕으로 세 번째 줄의 값 계산
    int third_line_1 = calculate(second_line_1 + second_line_2);
    int third_line_2 = calculate(second_line_2 + second_line_3);

    // 세 번째 줄의 계산 결과를 이용해 최종 궁합 백분율 계산
    int percent = third_line_1 * 10 + third_line_2;

    // 각 줄의 계산 결과와 최종 궁합 백분율 출력
    cout << name1[0] << " " << name2[0] << " " << name1[1] << " " << name2[1] << endl;
    cout << first_line_1 << " " << first_line_2 << " " << first_line_3 << " " << first_line_4 << endl;
    cout << second_line_1 << " " << second_line_2 << " " << second_line_3 << endl;
    cout << third_line_1 << " " << third_line_2 << endl;
    cout << "The chemistry between " << name1 << " and " << name2 << " is " << percent + 100 * final_cal(third_line_1) * final_cal(third_line_2) << "%." << endl;

    return 0;
}