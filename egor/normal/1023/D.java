import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int q = in.readInt();
            int[] a = in.readIntArray(n);
            int[] min = ArrayUtils.createArray(q + 1, n);
            int[] max = ArrayUtils.createArray(q + 1, -1);
            for (int i = 0; i < n; i++) {
                min[a[i]] = Math.min(min[a[i]], i);
                max[a[i]] = Math.max(max[a[i]], i);
            }
            LongIntervalTree tree = new LongIntervalTree(n) {

                protected long joinValue(long left, long right) {
                    return Math.max(left, right);
                }


                protected long joinDelta(long was, long delta) {
                    return Math.max(was, delta);
                }


                protected long accumulate(long value, long delta, int length) {
                    return Math.max(value, delta);
                }


                protected long neutralValue() {
                    return 0;
                }


                protected long neutralDelta() {
                    return 0;
                }
            };
            for (int i = 1; i <= q; i++) {
                if (min[i] != n) {
                    tree.update(min[i], max[i], i);
                }
            }
            boolean needMax = min[q] == n;
            for (int i = 0; i < n; i++) {
                if (a[i] != 0 && a[i] < tree.query(i, i)) {
                    out.printLine("NO");
                    return;
                }
                if (a[i] == 0) {
                    if (needMax) {
                        a[i] = q;
                        needMax = false;
                    } else {
                        a[i] = (int) Math.max(tree.query(i, i), 1);
                    }
                }
            }
            if (needMax) {
                out.printLine("NO");
                return;
            }
            out.printLine("YES");
            out.printLine(a);
        }

    }

    static abstract class IntervalTree {
        protected int size;

        protected IntervalTree(int size) {
            this(size, true);
        }

        public IntervalTree(int size, boolean shouldInit) {
            this.size = size;
            int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
            initData(size, nodeCount);
            if (shouldInit) {
                init();
            }
        }

        protected abstract void initData(int size, int nodeCount);

        protected abstract void initAfter(int root, int left, int right, int middle);

        protected abstract void initBefore(int root, int left, int right, int middle);

        protected abstract void initLeaf(int root, int index);

        protected abstract void updatePostProcess(int root, int left, int right, int from, int to, long delta,
                                                  int middle);

        protected abstract void updatePreProcess(int root, int left, int right, int from, int to, long delta,
                                                 int middle);

        protected abstract void updateFull(int root, int left, int right, int from, int to, long delta);

        protected abstract long queryPostProcess(int root, int left, int right, int from, int to, int middle,
                                                 long leftResult, long rightResult);

        protected abstract void queryPreProcess(int root, int left, int right, int from, int to, int middle);

        protected abstract long queryFull(int root, int left, int right, int from, int to);

        protected abstract long emptySegmentResult();

        public void init() {
            if (size == 0) {
                return;
            }
            init(0, 0, size - 1);
        }

        private void init(int root, int left, int right) {
            if (left == right) {
                initLeaf(root, left);
            } else {
                int middle = (left + right) >> 1;
                initBefore(root, left, right, middle);
                init(2 * root + 1, left, middle);
                init(2 * root + 2, middle + 1, right);
                initAfter(root, left, right, middle);
            }
        }

        public void update(int from, int to, long delta) {
            update(0, 0, size - 1, from, to, delta);
        }

        protected void update(int root, int left, int right, int from, int to, long delta) {
            if (left > to || right < from) {
                return;
            }
            if (left >= from && right <= to) {
                updateFull(root, left, right, from, to, delta);
                return;
            }
            int middle = (left + right) >> 1;
            updatePreProcess(root, left, right, from, to, delta, middle);
            update(2 * root + 1, left, middle, from, to, delta);
            update(2 * root + 2, middle + 1, right, from, to, delta);
            updatePostProcess(root, left, right, from, to, delta, middle);
        }

        public long query(int from, int to) {
            return query(0, 0, size - 1, from, to);
        }

        protected long query(int root, int left, int right, int from, int to) {
            if (left > to || right < from) {
                return emptySegmentResult();
            }
            if (left >= from && right <= to) {
                return queryFull(root, left, right, from, to);
            }
            int middle = (left + right) >> 1;
            queryPreProcess(root, left, right, from, to, middle);
            long leftResult = query(2 * root + 1, left, middle, from, to);
            long rightResult = query(2 * root + 2, middle + 1, right, from, to);
            return queryPostProcess(root, left, right, from, to, middle, leftResult, rightResult);
        }

    }

    static class ArrayUtils {
        public static int[] createArray(int count, int value) {
            int[] array = new int[count];
            Arrays.fill(array, value);
            return array;
        }

    }

    static abstract class LongIntervalTree extends IntervalTree {
        protected long[] value;
        protected long[] delta;

        protected LongIntervalTree(int size) {
            this(size, true);
        }

        public LongIntervalTree(int size, boolean shouldInit) {
            super(size, shouldInit);
        }

        protected void initData(int size, int nodeCount) {
            value = new long[nodeCount];
            delta = new long[nodeCount];
        }

        protected abstract long joinValue(long left, long right);

        protected abstract long joinDelta(long was, long delta);

        protected abstract long accumulate(long value, long delta, int length);

        protected abstract long neutralValue();

        protected abstract long neutralDelta();

        protected long initValue(int index) {
            return neutralValue();
        }

        protected void initAfter(int root, int left, int right, int middle) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
            delta[root] = neutralDelta();
        }

        protected void initBefore(int root, int left, int right, int middle) {
        }

        protected void initLeaf(int root, int index) {
            value[root] = initValue(index);
            delta[root] = neutralDelta();
        }

        protected void updatePostProcess(int root, int left, int right, int from, int to, long delta, int middle) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
        }

        protected void updatePreProcess(int root, int left, int right, int from, int to, long delta, int middle) {
            pushDown(root, left, middle, right);
        }

        protected void pushDown(int root, int left, int middle, int right) {
            value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root], middle - left + 1);
            value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root], right - middle);
            delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
            delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
            delta[root] = neutralDelta();
        }

        protected void updateFull(int root, int left, int right, int from, int to, long delta) {
            value[root] = accumulate(value[root], delta, right - left + 1);
            this.delta[root] = joinDelta(this.delta[root], delta);
        }

        protected long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult,
                                        long rightResult) {
            return joinValue(leftResult, rightResult);
        }

        protected void queryPreProcess(int root, int left, int right, int from, int to, int middle) {
            pushDown(root, left, middle, right);
        }

        protected long queryFull(int root, int left, int right, int from, int to) {
            return value[root];
        }

        protected long emptySegmentResult() {
            return neutralValue();
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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(int[] array) {
            print(array);
            writer.println();
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
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

        public int[] readIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
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

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
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