# C++ 문법 정리

## 입출력
### 파일 내용 표준 입력으로 읽기

```
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>

freopen("input.txt", "r", stdin);
```

### 띄어쓰기 있는 2차원 배열 읽기
```
for (int i = 0; i<r; i++)
    for (int j = 0; j<c; j++)
        // 개행문자 때문에 한칸 띄기
        scanf(" %d, &arr[i][j]); 
```

### 띄어쓰기 없는 2차원 배열 읽기
```
for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; j < m; j++) {
        map[i][j] = str[j] - '0';
    }
}

// C 에서는 scanf("%1d", &arr[i][j]);
```

### 입력 종료될때까지 받기
```
while(true){
    cin.getline(c, 31);
    if (cin.eof()) break;
}
```
```
while(cin >> n){
    if(cin.eof()) break;
}
```

## 동적 할당
```
int* arr = new int[n]()
```

## 초기화
```
fill(arr, arr+n, -1);
```
```
#import <cstring>
memset(arr, -1, sizeof(arr));
```

## 구조체
```
struct Edge{
    int u, v, w;
    bool operator<(const Edge& E) { return w < E.w;}
}

Edge e[100];

e[0] = {u-1, v-1, w};

sort(e, e+100);
```
w 가 작은 순으로 정렬


## 제곱, 루트, hypot
```
pow(base, n);
sqrt(x);
hypot(a, b); // sqrt(abs(a)^2 + abs(b)^2)
```

## 최소, 최댓값
```
#include <limits.h>

INT_MIN, INT_MAX
```