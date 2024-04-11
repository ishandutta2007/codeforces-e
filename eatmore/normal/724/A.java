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

public class A {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static final String DAYS[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

	static void solve() throws Exception {
		String d1 = next();
		String d2 = next();
		int i1, i2;
		for (i1 = 0; !d1.equals(DAYS[i1]); i1++) { }
		for (i2 = 0; !d2.equals(DAYS[i2]); i2++) { }
		int diff = (i2 - i1 + 7) % 7;
//		System.err.println(diff);
		out.print(diff == 0 || diff == 2 || diff == 3 ? "YES" : "NO");
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