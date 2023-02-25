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

    public static void min_max(double[] arr, double min, double max) {
        for (int i =0;i<arr.length;i++) {
            if (arr[i]<min) min = arr[i];
            if (arr[i]>max) max = arr[i];
        }
        System.out.print(min+ " "+ max);
    }

    public static void main(String[] args) {
//        Exercise 1
//        int[] numbers = fill_array(5);
//        print_array(numbers);

//        Exercise 2
        double min=Double.MAX_VALUE, max = Double.MIN_VALUE;
        double[] arr = {-1.0, 100, 3.14, -999.9, 21.37};
        min_max(arr, min, max);
        System.out.print(min+ " "+ max);
    }
}