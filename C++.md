# C++ 문법 정리

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

## 입력 종료될때까지 받기
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

## 제곱, 루트, hypot
```
pow(base, n);
sqrt(x);
hypot(a, b); // sqrt(abs(a)^2 + abs(b)^2)
```
