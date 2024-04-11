import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
        int height = in.readInt();
        int jump = in.readInt();
        char[] left = in.readString().toCharArray();
        char[] right = in.readString().toCharArray();
        int[] answer = new int[2 * height];
        int[] queue = new int[2 * height];
        int size = 1;
        Arrays.fill(answer, Integer.MAX_VALUE);
        answer[0] = 0;
        for (int i = 0; i < size; i++) {
            int current = queue[i];
            boolean isLeft = current < height;
            if (isLeft && left[current] == 'X' || !isLeft && right[current - height] == 'X' || answer[current] > current % height)
                continue;
            if (current % height + jump >= height) {
                out.printLine("YES");
                return;
            }
            if (answer[current + 1] == Integer.MAX_VALUE) {
                answer[current + 1] = answer[current] + 1;
                queue[size++] = current + 1;
            }
            if (current % height != 0 && answer[current - 1] == Integer.MAX_VALUE) {
                answer[current - 1] = answer[current] + 1;
                queue[size++] = current - 1;
            }
            int jumpTo;
            if (isLeft)
                jumpTo = current + height + jump;
            else
                jumpTo = current - height + jump;
            if (answer[jumpTo] == Integer.MAX_VALUE) {
                answer[jumpTo] = answer[current] + 1;
                queue[size++] = jumpTo;
            }
        }
        out.printLine("NO");
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
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

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}