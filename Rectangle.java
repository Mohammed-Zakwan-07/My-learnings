class Rectangle {
  double length;
  double breadth;
  
  Rectangle () {
      length = 10;
      breadth = 7;
  }
  
  Rectangle (double length, double breadth) {
      this.length = length;
      this.breadth = breadth;
  }
  double get_Area () {
      return ( length * breadth );
  }
  double get_perimeter () {
      return ( ( 2 * length ) + ( 2 * breadth ));
  }
  public static void main (String [] args) {
      Rectangle Rectangle1 = new Rectangle(10, 7);
      System.out.println("The area is " + Rectangle1.get_Area());
      System.out.println("The perimeter is " + Rectangle1.get_perimeter());
  }
}