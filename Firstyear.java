import java.util.Scanner;

class Student {
  String Name, Enroll;
  double mark1, mark2, mark3, total;

  public Student(String Name, String Enroll, double mark1, double mark2, double mark3) {
    this.Name = Name;
    this.Enroll = Enroll;
    this.mark1 = mark1;
    this.mark2 = mark2;
    this.mark3 = mark3;
    if (mark1 >= 50 && mark2 >= 50 && mark3 >= 50) {
      this.total = mark1 + mark2 + mark3;
    } else {
      this.total = 0;
    }
  }

  public void display() {
    System.out.println();
    System.out.println("Name: " + Name);
    System.out.println("Enroll: " + Enroll);
    System.out.println("Subject 1: " + mark1);
    System.out.println("Subject 2: " + mark2);
    System.out.println("Subject 3: " + mark3);
    System.out.println("Total " + total);
  }

  public static Student inpustudent(Scanner sc) {
    System.out.println("Enter Name : ");
    String name = sc.next();
    System.out.println("Enter Enroll : ");
    String enroll = sc.next();
    System.out.println("Enter mark1 : ");
    double mark1 = sc.nextDouble();
    System.out.println("Enter mark2 : ");
    double mark2 = sc.nextDouble();
    System.out.println("Enter mark3 : ");
    double mark3 = sc.nextDouble();
    sc.nextLine();
    return new Student(name, enroll, mark1, mark2, mark3);
  }
}

class Firstyear {
  String classname, staff;
  int n;
  Student[] students;

  Firstyear(String classname, String staff, int n, Scanner sc) {
    this.classname = classname;
    this.staff = staff;
    this.n = n;
    students = new Student[n];
    for (int i = 0; i < n; i++) {
      System.out.println();
      System.out.println("Enter the details of student " + (i + 1));
      students[i] = Student.inpustudent(sc);
    }
  }

  void displayclassdetails() {
    System.out.println("Classname : " + classname);
    System.out.println("Staff name : " + staff);
    System.out.println("Number of students : " + n);
    for (Student student : students) {
      student.display();
    }
  }

  void beststudent() {
    Student best = students[0];
    for (int i = 0; i < n; i++) {
      if (students[i].total > best.total) {
        best = students[i];
      }
    }
    System.out.println();
    System.out.println("Best Student of the class : " + best.Name);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println();
    System.out.println("Enter class name (bca,bba,bcom,bsc) : ");
    String classname = sc.nextLine();
    System.out.println("Enter staff name : ");
    String staff = sc.nextLine();
    System.out.println("Enter number of student : ");
    int n = sc.nextInt();
    Firstyear firstyear = new Firstyear(classname, staff, n, sc);

    firstyear.displayclassdetails();
    firstyear.beststudent();
    sc.close();
  }
}
