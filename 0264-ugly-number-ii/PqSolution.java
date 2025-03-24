import java.util.PriorityQueue;

class PqSolution {
    /** Ugly number: positive int with only prime factors {2,3,5} */
    public int nthUglyNumber(int n) {
        // We need to try n combinations of multiplying a number by 2,3,5, starting from 1
        // PQ trick is used to access the minimum, preserving order
        PriorityQueue<Long> q = new PriorityQueue<>();
        q.add(1L);

        for (long i = 1; i < n; i++) {
            long tmp = q.poll();
            while (!q.isEmpty() && q.peek() == tmp)
                tmp = q.poll();

            q.add(tmp * 2);
            q.add(tmp * 3);
            q.add(tmp * 5);
        }

        return q.poll().intValue();
    }

    public static void main(String[] args) {
        for (int n = 1; n <= 20; n++)
            System.out.println(n + "th number: " + new PqSolution().nthUglyNumber(n));
    }
}