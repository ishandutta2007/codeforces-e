import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		String s = in.readLine();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == ' ') {
				continue;
			}
			if (s.charAt(i) == '"') {
				int j;
				for (j = i + 1; j < s.length() && s.charAt(j) != '"'; j++) { }
				if (j >= s.length()) {
					throw new AssertionError();
				}
				if (j + 1 < s.length() && s.charAt(j + 1) != ' ') {
					throw new AssertionError();
				}
				out.print('<');
				out.print(s.substring(i + 1, j));
				out.println('>');
				i = j + 1;
			} else {
				int j;
				for (j = i; j < s.length() && s.charAt(j) != ' ' && s.charAt(j) != '"'; j++) { }
				if (j < s.length() && s.charAt(j) != ' ') {
					throw new AssertionError();
				}
				out.print('<');
				out.print(s.substring(i, j));
				out.println('>');
				i = j;
			}
		}
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}