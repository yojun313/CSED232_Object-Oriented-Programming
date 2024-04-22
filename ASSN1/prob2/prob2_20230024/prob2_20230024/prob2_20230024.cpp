#include <iostream> 
#include <iomanip> 

// x에 대한 함수 정의, 이 경우 x의 제곱을 반환
double f_function(double x) {
    return x * x;
}

int main() // 메인 함수의 시작
{
    using namespace std;

    double x0; // 시작점 x0을 저장할 실수형 변수 선언
    double x; // 특정 점 x를 저장할 실수형 변수 선언
    double h; // 증분 h를 저장할 실수형 변수 선언

    cin >> x0 >> x >> h; // 사용자로부터 x0, x, h 값 입력 받음

    // 정확한 함수값 계산
    double exact_answer = f_function(x);
    // 근사적 함수값 계산: 함수 f(x0)와 f(x0+h)의 차이를 h로 나눈 값에 (x - x0)을 곱한 후 f(x0)에 더함
    double approximate_answer = f_function(x0) + ((f_function(x0 + h) - f_function(x0)) / h) * (x - x0);

    // 정확한 값과 근사값을 소수점 다섯 번째 자리까지 출력
    cout << setprecision(5) << "Exact Answer is " << exact_answer << endl;
    cout << setprecision(5) << "Approximate answer is " << approximate_answer << endl;

    return 0;
}