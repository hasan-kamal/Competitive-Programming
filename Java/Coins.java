import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import java.util.Arrays;

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

public class Coins{
	public static void main(String[] args) throws IOException{
		Reader.init(System.in);
		int t = Reader.nextInt();
		while(t > 0){

			int[] count = new int[3];
			for(int i = 0; i < 3; i++){
				String inp = Reader.next();
				if(inp.charAt(1) == '>'){
					count[inp.charAt(0) - 'A']++;
					count[inp.charAt(2) - 'A']--;
				}else{
					count[inp.charAt(0) - 'A']--;
					count[inp.charAt(2) - 'A']++;
				}
			}

			int[] cpy = count.clone();
			Arrays.sort(cpy);
			if(cpy[0] == -2 && cpy[1] == 0 && cpy[2] == 2){
				char[] output = new char[3];
				for(int i = 0; i < 3; i++){
					if(count[i] == 2)
						output[2] = (char)('A' + i);
					else if(count[i] == 0)
						output[1] = (char)('A' + i);
					else if(count[i] == -2)
						output[0] = (char)('A' + i);
				}
				System.out.println(new String(output));
			}
			else
				System.out.println("Impossible");

			t--;
		}
	}
}