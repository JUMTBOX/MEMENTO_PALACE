**💡선형 스캔**
  
```text

LinearScan(Array: A, Integer: target):

    Integer: i = 0

    WHILE i < length(A):

        IF A[i] == target:

            return i

        i = i + 1

    return -1

```

  

```javascript

/**

 * @param {number[]} A

 * @param {number} target

 */

function linearScan(A, target) {

  let i = 0;

  while (i < A.length) {

    if (A[i] === target) return i;

    i = i + 1;

  }

  return -1;

}

```

  

**💡이진 탐색 알고리즘**

- `정렬된`리스트에서 목표 값을 찾는 알고리즘으로, 정렬된 데이터에서만 동작한다.

1. `리스트를 반으로 분할하고 목푯값이 어느 쪽 절반에 속하는지 결정한다.`

2. `목푯값이 포함되지 않는 절반을 버리고 나머지 절반을 가지고 같은 과정을 반복하여 마지막 값이 남을 때까지 수행한다.`


- 이진 탐색의 매 반복은 현재 탐색 구간의 `중간 지점 값(중앙값)`을 선택하며 시작된다.

- `IndexMid = Floor((IndexHigh + IndexLow) / 2 )`

- 그런 다음 중간 위치의 값(`A[IndexMid]`)과 목표 값을 비교한다.

- 중앙값이 목표 값 보다 작을 경우 목표 값은 중앙 인덱스 보다 뒤에 위치 해야 한다.

- 이로 인해 `IndexLow = IndexMid + 1`로 탐색 공간을 절반으로 줄일 수 있다.

  

**구현**

```text

BinarySearch(Array: A, Integer: target):

    Integer: IndexHigh = length(A) - 1;

    Integer: IndexLow = 0;

  

    WHILE IndexLow <= IndexHigh:

        Integer: IndexMid = Floor((IndexHigh + IndexLow) / 2)

  

        IF A[IndexMid] == target:

            return IndexMid

        IF A[IndexMid] < target:

            IndexLow = IndexMid + 1

        ELSE:

            IndexHigh = IndexMid - 1

  

    return -1

```


```javascript

/**

 * @param {number[]} A

 * @param {number} target

 */

function binarySearch(A, target) {

  let IndexHigh = A.length - 1;

  let IndexLow = 0;

  

  while (IndexLow < IndexHigh) {

    let IndexMid = Math.floor((IndexLow + IndexHigh) / 2);

    if (A[IndexMid] === target) {

      return IndexMid;

    } else if (A[IndexMid] < target) {

      IndexLow = IndexMid + 1;

    } else {

      IndexHigh = IndexMid - 1;

    }

  }

  return -1;

}

```

prev :  [[Ch1.메모리 안 구조]]
next : 