abstract class Product {
  abstract double getPrice();

  abstract String getDescription();
}

class Electronics extends Product {
  private double price;
  private String description;

  public Electronics(double price, String description) {
    this.price = price;
    this.description = description;
  }

  @Override
  public double getPrice() {
    return price;
  }

  @Override
  public String getDescription() {
    return description;
  }
}

class Clothing extends Product {
  double price;
  String description;

  public Clothing(double price, String description) {
    this.price = price;
    this.description = description;
  }

  @Override
  double getPrice() {
    return price;
  }

  @Override
  String getDescription() {
    return description;
  }
}

public class Products {
  public static void main(String[] args) {
    Product laptop = new Electronics(999.99, "High-end gaming laptop");
    Product tshirt = new Clothing(29.99, "Cotton T-shirt, size M");

    System.out.println("Price : " + laptop.getPrice());
    System.out.println(("Description : " + laptop.getDescription()));
    System.out.println("Price : " + tshirt.getPrice());
    System.out.println("Description : " + tshirt.getDescription());
  }
}
