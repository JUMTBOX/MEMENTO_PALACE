
- 이진 탐색 알고리즘의 개념을 기반으로 동적 자료 구조를 생성한다.

- 여기서 핵심 단어는 `동적`이다. 정렬된 배열과 달리, 이진 탐색 트리는 효율적인 원소 추가와 삭제 뿐 아니라 탐색도 지원하기 때문에, 이진 탐색의 알고리즘적 효율성과 동적 자료 구조의 적응성을 완벽하게 결합해준다.
  

**📝이진 탐색 트리 구조**

- 트리는 노드의 분기 사슬로 구성된 계층적인 자료 구조다.

- 트리 구조는 연결 리스트를 자연스럽게 확장한 것인데, 트리 노드는 `서로소(disjoint)`인 하부 리스트를 가지는 2가지 next 노드를 허용한다는 점에서 연결 리스트와 차이가 있다.

- 노드는 값을 포함하며, 트리의 하위 노드를 가리키는 포인터를 최대 두 개 가진다.

- 자식이 하나 이상 있는 노드를 `내부(internal, 또는 비단말/비말단/비종단)노드`, 어떤 자식도 없는 노드를 `단말(terminal, 또는 말단/종단)노드` 또는 `리프(leaf)노드`라고 부른다.

- 연결 리스트와 마찬가지로 탐색 트리의 개별 노드는 컴퓨터 메모리 전체에 분산될 수 있다. 각 노드는 포인터의 강력함과 유연성을 통해 자기 자식 및 부모에게만 연결 되어 있다.


```text

TreeNode {

  Type: value

  TreeNode: left

  TreeNode: right

  TreeNode: parent

}

```

- 이진 탐색 트리의 힘은 값이 트리 안에서 조직화되는 방법으로부터 기인한다. 이진 탐색 트리 속성을 다음과 같이 말할 수 있다. <br/>

  `모든 노드 N에 대해, N의 왼쪽 하위 트리에 속한 모든 노드의 값은 N의 값보다 작으며, N의 오른쪽 하위 트리에 속한 모든 노드의 값은 N의 값보다 크다.`

- 앞에서 본 정의는 이진 탐색 트리가 유일한 값들만 포함하도록 암시적으로 제한한다. 이진 탐색 트리 속성을 변경하면 중복 값을 허용하는 이진 탐색 트리를 정의할 수도 있다.

  

**📝이진 탐색 트리에서 탐색하기**

- 루트 노드부터 아래로 내려가면서 값을 탐색한다.

- 각 단계에서는 현재 노드의 값과 목푯값을 비교해 왼쪽 하위 트리나 오른쪽 하위 트리 중 어느 쪽을 탐색할지 결정한다.

- 목푯값이 현재 값보다 작으면 왼쪽으로, 현재 값보다 크다면 오른쪽으로 탐색을 진행한다.

- 탐색은 목푯값을 발견하거나 탐색해야 할 방향에 더 이상 자식이 없는 노드에 도달하면 종료된다. 후자의 경우, 목푯값이 트리에 없다는 점을 명확히 말할 수 있다.

  

**💡반복적 탐색과 재귀적 탐색**

- 재귀 예제

```text

FindValue(TreeNode:current, Type:target):

  IF current == null:

    return null

  IF current.value == target:

    return current

  IF target < current.value AND current.left != null:

    return FindValue(current.left, target)

  IF target > current.value AND current.right != null:

    return FindValue(current.right, target)

  return null        

```

- 반복 예제

```text

FindValueItr(TreeNode:root, Type:target):

  TreeNode: current = root;

  WHILE current != null AND current.value != target:

    IF target < current.value:

      current = current.left

    ELSE:

      current = current.right

  return current    

```

**💡트리 탐색과 정렬된 탐색 비교**

- 이진 탐색은 데이터 크기에 로그 스케일로 비례한 시간이 걸린다. `O(logn)`

- 왜 귀찮게 데이터를 정렬된 배열 대신 트리에 넣어야 하며, 포인터에 따른 불필요한 복잡성과 부가 비용을 감수 해야하는가?

<br>`이진 탐색 트리 등 동적 자료 구조의 장점은 데이터가 변경되는 경우에 드러난다. 정렬된 배열에서는 데이터를 추가하거나 삭제할 때마다 매번 배열을 갱신해야 하므로 비용이 많이 들 수 있다.`

<br> `반면, 이진 탐색 트리는 데이터 자체가 변경되어도 탐색 가능한 구조가 유지된다.`

  

**📝이진 탐색 트리 변경하기**

- 이진 탐색 트리를 사용하거나 변경할 때는 항상 루트 노드에 특별한 관심을 가져야 한다.

- `트리에서 노드를 탐색할 때는 항상 루트 노드에서 시작한다.`


```text

FindTreeNode(BinarySearchTree: tree, Type:target):

  IF tree.root == null:

    return null

  return FindValue(tree.root, target);  

```


**💡노드 삽입하기**

- 이진 탐색 트리에 값을 삽입하는 것은 탐색과 기본적으로 같은 알고리즘을 사용한다.

- 탐색과 삽입 알고리즘의 주된 차이는, 삽입 알고리즘은 막다른 골목에 도달한 후 현재 노드의 자식으로 새 노드를 추가한다는 것이다.

- 새 값이 현재 노드의 값보다 작은 경우에는 왼쪽,그렇지 않으면 오른쪽 자식으로 새 노드를 추가한다.

