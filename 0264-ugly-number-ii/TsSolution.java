import java.util.TreeSet;

class TsSolution {
    public int nthUglyNumber(int n) {
        /** Similar to PQ solution, but duplicates are not included */
        TreeSet<Long> q = new TreeSet<>();
        q.add(1L);

        for (long i = 1; i < n; i++) {
            long tmp = q.pollFirst();
            q.add(tmp * 2);
            q.add(tmp * 3);
            q.add(tmp * 5);
        }

        return q.first().intValue();
    }

    public static void main(String[] args) {
        for (int n = 1; n <= 20; n++)
            System.out.println(n + "th number: " + new PqSolution().nthUglyNumber(n));
    }
}