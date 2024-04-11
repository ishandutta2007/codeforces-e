import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BIgraSModulem solver = new BIgraSModulem();
        solver.solve(1, in, out);
        out.close();
    }

    static class BIgraSModulem {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            while (true) {
                String command = in.readString();
                if (!command.equals("start")) {
                    return;
                }
                out.printLine("? 1 2");
                out.flush();
                String result = in.readString();
                if ("e".equals(result)) {
                    return;
                }
                if (result.equals("x")) {
                    out.printLine("? 4 5");
                    out.flush();
                    result = in.readString();
                    if ("e".equals(result)) {
                        return;
                    }
                    if ("x".equals(result)) {
                        out.printLine("! 1");
                    } else {
                        out.printLine("! 2");
                    }
                    out.flush();
                    continue;
                }
                int from = 3;
                int to = 1000000000;
                while (2 * (from - 1) < to) {
                    out.printLine("?", from - 1, 2 * (from - 1));
                    out.flush();
                    result = in.readString();
                    if ("e".equals(result)) {
                        return;
                    }
                    if ("x".equals(result)) {
                        to = 2 * (from - 1);
                    } else {
                        from = 2 * (from - 1) + 1;
                    }
                }
                while (from < to) {
                    out.printLine("?", from - 1, (from + to) / 2);
                    out.flush();
                    result = in.readString();
                    if ("e".equals(result)) {
                        return;
                    }
                    if ("x".equals(result)) {
                        to = (from + to) / 2;
                    } else {
                        from = (from + to) / 2 + 1;
                    }
                }
                out.printLine("!", from);
                out.flush();
            }
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void flush() {
            writer.flush();
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}