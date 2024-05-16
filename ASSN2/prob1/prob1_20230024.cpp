#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip> 

#define MAX_STUDENT_CNT 100 // �ִ� �л� ��

using namespace std;

// �л� ���� ����ü ����
typedef struct _student_info
{
    int    id;                 // �й�
    string name;               // �̸�
    int    midterm_exam_score; // �߰���� ����
    int    final_exam_score;   // �⸻��� ����
    int    total_score;        // ����
    int    retake;             // ����� ����
    char   grade;              // ����
} STUDENT_INFO;

// �Լ� ���� ����
//int  make_test_data(STUDENT_INFO* StudentInfo); // �׽�Ʈ��
int  menu_select(void);
bool add_student(STUDENT_INFO* student);
bool edit_score(STUDENT_INFO* StudentList, int StudentCnt);
void print_average(STUDENT_INFO* StudentList, int StudentCnt);
void print_list(STUDENT_INFO* StudentList, int StudentCnt);
void print_grade(STUDENT_INFO* StudentList, int StudentCnt);


int main(void)
{
    int          StudentCnt = 0;               // ���� ��ϵ� �л� �� 
    int          SelectNum = 0;                // ����ڰ� ������ �޴� ��ȣ
    STUDENT_INFO StudentList[MAX_STUDENT_CNT]; // �л� ���� �迭
    
    //StudentCnt = make_test_data(StudentList);  // 2,3,4,5 �׽�Ʈ�� ���� ���õ����� �ۼ�

    while (true)
    {
        SelectNum = menu_select();

        if (SelectNum == 1)       // 1. �л� �߰�
        {
            if (add_student(&StudentList[StudentCnt]) == true)
                StudentCnt++;
        }
        else if (SelectNum == 2)  // 2. �л� ���� ����
        {
            edit_score(StudentList, StudentCnt);
        }
        else if (SelectNum == 3)  // 3. ��� ���� ���
        {
            print_average(StudentList, StudentCnt);
        }
        else if (SelectNum == 4)  // 4. ����ǥ ���
        {
            print_list(StudentList, StudentCnt);
        }
        else if (SelectNum == 5)  // 5. ���ǥ ���
        {
            print_grade(StudentList, StudentCnt);
        }
        else if (SelectNum == 6)  // 6. ���α׷� ����
        {
            cout << "Good Bye!" << endl;
            return 0;
        }
    }

    return 0;
}
/*
int make_test_data(STUDENT_INFO* StudentInfo)
{
    int idx = 0;

    StudentInfo[idx].id = 20220001;
    StudentInfo[idx].name = "Ponix";
    StudentInfo[idx].midterm_exam_score = 100;
    StudentInfo[idx].final_exam_score = 0;
    StudentInfo[idx].retake = 1;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    StudentInfo[idx].id = 20220002;
    StudentInfo[idx].name = "TAFriend";
    StudentInfo[idx].midterm_exam_score = 100;
    StudentInfo[idx].final_exam_score = 100;
    StudentInfo[idx].retake = 1;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    StudentInfo[idx].id = 20230001;
    StudentInfo[idx].name = "StudentB";
    StudentInfo[idx].midterm_exam_score = 48;
    StudentInfo[idx].final_exam_score = 85;
    StudentInfo[idx].retake = 0;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    StudentInfo[idx].id = 20230002;
    StudentInfo[idx].name = "StudentC";
    StudentInfo[idx].midterm_exam_score = 89;
    StudentInfo[idx].final_exam_score = 78;
    StudentInfo[idx].retake = 0;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    StudentInfo[idx].id = 20230003;
    StudentInfo[idx].name = "StudentD";
    StudentInfo[idx].midterm_exam_score = 42;
    StudentInfo[idx].final_exam_score = 23;
    StudentInfo[idx].retake = 0;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    StudentInfo[idx].id = 20230004;
    StudentInfo[idx].name = "StudentE";
    StudentInfo[idx].midterm_exam_score = 48;
    StudentInfo[idx].final_exam_score = 67;
    StudentInfo[idx].retake = 0;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    StudentInfo[idx].id = 20230005;
    StudentInfo[idx].name = "StudentF";
    StudentInfo[idx].midterm_exam_score = 98;
    StudentInfo[idx].final_exam_score = 97;
    StudentInfo[idx].retake = 0;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    StudentInfo[idx].id = 20230006;
    StudentInfo[idx].name = "StudentG";
    StudentInfo[idx].midterm_exam_score = 64;
    StudentInfo[idx].final_exam_score = 75;
    StudentInfo[idx].retake = 0;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    StudentInfo[idx].id = 20230007;
    StudentInfo[idx].name = "StudentH";
    StudentInfo[idx].midterm_exam_score = 45;
    StudentInfo[idx].final_exam_score = 86;
    StudentInfo[idx].retake = 0;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    StudentInfo[idx].id = 20230008;
    StudentInfo[idx].name = "StudentI";
    StudentInfo[idx].midterm_exam_score = 62;
    StudentInfo[idx].final_exam_score = 39;
    StudentInfo[idx].retake = 0;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    StudentInfo[idx].id = 20230009;
    StudentInfo[idx].name = "Stupid";
    StudentInfo[idx].midterm_exam_score = 2;
    StudentInfo[idx].final_exam_score = 5;
    StudentInfo[idx].retake = 0;
    StudentInfo[idx].total_score = StudentInfo[idx].midterm_exam_score + StudentInfo[idx].final_exam_score;
    ++idx;

    return idx;
}
*/
int menu_select(void)
{
    int SelectNum = 0;

    // ����� �޴� ���
    cout << "----------MENU----------" << endl;
    cout << "1. Add a student" << endl;
    cout << "2. Edit the score of a student" << endl;
    cout << "3. Print average score" << endl;
    cout << "4. Print scores list" << endl;
    cout << "5. Print grades list" << endl;
    cout << "6. Exit" << endl;
    cout << "------------------------" << endl;

    // ����ڷκ��� �޴� ��ȣ �Է� ����
    cout << "Selection: ";
    cin >> SelectNum;

    return SelectNum;
}

