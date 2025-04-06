import java.awt.*;
import java.awt.event.*;

public class familydetailsAWT extends Frame implements ActionListener {
  Label label;
  Button father, mother;

  familydetails() {

    label = new Label("Click to see details");
    father = new Button("Father details");
    mother = new Button("Mother details");

    father.addActionListener(this);
    mother.addActionListener(this);

    add(father);
    add(mother);
    add(label);

    setTitle("Details");
    setSize(400, 200);
    setLayout(new FlowLayout());
    setVisible(true);
  }

  public void actionPerformed(ActionEvent ae) {
    if (ae.getSource() == father) {
      label.setText("Name: John cena, Age: 56, Occupation: Actor");
    } else if (ae.getSource() == mother) {
      label.setText("Name: Jane cena, Age: 40, Occupation: Actor");
    }
  }

  public static void main(String[] args) {
    new familydetails();
  }
}