- `중복 값을 허용하는 경우에는 막다른 골목에 도달할 때까지 계속 진행한 다음에 새 값을 트리에 삽입한다. 중복 값을 허용하지 않는 경우에는 새 값과 일치하는 노드에 저장된 데이터를 대체하거나 추가 정보를 저장할 수 있다.

예를 들어, 해당 값이 트리에 추가된 횟수를 나타내는 카운터를 추가 정보로 저장할 수 있다.`

- 이 책에서는 중복 데이터를 덮어쓰는 경우에만 초점을 맞춘다.

```text

InsertTreeNode(BinarySearchTree: tree, Type: new_value):

  IF tree.root == null:

    tree.root = TreeNode(new_value)

  ELSE:

    InsertNode(tree.root, new_value)

```

  
```text

InsertNode(TreeNode:current, Type:new_value):

  IF new_value == current.value:

    // 노드를 필요에 맞게 변경한다.

    return

  IF new_value < current.value:

    IF current.left != null:

      InsertNode(current.left, new_value)

    ELSE:

      current.left = TreeNode(new_value)

      current.left.parent = current

  ELSE:

    IF current.right != null:

      InsertNode(current.right, new_value)

    ELSE:

      current.right = TreeNode(new_value)

      current.right.parent = current          

```

  

**💡노드 제거하기**

- 노드를 제거할 때는 세 가지 경우를 고려해야 한다.

  - 자식이 없는 리프 노드를 제거하는 경우

  - 자식이 하나 뿐인 내부 노드를 제거하는 경우

  - 자식이 둘인 내부 노드를 제거하는 경우

- 리프 노드를 제거할 때는 해당 노드를 제거하고 부모의 (제거된 노드를 가리키는) 자식 포인터를 null로 갱신해서 해당 노드가 더 이상 존재하지 않음을 표시해야 한다.

- 제거 대상 노드가 자식을 하나만 가진 경우, 해당 자식을 제거된 노드의 부모노드의 자식으로 승격시키고 제거 대상 노드를 제거한다.

- 승격될 노드가 이미 부모의 하위 트리에 속해 있었기 때문에 해당 노드의 모든 하위 항목은 이진 탐색 트리의 속성을 계속 유지한다.

- 자식 노드가 둘인 내부 노드를 제거하려면 복잡도가 상당히 높아진다. 임의로 자식 노드 하나를 승격시키면 반대쪽 자식 노드는 더 이상 포인터 사슬을 통해 루트 노드와 연결되지 않으므로 이를 방지해야 한다.

- 반드시 제거할 노드를 제외한 나머지 트리의 무결성을 유지하고 계속 이진 탐색 트리 속성을 따르게 보장해야 한다.

- ```text
  자식이 둘인 내부 노드를 제거할 때는 교환하여도 이진 탐색 트리 속성이 유지될 수 있는 다른 노드와 제거 대상 노드를 교환한다.

  이를 위해서는 제거할 노드의 '후속자(successor)'를 찾아야 한다. 후속자는 정렬된 순서로 노드를 순회할 때 제거할 노드 바로 다음에 만나게 될 노드다.

  후속자의 값을 제거된 노드 위치에 넣는다. 이때 후속자 노드도 자식 노드를 가질 수 있다. 따라서 이진 트리의 포인터를 깨뜨리지 않고 후속자를 제거하기 위해

  여기서 설명하는 제거 절차를 후속자 노드를 대상으로 다시 적용 해야 한다. 후속자를 찾아 후속자를 가리키는 포인터를 저장한 다음, 후속자를 트리에서 제거한다.
  ```

- ```text
   제거를 수행하려면 노드의 후속자를 효율적으로 찾을 수 있어야 한다. 여기서 한 가지 중요한 장점이 있다.

  여기서는 제거하려는 노드에 자식이 2개인 경우만 고려하기 때문에 후속자를 항상 노드의 오른쪽 하위 트리에서 찾을 수 있다는 점이다.

  구체적으로 후속자는 오른쪽 하위 트리의 최소(또는 가장 왼쪽) 노드다. 게다가 이 후속자 노드는 자식을 기껏해야 하나(있다면 오른쪽)만 가진다는 점이 보장된다.

  후속자 후보가 왼쪽에 자식을 가지고 있다면 그 왼쪽 자식(또는 자식의 왼쪽 하위 트리를 계속 따라 내려간 가장 작은 노드)이 진짜 후속자가 된다.
  ```







```text

RemoveTreeNode(BinarySearchTree: tree, TreeNode: node):

  IF tree.root == null OR node == null:

    return

  # 경우 A: 리프 노드 제거

  IF node.left == null AND node.right == null:

    IF node.parent == null:

      tree.root = null

    ELSE IF node.parent.left == node:

      node.parent.left = null

    ELSE:

      node.parent.right = null

    return

  # 경우 B: 자식이 하나인 노드 제거

  IF node.left == null OR node.right == null

    TreeNode: child = node.left

    IF node.left == null:

      child = node.right

    child.parent = node.parent

    IF node.parent == null:

      tree.root = child

    ELSE IF node.parent.left == node:

      node.parent.left = child

    ELSE:

      node.parent.right = child

    return  

  # 경우 C: 자식이 둘인 노드 제거          

```


**📝균형이 맞지 않는 트리의 위험성**

  

**📝이진 탐색 트리 대량 구축**

  

**📝중요성**



prev : [[Ch4. 스택과 큐]] 
next : 