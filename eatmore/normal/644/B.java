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
		int n = nextInt();
		int b = nextInt() + 1;
		int queue[] = new int[n];
		int queueHead = 0, queueTail = 0;
		long ans[] = new long[n];
		for (int i = 0; i < n; i++) {
			long time = nextLong();
			while (queueHead < queueTail && ans[queue[queueHead]] <= time) {
				++queueHead;
			}
			long duration = nextLong();
			if (queueHead + b == queueTail) {
				ans[i] = -1;
			} else {
				ans[i] = (queueHead == queueTail ? time : ans[queue[queueTail - 1]]) + duration;
				queue[queueTail++] = i;
			}
		}
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(ans[i]);
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