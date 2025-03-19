class InvalidAgeException extends Exception {
  InvalidAgeException(String s) {
    super(s);
  }
}

class InvalidAge {
  static void validate(int age) throws InvalidAgeException {
    if (age < 18) {
      throw new InvalidAgeException("Age is less than 18 Not valid!!");
    } else {
      System.out.println("Welcome to vote");
    }
  }

  public static void main(String[] args) {
    try {
      validate(13);
    } catch (Exception m) {
      System.out.println(m.getMessage());
    }
    System.out.println("Rest of the code");
  }
}
