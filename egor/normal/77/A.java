import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.Map;
import java.io.*;
import java.util.HashMap;

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
		Solver solver = new TaskA();
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

	@Override
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

class TaskA implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		Map<String, Integer> index = new HashMap<String, Integer>();
		index.put("Anka", 0);
		index.put("Chapay", 1);
		index.put("Cleo", 2);
		index.put("Troll", 3);
		index.put("Dracul", 4);
		index.put("Snowy", 5);
		index.put("Hexadecimal", 6);
		int likeCount = in.readInt();
		boolean[][] likes = new boolean[7][7];
		for (int i = 0; i < likeCount; i++) {
			String first = in.readString();
			in.readString();
			String second = in.readString();
			likes[index.get(first)][index.get(second)] = true;
		}
		int minDifference = Integer.MAX_VALUE;
		int maxLikes = 0;
		int mefistoExp = in.readInt();
		int diabloExp = in.readInt();
		int baalExp = in.readInt();
		for (int i = 1; i < 128; i++) {
			for (int j = i; j != 0; j = (j - 1) & i) {
				@SuppressWarnings({"UnnecessaryLocalVariable"}) 
				int firstSet = j;
				int secondSet = i - j;
				int thirdSet = 127 - i;
				int firstCount = Integer.bitCount(firstSet);
				int secondCount = Integer.bitCount(secondSet);
				int thirdCount = Integer.bitCount(thirdSet);
				if (firstCount == 0 || secondCount == 0 || thirdCount == 0)
					continue;
				int currentDifference = Math.max(Math.abs(mefistoExp / firstCount - diabloExp / secondCount), Math.max(
					Math.abs(mefistoExp / firstCount - baalExp / thirdCount), Math.abs(diabloExp / secondCount - baalExp / thirdCount)));
				if (currentDifference > minDifference)
					continue;
				int currentLikes = 0;
				for (int k = 0; k < 7; k++) {
					for (int l = 0; l < 7; l++) {
						if (k == l)
							continue;
						int mask = (1 << k) + (1 << l);
						if (likes[k][l] && ((firstSet & mask) == mask || (secondSet & mask) == mask || (thirdSet & mask) == mask))
							currentLikes++;
					}
				}
				if (currentDifference < minDifference || currentLikes > maxLikes) {
					minDifference = currentDifference;
					maxLikes = currentLikes;
				}
			}
		}
		out.println(minDifference + " " + maxLikes);
	}
}