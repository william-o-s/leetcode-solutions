import java.util.List;

class Solution {
    public static void main(String[] args) {
        List<Integer> list = List.of(1, 2, 3, 4, 5);


        int sum = list
            .stream()
            .map(elem -> elem % 2 == 0 ? 1 : 0)
            .reduce(0, (s, i) -> s + i);

        System.out.printf("Sum: %d%n", sum);
    }
}