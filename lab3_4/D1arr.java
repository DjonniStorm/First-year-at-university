import java.util.Random;

public class D1arr {
    protected int[] d1arr;
    public D1arr(int size) {
        Random rnd = new Random();
        d1arr = new int[size];
        for (int i = 0; i < size; i++) d1arr[i] = rnd.nextInt(-10, 10);
    }
    public D1arr(int[] d1arr) {this.d1arr = d1arr;}
    public void Task1(int[] d1arr) {
        int max = -1;
        for (int i : d1arr) if (i > max && i % 2 == 0) max = i;
        System.out.print("\n" + (max == -1 ? "Нет" : max));
    }
    public void printArr() {
        System.out.print("\n");
        for (int i : d1arr) System.out.printf("%5d ", i);
    }

    public void inLine() {
        String line = "";
        for (int i = 0; i < d1arr.length; i++) line = line + "   "  + d1arr[i];
        System.out.print("\n" + line);
    }
}