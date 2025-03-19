public class MultiCatch {
  public static void main(String[] args) {
    try {
      int[] arr = new int[5];
      arr[6] = 9;
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println(e);
    }

    try {
      int num1 = Integer.parseInt("abc");
    } catch (NumberFormatException e) {
      System.out.println(e);
    }
    System.out.println("rest of the code");
  }
}
