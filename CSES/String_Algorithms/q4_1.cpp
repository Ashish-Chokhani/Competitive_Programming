import java.util.*;

public class Main {
    static long get_hash(int l, int r, long[] hash, long[] power, long M) {
        long h = hash[r+1] - (power[r-l+1]*hash[l]%M)%M; 
        return h < 0 ? h+M : h;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = s.length();

        long P = 31;
        long M = 1000000007;

        long[] power = new long[n+5];
        power[0] = 1;

        for(int i=1; i<n; i++) {
            power[i] = (power[i-1]*P)%M;
        }

        long[] hash = new long[n+10];

        for(int i=1; i<=n; i++) {
            hash[i] = (hash[i-1]*P + s.charAt(i-1))%M;
        }

        for(int i=0; i<n; i++) {
            int runIdx = 0;
            boolean ok = true;
            while(runIdx < n) {
                int len = Math.min(i+1, n-runIdx);
                ok &= (get_hash(0,len-1,hash,power,M) == get_hash(runIdx,runIdx+len-1,hash,power,M));
                runIdx += len;
            }
            if(ok) {
                System.out.print(i+1 + " ");
            }
        }
    }
}