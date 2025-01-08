class Vegetables {
  String Name;
  String Color;
  
  Vegetables(String Name,String Color) {
      this.Name = Name;
      this.Color = Color;
  }
  void DisplayString () {
      System.out.println(Name + ":" + Color);
  }
  public static void main(String[] args) {
      Vegetables Vegetable1 = new Vegetables("Carrot","Orange");
      Vegetable1.DisplayString();
  }
}