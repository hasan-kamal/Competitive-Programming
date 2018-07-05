import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Reader {
	    static BufferedReader reader;
	    static StringTokenizer tokenizer;

	    /** call this method to initialize reader for InputStream */
	    static void init(InputStream input) {
	        reader = new BufferedReader(
	                     new InputStreamReader(input) );
	        tokenizer = new StringTokenizer("");
	    }

	    /** get next word */
	    static String next() throws IOException {
	        while ( ! tokenizer.hasMoreTokens() ) {
	            //TODO add check for eof if necessary
	            tokenizer = new StringTokenizer(
	                   reader.readLine() );
	        }
	        return tokenizer.nextToken();
	    }

	    static int nextInt() throws IOException {
	        return Integer.parseInt( next() );
	    }
		
	    static double nextDouble() throws IOException {
	        return Double.parseDouble( next() );
	    }
}

public class PopularFoobar{

	public static int minimum(int x, int y){
		return x < y ? x : y;
	}

	public static void main(String[] args) throws IOException{
		Reader.init(System.in);
		int n = Reader.nextInt();
		String target = "fbar";
		String targetDouble = "o";
		while(n > 0){
			String s = Reader.next();
			int[] count = new int[26];
			for(int i = 0; i < 26; i++)
				count[i] = 0;
			for(int i = 0; i < s.length(); i++){
				count[s.charAt(i) - 'a'] += 1;
			}
			int ans = (int)1e9;
			for(int i = 0; i < target.length(); i++){
				ans = minimum(ans, count[target.charAt(i) - 'a']);
			}
			for(int i = 0; i < targetDouble.length(); i++){
				ans = minimum(ans, (count[targetDouble.charAt(i)- 'a']) / 2);
			}
			n--;
			System.out.println(ans);
		}
	}
}