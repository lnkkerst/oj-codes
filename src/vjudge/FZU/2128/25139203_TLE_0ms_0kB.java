import java.io.*;
import java.util.*;

class Node {
    int l, r;
}

class MyComprator implements Comparator {
    public int compare(Object x, Object y) {
        Node a = (Node)x, b = (Node)y;
        if(a.l == b.l) return a.r > b.r ? 1 : -1;
        else return a.l > b.l ? 1 : -1;
    }
}

public class Main {
    public static void main(String[] argv) {
        Vector<Node> q = new Vector<Node>();
        int n, kmp[] = new int[233];
        String a, b;
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            a = in.next();
            n = in.nextInt();
            for(int k = 1; k <= n; ++k) {
                b = in.next();
                int la = a.length(), lb = b.length(), j = 0;
                for(int i = 1; i < lb; ++i) {
                    while(j != 0 && b.charAt(i) != b.charAt(j)) j = kmp[j];
                    if(b.charAt(j) == b.charAt(i)) ++j;
                    kmp[i] = j;
                } j = 0;
                for(int i = 0; i < la; ++i) {
                    while(j != 0 && b.charAt(j) != a.charAt(i)) j = kmp[j];
                    if(b.charAt(j) == a.charAt(i)) ++j;
                    if(j == lb) {
                        Node tmp = new Node();
                        tmp.l = i - lb + 1;
                        tmp.r = i;
                        q.add(tmp);
                        j = kmp[j];
                    }
                }
            }
            Collections.sort(q, new MyComprator());
            int ans = -1;
            for(int i = 1; i < q.size(); ++i)
                ans = Math.max(ans, q.get(i).r - q.get(i - 1).l - 1);
            if(ans == -1) System.out.println(a.length());
            else System.out.println(ans);
            q.clear();
        }
    }
}