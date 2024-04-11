import java.util.InputMismatchException;
import java.math.BigInteger;
import java.io.*;
import java.util.Arrays;

/**
 * Generated by Contest helper plug-in
 * Actual solution is at the bottom
 */
public class Main {
	public static void main(String[] args) {
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskC();
		solver.solve(1, in, out);
		Exit.exit(in, out);
	}
}

abstract class InputReader {
	private boolean finished = false;

	public abstract int read();

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public void setFinished(boolean finished) {
		this.finished = finished;
	}

	public abstract void close();
}

class StreamInputReader extends InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar, numChars;

	public StreamInputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}

class Exit {
	private Exit() {
	}

	public static void exit(InputReader in, PrintWriter out) {
		in.setFinished(true);
		in.close();
		out.close();
	}
}

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
}

class TaskC implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int n = in.readInt();
		int[] nimber = new int[n + 1];
		int[] minimum = new int[n + 1];
		Arrays.fill(minimum, -1);
		int[] value = new int[5 * n];
		for (int i = 3; i <= n; i++) {
			for (int j = 2; j * j < 2 * i; j++) {
				if (2 * i % j == 0) {
					int min = j;
					int max = 2 * i / j;
					if ((max & 1) == (min & 1))
						continue;
					int a = (min + max - 1) >> 1;
					int b = a - min;
					int current = 0;
					for (int k = b + 1; k <= a; k++)
						current ^= nimber[k];
					if (current == 0 && minimum[i] == -1)
						minimum[i] = min;
					value[current] = i;
				}
			}
			for (int j = 0; ; j++) {
				if (value[j] != i) {
					nimber[i] = j;
					break;
				}
			}
		}
		out.println(minimum[n]);
	}
}