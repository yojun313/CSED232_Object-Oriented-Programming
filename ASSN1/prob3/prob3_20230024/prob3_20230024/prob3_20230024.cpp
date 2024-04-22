#include <iostream> // ǥ�� ����� ���̺귯�� ����

// �־��� ���� x�� ���� Ư�� ����� �����ϴ� �Լ�
int calculate(int x)
{
    return x % 10; // x�� 10���� ���� ������ ��ȯ
}

// ���� ����� ���� �Լ�
int final_cal(int y)
{
    // y���� 1���� 9���� ���ʴ�� �� ���� ��� ���� ��, 1���� 9������ ������ ���� ��� ��ȯ
    return ((y - 1) * (y - 2) * (y - 3) * (y - 4) * (y - 5) * (y - 6) * (y - 7) * (y - 8) * (y - 9)) / (1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9);
}

int main()
{
    using namespace std;

    char name1[3]; // ù ��° �̸��� ������ ���� �迭
    char name2[3]; // �� ��° �̸��� ������ ���� �迭

    // ����ڷκ��� �� �̸��� �Է� ����
    cin >> name1 >> name2;

    // �� �̸��� ù ��° �� �� ��° ���ڿ� ���� calculate �Լ��� ����Ͽ� ù ��° ���� �� ���
    int first_line_1 = calculate(name1[0]);
    int first_line_2 = calculate(name2[0]);
    int first_line_3 = calculate(name1[1]);
    int first_line_4 = calculate(name2[1]);

    // ù ��° ���� ��� ����� �������� �� ��° ���� �� ���
    int second_line_1 = calculate(first_line_1 + first_line_2);
    int second_line_2 = calculate(first_line_2 + first_line_3);
    int second_line_3 = calculate(first_line_3 + first_line_4);

    // �� ��° ���� ��� ����� �������� �� ��° ���� �� ���
    int third_line_1 = calculate(second_line_1 + second_line_2);
    int third_line_2 = calculate(second_line_2 + second_line_3);

    // �� ��° ���� ��� ����� �̿��� ���� ���� ����� ���
    int percent = third_line_1 * 10 + third_line_2;

    // �� ���� ��� ����� ���� ���� ����� ���
    cout << name1[0] << " " << name2[0] << " " << name1[1] << " " << name2[1] << endl;
    cout << first_line_1 << " " << first_line_2 << " " << first_line_3 << " " << first_line_4 << endl;
    cout << second_line_1 << " " << second_line_2 << " " << second_line_3 << endl;
    cout << third_line_1 << " " << third_line_2 << endl;
    cout << "The chemistry between " << name1 << " and " << name2 << " is " << percent + 100 * final_cal(third_line_1) * final_cal(third_line_2) << "%." << endl;

    return 0;
}