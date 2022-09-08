# Professional 양성과정 - 1. Ad Hoc Algorithms



## Anagram 쌍의 개수 찾기

> Anagram: 두 단어가 같은 글자들로 구성되어 순서가 다를 수 있는 경우

* n 개의 단어가 주어져 있고, 단어들의 길이의 합은 W이다. 단어들 중에 anagram 이 되는 쌍의 개수를 계산하라

1. 두 단어가 anagram 인지 확인한다.
2. 여러 단어 사이에서 anagram 의 개수를  센다.

두 단어가 anagram 인지 O(x+y) 시간에 알 수 있다면, 전체 단어에 대해 O(n^2) 번의 비교를 함으로써 O(Wn) 시간 안에 문제를 풀 수 있다.  이때 O(Wn^2) 가 아니라 O(Wn) 인 이유는, 각 단어가 O(x_i N)  번 비교가 되고, 길이가 W 인 모든 단어에 대해 합했을 때 O(Wn) 번이 되기 때문이다. 이제 O(x+y) 시간에 두 단어 비교가 가능해야 한다. 각 단어의 글자를 정렬하고, 정렬된 단어들을 정렬해서 인접한 단어들이 같은지 비교하면 된다. 

1) 두 단어의 글자를 정렬할 때, 보통 정렬이 nlogn 이기 때문에 O(xlogx + ylogy) 가 아니라 O(x+y) 시간에 정렬을 하기 위해서는, **counting sort** 를 사용해야 한다. Counting sort 를 사용할 수 있는 이유는, 글자가 26가지 밖에 없기 때문에 각 글자의 개수를 세서 비교할 수 있다. 모든 단어에 대해 정렬을 한다면 O(Wn) 시간에 끝난다. 

2) 정렬된 단어들을 다시 정렬하기 위해서는 **radix sort** 를 사용한다. Radix sort 는 첫번째 글자를 기준으로 sort 하고, 두번째 글자를 기준으로 sort 하여 n 번째 글자까지 비교를 한다. 문자열을 복사하여 옮길 때 시간이 걸리므로, 구현할 때에는 포인터를 사용한다. 이로써 전체 글자 수에 비례하는 시간에 단어들을 정렬할 수 있다.  만약 단어들을 직접 정렬하는 것이 아닌, A 과정에서 생성된 counting sort 배열을 정렬한다면 radix sort 과정이 O(W) 이 아닌 O(26nlogn) 시간 안에 끝난다. W 가 nlogn 보다 클 경우에 빠르고, 그렇지 않더라도 비슷한 속도를 낼 수 있다.

참고로, N 개의 단어들 사이에서 anagram 쌍을 찾을 때, 그 쌍의 개수가 N 이상인 N^2일 수도 있다. N 개의 단어 전체가 anagram 일 경우에 N * (N-1) / 2 가 조합의 개수이기 때문이다. 



```c++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    const int n = 17;
    const int max_word_length = 10;
    vector<string> words =
    {
        "CARS", "REPAID", "DUES", "NOSE", "SIGNED", "LANE", "PAIRED", "ARCS",
        "GRAB", "USED", "ONES", "BRAG", "SUED", "LEAN", "SCAR", "DESIGN", "ANAGRAM"
    };

    // counting sort - O(W)
    int count[n][26] = { 0, };
    pair<int, int*> arr[n]; // 단어 id 와 count 배열의 시작 주소 저장
    for (int id = 0; id < n; id++) {
        for (char c : words[id]) {
            int& cnt = count[id][c-'A'];
            cnt = (cnt > 0) ? cnt + 1 : 1;
        }
        arr[id].first = id;
        arr[id].second = count[id];
    }


    // radix sort - O(26nlogn)
    queue<pair<int, int*>> q[max_word_length];
    for (int alph = 0; alph < 26; alph++) { // 'A' ~ 'Z' 기준 정렬
        for (int pos = 0; pos < n; pos++) { // 각 단어별로
            int id = arr[pos].first;
            int k = arr[pos].second[alph]; // 해당 글자가 몇개 있는지
            q[k].push({ id, arr[pos].second });
        }

        int pos = 0;
        for (int k = 0; k < max_word_length; k++) {
            while (!q[k].empty()) {
                int id = q[k].front().first;
                int* ptr = q[k].front().second;
                arr[pos] = { id, ptr }; // 덮어씌우기
                q[k].pop();
                pos++;
            }
        }
    }


    // calculate - O(Wn)
    int parent[n]; fill(parent, parent + n, -1);
    for (int i = 0; i < n; i++) {
        int id1 = arr[i].first;
        if (parent[id1] != -1) continue; // 이미 어떤 단어의 anagram 일 경우
        parent[id1] = id1;
        for (int j = i+1; j < n; j++) {
            int id2 = arr[j].first;
            if (parent[id2] != -1) continue;
            bool is_anagram = true;
            for (int k = 0; k < 26; k++) {
                if (arr[i].second[k] != arr[j].second[k]) {
                    is_anagram = false;
                    break;
                }
            }

            if (is_anagram) {
                parent[id2] = id1;
            }
        }
    }

    vector<int> result[n];
    for (int i = 0; i < n; i++) {
        int p = parent[i];
        while (p != parent[p]) {
            p = parent[p];
        }
        result[p].push_back(i);
    }


    // print - anagram
    for (int i = 0; i < n; i++) {
        if (result[i].size() > 1) {
            for (int id : result[i]) {
                cout << words[id] << " ";
            }
            cout << endl;
        }
    }
}
```





## 정렬된 두 배열에서 특정한 합을 만드는 두 수 찾기

* 자연수들이 정렬되어 저장된 두 배열 A, B 가 주어지고 목표값 x 가 주어졌을 때 두 배열에서 각각 하나의 자연수를 골라 더해서 x 를 만드는 쌍을 출력하라. 
  * 단, 같은 값은 없다. (만약 같은 값이 있다면 O(n^2) )

1. 슬라이딩 알고리즘 : A 는 왼쪽, B 는 오른쪽 끝에서 시작
   1. 현재 위치의 합이 목표보다 작으면 A 포인터를 오른쪽으로
   2. 목표보다 크면 B 포인터를 왼쪽으로

위와 같은 방법은 O(n) 의 시간 복잡도를 가지지만, O(n^2) 개의 모든 가능한 경우를 검사하는 것은 아니다. 따라서 빠트리는 경우가 없다는 것을 증명해야 한다. 귀류법을 사용해, 만약 A[s] + B[t] = X 가 유일한 답이고, 이 답을 못찾았다고 가정하자. 그렇다면 i = s, j < t 인 상황이 있어야만 한다. 만약 j > t 라면 A[i] + B[j] > X 이기 때문에 프로그램의 논리상 j 인덱스를 줄이게 되고, 유일한 답을 찾게 되기 때문이다. 따라서 i < s, j = t 인 상황에서 i 인덱스를 증가시키는 동시에 j 를 감소해야 하는데, 논리상 불가능하다. 그러므로 답을 못찾는 경우는 없다.





## 정렬된 두 배열을 merge 했을 때 k 번째 값 찾기

> Merge: 두 배열의 원소들을 모아서 하나의 정렬된 배열을 만드는 것

* 정렬된 배열 A, B 가 주어지고, 두 배열을 merge 해서 C 를 만들었을 때 C[k] 에 어떤 값이 올 것인가?
  * 단, 같은 값은 없다.

Merge 를 시작했다고 가정하고, k 번째가 이동하기 직전의 순간을 보자. A 에서 a 까지, B 에서 b 까지 merge 를 했을 때, a 와 b 중 작은 값이 k 번째 값이다. 

