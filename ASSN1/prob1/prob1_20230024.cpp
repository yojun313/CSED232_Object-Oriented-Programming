#include <iostream> // ǥ�� ����� ��Ʈ���� ���� ��� ������ ����

int main() // ���� �Լ��� ����
{
    using namespace std; // 

    char name[99]; // ����� �̸��� ������ �� �ִ� char Ÿ�� �迭 ���� 
    int birth; // ������� ����⵵�� ������ ������ ���� ����
    int student_id; // ������� �л� ID�� ������ ������ ���� ����

    cin >> name; // ǥ�� �Է��� ���� ����� �̸��� �޾� name �迭�� ����
    cin >> birth >> student_id; // ǥ�� �Է��� ���� ����⵵�� �л� ID�� ���ʷ� �޾� ���� birth, student_id ������ ����

    cout << "My name is " << name << "." << endl; // ǥ�� ������� ������� �̸��� ���
    cout << "I am " << 2024 - birth + 1 << " years old." << endl; // ǥ�� ������� ������� ���̸� ����Ͽ� ��� (2024�� ����, �ѱ��� ���� ��� ��� ����)
    cout << "My student ID is " << student_id << "." << endl; // ǥ�� ������� ������� �л� ID�� ���

    return 0;
}