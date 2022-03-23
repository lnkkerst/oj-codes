import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] b = new int[1001];
        int n = in.nextInt();
        for(int i = 1; i <= n; ++i) {
            b[in.nextInt()] = 1;
        }
        int ans = 0;
        for(int i = 0; i <= 1000; ++i) {
            ans += b[i];
        }
        System.out.println(ans);
        for(int i = 0; i <= 1000; ++i) {
            if(b[i] == 1) {
                System.out.print(i + " ");
            }
        }
    }
}