// 1. �л� �߰�
// �л� ������ �Է� �޾� �迭�� ����
// �Է� ���� ��ȿ�� �˻� ��, ������ ������ ���� �޽��� ����ϰ� false ��ȯ
// ��� �Է°��� ��ȿ�ϸ� �л� ���� �迭�� �����ϰ� true�� ��ȯ�մϴ�.
bool add_student(STUDENT_INFO* student)
{
    // �й� �Է� �ޱ�
    cout << "Student id: ";
    cin >> student->id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // �й� ��ȿ�� �˻�
    if (student->id < 10000000 || student->id > 99999999)
    {
        cout << "Failed to add: invalid student id!" << endl;
        return false;
    }

    // �̸� �Է� �ޱ�
    cout << "Name: ";
    getline(cin, student->name);

    // �̸� ���� ��ȿ�� �˻�
    if (student->name.length() > 10)
    {
        cout << "Failed to add: invalid name!" << endl;
        return false;
    }

    // �̸��� ���ĺ����θ� �̷���� �ִ��� �˻�
    for (int i = 0; i < student->name.length(); i++)
    {
        char ch = student->name[i];
        if (!isalpha(ch))
        {
            cout << "Failed to add: invalid name!" << endl;
            return false;
        }
    }

    // �߰���� ���� �Է� �ޱ�
    cout << "Midterm exam score: ";
    cin >> student->midterm_exam_score;

    // �߰���� ���� ��ȿ�� �˻�
    if (student->midterm_exam_score < 0 || student->midterm_exam_score > 100)
    {
        cout << "Failed to add: invalid midterm exam score!" << endl;
        return false;
    }

    // �⸻��� ���� �Է� �ޱ�
    cout << "Final exam score: ";
    cin >> student->final_exam_score;

    // �⸻��� ���� ��ȿ�� �˻�
    if (student->final_exam_score < 0 || student->final_exam_score > 100)
    {
        cout << "Failed to add: invalid final exam score!" << endl;
        return false;
    }

    // ���� �Ի�
    student->total_score = student->midterm_exam_score + student->final_exam_score;

    // ����� ���� �Է� �ޱ�
    cout << "Retake: ";
    cin >> student->retake;

    // ����� ���� ��ȿ�� �˻�
    if (student->retake != 0 && student->retake != 1)
    {
        cout << "Failed to add: invalid retake value!" << endl;
        return false;
    }

    cout << "The student is added!" << endl;

    return true;
}

