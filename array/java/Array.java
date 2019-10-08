
public class Array {
    public static void main(String[] args) {
        int[] odds = { 1, 3, 5, 7, 9 };

        for (int i = 0; i < odds.length; i++) {
            System.out.println(
                String.format("  odds[%d] = %d", i, odds[i])
            );
        }
    }
}

// Array.java
