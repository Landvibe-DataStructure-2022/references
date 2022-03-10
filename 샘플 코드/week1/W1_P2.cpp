#include <iostream>
#include <string>

using namespace std;

int n; // 배열의 크기 N
int arr[10000]; // 최대 크기가 10,000인 배열 arr

int main() {
    int t; // 테스트 케이스 수 T
    cin >> t;

    while (t--) {
        int d; // 시프트 연산을 할 횟수 D

        memset(arr, 0, sizeof(arr));
//        #include <string>을 선언하면 쓸 수 있는 함수
//        (첫 번째(배열 혹은 벡터))를 (세 번째(배열 혹은 벡터의 크기))만큼 (두 번째(0 or -1만 가능))로 초기화시킴

//        만약 memset을 쓰지 않는다면, 그냥 아래 코드처럼 while문을 반복할 때마다 배열을 초기화해주면 됨
//        for(int i = 0; i<10000; i++) {
//            arr[i] = 0;
//        }

        cin >> n >> d; // 배열의 크기와 시프트 횟수를 입력받음
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // 배열을 입력받음
        }

//        문제해결 포인트
//        굳이 직접 배열을 한 칸씩 매번 옮겨야 할까?
//        배열을 직접 옮기지 말고, 0번째부터 읽는게 아니라 시프트한 횟수를 계산해서 읽으면 안 될까?

        int curIndex = 0; // 처음 배열을 읽게 될 위치에 관한 변수 curIndex

        curIndex = d % n; // d가 n보다 클 경우, d/n만큼 시프트하고 나머지만큼 처음 읽을 위치를 조정해주면 된다.
        curIndex = n - curIndex; // 오른쪽으로 시프트시키는 것이기 때문에, 한 번 시프트하면 0번째 인덱스를 보는 게 아니라 n-1번째 인덱스를 봐야 한다.
        for (int i = 0; i < n; i++) { // 배열 전체 출력하려면 n번 반복해야 한다
            if (curIndex == n) {
                curIndex = 0; // curIndex++를 하다 curIndex가 n이 되면, 배열의 인덱스 범위를 초과하게 되므로 다시 0으로 만들어서 배열 맨 앞부터 읽게 함
            }
            cout << arr[curIndex] << " "; // 출력
            curIndex++; // 다음꺼 읽기 위해 curIndex++
        }
        cout << "\n";
    }
    return 0;
}