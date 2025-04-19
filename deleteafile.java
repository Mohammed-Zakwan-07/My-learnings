import java.io.File;

public class deleteafile {
  public static void main(String[] args) {
    File file = new File("example.txt");
    if (file.delete()) {
      System.out.println("Deleted: " + file.getName());
    } else {
      System.out.println("File deletion failed.");
    }
  }
}
