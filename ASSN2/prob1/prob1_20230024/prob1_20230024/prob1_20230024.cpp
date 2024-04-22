#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip> 

#define MAX_STUDENT_CNT 100 // 최대 학생 수

using namespace std;

// 학생 정보 구조체 정의
typedef struct _student_info
{
    int    id;                 // 학번
    string name;               // 이름
    int    midterm_exam_score; // 중간고사 점수
    int    final_exam_score;   // 기말고사 점수
    int    total_score;        // 총점
    int    retake;             // 재시험 여부
    char   grade;              // 학점
} STUDENT_INFO;

// 함수 원형 선언
//int  make_test_data(STUDENT_INFO* StudentInfo); // 테스트용
int  menu_select(void);
bool add_student(STUDENT_INFO* student);
bool edit_score(STUDENT_INFO* StudentList, int StudentCnt);
void print_average(STUDENT_INFO* StudentList, int StudentCnt);
void print_list(STUDENT_INFO* StudentList, int StudentCnt);
void print_grade(STUDENT_INFO* StudentList, int StudentCnt);


int main(void)
{
    int          StudentCnt = 0;               // 현재 등록된 학생 수 
    int          SelectNum = 0;                // 사용자가 선택한 메뉴 번호
    STUDENT_INFO StudentList[MAX_STUDENT_CNT]; // 학생 정보 배열
    
    //StudentCnt = make_test_data(StudentList);  // 2,3,4,5 테스트를 위한 샘플데이터 작성

    while (true)
    {
        SelectNum = menu_select();

        if (SelectNum == 1)       // 1. 학생 추가
        {
            if (add_student(&StudentList[StudentCnt]) == true)
                StudentCnt++;
        }
        else if (SelectNum == 2)  // 2. 학생 점수 수정
        {
            edit_score(StudentList, StudentCnt);
        }
        else if (SelectNum == 3)  // 3. 평균 점수 출력
        {
            print_average(StudentList, StudentCnt);
        }
        else if (SelectNum == 4)  // 4. 점수표 출력
        {
            print_list(StudentList, StudentCnt);
        }
        else if (SelectNum == 5)  // 5. 등급표 출력
        {
            print_grade(StudentList, StudentCnt);
        }
        else if (SelectNum == 6)  // 6. 프로그램 종료
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

    // 사용자 메뉴 출력
    cout << "----------MENU----------" << endl;
    cout << "1. Add a student" << endl;
    cout << "2. Edit the score of a student" << endl;
    cout << "3. Print average score" << endl;
    cout << "4. Print scores list" << endl;
    cout << "5. Print grades list" << endl;
    cout << "6. Exit" << endl;
    cout << "------------------------" << endl;

    // 사용자로부터 메뉴 번호 입력 받음
    cout << "Selection: ";
    cin >> SelectNum;

    return SelectNum;
}

// 1. 학생 추가
// 학생 정보를 입력 받아 배열에 저장
// 입력 값의 유효성 검사 후, 오류가 있으면 오류 메시지 출력하고 false 반환
// 모든 입력값이 유효하면 학생 정보 배열에 저장하고 true를 반환합니다.
bool add_student(STUDENT_INFO* student)
{
    // 학번 입력 받기
    cout << "Student id: ";
    cin >> student->id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // 학번 유효성 검사
    if (student->id < 10000000 || student->id > 99999999)
    {
        cout << "Failed to add: invalid student id!" << endl;
        return false;
    }

    // 이름 입력 받기
    cout << "Name: ";
    getline(cin, student->name);

    // 이름 길이 유효성 검사
    if (student->name.length() > 10)
    {
        cout << "Failed to add: invalid name!" << endl;
        return false;
    }

    // 이름이 알파벳으로만 이루어져 있는지 검사
    for (int i = 0; i < student->name.length(); i++)
    {
        char ch = student->name[i];
        if (!isalpha(ch))
        {
            cout << "Failed to add: invalid name!" << endl;
            return false;
        }
    }

    // 중간고사 점수 입력 받기
    cout << "Midterm exam score: ";
    cin >> student->midterm_exam_score;

    // 중간고사 점수 유효성 검사
    if (student->midterm_exam_score < 0 || student->midterm_exam_score > 100)
    {
        cout << "Failed to add: invalid midterm exam score!" << endl;
        return false;
    }

    // 기말고사 점수 입력 받기
    cout << "Final exam score: ";
    cin >> student->final_exam_score;

    // 기말고사 점수 유효성 검사
    if (student->final_exam_score < 0 || student->final_exam_score > 100)
    {
        cout << "Failed to add: invalid final exam score!" << endl;
        return false;
    }

    // 총점 게산
    student->total_score = student->midterm_exam_score + student->final_exam_score;

    // 재시험 여부 입력 받기
    cout << "Retake: ";
    cin >> student->retake;

    // 재시험 여부 유효성 검사
    if (student->retake != 0 && student->retake != 1)
    {
        cout << "Failed to add: invalid retake value!" << endl;
        return false;
    }

    cout << "The student is added!" << endl;

    return true;
}

// 2. 학생 점수 수정
// 학생의 중간고사 점수나 기말고사 점수 수정
// 수정할 학생의 학번과 수정할 점수 종류, 새로운 점수를 입력받아 해당 학생의 정보 업데이트
bool edit_score(STUDENT_INFO* StudentList, int StudentCnt)
{
    int SelectNum = 0;
    int StudentID = 0;
    int StudentIndex = 0;
    int Score = 0;

    // 수정할 점수 종류 선택
    cout << "--------Fuction--------" << endl;
    cout << "1. Edit the midterm exam score" << endl;
    cout << "2. Edit the final exam score" << endl;
    cout << "------------------------" << endl;
    cout << "Selection: ";
    cin >> SelectNum;

    // 학번 입력 받기
    cout << "Student id: ";
    cin >> StudentID;

    // 입력 받은 정수가 8 자리 양의 정수인지 확인
    if (StudentID < 10000000 || StudentID > 99999999)
    {
        cout << "Failed to add: invalid student id!" << endl;
        return false;
    }

    // 학번 검색 및 인덱스 찾기
    for (StudentIndex = 0; StudentIndex < StudentCnt; StudentIndex++)
    {
        if (StudentList[StudentIndex].id == StudentID)
        {
            break;
        }
        // 학생이 목록에 없으면 오류메시지 출력 후 함수 종료
        else if (StudentList[StudentIndex].id != StudentID && StudentIndex == StudentCnt - 1)
        {
            cout << "Can't find the student id: " << StudentID << endl;
            return false;
        }
    }

    // 새로운 점수 입력 받기
    cout << "Score: ";
    cin >> Score;

    // 입력 받은 정수 범위가 0~100인지 확인
    if (Score < 0 || Score > 100)
    {
        cout << "Failed to edit: invalid exam score!" << endl;
        return false;
    }

    // 입력받은 점수로 변환
    if (SelectNum == 1)
        StudentList[StudentIndex].midterm_exam_score = Score;
    else
        StudentList[StudentIndex].final_exam_score = Score;

    // total_score 업데이트
    StudentList[StudentIndex].total_score = StudentList[StudentIndex].midterm_exam_score + StudentList[StudentIndex].final_exam_score;

    cout << "Score editing done!" << endl;

    return true;
}

// 3. 평균 점수 출력
// 등록된 모든 학생들의 평균 점수와 표준편차를 계산하여 출력
void print_average(STUDENT_INFO* StudentList, int StudentCnt)
{
    int    total_score = 0;
    double average_score = 0.0;
    double sigma = 0.0;
    double deviation = 0.0;

    // 총점 계산
    for (int i = 0; i < StudentCnt; i++)
    {
        total_score += (StudentList[i].midterm_exam_score + StudentList[i].final_exam_score);
    }

    // 평균 점수 계산
    average_score = total_score / StudentCnt;

    // 표준편차 계산을 위한 준비
    for (int i = 0; i < StudentCnt; i++)
    {
        sigma += pow(StudentList[i].midterm_exam_score + StudentList[i].final_exam_score - average_score, 2);
    }

    // 표준편차 계산
    deviation = sqrt(sigma / StudentCnt);

    // 평균 점수와 표준편차 출력
    cout << setprecision(5) << "Average Score: " << average_score << endl;
    cout << setprecision(5) << "Standard deviation: " << deviation << endl;

    return;
}

// 4. 점수표 출력
// 등록된 모든 학생들의 점수 목록을 총점의 내림차순으로 정렬하여 출력
void print_list(STUDENT_INFO* StudentList, int StudentCnt)
{
    // 버블 정렬을 사용하여 학생 목록을 총점의 내림차순으로 정렬
    for (int i = 0; i < StudentCnt - 1; i++)
    {
        for (int j = 0; j < StudentCnt - i - 1; j++)
        {
            int totalScoreJ = StudentList[j].midterm_exam_score + StudentList[j].final_exam_score;
            int totalScoreJPlus1 = StudentList[j + 1].midterm_exam_score + StudentList[j + 1].final_exam_score;

            // 다음 학생의 총점이 높으면 교체한다.
            if (totalScoreJ < totalScoreJPlus1)
            {
                STUDENT_INFO temp = StudentList[j];
                StudentList[j] = StudentList[j + 1];
                StudentList[j + 1] = temp;
            }
            // 총점이 같으면 학번 순서로 정렬한다.
            else if (totalScoreJ == totalScoreJPlus1 && StudentList[j].id > StudentList[j + 1].id)
            {
                STUDENT_INFO temp = StudentList[j];
                StudentList[j] = StudentList[j + 1];
                StudentList[j + 1] = temp;
            }
        }
    }
    
    // 학생 리스트 출력
    for (int i = 0; i < StudentCnt; i++)
    {
        cout << StudentList[i].id << " " << StudentList[i].name << " " << StudentList[i].midterm_exam_score << " " << StudentList[i].final_exam_score << " " << StudentList[i].midterm_exam_score + StudentList[i].final_exam_score << endl;
    }

    cout << "Finished printing the list!" << endl;

    return;
}

// 5. 등급표 출력
// 등록된 모든 학생들에 대해 총점을 기준으로 등급을 계산하고, 학생의 ID, 이름, 총점, 재시험 여부, 학점을 출력합니다.
void print_grade(STUDENT_INFO* StudentList, int StudentCnt)
{
    int    countLarger = 0;
    double percentile = 0.0;

    for (int i = 0; i < StudentCnt; i++)
    {
        // 순위 계산을 위해 i번째 사람의 총점보다 큰 사람 수 세기
        for (int j = 0; j < StudentCnt; j++)
        {
            if (StudentList[j].total_score > StudentList[i].total_score)
            {
                countLarger++;
            }
        }

        // 상위 백분율 계산
        percentile = 100 * ((double)(countLarger + 1) / (double)(StudentCnt));

        // 학점을 A 받기 위한 조건
        if ((StudentList[i].total_score > 150) && (StudentCnt * 0.3 < 1 && countLarger == 0 || percentile < 30))
        {
            StudentList[i].grade = 'A';
            // 재수강 했을 때 한 단계 낮춤
            if (StudentList[i].retake == 1)
                StudentList[i].grade = 'B';
        }
        // 학점을 B 받기 위한 조건
        else if ((StudentList[i].total_score > 100) && (StudentCnt * 0.7 < 2 && countLarger == 1 || percentile < 70))
        {
            StudentList[i].grade = 'B';
            // 재수강 했을 때 한 단계 낮춤
            if (StudentList[i].retake == 1)
                StudentList[i].grade = 'C';
        }
        // 학점을 C 받기 위한 조건
        else if ((StudentList[i].total_score > 50) && (StudentCnt * 0.9 < 3 && countLarger == 2 || percentile < 90))
        {
            StudentList[i].grade = 'C';
            // 재수강 했을 때 한 단계 낮춤
            if (StudentList[i].retake == 1)
                StudentList[i].grade = 'D';
        }
        // 아무것도 해당 안 될 경우 학점 D
        else
        {
            StudentList[i].grade = 'D';
        }
        // 등급 포함 리스트 출력
        cout << StudentList[i].id << " " << StudentList[i].name << " " << StudentList[i].total_score << " " << StudentList[i].retake << " " << StudentList[i].grade << endl;
        countLarger = 0;
    }

    cout << "Finished printing the list!" << endl;

    return;
}