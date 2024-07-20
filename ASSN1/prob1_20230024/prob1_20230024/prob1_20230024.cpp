#include <iostream> // 표준 입출력 스트림을 위한 헤더 파일을 포함

int main() // 메인 함수의 시작
{
    using namespace std; // 

    char name[99]; // 사용자 이름을 저장할 수 있는 char 타입 배열 선언 
    int birth; // 사용자의 출생년도를 저장할 정수형 변수 선언
    int student_id; // 사용자의 학생 ID를 저장할 정수형 변수 선언

    cin >> name; // 표준 입력을 통해 사용자 이름을 받아 name 배열에 저장
    cin >> birth >> student_id; // 표준 입력을 통해 출생년도와 학생 ID를 차례로 받아 각각 birth, student_id 변수에 저장

    cout << "My name is " << name << "." << endl; // 표준 출력으로 사용자의 이름을 출력
    cout << "I am " << 2024 - birth + 1 << " years old." << endl; // 표준 출력으로 사용자의 나이를 계산하여 출력 (2024년 기준, 한국식 나이 계산 방법 적용)
    cout << "My student ID is " << student_id << "." << endl; // 표준 출력으로 사용자의 학생 ID를 출력

    return 0;
}