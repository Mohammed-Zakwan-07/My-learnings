import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileOperationsExample {
  public static void main(String[] args) {
    try {
      File file = new File("example.txt");
      if (file.createNewFile()) {
        System.out.println("File created: " + file.getName());
      } else {
        System.out.println("File already exists.");
      }
      FileWriter writer = new FileWriter("example.txt");
      for (int i = 0; i < 10; i++) {
        writer.write(i + ".\t");
        writer.write("Hello, Java file handling!\n\tThis is the second line.\n\n");
      }
      writer.close();
      System.out.println("Successfully wrote to the file.");

      Scanner scanner = new Scanner(file);
      while (scanner.hasNextLine()) {
        String line = scanner.nextLine();
        System.out.println(line);
      }
      scanner.close();
    } catch (IOException e) {
      System.out.println(e);
      e.printStackTrace();
    }
  }
}
