import java.util.ArrayList;
import java.util.List;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.Comparator;
import java.io.*;
import java.util.Arrays;
import java.util.Collection;

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
		Solver solver = new TaskB();
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
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

class IOUtils {
	public static void printArray(int[] array, PrintWriter out) {
		if (array.length == 0) {
			out.println();
			return;
		}
		out.print(array[0]);
		for (int i = 1; i < array.length; i++)
			out.print(" " + array[i]);
		out.println();
	}

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}

class TaskB implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int count = in.readInt();
		long length = in.readLong();
		int[] repetitions = IOUtils.readIntArray(in, count);
		int[] repetitionsCopy = repetitions.clone();
		Arrays.sort(repetitionsCopy);
		int last = 0;
		int remaining = count;
		for (int i : repetitionsCopy) {
			long timeRequired = (long) (i - last) * remaining;
			if (timeRequired <= length) {
				length -= timeRequired;
				remaining--;
				last = i;
			} else {
				long delta = last + length / remaining + 1;
				length %= remaining;
				if (length == 0) {
					int index = 0;
					int[] answer = new int[remaining];
					for (int k = 0; k < count; k++) {
						if (repetitions[k] >= delta)
							answer[index++] = k + 1;
					}
					IOUtils.printArray(answer, out);
					return;
				}
				int[] answer = new int[remaining];
				for (int j = 0; j < count; j++) {
					if (repetitions[j] > last) {
						length--;
						if (length == 0) {
							int index = 0;
							for (int k = j + 1; k < count; k++) {
								if (repetitions[k] >= delta)
									answer[index++] = k + 1;
							}
							for (int k = 0; k <= j; k++) {
								if (repetitions[k] > delta)
									answer[index++] = k + 1;
							}
							answer = Arrays.copyOf(answer, index);
							IOUtils.printArray(answer, out);
							return;
						}
					}
				}
			}
		}
		if (length == 0)
			out.println();
		else
			out.println(-1);
	}
}