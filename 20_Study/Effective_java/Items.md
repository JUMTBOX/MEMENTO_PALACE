## Effective Java 

### 객체 생성과 파괴

**Item 2. `생성자에 매개변수가 많다면 빌더를 고려하라`**

<a href='./builder_pattern.md'>예제</a>

**Item 4. `인스턴스화를 막고싶다면 private 생성자를 사용하라`**

```java
public class UtilityClass {
  
  private UtilityClass () {
    throw new AssertionError();
  }
}
```

**Item 6. `불필요한 객체 생성을 피하라`**
- 생성자는 호출할 때마다 새로운 객체를 만들지만, 팩토리 메서드는 그렇지 않다.
- `Boolean(String)` vs `Boolean.valueOf(String)`
- 반복문 내부에서는 `String#matches(...)`를 사용하지 말자 feat.`Pattern`
```text
Pattern 문서에서는 Pattern을 “정규표현식의 컴파일된 표현”이라고 설명합니다.
정규식 문자열은 먼저 Pattern 인스턴스로 컴파일되어야 하고, 
그 결과로 만들어진 Pattern에서 Matcher를 생성해 입력 문자열과 매칭합니다.
```

### 모든 객체의 공통 메서드

**Item 10. `equals는 일반 규약을 지켜 재정의하라`**
 - `반사성(reflexivity)`: null이 아닌 모든 참조 값 x에 대해, `x.equals(x)` true다.
 - `대칭성(symmetry)`: null이 아닌 모든 참조 값 x,y에 대해, `x.equals(y)`가 true면 `y.equals(x)`도 true다.
 - `추이성(transitivity)`: null이 아닌 모든 참조 값 x,y,z에 대해, `x.equals(y)`가 true이고 `y.equals(z)`도 true면 `x.equals(z)` true다.
 - `일관성(consistency)`: null이 아닌 모든 참조 값 x,y에 대해, `x.equals(y)`를 반복해서 호출하면 항상 true를 반환하거나 항상 false를 반환한다.
 - `null-아님`: null이 아닌 모든 참조 값 x에 대해, `x.equals(null)`은 false다.

**양질의 `equals`메서드 구현 방법**
1. == 연산자를 사용해 입력이 자기 자신의 참조인지 확인한다.
2. instanceof 연산자로 입력이 올바른 타입인지 확인한다.
3. 입력을 올바른 타입으로 형변환한다.
4. 입력 객체와 자기 자신의 대응되는 '핵심'필드들이 모두 일치하는지 하나씩 검사한다.

```text
float과 double을 제외한 기본 타입 필드는 == 연산자로 비교하고, 참조 타입 필드는 각각의 equals 메서드로,
float과 double 필드는 각각 정적 메서드인 Float.compare(f,f) 와 Double.compare(d,d)로 비교한다.
Float.equals나 Double.equals 메서드를 대신 사용할 수도 있지만, 이 메서드들은 오토박싱을 수반할 수 있으니 성능상 좋지 않다.
배열 필드는 원소 각각을 앞서의 지침대로 비교한다. 배열의 모든 요소가 핵심 필드라면 Arrays.equals 메서드들 중 하나를 사용하자.
때로는 null도 정상 값으로 취급하는 참조 타입 필드도 있다. 이런 필드는 정적 메서드인 Objects.equals(o,o)로 비교해 NPE 발생을 예방하자.
```

**Item 11. `equals를 재정의하려거든 hashCode도 재정의하라`**
- 재정의한 equals에서 논리적 동치를 허용한다면, 논리적 동치인 두 객체의 hashCode 값도 동일하도록 재정의 해야한다.
  - `그러지 않는다면 HashMap이나 HashSet 같은 컬렉션의 원소로 사용할 때 문제를 일으킬 것이다.` 

```text
# 점검
- equals()에 사용한 필드를 hashCode()에도 반영했는가?
- 필드 순서가 최종 해시에 영향을 끼치는가?
- 자주 들어오는 실제 데이터에서 해시 충돌이 적은가?
```

`10,11 결론 google의 AutoValue를 쓰자...`

**Item 12. `toString을 항상 재정의하라`**
- 실전에서 `toString은 그 객체가 가진 주요 정보 모두를 반환하는게 좋다.`