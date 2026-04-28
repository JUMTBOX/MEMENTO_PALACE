**📝배열**

**💡삽입 정렬**

- 배열의 일부를 정렬하고, 이 범위를 전체 배열이 정렬될 때까지 확장한다.

- 인덱스 i에 있는 원소를 선택하고 정렬되어 있는 앞부분에서 이 원소의 올바른 위치를 찾아낸 뒤 나머지 원소를 뒤로 이동시켜서 선택한 원소가 들어갈 공간을 만든 후 삽입한다.

- 처음에는 첫 번째 원소를 초기 정렬된 접두사로 선언하고 `i = 1`부터 반복을 시작할 수 있다.  

```text

InsertionSort(array: A):

    Integer: N = length(A)

    Integer: i = 1

    WHILE i < N:
        Type: current = A[i]

        Integer: j = i - 1;

        WHILE j >= 0 AND A[j] > current:

            A[j + 1] = A[j]

            i = j - 1

        A[j + 1] = current

        i = i + 1
```

```javascript

/** @param {number[]} A */
function insertionSort(A) {
  const N = A.length;
  let i = 1;

  while (i < N) {

    let current = A[i];

    let j = i - 1;

    while (j >= 0 && A[j] > current) {
      A[j + 1] = A[j];
      
      i = j - 1;
    }
 
    A[j + 1] = current;

    i = i + 1;
  }
}
```

- 바깥쪽 루프는 최초의 정렬되지 않은 원소인 인덱스 i가 1인 원소부터 시작하고 정렬되지 않은 범위에 있는 각 값을 반복한다.
- `(1)` 안쪽 루프는 인덱스 j를 사용해 정렬된 접두사의 원소를 맨 뒤에서부터 하나씩 반복한다.
- `(2)` 반복 각 단계에서 현재 값과 정렬된 접두사 안에 있는 인덱스 j의 값을 비교해 확인한다.
- j에 있는 원소가 더 크면 두 값의 순서가 잘못됐으므로 교환해야 한다.
- 내부 루프는 현재 값을 배열의 맨 앞에 밀어넣거나 현재 값보다 이전 값이 더 작을 때까지만 계속 진행한다.
- 이제 내부 루프의 끝에서 현재 값을 올바른 위치에 쓰기만 하면 된다.
- 바깥쪽 루프는 다음 정렬되지 않은 값으로 진행한다.

**삽입 정렬의 시간 복잡도: O(N^2)**

**📝문자열**

- 한 번의 연산으로 직접 비교할 수 있는 정수와 달리, 문자열은 각 문자를 반복하면서 비교해야 한다.
- `문자열의 동등성 검사 알고리즘`: 먼저 문자열의 길이를 비교, 길이가 같다면 알고리즘은 각 위치를 순회하며 해당 위치에 있는 두 문자를 비교한다.
  
```text

StringEquals(String: str1, String: str2 ):

    IF length(str1) != length(str2):
        return False
  
    Integer: N = length(str1)

    Integer: i = 0
  
    WHILE i < N AND str1[i] == str2[i]:
        i = i + 1

    return i == N

```

  

```javascript

/**

 * @param {String} str1

 * @param {String} str2

 */
function stringEquals(str1, str2) {
  if (str1.length !== str2.length) return false;

  const N = str1.length;
  let i = 0;

  while (i < N && str1[i] === str2[i]) {
    i = i + 1;
  }
  
  return i === N;
}

```

next:  [[Ch2. 이진 탐색]]