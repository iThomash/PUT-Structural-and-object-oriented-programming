public class Main {

    public static int[] fill_array(int n) {
        int[] newArr = new int[n];
        for (int i =0; i<n;i++) {
            newArr[i] = i+1;
        }
        return newArr;
    }

    public static void print_array(int[] arr) {
        for (int i =0; i<arr.length;i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] numbers = fill_array(5);
        print_array(numbers);
    }
}