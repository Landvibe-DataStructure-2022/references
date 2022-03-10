#include <iostream>
#include <string>

using namespace std;

int arr[10000]; // 크기 N이 5<=N<=10,000인 배열, 전역변수로 배열을 선언하면 모든 값이 0으로 초기화된다.
int n; // 배열의 크기

int at(int index) {
    // 배열의 index번째에 있는 element를 return한다.
    return arr[index];
}

void add(int index, int value) {
    // 배열의 맨 끝번째부터 index + 1번째까지 자기 앞 칸의 element를 가져온다. (배열을 전체적으로 한 칸씩 밀어주는 과정)
    for (int i = n - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    // 배열의 index번째에 value를 넣는다.
    arr[index] = value;
}

void remove(int index) {
    // 배열의 index번째부터 배열의 맨 끝 - 1번째까지 자기 뒷 칸의 element를 가져온다. (배열을 전체적으로 한 칸씩 당겨주는 과정)
    for (int i = index; i <= n - 2; i++) {
        arr[i] = arr[i + 1];
    }
    // 배열의 맨 끝은, 가져올 자기 뒷 칸이 없으므로 0을 넣는다.
    arr[n - 1] = 0;
}

int set(int index, int value) {
    // 배열의 index번째에 value 값을 그냥 단순 넣어주는 작업
    arr[index] = value;
    // index번째의 element 값을 return한다.
    return arr[index];
}

void print() {
    // 배열 전체를 순회하면서 출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int find_max() {
    // 배열에 들어가는 정수 Z의 범위는 0<=Z<=10,000이므로, 초기 max값을 -1로 할당한다.
    int max = -1;
    // 배열을 순회하면서, 현재 배열의 값이 max보다 크면 max 값을 최신화해준다.
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    // max값을 return한다.
    return max;
}

int main() {
    int t; // 테스트 케이스 수

//    배열을 전역변수로 선언하지 않고 지역변수로 선언할 시 아래 코드로 배열 내 모든 값을 0으로 초기화해야 한다.
//    또, 배열을 지역변수로 선언할 시, 각 함수들은 main 바깥에 있기 때문에 함수에 배열을 전달하던지, 함수를 main문 안으로 가져와야 한다.
//    난 귀찮으니까 그냥 전역변수로 쓴다 ... 이게 편하다.
//    for (int i = 0; i < 10000; i++) {
//        arr[i] = 0;
//    }

    cin >> n >> t; // 배열의 크기와 테스트 케이스 수를 입력한다.

    // 아래 반복문을 t번 반복한다.
    while (t--) {
        string cmd; // 입력받을 명령어
        cin >> cmd; // cmd 입력
        int index; // cmd에 따라 사용될 index
        int value; // cmd에 따라 사용될 value

        // cmd에 따라 if문으로 분기처리한다.
        if (cmd == "at") {
            cin >> index;
            cout << at(index) << "\n";
        } else if (cmd == "add") {
            cin >> index >> value;
            add(index, value);
        } else if (cmd == "remove") {
            cin >> index;
            remove(index);
        } else if (cmd == "set") {
            cin >> index >> value;
            cout << set(index, value) << "\n";
        } else if (cmd == "print") {
            print();
            cout << "\n";
        } else if (cmd == "find_max") {
            cout << find_max();
            cout << "\n";
        }
    }
    return 0;
}