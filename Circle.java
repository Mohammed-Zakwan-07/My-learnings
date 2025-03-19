interface Shape {
  public void circle();
}

interface Color extends Shape {
  public void color();
}

public class Circle implements Color {
  String color;

  Circle(String color) {
    this.color = color;
  }

  @Override
  public void circle() {
    System.out.println("This is a Circle");
  }

  @Override
  public void color() {
    System.out.println("This is " + color);
  }

  public static void main(String[] args) {
    Circle obj = new Circle("Pink");
    obj.circle();
    obj.color();
  }
}
