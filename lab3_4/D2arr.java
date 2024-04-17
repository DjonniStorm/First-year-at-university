import java.util.Random;

public class D2arr extends D1arr {
    private int[][] d2arr;
    public D2arr(int m, int n) {
        super(n);
        d2arr = new int[m][n];
        Random rnd = new Random();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                d2arr[i][j] = rnd.nextInt(-10, 10);
            }
        }
    }
    public D2arr(int[][] myArr) {super(0); d2arr = myArr;}
    public D2arr(int m) {
        super(m); d2arr = new int[m][]; Random rnd = new Random();
        for (int i = 0; i < m; i++) {
            int[] tmp = new int[rnd.nextInt(1, m)];
            for (int j = 0; j < tmp.length; j++) tmp[j] = rnd.nextInt(-10, 10);
            d2arr[i] = tmp;
        }
    }
    public void Task2() {
        if (d2arr.length != d2arr[0].length) {System.out.print("\n" + "Не квадратная"); return;}
        int firstIndex = -1; int secondIndex = -1;
        for (int j = 0; j < d2arr[0].length; j++) {
            if (d2arr[d2arr.length - 1][j] < 0) {
                firstIndex = j; break;
            }
        }
        for (int j = d2arr[0].length - 1; j > 0; j--) {
            if (d2arr[0][j] > 0) {
                secondIndex = j; break;
            }
        }
        if (firstIndex == -1 || secondIndex == -1) {System.out.print("\n Поменять не получилось"); return;}
        if (firstIndex == secondIndex) {printArr(); return;}
        for (int i = 0; i < d2arr.length; i++) {
            int temp = d2arr[i][firstIndex];
            d2arr[i][firstIndex] = d2arr[i][secondIndex];
            d2arr[i][secondIndex] = temp;
        }
        printArr();
    }
    public void Task3() {
        int maxLine = -1;
        for (int i = 0, max = 0; i < d2arr.length; i++) {
            if (d2arr[i].length > max) {
                max = d2arr[i].length;
                maxLine = i;
            }
        }
        if (maxLine != -1)
            Task1(d2arr[maxLine]);
    }

    @Override
    public void printArr() {
        System.out.print("\n");
        for (int[] i : d2arr) {
            System.out.print("\n");
            for (int j : i) {
                System.out.printf("%5d", j);}
            }
    }
}