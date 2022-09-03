# C++ 팁


## #include <vector>

#### 초기화

```c++
// 사이즈 설정
vector<int> v(10);

// 크기 10의 벡터에 1로 초기화
vector<int> v(10,1); 

// 사이즈 재설정 및 초기화
v.resize(20, 0);
```



#### 원소 접근

```c++
// idx 번째 원소 참조
v.at(idx);

// 첫번째 원소 참조
v.front();

// 마지막 원소 참조
v.back();

// 첫번째 원소의 위치 가리킴
v.begin();

// 마지막 원소 다음의 위치 가리킴
v.end();
```



#### 삽입, 삭제

```c++
// 인덱스 1 에 'a' 삽입
v.insert(1, 'a')

// 삭제하고 싶은 원소의 위치 삭제
auto iter = v.begin();
v.erase(iter);
```



#### iterator

```c++
for (auto iter = v.begin(); iter < v.end() ; iter++ ) {
	cout << *iter << endl;
}
```



#### 벡터가 빌 때까지 끝의 원소 출력 (stack)

```c++
while (!v.empty()) {
	cout << v.back() << endl;
	v.pop_back();
}
```





## #include <algorithm>

#### sort()

```c++
// 디폴트는 less, 오름차순
sort(s.begin(), s.end(), greater<int>());

struct{
    bool operator()(int a, int b) const { 
        // a, b 순서로 들어왔을 때 swap 을 해야할지 여부 반환
        // 해당 코드에서 a 가 더 작으면 swap 을 하므로,
        // 
        return a < b;
    }
} comp;
sort(s.begin(), s.end(), comp);
```





#### find()

```c++
vector<int> v;

auto it = find(v.begin(), v.end(), num);
if (it == v.end()) 
    printf("not found");
else
    printf("found at %d", it - v.begin());
```

#### find_if()

```c++
vector<int> v;

auto it = find_if(v.begin(), v.end(), isOdd);
if (it != v.end()) {
	printf("%d", *id);
	it = find_if(it+1, v.end(), isOdd);
}
```





## #include <string>



## 여러 값을 한번에 묶기

#### tuple

```c++
#include <tuple>

typedef tuple<bool, int, string> Info;

vector<Info> v;
v.push_back({ false,10,"hello" });
v.push_back(make_tuple(true, 30, "world"));

for (int i = 0; i < v.size(); i++) {
	printf("%d %d %s\n", get<0>(v[i]), get<1>(v[i]), get<2>(v[i]).c_str());
}
```



## 알고리즘

###  이진 탐색

```c++
// 하한선
int lower_bound(const vector<int>& vec, int value) {
	int lo = 0, hi = vec.size();

	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (vec[mid] < value) // 찾는 값이 현재 값보다 클때
			lo = mid + 1; // lo 를 mid 다음으로 옮김
		else:
        	hi = mid
	}
	return lo;
}
```



```c++
// 상한선
int upper_bound(const vector<int>& vec, int value) {
	int lo = 0, hi = vec.size();

	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (vec[mid] <= value) // 찾는 값이 현재 값보다 크거나 같을 때
			lo = mid + 1; // lo 를 mid 다음으로 옮김 (끝내거나, 더 찾거나)
		else
			hi = mid
	}
	return lo;
}
```



