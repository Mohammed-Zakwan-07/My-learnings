import java.util.Scanner;

class Armstrong {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter number a:");
        int num = input.nextInt();
        
        int ognum = num;
        int Sum = 0;
        
        while (num > 0) {
            int digits = num % 10;
            Sum += digits * digits * digits;
            num /= 10;
        }
        
        
        if (ognum == Sum) { 
            System.out.println(ognum + " is an Armstrong number.");
        } else {
            System.out.println(ognum + " is not an Armstrong number.");
        }
        input.close();
    }
}
