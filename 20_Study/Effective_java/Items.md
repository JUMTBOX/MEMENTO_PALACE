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