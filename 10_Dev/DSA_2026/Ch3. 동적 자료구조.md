**💡정적 배열**

- 배열 2배 늘리기

- 요소가 가득 차면 길이가 2배인 새로운 배열 (`기존의 2배 크기의 메모리를 새로 할당 받은..`)을 만들어 기존 배열의 원소를 복사

```text

ArrayDouble(Array: old_array):

    Integer: length = old_array의 길이

    Array: new_array = 크키가 length * 2인 새로운 빈 배열

    Integer : j = 0

    WHILE j < length

        new_array[i] = old_array[i]

        i = j + 1

    return new_array    

```

  

```javascript

/**

 * @param {any[]} old_array

 * */

function arrayDouble(old_array) {

    let len = old_array.length;

    let new_array = new Array(len * 2).fill(null);

    let j = 0;

    while(j < len) {

        new_array[i] = old_array[j];

        i = j + 1;

    }

    return new_array;

}

```

- 생성시에 크기와 메모리 레이아웃이 고정되는 한계 때문에 삽입과 삭제 모두 불~편..

  

**💡연결 리스트**

- 연결 리스트는 포인터로 연결된 노드의 사슬로 이루어진다.

- 각 원소를 저장하기 위해 값과 포인터를 포함하므로, 같은 항목을 저장할 때 배열보다 더 많은 메모리를 사용한다.

  <br/> 배열이 `K x N` 이라면 연결 리스트는 `K x (N + M)`

```text

LinkedListNode {

    Type: value,

    LinkedListNode: next

}

```

- 일부 서적에서는 연결 리스트를 잘 정돈된 구조로 나타내곤 하는데, 실제로는 프로그램의 메모리 전체에 리스트 노드가 흩어져 있을 수 있다.

- 리스트 전체를 하나의 연속적인 메모리 블록에 유지해야만 한다는 제약이 없는 것이 포인터와 동적 자료구조의 진정한 장점이다.

  

- 프로그램은 일반적으로 연결 리스트의 시작점이자 머리(head)인 하나의 포인터를 유지하면서 연결 리스트를 저장한다.

- 그 후 프로그램은 머리에서 시작해 포인터를 통해 노드를 반복함으로써 리스트의 모든 원소에 접근할 수 있다.

```typescript

class LinkedListNode {

  value;

  next;

}

  

function linkedListLookUp(head:LinkedListNode, element_number:number): LinkedListNode | null {

  let current = head;

  let count = 0;

  while(count < element_number && current != null) {

    current = current.next;

    count += 1;

  }

  return current;

}

```

- 연결 리스트는 배열보다 계산 부가 비용이 더 높다. 배열의 원소에 접근할 때 우리는 오프셋을 한 번에 계산해서 메모리에서 올바른 주소를 찾을 수 있다.

- 어떤 인덱스를 선택하더라도 배열 접근은 한 번의 산술 계산과 한 번의 메모리 조회만으로 끝난다.

- 연결 리스트는 관심 있는 원소에 도달할 때까지 맨 앞에서부터 반복해야만 한다.

- 연결 리스트의 경우 원소 접근의 부가 비용을 증가시키는 대신 전체 자료 구조의 유연성이 상당히 증가한다.

  

**💡💡연결 리스트에 대한 연산**

  

**💡연결 리스트에 원소 삽입하기**

- 배열에 새 원소를 삽입하려면 더 큰 새 메모리 블록을 할당하고 원래 배열의 모든 값을 새 블록으로 복사해야 할 수도 있다.

- 메모리 블록을 새로 할당하지 않더라도 (앞쪽이나 중간에서의)삽입을 위해서는 배열을 순회하면서 원소를 하나씩 뒤로 이동시켜야 한다.

- 새 노드의 위치를 알고 있으면 이전 노드의 next 포인터가 새 노드를 가리키도록 갱신하고 새 노드의 next 포인터를 올바른 노드로 지정하면 된다.


