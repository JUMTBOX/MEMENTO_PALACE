```java
public abstract class Pizza {

  public enum Topping {HAM, MUSHROOM, ONION, PEPPER, SAUSAGE}

  final Set<Topping> toppings;

  abstract static class Builder<T extends Builder<T>> {

    EnumSet<Topping> toppings = EnumSet.noneOf(Topping.class);

    public T addTopping(Topping topping) {
      toppings.add(Objects.requireNonNull(topping));
      return self();
    }

    abstract Pizza build();

    /** 하위 클래스는 이 메서드를 재정의하여 this를 반환하도록 해야한다. */
    protected abstract T self();
  }

  Pizza(Builder<?> builder) {
    toppings = builder.toppings.clone();
  }
}

public class NyPizza extends Pizza {

  public enum Size {SMALL, MEDIUM, LARGE}

  private final Size size;

  public static class Builder extends Pizza.Builder<Builder> {

    private final Size size;

    public Builder(Size size) {
      this.size = Objects.requireNonNull(size);
    }

    @Override
    NyPizza build() {
      return new NyPizza(this);
    }

    @Override
    protected Builder self() {
      return this;
    }
  }
  
  private NyPizza (Builder builder) {
    super(builder);
    size = builder.size;
  }
} 
```