// 2. �л� ���� ����
// �л��� �߰���� ������ �⸻��� ���� ����
// ������ �л��� �й��� ������ ���� ����, ���ο� ������ �Է¹޾� �ش� �л��� ���� ������Ʈ
bool edit_score(STUDENT_INFO* StudentList, int StudentCnt)
{
    int SelectNum = 0;
    int StudentID = 0;
    int StudentIndex = 0;
    int Score = 0;

    // ������ ���� ���� ����
    cout << "--------Fuction--------" << endl;
    cout << "1. Edit the midterm exam score" << endl;
    cout << "2. Edit the final exam score" << endl;
    cout << "------------------------" << endl;
    cout << "Selection: ";
    cin >> SelectNum;

    // �й� �Է� �ޱ�
    cout << "Student id: ";
    cin >> StudentID;

    // �Է� ���� ������ 8 �ڸ� ���� �������� Ȯ��
    if (StudentID < 10000000 || StudentID > 99999999)
    {
        cout << "Failed to add: invalid student id!" << endl;
        return false;
    }

    // �й� �˻� �� �ε��� ã��
    for (StudentIndex = 0; StudentIndex < StudentCnt; StudentIndex++)
    {
        if (StudentList[StudentIndex].id == StudentID)
        {
            break;
        }
        // �л��� ��Ͽ� ������ �����޽��� ��� �� �Լ� ����
        else if (StudentList[StudentIndex].id != StudentID && StudentIndex == StudentCnt - 1)
        {
            cout << "Can't find the student id: " << StudentID << endl;
            return false;
        }
    }

    // ���ο� ���� �Է� �ޱ�
    cout << "Score: ";
    cin >> Score;

    // �Է� ���� ���� ������ 0~100���� Ȯ��
    if (Score < 0 || Score > 100)
    {
        cout << "Failed to edit: invalid exam score!" << endl;
        return false;
    }

    // �Է¹��� ������ ��ȯ
    if (SelectNum == 1)
        StudentList[StudentIndex].midterm_exam_score = Score;
    else
        StudentList[StudentIndex].final_exam_score = Score;

    // total_score ������Ʈ
    StudentList[StudentIndex].total_score = StudentList[StudentIndex].midterm_exam_score + StudentList[StudentIndex].final_exam_score;

    cout << "Score editing done!" << endl;

    return true;
}

// 3. ��� ���� ���
// ��ϵ� ��� �л����� ��� ������ ǥ�������� ����Ͽ� ���
void print_average(STUDENT_INFO* StudentList, int StudentCnt)
{
    int    total_score = 0;
    double average_score = 0.0;
    double sigma = 0.0;
    double deviation = 0.0;

    // ���� ���
    for (int i = 0; i < StudentCnt; i++)
    {
        total_score += (StudentList[i].midterm_exam_score + StudentList[i].final_exam_score);
    }

    // ��� ���� ���
    average_score = total_score / StudentCnt;

    // ǥ������ ����� ���� �غ�
    for (int i = 0; i < StudentCnt; i++)
    {
        sigma += pow(StudentList[i].midterm_exam_score + StudentList[i].final_exam_score - average_score, 2);
    }

    // ǥ������ ���
    deviation = sqrt(sigma / StudentCnt);

    // ��� ������ ǥ������ ���
    cout << setprecision(5) << "Average Score: " << average_score << endl;
    cout << setprecision(5) << "Standard deviation: " << deviation << endl;

    return;
}