```typescript

class LinkedListNode {

  value;

  next;

}

  

function linkedListInsertAfter (previous: LinkedListNode, new_node: LinkedListNode) {

  new_node.next = previous.next;

  previous.next = new_node;

}

```

  
```text

  

LinkedListInsert(LinkedListNode: head, Integer: index, Type:value):

  # 새 머리 노드를 삽입하는 특별한 경우

  IF index == 0:

    LinkedListNode: new_head = LinkedListNode(value)

    new_head.next = head

    return new_head

  # (2)  

  LinkedListNode: current = head  

  LinkedListNode: previous = null

  Integer: count = 0

  WHILE count < index AND current != null:

    previous = current

    current = current.next

    count = count + 1

  # 필요한 인덱스에 도달하기 전에 리스트 끝에 도달했는지 검사한다.

  IF count < index:

    인덱스가 잘못됐다는 오류를 발생시킨다.

  LinkedListNode: new_node = LinkedListNode(value)

  new_node.next = previous.next

  previous.next = new_node

  return head    

```

**💡연결 리스트에 원소 제거하기**

- 연결 리스트의 어디에서든 원소를 제거하기 위해서는 해당 노드를 제거하고 제거된 노드의 바로 앞 노드의 포인터를 조정하면 된다.

  
```text

LinkedListDelete(LinkedListNode: head, Integer: index):

  // #(1)

  IF head == null:

    return null

  // #(2)

  IF index == 0:

    new_head = head.next          

    head.next = null

    return new_head

  LinkedListNode: current = head

  LinkedListNode: previous = null

  Integer: count = 0

  WHILE count < index AND current != null:  // #(3)

    previous = current

    current = current.next

    count = count + 1

  IF current != null:                       // #(4)

    previous.next = current.next            // #(5)

    current.next = null                     // #(6)

  ELSE:

    인덱스가 잘못되었다는 오류를 발생시킨다.

  return head                               // #(7)

```

- `(1)`: 리스트가 비어 있으면 제거할 것이 없으므로 null 값을 반환해서 리스트가 여전히 비어 있음을 나타낸다.

- `(2)`: 첫 번째 노드를 제거하는지 확인한 후, 첫 번째 노드를 제거하는 경우라면 리스트의 첫 번째 노드를 제거하고 새 머리 노드의 주소를 반환한다.

- `(3),(4),(5),(6)`: `lookUp`과정을 통해 찾은 `previous`노드의 next를 현재 노드의 next로 설정해서 제거할 노드를 리스트에서 제거한다.

  - WHILE 루프가 목록의 끝을 넘어가서 `current`가 null이라면 제거할 노드가 없으므로 오류를 던진다.

  - 함수는 또 제거된 노드의 next 포인터를 null로 설정해서 일관성(더 이상 리스트의 다음 노드가 없음)을 보장하고, 자동 메모리 관리를 사용하는 프로그래밍 언어에서 더 이상 사용되지 않는 메모리가 올바로 해제될 수 있게 한다.

- `(7)`: 함수는 리스트 머리 노드의 주소를 반환하면서 완료된다.

- 제거할 노드의 값을 안다면 루프 조건을 다음과 같이 갱신해서 특정 값을 가진 최초의 노드를 제거할 수 있다.

- `WHILE current != null AND current.value != value:`

  
**💡이중 연결 리스트**

- 이중 연결 리스트는 다음과 이전 항목을 가리키는 포인터를 모두 포함한다

```text

DoublyLinkedListNode {

  Type: Value

  DoublyLinkedListNode: next

  DoublyLinkedListNode: previous

}

```

- 임의의 노드를 가리키는 포인터가 주어졌을 때, 그 노드의 이전 노드에 접근하고 싶다면 단일 연결 리스트에서는 처음부터 목록을 순회해야만 하지만 이중 연결 리스트에서는 임의의 노드로부터 직접 이전 노드에 접근할 수 있다.

prev : [[Ch2. 이진 탐색]]
next : [[Ch4. 스택과 큐]]
