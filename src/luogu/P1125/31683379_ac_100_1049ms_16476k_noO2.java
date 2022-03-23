import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        char[] a = s.toCharArray();
        int[] b = new int[26];
        for(char i : a) {
            ++b[i - 'a'];
        }
        int maxn = Integer.MIN_VALUE, minn = Integer.MAX_VALUE;
        for(int i : b) {
            if(i > maxn) maxn = i;
            if(i != 0 && i < minn) minn = i;
        }
        if(pd(maxn - minn)) {
            System.out.print("Lucky Word\n" + (maxn - minn));
        } else {
            System.out.print("No Answer\n" + 0);
        }
        in.close();
    }
    private static boolean pd(int x) {
        if(x == 1 || x == 0) return false;
        if(x == 2) return true;
        for(int i = 2; i * i <= x; ++i) {
            if(x % i == 0) return false;
        }
        return true;
    }

}