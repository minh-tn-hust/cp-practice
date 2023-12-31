import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class Parttern {
    String[] parttern;
    int[][] verticalHash;
    int[][] horizontalHash;

    Parttern(String[] pattern) {
        int width = parttern.length;
        int height = parttern[0].length();

        verticalHash = new int[width][height];
        horizontalHash = new int[height][width];
    }
}

public class Day13P2 {
    static FastScanner cin;
    static PrintWriter cout;

    public static void main(String[] args) {
        initIO();
        solve();
        closeIO();
    }

    static void initIO() {
        try {
            InputStreamReader readerStream = new FileReader("./adventofcode/local.in");
            OutputStreamWriter writerStream = new FileWriter("./adventofcode/local.out");
            cin = new FastScanner(readerStream);
            cout = new PrintWriter(writerStream);
        } catch (IOException ioException) {
            System.err.println(ioException.getStackTrace());
        }
    }

    static void closeIO() {
        cin.close();
        cout.close();
    }

    static void solve() {

    }
}

class FastScanner {
    public BufferedReader br;
    public StringTokenizer st = new StringTokenizer("");

    FastScanner(InputStreamReader inputStreamReader) {
        br = new BufferedReader(inputStreamReader);
    }

    public String next() {
        while (!st.hasMoreTokens())
            try { 
                st=new StringTokenizer(br.readLine());				               
            } catch (IOException e) {}
        return st.nextToken();
    }
    
    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

     public String nextLine() 
        { 
            String str = ""; 
            try { 
                if(st.hasMoreTokens()){ 
                    str = st.nextToken("\n"); 
                } 
                else{ 
                    str = br.readLine(); 
                } 
            } 
            catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    public void close() {
        try {
            br.close();
        } catch (IOException ioException) {
            System.out.println(ioException.getStackTrace());
        }
    }
}
