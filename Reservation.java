abstract class Reserve {
  abstract void reserve(String PassengerName, String date);
}

class ReserveTrain extends Reserve {
  @Override
  void reserve(String PassengerName, String Date) {
    System.out.println("Train seat is reserved for " + PassengerName + " on " + Date);
  }
}

class ReserveBus extends Reserve {
  @Override
  void reserve(String PassengerName, String Date) {
    System.out.println("Bus seat is reserved for " + PassengerName + " on " + Date);
  }
}

public class Reservation {
  public static void main(String[] args) {
    Reserve train = new ReserveTrain();
    Reserve bus = new ReserveBus();
    train.reserve("Tom", "15-3-2025");
    bus.reserve("Jerry", "15-3-2025");
  }
}
