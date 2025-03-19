abstract class message {
  abstract void PlayMessage();
}

class TextMessage extends message {
  @Override
  void PlayMessage() {
    System.out.println("Here's a text message");
  }
}

class VoiceMessage extends message {
  @Override
  void PlayMessage() {
    System.out.println("Here's a Voice message");
  }
}

class FaxMessage extends message {
  @Override
  void PlayMessage() {
    System.out.println("Here's a Fax message");
  }
}

class Messages {
  public static void main(String[] args) {
    message Text = new TextMessage();
    Text.PlayMessage();
    message Voice = new VoiceMessage();
    Voice.PlayMessage();
    message Fax = new FaxMessage();
    Fax.PlayMessage();
  }
}
