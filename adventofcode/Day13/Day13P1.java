import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;


class Debug {
	// change to System.getProperty("ONLINE_JUDGE")==null; for CodeForces
	public static final boolean LOCAL = true;
	private static <T> String ts(T t) {
		if(t==null) {
			return "null";
		}
		try {
			return ts((Iterable) t);
		}catch(ClassCastException e) {
			if(t instanceof int[]) {
				String s = Arrays.toString((int[]) t);
				return "{"+s.substring(1, s.length()-1)+"}";
			}else if(t instanceof long[]) {
				String s = Arrays.toString((long[]) t);
				return "{"+s.substring(1, s.length()-1)+"}";
			}else if(t instanceof char[]) {
				String s = Arrays.toString((char[]) t);
				return "{"+s.substring(1, s.length()-1)+"}";
			}else if(t instanceof double[]) {
				String s = Arrays.toString((double[]) t);
				return "{"+s.substring(1, s.length()-1)+"}";
			}else if(t instanceof boolean[]) {
				String s = Arrays.toString((boolean[]) t);
				return "{"+s.substring(1, s.length()-1)+"}";
			}
			try {
				return ts((Object[]) t);
			}catch(ClassCastException e1) {
				return t.toString();
			}
		}
	}
	private static <T> String ts(T[] arr) {
		StringBuilder ret = new StringBuilder();
		ret.append("{");
		boolean first = true;
		for(T t: arr) {
			if(!first) {
				ret.append(", ");
			}
			first = false;
			ret.append(ts(t));
		}
		ret.append("}");
		return ret.toString();
	}
	private static <T> String ts(Iterable<T> iter) {
		StringBuilder ret = new StringBuilder();
		ret.append("{");
		boolean first = true;
		for(T t: iter) {
			if(!first) {
				ret.append(", ");
			}
			first = false;
			ret.append(ts(t));
		}
		ret.append("}");
		return ret.toString();
	}
	public static void dbg(Object... o) {
		if(LOCAL) {
			System.err.print("Line #"+Thread.currentThread().getStackTrace()[2].getLineNumber()+": [");
			for(int i = 0; i<o.length; i++) {
				if(i!=0) {
					System.err.print(", ");
				}
				System.err.print(ts(o[i]));
			}
			System.err.println("]");
		}
	}
}

class Parttern {
    String[] parttern;
    long[] verticalHash;
    long[] verticalReverseHash;
    long[] horizontalHash;
    long[] horizontalReverseHash;


    Parttern(String[] pattern) {
        this.parttern = pattern;
        initVerticalHash();
        initHorizontalHash();
    }

    int getHorizontalReflectNum() {
        int height = parttern.length;
        for (int i = 1; i < height - 1; i++) {
            if (isReflectAtIndex(i, horizontalHash)) {
                return i;
            }
        }

        return 0;
    }

    int getVerticalReflectNum() {
        int width = parttern[0].length();
        for (int i = 1; i < width - 1; i++) {
            if (isReflectAtIndex(i, verticalHash)) {
                return i;
            }
        }

        return 0;
    }

    boolean isReflectAtIndex(int beginRightPartIndex, long[] prefixSumHash) {
        int size = prefixSumHash.length;
        int reflectSize = Math.min(beginRightPartIndex, size - beginRightPartIndex);

        int endRightPartIndex = beginRightPartIndex + reflectSize - 1;
        int beginLeftPartIndex = beginRightPartIndex - reflectSize;
        int endLeftPartIndex = beginRightPartIndex - 1;

        long leftPartHash = getHash(prefixSumHash, beginLeftPartIndex, endLeftPartIndex);
        long rightPartHash = getHash(prefixSumHash, beginRightPartIndex, endRightPartIndex);

        return leftPartHash == rightPartHash;
    }

    long getHash(long[] hash, int begin, int end) {
        long sum = 0;
        for (int i = begin; i <= end; i++) {
            sum += hash[i];
        }

        return sum;
    }

    void initVerticalHash() {
        int width = parttern[0].length();
        int height = parttern.length;
        verticalHash = new long[width];
        for (int c = 0; c < width; c++) {
            long hash = 0;
            for (int r = 0; r < height; r++) {
                if (parttern[r].charAt(c) == '.') {
                    hash += (1 << r);
                } else {
                    hash += (0 << r);
                }

            }
            
            verticalHash[c] = hash;
        }
    }

    void initHorizontalHash() {
        int width = parttern[0].length();
        int height = parttern.length;
        horizontalHash = new long[height];
        for (int r = 0; r < height; r++) {
            long hash = 0;
            for (int c = 0; c < width; c++) {
                if (parttern[r].charAt(c) == '.') {
                    hash += (1 << c);
                } else {
                    hash += (0 << c);
                }

            }

            horizontalHash[r] = hash;
        }
    }
}

public class Day13P1 {
    static FastScanner cin;
    static PrintWriter cout;

    public static void main(String[] args) {
        initIO();
        solve();
        closeIO();
    }

    static void initIO() {
        try {
            InputStreamReader readerStream = new FileReader("/home/anoobagain/Documents/cp-practice/adventofcode/Day13/local.in");
            OutputStreamWriter writerStream = new FileWriter("/home/anoobagain/Documents/cp-practice/adventofcode/Day13/local.out");
            cin = new FastScanner(readerStream);
            cout = new PrintWriter(writerStream);
            System.out.println("DONE INIT IO");
        } catch (IOException ioException) {
            System.err.println(ioException.getStackTrace());
        }
    }

    static void closeIO() {
        cin.close();
        cout.close();
    }

    static void solve() {
        String line;

        List<String> parttern = new ArrayList<String>();
        long sum = 0;
        while (true) {
            line = cin.nextLine();

            if (line == null || line.length() == 0) {
                Parttern p = new Parttern(parttern.toArray(new String[0]));
                int vertical =  p.getVerticalReflectNum();
                int horizontal =  p.getHorizontalReflectNum();
                Debug.dbg(vertical, horizontal);
                sum += horizontal * 100 + vertical;
                parttern.clear();
                if (line == null) {
                    break;
                } else {
                    continue;
                }
            }

            parttern.add(line);
        }
        cout.print(sum);
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