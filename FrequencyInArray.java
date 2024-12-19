import java.util.Scanner;

public class FrequencyInArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        int[] arr = new int[size];
        int[] frequency = new int[size];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
            frequency[i] = -1;
        }

        for (int i = 0; i < size; i++) {
            int count = 1;
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    frequency[j] = 0;
                }
            }
            if (frequency[i] != 0) {
                frequency[i] = count;
            }
        }

        for (int i = 0; i < size; i++) {
            if (frequency[i] != 0) {
                System.out.println(arr[i] + " occurs " + frequency[i] + " times");
            }
        }

        scanner.close();
    }
}
