import java.util.Scanner;

class Student {
  String enrollmentNo;
  String name;
  int mark1, mark2, mark3, totalMarks;

  Student(String enrollmentNo, String name, int mark1, int mark2, int mark3) {
    this.enrollmentNo = enrollmentNo;
    this.name = name;
    this.mark1 = mark1;
    this.mark2 = mark2;
    this.mark3 = mark3;

    if (mark1 >= 50 && mark2 >= 50 && mark3 >= 50) {
      this.totalMarks = mark1 + mark2 + mark3;
    } else {
      this.totalMarks = 0;
    }
  }

  void display() {
    System.out.println("Enrollment No: " + enrollmentNo);
    System.out.println("Name: " + name);
    System.out.println("Marks: " + mark1 + ", " + mark2 + ", " + mark3);
    System.out.println("Total Marks: " + totalMarks);
    System.out.println("---------------------------");
  }

  public static Student inputStudent(Scanner sc) {
    System.out.print("Enter Enrollment No: ");
    String enrollmentNo = sc.next();
    System.out.print("Enter Name: ");
    String name = sc.next();
    System.out.print("Enter Marks for 3 subjects: ");
    int mark1 = sc.nextInt();
    int mark2 = sc.nextInt();
    int mark3 = sc.nextInt();

    return new Student(enrollmentNo, name, mark1, mark2, mark3);
  }
}

class FirstYear {
  String className;
  String staffName;
  int numStudents;
  Student[] students;

  FirstYear(String className, String staffName, int numStudents, Scanner sc) {
    this.className = className;
    this.staffName = staffName;
    this.numStudents = numStudents;
    students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
      System.out.println("\nEnter details for Student " + (i + 1) + ":");
      students[i] = Student.inputStudent(sc);
    }
  }

  void displayClassDetails() {
    System.out.println("\nClass Name: " + className);
    System.out.println("Staff Name: " + staffName);
    System.out.println("Number of Students: " + numStudents);
    System.out.println("\nStudent Details:");
    for (Student student : students) {
      student.display();
    }
  }

  Student bestStudent() {
    Student best = students[0];
    for (int i = 1; i < numStudents; i++) {
      if (students[i].totalMarks > best.totalMarks) {
        best = students[i];
      }
    }
    return best;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter Class Name (BCA, B.Com, BSc): ");
    String className = sc.next();
    System.out.print("Enter Staff Name: ");
    String staffName = sc.next();
    System.out.print("Enter Number of Students: ");
    int numStudents = sc.nextInt();

    FirstYear firstYear = new FirstYear(className, staffName, numStudents, sc);

    firstYear.displayClassDetails();

    Student best = firstYear.bestStudent();
    System.out.println("\nBest Student in the Class:");
    best.display();

    sc.close();
  }
}
