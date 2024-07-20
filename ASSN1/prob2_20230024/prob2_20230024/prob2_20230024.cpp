#include <iostream> 
#include <iomanip> 

// x�� ���� �Լ� ����, �� ��� x�� ������ ��ȯ
double f_function(double x) {
    return x * x;
}

int main() // ���� �Լ��� ����
{
    using namespace std;

    double x0; // ������ x0�� ������ �Ǽ��� ���� ����
    double x; // Ư�� �� x�� ������ �Ǽ��� ���� ����
    double h; // ���� h�� ������ �Ǽ��� ���� ����

    cin >> x0 >> x >> h; // ����ڷκ��� x0, x, h �� �Է� ����

    // ��Ȯ�� �Լ��� ���
    double exact_answer = f_function(x);
    // �ٻ��� �Լ��� ���: �Լ� f(x0)�� f(x0+h)�� ���̸� h�� ���� ���� (x - x0)�� ���� �� f(x0)�� ����
    double approximate_answer = f_function(x0) + ((f_function(x0 + h) - f_function(x0)) / h) * (x - x0);

    // ��Ȯ�� ���� �ٻ簪�� �Ҽ��� �ټ� ��° �ڸ����� ���
    cout << setprecision(5) << "Exact Answer is " << exact_answer << endl;
    cout << setprecision(5) << "Approximate answer is " << approximate_answer << endl;

    return 0;
}