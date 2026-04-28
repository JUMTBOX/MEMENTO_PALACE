
- 스택은 깊이 우선 탐색(depth-first-search)의 핵심을 이룬다.

  - `깊이 우선 탐색은 한 경로를 깊이 들어가면서 막다른 길에 도달할 때까지 탐색하는 방식이다.`

- 큐는 너비 우선 탐색(breadth-first-search)을 가능하게 한다.

  -`너비 우선 탐색은 더 깊이 파고 들어가기 전에 인접한 얕게 탐색하는 방식이다.`


**📝스택**
  
- 후입선출 (LIFO, Last In First Out)

- 새로운 원소를 스택의 맨 위에 추가하고 스택의 맨 위에서부터 원소를 제거한다.

- 형식적으로 말해 스택은 다음 두 가지 연산을 지원한다.

  - `푸시(push)`: 새로운 원소를 스택의 맨 위에 추가한다.

  - `팝(pop)`: 스택의 맨 위에서 원소를 제거하고 반환한다.

- 배열이나 연결 리스트 어느쪽으로든 스택을 구현할 수 있다.

  

```text

Stack {

  Integer: array_size

  Integer: top

  Array of values: array

}

```

  

**💡`push`**

  

- 처음에는 스택에 아무것도 없음을 나타내기 위해 top 인덱스를 -1로 설정한다.

- 새 원소를 스택에 푸시할 때, top 인덱스를 1 증가시켜서 다음 공간을 가리키게 하고, 그 인덱스에 새 값을 추가한다.

- 따라서 배열은 스택의 아래에서 위로 정렬된다.

- 고정 크기의 배열에 원소를 추가할 때는 공간이 허용하는 것보다 더 많은 원소를 추가하지 않도록 주의해야 한다.

  

```text

Push(Stack: s, Type: value):

  IF s.top == s.array_size -1:

    배열 크기를 증가시킨다.

  s.top = s.top + 1;

  s.array[s.top] = value

```

  

- 배열로 구현된 스택에 원소를 푸시하는 코드는 새 원소를 삽입할 공간이 있는지 확인한 다음, 공간이 부족하면 배열을 확장한다.

- 그 후 top 원소의 인덱스를 증가시키고, 증가시킨 새 인덱스 위치에 값을 삽입한다.

  

**💡`pop`**

  

- 스택에서 항목을 팝할 때는 다시 top 인덱스를 사용해 올바른 원소를 찾는다.

- 찾은 원소를 배열에서 제거하고 top 인덱스를 감소시킨다.

  

```text

Pop(Stack: s):

  Type: value = null

  IF s.top > -1:

    value = s.array[s.top]

    s.top = s.top - 1

  return value

```

  

- 배열에 충분한 공간이 남아있는 한 항목을 추가하거나 제거하는 데 들어가는 비용은 고정적이며, 스택에 들어 있는 원소의 개수와는 무관하다.

- 하지만 삽입 중 배열 크기를 확장할 때 추가 비용이 발생할 수 있으니 사용 사례에 맞추어 충분히 큰 배열을 미리 할당하는 편이 좋다.

  

**💡연결 리스트로 스택 구현하기**

  

- 표준 `head`포인터는 스택의 `top`포인터로 작동한다.

```text

Stack {

  LinkedListNode: head

}

```

- 연결 리스트를 사용한 구현에서는 새로운 배열 칸을 채우고 인덱스를 갱신하는 대신, 연결 리스트에서 노드를 생성하거나 제거하고, 각각의 노드 포인터를 갱신하고 스택의 top 포인터를 갱신해야한다.

- 스택에 항목을 푸시할 때는 연결 리스트 앞쪽에 항목을 추가한다.

  

```text

Push(Stack: s, Type: value):

  LinkedListNode: node = LinkedListNode(value)

  node.next = s.head

  s.head = node

```

- 마찬가지로 스택에서 항목을 팝할 때는 head 노드의 값을 반환하고, head 노드 포인터를 리스트의 다음 항목으로 이동시킨다.

  

```text

Pop(Stack: s):

  Type: value = null

  IF s.head != null:

    value = s.head.value

    s.head = s.head.next

  return value

```

- 연결 리스트는 데이터와 함께 크거나 작아질 수 있고, 더 이상 배열이 꽉 차는 것에 대해 걱정할 필요가 없으며, 배열 크기를 늘리는 추가 비용을 지불할 필요도 없다.

  

**📝큐(Queue)**

- 스택과 마찬가지로 큐도 배열과 연결 리스트로 구현할 수 있다.

- 큐는 두 연산을 지원한다.

1. 엔큐(enqueue): 큐의 뒤쪽에 새로운 항목을 추가한다.

2. 디큐(dequeue): 큐의 앞쪽에서 항목을 제거하고 반환한다.

  

**💡연결 리스트로 규 구현하기**

```text

Queue {

  LinkedListNode: front

  LinkedListNode: back

}

```

```text

Enqueue(Queue: q, Type: value):

  LinkedListNode: node = LinkedListNode(value)

  IF q.back == null:

    q.front = node

    q.back = node

  ELSE:

    q.back.next = node;

    q.back = node;  

```

```text

Dequeue(Queue: q):

  IF q.front == null:

    return null

  Type: value = q.front.value

  q.front = q.front.next

  IF q.front == null:

    q.back = null

  return value  

```

  

**📝순서의 중요성**

- 원소를 삽입하거나 제거하는 순서는 알고리즘의 동작에 놀라운 영향을 미칠 수 있다.

  

**💡깊이 우선 탐색(DFS)**

- 깊이 우선 탐색은 계속해서 더 깊이 탐색하면서 막다른 골목에 도달할 때까지 한 가지 경로를 진행한다.

- 막다른 골목에 도달하면 마지막으로 방문했던 분기로 돌아가 다음 가능성을 확인한다.

- 이 방식은 스택을 사용해 앞으로 탐색해야 할 목록을 유지하며, 다음으로 시도할 대상으로 항상 최근에 삽입한 가능성을 가장 먼저 선택한다.

  

**💡너비 우선 탐색(BFS)**

- 깊이 우선 탐색과 유사한 방식으로 주제를 탐색하지만, 큐를 사용해 미래의 가능성을 저장한다.

- 각 단계에서 탐색은 가장 오래 기다린 가능성을 탐색하며, 더 깊은 단계를 탐색하기 전에 같은 깊이의 여러 다른 방향으로 뻗어나간다.

prev : [[Ch3. 동적 자료구조]]
next : [[Ch5. 이진 탐색 트리]]