// 4. ����ǥ ���
// ��ϵ� ��� �л����� ���� ����� ������ ������������ �����Ͽ� ���
void print_list(STUDENT_INFO* StudentList, int StudentCnt)
{
    // ���� ������ ����Ͽ� �л� ����� ������ ������������ ����
    for (int i = 0; i < StudentCnt - 1; i++)
    {
        for (int j = 0; j < StudentCnt - i - 1; j++)
        {
            int totalScoreJ = StudentList[j].midterm_exam_score + StudentList[j].final_exam_score;
            int totalScoreJPlus1 = StudentList[j + 1].midterm_exam_score + StudentList[j + 1].final_exam_score;

            // ���� �л��� ������ ������ ��ü�Ѵ�.
            if (totalScoreJ < totalScoreJPlus1)
            {
                STUDENT_INFO temp = StudentList[j];
                StudentList[j] = StudentList[j + 1];
                StudentList[j + 1] = temp;
            }
            // ������ ������ �й� ������ �����Ѵ�.
            else if (totalScoreJ == totalScoreJPlus1 && StudentList[j].id > StudentList[j + 1].id)
            {
                STUDENT_INFO temp = StudentList[j];
                StudentList[j] = StudentList[j + 1];
                StudentList[j + 1] = temp;
            }
        }
    }
    
    // �л� ����Ʈ ���
    for (int i = 0; i < StudentCnt; i++)
    {
        cout << StudentList[i].id << " " << StudentList[i].name << " " << StudentList[i].midterm_exam_score << " " << StudentList[i].final_exam_score << " " << StudentList[i].midterm_exam_score + StudentList[i].final_exam_score << endl;
    }

    cout << "Finished printing the list!" << endl;

    return;
}

// 5. ���ǥ ���
// ��ϵ� ��� �л��鿡 ���� ������ �������� ����� ����ϰ�, �л��� ID, �̸�, ����, ����� ����, ������ ����մϴ�.
void print_grade(STUDENT_INFO* StudentList, int StudentCnt)
{
    int    countLarger = 0;
    double percentile = 0.0;

    for (int i = 0; i < StudentCnt; i++)
    {
        // ���� ����� ���� i��° ����� �������� ū ��� �� ����
        for (int j = 0; j < StudentCnt; j++)
        {
            if (StudentList[j].total_score > StudentList[i].total_score)
            {
                countLarger++;
            }
        }

        // ���� ����� ���
        percentile = 100 * ((double)(countLarger + 1) / (double)(StudentCnt));

        // ������ A �ޱ� ���� ����
        if ((StudentList[i].total_score > 150) && (StudentCnt * 0.3 < 1 && countLarger == 0 || percentile < 30))
        {
            StudentList[i].grade = 'A';
            // ����� ���� �� �� �ܰ� ����
            if (StudentList[i].retake == 1)
                StudentList[i].grade = 'B';
        }
        // ������ B �ޱ� ���� ����
        else if ((StudentList[i].total_score > 100) && (StudentCnt * 0.7 < 2 && countLarger == 1 || percentile < 70))
        {
            StudentList[i].grade = 'B';
            // ����� ���� �� �� �ܰ� ����
            if (StudentList[i].retake == 1)
                StudentList[i].grade = 'C';
        }
        // ������ C �ޱ� ���� ����
        else if ((StudentList[i].total_score > 50) && (StudentCnt * 0.9 < 3 && countLarger == 2 || percentile < 90))
        {
            StudentList[i].grade = 'C';
            // ����� ���� �� �� �ܰ� ����
            if (StudentList[i].retake == 1)
                StudentList[i].grade = 'D';
        }
        // �ƹ��͵� �ش� �� �� ��� ���� D
        else
        {
            StudentList[i].grade = 'D';
        }
        // ��� ���� ����Ʈ ���
        cout << StudentList[i].id << " " << StudentList[i].name << " " << StudentList[i].total_score << " " << StudentList[i].retake << " " << StudentList[i].grade << endl;
        countLarger = 0;
    }

    cout << "Finished printing the list!" << endl;

    return;
}